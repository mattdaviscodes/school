# CS 302 - Project 1
Date: 9/5/18 | Author: Matt Davis | [Assignment](./cs302-hw1.pdf)

1. `2 9 3`
2a. In C and C++, arrays are just pointers to their first elements, and are passed to functions as such. With only the pointer to work with, a developer has know way of knowing how many elements are in the array. Passing the dimensions of the array is the best way to avoid problems that might arise when dealing with an array of unknown size.

NOTE: I'm not sure why the questions is asking about 2d arrays specifically. It is my understanding that this practice is recommended for any function which takes an array as input.

2b. [Code](./questions/2b.cpp) and [diagram](./questions/2b.pdf). When indexing into dynamic, multi-dimensional arrays, the system first uses the local, top-level reference to the array. In the case of the examples linked here, this is `arr`, which is a `int**` variable local to the program. The indices provided by the user are then used in succession to look up the arrays stored on the stack. If the user requests `arr[1][2]` for example, the system would first access the element at `arr[1]`, which is of type `int*` (an array of integers). It would then use the value of that lookup to find the element at index 2, which is of type `int`.

3. [Code](./code/3.cpp) build with `make`

4. ```c++
        #include <iostream>

        int main()
        {
            int* ptr;
            int* temp;
            int x;

            ptr = new int;
            *ptr = 4;
            temp = new int;     // temp needs to be allocated before its value can be assigned
            *temp = *ptr;
            std::cout << ptr << " " << temp << std::endl;  // Qualify cout with std::. Also add spaces and endl for readability
            x = 9;
            *temp = x;
            std::cout << *ptr << " " << *temp << std::endl;
        //    ptr = new int;    No need to re-allocate
            *ptr = 5;
            std::cout << *ptr << " " << *temp << std::endl; // output is: … 5 9

            // Remember to deallocate
            delete ptr;
            delete temp;

            return 0;
        }
    ```
