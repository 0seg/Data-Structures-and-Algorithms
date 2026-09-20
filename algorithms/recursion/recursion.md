# Recursion

## What is Recursion?

Recursion is a technique where a function calls itself to solve a smaller version of the same problem.

General idea:

    Problem
       ↓
    Smaller problem
       ↓
    Smaller problem
       ↓
    Base case

## Basic Structure

A recursive function needs:

1. **Base Case** → condition that stops the recursion.
2. **Recursive Case** → the function calls itself with a smaller problem.

Example:

    int factorial(int n) {
        if (n <= 1)
            return 1;

        return n * factorial(n - 1);
    }

Without a proper base case, recursion can continue until a **Stack Overflow** occurs.

---

## Call Stack

Each recursive call creates a new **stack frame** in the Call Stack.

Example:

    factorial(4)

    factorial(4)
        factorial(3)
            factorial(2)
                factorial(1)  ← Base Case

Once the base case is reached, the calls return:

    factorial(1) = 1
    factorial(2) = 2 * 1
    factorial(3) = 3 * 2
    factorial(4) = 4 * 6

    Result = 24

Recursion has two phases:

    Calling phase   → calls are added to the stack
    Returning phase → calls return and resolve

---

## Before vs After the Recursive Call

The position of an operation relative to the recursive call affects the execution order.

Operation before recursion:

    print(n)
    func(n - 1)

For `n = 5`:

    5 4 3 2 1

Operation after recursion:

    func(n - 1)
    print(n)

For `n = 5`:

    1 2 3 4 5

The code after the recursive call executes during the **returning phase**.

---

## Complexity

The complexity depends on:

- Number of recursive calls.
- How much the problem decreases.
- Work performed in each call.

For example:

    factorial(n)

makes approximately `n` recursive calls.

    Time:  O(n)
    Space: O(n)

The space complexity is `O(n)` because the recursive calls remain in the Call Stack.

---

## Key Idea

> Recursion solves a problem by solving a smaller version of the same problem until reaching a base case.

## Analyzing Recursion

When analyzing a recursive function, ask:

1. What is the **base case**?
2. How does the problem become smaller?
3. What happens **before** the recursive call?
4. What happens **after** the recursive call?
5. What is the **time and space complexity**?