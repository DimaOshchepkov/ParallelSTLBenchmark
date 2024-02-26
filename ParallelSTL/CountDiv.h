#pragma once
#include <vector>

// ������� ��� ���������� ���������� ��������� �����
int countDivisors(int n);

// ������� ��� �������� ������� � ����������� ��������� ����� �� ������� �������
std::vector<int> createDivisorsVectorSeq(const std::vector<int>& vec);

std::vector<int> createDivisorsVectorPar(const std::vector<int>& vec);

std::vector<int> createDivisorsVectorParUnseq(const std::vector<int>& vec);

void fillVectorWithRandom(std::vector<int>& vec, int minVal, int maxVal);