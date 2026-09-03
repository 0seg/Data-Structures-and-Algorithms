# Stack

## What is it?

A stack is a linear data structure that follows the **LIFO (Last In, First Out)** principle: the last element added is the first one to be removed.

## Visualization

```text
        TOP
         ↓
       ┌───┐
       │ 3 │
       ├───┤
       │ 2 │
       ├───┤
       │ 1 │
       └───┘
```

## How does it work?

Elements can only be added and removed from one end of the structure, called the **top**.

The most recently added element is always the first one to be removed.

## Operations

| Operation | Description | Time Complexity |
|-----------|-------------|-----------------|
| `push()` | Adds an element to the top | O(1) |
| `pop()` | Removes the top element | O(1) |
| `top()` | Returns the top element | O(1) |
| `empty()` | Checks whether the stack is empty | O(1) |

## When should you use it?

A stack is useful when the most recently added element needs to be processed first.

Common use cases include:

- Undo operations
- Browser history
- Function calls
- Parentheses validation
- Depth-First Search (DFS)
- Backtracking

## Key Takeaway

> A stack restricts access to its elements: only the element at the top can be directly accessed.

## Implementation

The implementation of the stack can be found in this directory.