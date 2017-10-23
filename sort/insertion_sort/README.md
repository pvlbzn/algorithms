# Insertion Sort

Inserted sort implemented on primitive array and singly linked list.
Singly linked list implementation can be found at [data_structure/singly_linked_list/](https://github.com/pvlbzn/algorithms/tree/master/data_structure/singly_linked_list) .

Main purpose of this implementation to show why it is important to think about both: algorithm itself and datastructure. Comments on each implementation and it's pros/cons can be found at implementational files as a docstrings.


## Plots

Plots were done using `gnuplot`. Each functions was called n times and time was measured using `chrono` facilities. However the time is not a relevant metric, but the curve itself is.

Plotting methodology:
Plotting function takes `dsize` as a paramenter. `dsize` is a number of elements in the final datastructure, whether it primitive `int` or `node`. Plotting algorithm creates data instance with `n` elements, where `n` is a number in the range `1..dsize`. On each iteration `n` is linearly incremented by `5`. Therefore there are `dsize / 5` plotting points. On each iteration _insertion sort_ is called, time is measured and printed to the `stdout` as `n    duration` where `n` is current dataset size and `duration` is elapsed time to sort dataset of size `n`.
As a trade off of this resolution _insertion sort_ actually called not `dsize` times, but it _(can be calculated recursively as)_:

```
def dsum(n):
  if n == 1: return 1
  return n + dsum(n-1)
```
Therefore for the `dsize` of 1500, there will be 1125750 calls to _insertion sort_, in total.


#### Insertion Sort: `int[]`

![Insertion Sort on int gnuplot](https://github.com/pvlbzn/algorithms/raw/master/plots/insertion_sort_on_array_primitive.png)


#### Insertion Sort: [data_structure/singly_linked_list/](https://github.com/pvlbzn/algorithms/tree/master/data_structure/singly_linked_list)

![Insertion Sort on singly linked list](https://github.com/pvlbzn/algorithms/raw/master/plots/insertion_sort_on_singly_linked_list.png)

