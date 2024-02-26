#include "CountDiv.h"

#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <execution> // Для std::execution

// Функция для заполнения вектора случайными числами в заданном диапазоне
void fillVectorWithRandom(std::vector<int>& vec, int minVal, int maxVal) {
    // Инициализация генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(minVal, maxVal);

    // Заполнение вектора случайными числами
    for (int& num : vec) {
        num = distrib(gen);
    }
}

// Функция для вычисления количества делителей числа
int countDivisors(int n) {
    int divisors = 0;
    int sqrt_n = sqrt(n); // Квадратный корень числа

    // Проверяем числа от 1 до корня из n
    for (int i = 1; i <= sqrt_n; ++i) {
        if (n % i == 0) {
            divisors += 2; // Добавляем два делителя: i и n/i
        }
    }

    // Учитываем случай, когда sqrt_n является делителем
    if (std::abs(sqrt_n * sqrt_n - n) < std::pow(10, -6)) {
        divisors--;
    }

    return divisors;
}

// Функция для создания вектора с количеством делителей чисел из другого вектора
std::vector<int> createDivisorsVectorSeq(const std::vector<int>& vec) {
    std::vector<int> divisorsVec(vec.size());

    // Используем политику выполнения policy в std::transform
    std::transform(std::execution::seq, vec.begin(), vec.end(), divisorsVec.begin(), countDivisors);

    return divisorsVec;
}

std::vector<int> createDivisorsVectorPar(const std::vector<int>& vec) {
    std::vector<int> divisorsVec(vec.size());
    std::transform(std::execution::par, vec.begin(), vec.end(), divisorsVec.begin(), countDivisors);

    return divisorsVec;
}

std::vector<int> createDivisorsVectorParUnseq(const std::vector<int>& vec) {
    std::vector<int> divisorsVec(vec.size());
    std::transform(std::execution::par_unseq, vec.begin(), vec.end(), divisorsVec.begin(), countDivisors);

    return divisorsVec;
}