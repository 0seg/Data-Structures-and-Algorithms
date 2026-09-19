# Arrays

## What is an Array?

A data structure that stores elements of the **same type** in **contiguous memory locations**.

### Mental Model

Think of an array as a row of numbered boxes:

```text
Index:   0    1    2    3
        [10] [20] [30] [40]
```

The index starts at `0`.

## Memory

Array elements are stored **contiguously**.

```text
[10][20][30][40]
 ↑
same contiguous memory region
```

Where the array lives depends on how it is created:

- Local array → **Stack**
- Dynamic array → **Heap**
- Global/static array → **Static storage**

> **Array ≠ Stack.**  
> Array describes the data structure; Stack/Heap describe where it lives in memory.

## Why is Access O(1)?

The address can be calculated directly:

`address = base_address + index × element_size`

Therefore:

**Access → O(1)**

## Common Operations

| Operation | Complexity |
|---|---|
| Access | O(1) |
| Search | O(n) |
| Insert/Delete middle | O(n) |

## Key Idea

> **Array = contiguous memory + index-based direct access.**

Fast access, but inserting/deleting in the middle can require shifting elements.
