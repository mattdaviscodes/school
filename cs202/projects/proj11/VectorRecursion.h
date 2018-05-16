#include <vector>


template <class T>
void swap(std::vector<T> & vec, int a, int b) {
    T tmp;

    tmp = vec[a];
    vec[a] = vec[b];
    vec[b] = tmp;
}

template <class T>
void vector_resort(std::vector<T> & vec, size_t n) {
    if (n == 1) {
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (vec[i] > vec[i + 1]) {
            swap(vec, i, i + 1);
        }
    }

    vector_resort(vec, n - 1);
}

template <class T>
int vector_research(std::vector<T> & vec, const T & value, int left, int right) {
    int mid = (left + right) / 2;

    if (left > right) {
        return -1;
    }

    if (vec[mid] < value) {
        return vector_research(vec, value, mid + 1, right);
    } else if (vec[mid] > value) {
        return vector_research(vec, value, left, mid - 1);
    }

    return mid;

}