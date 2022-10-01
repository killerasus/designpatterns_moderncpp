# Adapter

A construct which adapts an existing interface X to conform to the requires interface Y.

- Determine the API you have and the API you need.
- Create a component that aggregates the adaptee.
- Intermediate representations can pile up: use caching and other optimizations.

## In the STL

`stack`, `queue` and `priority_queue` both adapt the interface of a `dequeue` to the desired data structure.
