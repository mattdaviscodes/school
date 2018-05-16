# Project 11
Submitted: 5/15/18

### Purpose
This project presented a chance to experiment with recursion. We were
instructed to write two fairly simple functions (sort and search) which
would operate on `std::vector`s. These functions needed to be templated,
so the vectors could be of any type. The project was also an opportunity
to try out some of the std library.

### Design Choices
I chose to implement bubble sort for my sorting algorithm. This isn't
an efficient choice, and does not benefit at all from recursion, but
it's a simple algorithm which I knew how to construct easily. It can
still be called recursively, regardless of performance. Each call is
another pass over the input, swapping elements as we go. The base
condition depends on an extra parameter passed in, which is the index of
the point in the array past which has already been sorted. This number
decrements with each call, so once it reaches 1, we know the array
is sorted and we can return.

I also templated a helper function `swap` to facilitate the sorting.

The only possible problems I see with my implementation is that both
sort and swap depend on comparison (`>` and `<`). If type `T` has not
implemented the comparison operators, then these will fail. This burden
should be on the developer using these functions, but some error
checking might be a good addition, given time.