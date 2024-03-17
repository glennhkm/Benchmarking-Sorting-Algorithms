#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int isNotUnique(int *arr, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    clock_t start, end;
    double cpu_time_used;
    int size = 1000000;
    int *arr = malloc(size * sizeof(int));
    int i = 0;

    start = clock();

    while (i < 1000000)
    {
        srand(time(NULL) + clock());
        Sleep(1);
        int random_number = rand();

        // if (i > 0)
        // {
        if (!isNotUnique(arr, 1000000, random_number))
        {
            arr[i] = random_number;
            printf("Random %d : %d\n", i, random_number);
            i++;
        }
    }

    end = clock(); // Selesai menghitung waktu
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // printf("ISI ARRAY = ");
    // for (int i = 0; i < 1000000; i++)
    // {
    //     printf("%d, ", arr[i]);
    // }

    printf("MAX RAND %d\n", RAND_MAX);
    printf("Waktu eksekusi: %f detik\n", cpu_time_used);
    // printf("Result : %d", 121 % 7);
    // printf("Random : %d", random_number % 100000);
    // while (i <= 10)
    // {
    //     printf("Clock : %d\n", clock());
    //     printf("Clock : %d\n", time(NULL));
    //     Sleep(0.1);
    //     i++;
    // }
}

// int isValueInArray(int value, int *arr, int size) {
//     for (int i = 0; i < size; ++i) {
//         if (arr[i] == value) {
//             return 1; // Nilai sudah ada dalam array
//         }
//     }
//     return 0; // Nilai belum ada dalam array
// }

// // Fungsi untuk mengisi array dengan nilai random yang unik
// void fillUniqueRandom(int *arr, int size) {
//     int i = 0;
//     while (i < size) {
//         srand(time(NULL) + i);  // Ganti seed dengan sesuatu yang berbeda setiap iterasi
//         int random_number = rand();
//         if (!isValueInArray(random_number, arr, i)) {
//             arr[i] = random_number;
//             printf("Random %d: %d\n", i, random_number);
//             i++;
//         }
//     }
// }

// int main() {
//     clock_t start, end;
//     double cpu_time_used;
//     int arr[100];
//     int nilaiAwal = time(NULL);

//     start = clock();
//     fillUniqueRandom(arr, 100);

//     end = clock(); // Selesai menghitung waktu
//     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

//     printf("Waktu eksekusi: %f detik\n", cpu_time_used);

//     return 0;
// }