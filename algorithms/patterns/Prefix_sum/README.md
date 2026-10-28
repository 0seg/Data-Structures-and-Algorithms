# Prefix Sum

Prefix Sum is a preprocessing technique that stores cumulative sums of an array to answer range-sum queries in constant time.

## Definition

Given an array \(A\) of size \(n\), its prefix sum array \(P\) is defined as:

\[
P[i] = \sum_{j=0}^{i} A[j]
\]

Each element \(P[i]\) represents the sum of all elements from index \(0\) to \(i\).

## Range Sum

For an inclusive range \([l,r]\), the sum is obtained by subtracting the prefix before \(l\) from the prefix at \(r\):

\[
\operatorname{sum}(l,r)=
\begin{cases}
P[r], & l=0\\
P[r]-P[l-1], & l>0
\end{cases}
\]

This allows range-sum queries without iterating over the selected elements.

## Complexity

- **Preprocessing:** \(O(n)\)
- **Range query:** \(O(1)\)
- **Space:** \(O(n)\)

Prefix Sum is particularly useful when multiple range-sum queries are performed over a static array. For frequently updated data, structures such as Fenwick Trees or Segment Trees may be more suitable.
