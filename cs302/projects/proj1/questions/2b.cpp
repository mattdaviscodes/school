// Copyright 2018 Matt Davis matt.davis@nevada.unr.edu

#include <iostream>

int main() {
    int rows = 3;
    int cols = 5;

    int** arr = new int*[rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    return 0;
}
