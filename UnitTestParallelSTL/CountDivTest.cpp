#include "pch.h"

bool eq(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    if (vec1.size() != vec2.size()) {
        return false;
    }
    for (size_t i = 0; i < vec1.size(); ++i) {
        if (vec1[i] != vec2[i]) {
            return false;
        }
    }
    return true;
}
TEST(CountDiv, createDivisorsVectorPar) {
    std::vector<int> vec1 = { 6, 8, 3, 9 };
    ASSERT_TRUE(eq(createDivisorsVectorPar(vec1), { 4, 4, 2, 3 }));
}

TEST(CountDiv, createDivisorsVectorSeq) {
    std::vector<int> vec1 = { 6, 8, 3, 9 };
    ASSERT_TRUE(eq(createDivisorsVectorSeq(vec1), { 4, 4, 2, 3 }));
}

TEST(CountDiv, createDivisorsVectorParUnseq) {
    std::vector<int> vec1 = { 6, 8, 3, 9 };
    ASSERT_TRUE(eq(createDivisorsVectorParUnseq(vec1), { 4, 4, 2, 3 }));
}