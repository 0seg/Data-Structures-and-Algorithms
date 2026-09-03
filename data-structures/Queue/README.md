# Queue

## What is it?

A queue is a linear data structure that follows the **FIFO (First In, First Out)** principle: the first element added is the first one to be removed.

## Visualization

```text
FRONT                   REAR
  ↓                       ↓
[ 1 ] → [ 2 ] → [ 3 ] → [ 4 ]
  ↑                       ↑
remove                  add
```

## How does it work?

Elements are added at one end of the structure, called the **rear**, and removed from the other end, called the **front**.

The first element added to the queue is always the first one to be removed.

## Operations

| Operation | Description | Time Complexity |
|-----------|-------------|-----------------|
| `enqueue()` | Adds an element to the rear | O(1) |
| `dequeue()` | Removes the front element | O(1) |
| `front()` | Returns the front element | O(1) |
| `empty()` | Checks whether the queue is empty | O(1) |

## When should you use it?

A queue is useful when elements need to be processed in the same order they were added.

Common use cases include:

- Task scheduling
- Print queues
- Breadth-First Search (BFS)
- Message queues
- Request handling

## Key Takeaway

> A queue preserves insertion order: elements enter from the rear and leave from the front.

## Implementation

The implementation of the queue can be found in this directory.