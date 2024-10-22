#include <iostream>
#include <vector>


void heapify(std::vector<int>& vec, const int& size, const int& i) {
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < size && vec[left] > vec[i]) {
        largest = left;
    }

    if (right < size && vec[right] > vec[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(vec[largest], vec[i]);
        heapify(vec, size, largest);
    }
}

void buildMaxHeap(std::vector<int>& vec) {
    for (int i = (vec.size() - 1) / 2; i >= 0; --i) {
        heapify(vec, vec.size(), i);
    }
}

void heapSort(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = n - 1; i > 0; --i) {
        std::swap(vec[0], vec[i]);
        n -= 1;
        heapify(vec, n, 0);
    }
}

int main() {
    std::vector<int> vec = {4, 7, 1, 3, 6, 8};

    buildMaxHeap(vec);

    for (int elem : vec) {
        std::cout << elem << " ";
    }

    std::cout << std::endl;

    heapSort(vec);

    for (int elem : vec) {
        std::cout << elem << " ";
    }
    return 0;
}