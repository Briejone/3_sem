#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Функция для сравнения последовательности с шаблоном
int isMatch(const char *sequence, const char *pattern) {
    int n = strlen(sequence);
    int m = strlen(pattern);

    // Создаем таблицу для хранения промежуточных результатов
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((m + 1) * sizeof(int));
        memset(dp[i], 0, (m + 1) * sizeof(int)); // Инициализируем таблицу значениями 0 (false)
    }

    // Пустая строка соответствует пустому шаблону
    dp[0][0] = 1;

    // Заполняем таблицу для случая, если шаблон начинается с '*'
    for (int j = 1; j <= m; j++) {
        if (pattern[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // Заполняем DP таблицу
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pattern[j - 1] == '?' || pattern[j - 1] == sequence[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (pattern[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }

    int result = dp[n][m];

    // Освобождаем память
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    const char *sequence1 = "meow@stud.nstu.ru";
    const char *pattern1 = "meow@stud.n?tu.ru";
    int result1 = isMatch(sequence1, pattern1);
    printf("The sequence \"%s\" matches the pattern \"%s\": %s\n",
            sequence1, pattern1, result1 ? "Yes" : "No");
    
    const char *sequence2 = "hello";
    const char *pattern2 = "h?lo";
    int result2 = isMatch(sequence2, pattern2);
    printf("The sequence \"%s\" matches the pattern \"%s\": %s\n",
            sequence2, pattern2, result2 ? "Yes" : "No");


    return 0;
}
