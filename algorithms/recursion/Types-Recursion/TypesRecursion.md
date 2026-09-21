# Types of Recursion

## 1. Tail Recursion

The recursive call is the **last operation** performed by the function.

    function(n):
        if condition:
            do something
            function(n - 1)

There is no work left after the recursive call returns.

---

## 2. Head Recursion

The recursive call happens **before** the remaining operations.

    function(n):
        if condition:
            function(n - 1)
            do something

The work is performed during the **returning phase**.

---

## 3. Tree Recursion

A function makes **multiple recursive calls** from a single call.

    function(n):
        if condition:
            function(n - 1)
            function(n - 1)

This creates a branching **call tree**.

    f(3)
    ├── f(2)
    │   ├── f(1)
    │   └── f(1)
    └── f(2)
        ├── f(1)
        └── f(1)

With two recursive calls per level, the number of calls grows rapidly.

---

## 4. Indirect Recursion

Two or more functions call each other recursively.

    A → B → A → B → ...

Example:

    functionA() → functionB()
    functionB() → functionA()

The recursion does not happen directly inside the same function.

---

## 5. Nested Recursion

A recursive call is used as the **argument of another recursive call**.

    function(function(n + 1))

Example:

    nestedRecursion(
        nestedRecursion(n + 11)
    )

The inner recursive call must return before the outer call can continue.

---

## Comparison

| Type | Main Idea |
|---|---|
| Tail | Recursive call is the last operation |
| Head | Recursive call happens before the work |
| Tree | Multiple recursive calls |
| Indirect | Functions call each other |
| Nested | Recursive call inside another recursive call |

## Key Idea

> The type of recursion is determined by **how recursive calls are arranged and what happens around them**.