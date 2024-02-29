#include "pch.h"
#include "Matrix.h"
#include "Mult.h"

// Функция проверки равенства матриц
bool eq(const Matrix& mat1, const Matrix& mat2){
    if (mat1.get_rows() != mat2.get_rows() || mat1.get_cols() != mat2.get_cols())
        return false;

    for (int i = 0; i < mat1.get_rows(); ++i) {
        for (int j = 0; j < mat2.get_cols(); ++j) {
            if (mat1.at(i, j) != mat2.at(i, j))
                return false;
        }
    }
    return true;
}

TEST(Matrix, multiply_matrices_to_2dstorage_seq) {
    MatrixManager2dStorage m22, m23, res;
    m22.read_matrix_from_file("m22.txt");
    m23.read_matrix_from_file("m23.txt");
    res.read_matrix_from_file("res.txt");

    EXPECT_TRUE(eq(res, multiply_matrices_to_2dstorage_seq(m22, m23)));
}

TEST(Matrix, multiply_matrices_to_2dstorage_par) {
    MatrixManager2dStorage m22, m23, res;
    m22.read_matrix_from_file("m22.txt");
    m23.read_matrix_from_file("m23.txt");
    res.read_matrix_from_file("res.txt");

    EXPECT_TRUE(eq(res, multiply_matrices_to_2dstorage_par(m22, m23)));
}

TEST(Matrix, multiply_matrices_to_2dstorage_par_unseq) {
    MatrixManager2dStorage m22, m23, res;
    m22.read_matrix_from_file("m22.txt");
    m23.read_matrix_from_file("m23.txt");
    res.read_matrix_from_file("res.txt");

    EXPECT_TRUE(eq(res, multiply_matrices_to_2dstorage_seq(m22, m23)));
}