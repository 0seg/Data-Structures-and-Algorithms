# Diagonal Matrix

A diagonal matrix is a square matrix where all elements outside the main diagonal are zero.

Example:

```text
1 0 0
0 2 0
0 0 3
```

## Representation

Instead of storing the entire `n × n` matrix, this implementation stores only the elements of the main diagonal in a one-dimensional array.

For example:

```text
data = [1, 2, 3]

represents:

1 0 0
0 2 0
0 0 3
```

This reduces the required space from `O(n²)` to `O(n)`.

## Operations

- `set(i, j, x)` — Sets an element if it belongs to the main diagonal.
- `get(i, j)` — Retrieves an element from the matrix.
- `display()` — Displays the complete matrix.

## Complexity

| Operation | Time | Space |
|-----------|------|-------|
| `set()` | O(1) | O(1) |
| `get()` | O(1) | O(1) |
| `display()` | O(n²) | O(1) |

The matrix itself requires `O(n)` memory.

## Implementation

Implemented in C++ using dynamic memory allocation.