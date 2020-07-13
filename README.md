
# Pattern

This project prints and records a randomly generated hitomezashi stiching pattern.

Using the `Cell`, `Grid`, and `Gridline` classes to perform logic operations and conversions.
A grid is generated and then comverted to a `bitset`.

## `Cell`

A `Cell` in the `Grid` knows about the `Gridline`s to each side of it.
Using a simple logic operation in its `get_next`, a `Cell` can tell what colour its neighbour should be.

This result can be plugged into the neighbours `draw` method to change its colour.

## `Gridline`

The functions and properties of a `Gridline` are fairly simple.
It can randomly toggle it's "parity," and tell whether it seperates two cells via its `get_edge` method.

## `Grid`

The `Grid` class stores all of the `Cell`s and `Gridline`s in `vector`s, and can convert them to a `bitset`.
The `colour` method sets all the `Cells` to follow the rules of the colouring system.
The `randomize` method randomizes the parity of all the `Gridline`s.
The `convert_to_bitset` method stores all of the data of the `Cells` in a `bitset`.