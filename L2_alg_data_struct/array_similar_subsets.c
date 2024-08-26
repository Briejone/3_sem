#include <stdio.h>
#include <stdlib.h>

// Функция для вычисления суммы элементов массива
int sum(int* arr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

// Функция для вывода подмножества
void printSubset(int* arr, int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", arr[i]);
    }
    printf("}");
}

// Основная функция для разбиения множества на два подмножества
void partition(int* S, int n) {
    // Сортируем массив для жадного алгоритма
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (S[j] < S[j + 1]) {
                int temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }
        }
    }

    // Создаем два подмножества
    int* subset1 = (int*)malloc(n * sizeof(int));
    int* subset2 = (int*)malloc(n * sizeof(int));
    int sum1 = 0, sum2 = 0;
    int size1 = 0, size2 = 0;

    // Жадный подход: добавляем элементы в подмножество с меньшей суммой
    for (int i = 0; i < n; i++) {
        if (sum1 <= sum2) {
            subset1[size1++] = S[i];
            sum1 += S[i];
        } else {
            subset2[size2++] = S[i];
            sum2 += S[i];
        }
    }

    // Выводим результаты
    printf("Subset 1: ");
    printSubset(subset1, size1);
    printf("\nSubset 2: ");
    printSubset(subset2, size2);
    printf("\nDifference between amounts: %d\n", abs(sum1 - sum2));

    // Освобождаем память
    free(subset1);
    free(subset2);
}

int main() {
    int S[] = {5, 8, 1, 14, 7};
    int n = sizeof(S) / sizeof(S[0]);

    partition(S, n);

    return 0;
}
