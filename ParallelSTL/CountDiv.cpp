#include "CountDiv.h"

#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <execution> // ��� std::execution

// ������� ��� ���������� ������� ���������� ������� � �������� ���������
void fillVectorWithRandom(std::vector<int>& vec, int minVal, int maxVal) {
    // ������������� ���������� ��������� �����
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(minVal, maxVal);

    // ���������� ������� ���������� �������
    for (int& num : vec) {
        num = distrib(gen);
    }
}

// ������� ��� ���������� ���������� ��������� �����
int countDivisors(int n) {
    int divisors = 0;
    int sqrt_n = sqrt(n); // ���������� ������ �����

    // ��������� ����� �� 1 �� ����� �� n
    for (int i = 1; i <= sqrt_n; ++i) {
        if (n % i == 0) {
            divisors += 2; // ��������� ��� ��������: i � n/i
        }
    }

    // ��������� ������, ����� sqrt_n �������� ���������
    if (std::abs(sqrt_n * sqrt_n - n) < std::pow(10, -6)) {
        divisors--;
    }

    return divisors;
}

// ������� ��� �������� ������� � ����������� ��������� ����� �� ������� �������
std::vector<int> createDivisorsVectorSeq(const std::vector<int>& vec) {
    std::vector<int> divisorsVec(vec.size());

    // ���������� �������� ���������� policy � std::transform
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