# Prefix Sum

Prefix Sum is a preprocessing technique used to answer range-sum queries efficiently on a static array.

## Theory

Given an array `A` of size `n`, the prefix sum array `P` is defined as:

`P[i] = A[0] + A[1] + ... + A[i]`

Each position stores the cumulative sum from the beginning of the array up to index `i`.

For an inclusive range `[l, r]`, the sum is calculated as:

- If `l == 0`: `sum(l, r) = P[r]`
- Otherwise: `sum(l, r) = P[r] - P[l - 1]`

By subtracting the prefix before the requested range, we obtain its sum without iterating over the elements.

## Complexity

| Operation | Complexity |
|---|---|
| Preprocessing | `O(n)` |
| Range-sum query | `O(1)` |
| Auxiliary space | `O(n)` |

## Use Cases

Prefix Sum is useful when multiple range-sum queries must be answered over an array that does not change. For frequent updates, a Fenwick Tree or Segment Tree may be more appropriate.
