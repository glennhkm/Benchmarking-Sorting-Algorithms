#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBERS 1000000

void shuffle(int *arr, int size)
{
    printf("\nShuffling 1000k unique integers...\n\n");
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


void generateRandomNumbers(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }

    for (int i = 0; i < 1000000; i++)
    {
        arr[i] = i + 1;
    }

    shuffle(arr, MAX_NUMBERS);
}

void bubbleSort(int arr[], int size) {
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        // printf("BUBBLE SORT : %d\n", i);
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void saveToFile(const char* filename, int arr[], int size) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuka file %s\n", filename);
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d, ", arr[i]);
    }
    fclose(file);
    printf("Integers has filled into %s\n file", filename);
}

double measureTime(void (*sortFunction)(int*, int), int arr[], int size) {
    clock_t start = clock();
    sortFunction(arr, size);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC * 1000; // Waktu dalam milidetik
}

int main() {
    int *numbers = malloc(MAX_NUMBERS *sizeof(int));
    generateRandomNumbers(numbers, MAX_NUMBERS);
    saveToFile("unsorted.txt", numbers, MAX_NUMBERS);

    printf("\n---------------------------------------------------------------\n");
    printf("Sort Algorithm\t| Integers Total\t| Execution Time (ms)\n");
    printf("---------------------------------------------------------------\n");

    int step = 100000;
    for (int size = step; size <= MAX_NUMBERS; size += step) {
        int *arr = malloc(size * sizeof(int));
    
        memcpy(arr, numbers, size * sizeof(int));   
        printf("Bubble Sort\t| %dk\t\t\t| %.3f\n", size / 1000, measureTime(bubbleSort, arr, size));

        memcpy(arr, numbers, size * sizeof(int));
        printf("Selection Sort\t| %dk\t\t\t| %.3f\n", size / 1000, measureTime(selectionSort, arr, size));

        memcpy(arr, numbers, size * sizeof(int));
        printf("Insertion Sort\t| %dk\t\t\t| %.3f\n", size / 1000, measureTime(insertionSort, arr, size));

        if (size == MAX_NUMBERS)
        {
            memcpy(numbers, arr, size * sizeof(int));
        }

        printf("---------------------------------------------------------------\n");
    }

    printf("\nEntering sorted integer to txt file...\n");
    saveToFile("sorted.txt", numbers, MAX_NUMBERS);
    printf("\n");

    return 0;
}
