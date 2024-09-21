#include <stdio.h>
#include <stdlib.h>

// Структура для множества (set)
typedef struct {
    int* data;
    int size;
    int capacity;
} Set;

// Создание множества
Set* createSet(int capacity) {
    Set* set = (Set*)malloc(sizeof(Set));
    set->data = (int*)malloc(capacity * sizeof(int));
    set->size = 0;
    set->capacity = capacity;
    return set;
}

// Освобождение памяти множества
void freeSet(Set* set) {
    free(set->data);
    free(set);
}

// Проверка, содержится ли элемент в множестве
int contains(Set* set, int element) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == element) {
            return 1;
        }
    }
    return 0;
}

// Вставка элемента в множество
void add(Set* set, int element) {
    if (!contains(set, element)) {
        set->data[set->size++] = element;
    }
}

// Функция для вычисления суммы элементов множества
int sum(Set* set) {
    int total = 0;
    for (int i = 0; i < set->size; i++) {
        total += set->data[i];
    }
    return total;
}

// Функция для вывода множества
void printSet(Set* set) {
    printf("{");
    for (int i = 0; i < set->size; i++) {
        if (i > 0) printf(", ");
        printf("%d", set->data[i]);
    }
    printf("}");
}

// Основная функция для разбиения множества на два подмножества
void partition(int* S, int n) {
    // Сортировка массива для жадного алгоритма
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (S[j] < S[j + 1]) {
                int temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }
        }
    }

    // Создаем два множества
    Set* subset1 = createSet(n);
    Set* subset2 = createSet(n);
    int sum1 = 0, sum2 = 0;

    // Жадный подход: добавляем элементы в подмножество с меньшей суммой
    for (int i = 0; i < n; i++) {
        if (!contains(subset1, S[i]) && !contains(subset2, S[i])) { // Проверяем дубликаты
            if (sum1 <= sum2) {
                add(subset1, S[i]);
                sum1 += S[i];
            } else {
                add(subset2, S[i]);
                sum2 += S[i];
            }
        }
    }

    // Выводим результаты
    printf("Subset 1: ");
    printSet(subset1);
    printf("\nSubset 2: ");
    printSet(subset2);
    printf("\nDifference between amounts: %d\n", abs(sum1 - sum2));

    // Освобождаем память
    freeSet(subset1);
    freeSet(subset2);
}

int main() {
    int S[] = {25, 28, 14, 17, 90, 78, 90, 90}; 
    int n = sizeof(S) / sizeof(S[0]);

    partition(S, n);

    return 0;
}
