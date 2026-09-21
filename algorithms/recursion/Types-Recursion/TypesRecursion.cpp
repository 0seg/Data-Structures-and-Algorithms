#include <iostream>

// ============================================================
// Types of Recursion
// ============================================================

// ------------------------------------------------------------
// Tail Recursion
// The recursive call is the last operation performed.
// ------------------------------------------------------------
void tailRecursion(int n) {
    if (n > 0) {
        std::cout << n << " ";
        tailRecursion(n - 1);
    }
}

// ------------------------------------------------------------
// Head Recursion
// The recursive call happens first.
// The remaining statements execute during the return phase.
// ------------------------------------------------------------
void headRecursion(int n) {
    if (n > 0) {
        headRecursion(n - 1);
        std::cout << n << " ";
    }
}

// ------------------------------------------------------------
// Tree Recursion
// Each call makes multiple recursive calls.
// This creates a branching call tree.
// ------------------------------------------------------------
void treeRecursion(int n) {
    if (n > 0) {
        std::cout << n << " ";

        treeRecursion(n - 1);
        treeRecursion(n - 1);
    }
}

// ------------------------------------------------------------
// Indirect Recursion
// A function calls another function, which eventually
// calls the first function again.
//
// A → B → A → B ...
// ------------------------------------------------------------
void indirectRecursionB(int n);

void indirectRecursionA(int n) {
    if (n > 0) {
        std::cout << n << " ";
        indirectRecursionB(n - 1);
    }
}

void indirectRecursionB(int n) {
    if (n > 1) {
        std::cout << n << " ";
        indirectRecursionA(n / 2);
    }
}

// ------------------------------------------------------------
// Nested Recursion
// A recursive call is used as the argument of another
// recursive call.
//
// f(f(...))
// ------------------------------------------------------------
int nestedRecursion(int n) {
    if (n > 100) {
        return n - 10;
    }

    return nestedRecursion(
        nestedRecursion(n + 11)
    );
}

// ============================================================
// Main
// ============================================================

int main() {

    std::cout << "Tail Recursion: ";
    tailRecursion(5);
    std::cout << '\n';

    std::cout << "Head Recursion: ";
    headRecursion(5);
    std::cout << '\n';

    std::cout << "Tree Recursion: ";
    treeRecursion(3);
    std::cout << '\n';

    std::cout << "Indirect Recursion: ";
    indirectRecursionA(5);
    std::cout << '\n';

    std::cout << "Nested Recursion: ";
    std::cout << nestedRecursion(95);
    std::cout << '\n';

    return 0;
}