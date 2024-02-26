#pragma once
#include <vector>

// Функция для вычисления количества делителей числа
int countDivisors(int n);

// Функция для создания вектора с количеством делителей чисел из другого вектора
std::vector<int> createDivisorsVectorSeq(const std::vector<int>& vec);

std::vector<int> createDivisorsVectorPar(const std::vector<int>& vec);

std::vector<int> createDivisorsVectorParUnseq(const std::vector<int>& vec);

void fillVectorWithRandom(std::vector<int>& vec, int minVal, int maxVal);