#include <iostream>
#include <limits>

using namespace std;

// int[] => int*
// a function needs the size of the array as well
void printNumbers(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
}

int linearSearch(const int numbers[], size_t size, int target) {
    for (int i = 0; i < size; i++) {
        if (numbers[i] == target) {
            return i;
        }
    }

    return -1;
}

void swap(int numbers[], int i, int j) {
    const int tmp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = tmp;
}

void selectionSort(int numbers[], const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (numbers[i] > numbers[j]) {
                swap(numbers, i, j);
            }
        }
    }
}

void bubbleSort(int numbers[], const int size) {
    for (int pass = 0; pass < size; pass++) {
        for (int i = 1; i < size; i++) {
            if (numbers[i] < numbers[i - 1]) {
                swap(numbers, i, i - 1);
            }
        }
    }
}

int main() {
    int numbers[] = {10, 20};

    // prints array reference
    cout << numbers << endl;

    // sizeof(numbers) returns the size of the array in bytes
    // so this means for numbers array, sizeof(numbers) = 8
    // sizeof(int) returns the size of an integer in bytes
    cout << sizeof(int) << endl;

    for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
        cout << numbers[i] << endl;
    }

    // easier way to get the size of an array
    for (int i = 0; i < size(numbers); i++) {
        cout << numbers[i] << endl;
    }

    // == Copying arrays ==
    cout << "Copying arrays" << endl;
    int first[] = {10, 20, 30};

    // does not work, you cannot copy arrays like this
    // int second[] = first;

    // this also does not work
    // int second[3];
    // second = first;


    // == Copying arrays using a loop ==
    int second[size(first)];
    for (int i = 0; i < size(first); i++) {
        second[i] = first[i];
    }

    for (auto num: second) {
        cout << num << endl;
    }

    // == Comparing arrays ==
    cout << endl << "Comparing arrays" << endl;

    int compFirst[] = {10, 20, 30};
    int compSecond[] = {10, 20, 30};

    cout << compFirst << endl;
    cout << compSecond << endl;

    // == Comparing using a forloop ==
    bool areEqual = true;
    for (int i = 0; i < size(compFirst); i++) {
        if (compFirst[i] != compSecond[i]) {
            areEqual = false;
            break;
        }
    }

    cout << "Equal: " << areEqual << endl;

    // == Passing arrays to functions ==
    cout << endl << "Passing arrays to functions" << endl;
    printNumbers(compFirst, size(compFirst));

    // == Difference between int and size_t ==
    cout << endl << "Difference between int and size_t" << endl;

    // size_t is an unsigned long long type
    cout << numeric_limits<long long>::min() << endl;
    cout << numeric_limits<long long>::max() << endl;

    cout << numeric_limits<size_t>::min() << endl;
    cout << numeric_limits<size_t>::max() << endl;

    cout << sizeof(size_t) << endl;

    // == Unpacking arrays ==
    cout << endl << "Unpacking arrays" << endl;
    int values[3] = {10, 20, 30};
    // C++: structured bindings
    // JavaScript: destructuring
    // Python: unpacking

    auto [x, y, z] = values;
    cout << x << " " << y << " " << z << endl;

    // int x = values[0];
    // int y = values[1];
    // int z = values[2];

    // == Searching in arrays ==
    cout << endl << "Searching in arrays" << endl;
    int searchValues[] = {10, 20, 30, 40, 50};

    // Exercise: implement the linear search algorithm
    int searchValue = 10;

    cout << "Linear search" << endl;
    int index = linearSearch(searchValues, size(searchValues), searchValue);

    cout << index << endl;

    // == Sorting arrays ==
    cout << endl << "Sorting arrays" << endl;
    int unsorted[] = {10, 5, 20, 30, 40};

    // selectionSort(unsorted, size(unsorted));
    bubbleSort(unsorted, size(unsorted));

    printNumbers(unsorted, size(unsorted));

    // == Multi-dimensional arrays ==
    cout << endl << "Multi-dimensional arrays" << endl;
    // 2x3
    int matrix [2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // i = rows
    for (int i = 0; i < size(matrix); i++) {
        // j = columns
        for (int j = 0; j < size(matrix[0]); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
