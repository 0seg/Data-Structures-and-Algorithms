
#include <iostream>
#include <vector>
#include <stdexcept>

// Builds a prefix sum array from the input vector.
std::vector<long long> build_prefix_sum(
    const std::vector<int>& numbers)
{
    std::vector<long long> prefix(numbers.size());

    if (numbers.empty())
    {
        return prefix;
    }

    prefix[0] = numbers[0];

    for (std::size_t i = 1; i < numbers.size(); ++i)
    {
        prefix[i] = prefix[i - 1] + numbers[i];
    }

    return prefix;
}

// Returns the sum of the inclusive range [left, right].
long long range_sum(
    const std::vector<long long>& prefix,
    std::size_t left,
    std::size_t right)
{
    if (left > right || right >= prefix.size())
    {
        throw std::out_of_range("Invalid range");
    }

    if (left == 0)
    {
        return prefix[right];
    }

    return prefix[right] - prefix[left - 1];
}

int main()
{
    const std::vector<int> numbers = {2, 4, 1, 3, 5};

    const std::vector<long long> prefix =
        build_prefix_sum(numbers);

    std::cout << "Original array: ";
    for (int value : numbers)
    {
        std::cout << value << ' ';
    }

    std::cout << "\nPrefix sum:     ";
    for (long long value : prefix)
    {
        std::cout << value << ' ';
    }

    std::cout << "\n\n";

    // Sum elements at indices 1, 2, and 3.
    std::cout << "Sum of range [1, 3]: "
              << range_sum(prefix, 1, 3) << '\n';

    // Sum elements from the beginning through index 2.
    std::cout << "Sum of range [0, 2]: "
              << range_sum(prefix, 0, 2) << '\n';

    // Sum the entire array.
    std::cout << "Sum of range [0, 4]: "
              << range_sum(prefix, 0, 4) << '\n';

    return 0;
}
