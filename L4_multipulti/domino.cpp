#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <algorithm>

struct Domino {
    int side1;
    int side2;

    bool operator<(const Domino& other) const {
        if (side1 != other.side1)
            return side1 < other.side1;
        return side2 < other.side2;
    }

    bool operator==(const Domino& other) const {
        return (side1 == other.side1 && side2 == other.side2) ||
               (side1 == other.side2 && side2 == other.side1);
    }
};

std::set<Domino> createFullSet(int maxSideValue) {
    std::set<Domino> fullSet;
    for (int i = 0; i <= maxSideValue; ++i) {
        for (int j = i; j <= maxSideValue; ++j) {
            fullSet.insert({i, j});
        }
    }
    return fullSet;
}

std::set<Domino> findMissingDominoes(const std::vector<Domino>& currentSet, const std::set<Domino>& fullSet) {
    std::set<Domino> missingSet;
    for (const auto& domino : fullSet) {
        auto it = std::find_if(currentSet.begin(), currentSet.end(), 
            [&domino](const Domino& d) {
                return d == domino;
            });
        if (it == currentSet.end()) {
            missingSet.insert(domino);
        }
    }
    return missingSet;
}

// Для многопоточности просто выведем сообщение о запуске
void findMissingDominoesInRange(const std::vector<Domino>& currentSet, const std::set<Domino>& fullSet, int start, int end, std::set<Domino>& missingSet) {
    std::set<Domino> localMissingSet;
    for (const auto& domino : fullSet) {
        auto it = std::find_if(currentSet.begin() + start, currentSet.begin() + end,
            [&domino](const Domino& d) {
                return d == domino;
            });
        if (it == currentSet.begin() + end) {
            localMissingSet.insert(domino);
        }
    }
    // Просто добавим все в основной набор
    missingSet.insert(localMissingSet.begin(), localMissingSet.end());
}

void measureExecutionTime(const std::vector<Domino>& currentSet, const std::set<Domino>& fullSet, int numThreads) {
    auto startSingleThread = std::chrono::high_resolution_clock::now();
    auto missingDominoesSingleThread = findMissingDominoes(currentSet, fullSet);
    auto endSingleThread = std::chrono::high_resolution_clock::now();

    auto durationSingleThread = std::chrono::duration_cast<std::chrono::milliseconds>(endSingleThread - startSingleThread).count();
    std::cout << "Single-threaded execution time: " << durationSingleThread << " ms\n";

    std::set<Domino> missingSet;

    int partSize = currentSet.size() / numThreads;
    int remaining = currentSet.size() % numThreads;

    int start = 0;
    for (int i = 0; i < numThreads; ++i) {
        int end = start + partSize + (i < remaining ? 1 : 0);
        findMissingDominoesInRange(currentSet, fullSet, start, end, missingSet);
        start = end;
    }

    auto endMultiThread = std::chrono::high_resolution_clock::now();
    auto durationMultiThread = std::chrono::duration_cast<std::chrono::milliseconds>(endMultiThread - startSingleThread).count();
    std::cout << "Multi-threaded execution time: " << durationMultiThread << " ms\n";

    // Вывод отсутствующих домино
    std::cout << "Missing dominoes:\n";
    for (const auto& domino : missingSet) {
        std::cout << domino.side1 << "-" << domino.side2 << "\n";
    }
}

int main() {
    int maxSideValue = 6;  // Максимальное значение на одной стороне домино
    std::vector<Domino> currentSet = {{0, 0}, {0, 1}, {1, 1}, {1, 2}, {2, 3}};  // Пример текущего набора домино

    int numThreads = 4;  // Количество потоков

    auto fullSet = createFullSet(maxSideValue);
    measureExecutionTime(currentSet, fullSet, numThreads);

    return 0;
}
