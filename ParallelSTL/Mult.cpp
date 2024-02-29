#include "Mult.h"

#include <iostream>
#include <execution>

MatrixManager2dStorage transpose_matrix(const Matrix& mat) {
    int rows = mat.get_rows();
    int cols = mat.get_cols();

    // Создаём новую матрицу с переставленными размерами
    MatrixManager2dStorage transposed_mat(mat.get_cols(), mat.get_rows());
    // Некоторая логика для инициализации transposed_mat...

    // Транспонирование матрицы
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Заполняем элементы новой матрицы
            transposed_mat.at(j, i) = mat.at(i, j);
        }
    }

    return transposed_mat;
}

int scalar_product_par_unseq(const int* v1, const int* v2, size_t size) {
    return std::transform_reduce(std::execution::par_unseq,
        v1, v1 + size,
        v2,
        int(0),
        std::plus<int>(),
        std::multiplies<int>());
}

int scalar_product_seq(const int* v1, const int* v2, size_t size) {
    return std::transform_reduce(
        v1, v1 + size,
        v2,
        int(0),
        std::plus<int>(),
        std::multiplies<int>());
}

int scalar_product_par(const int* v1, const int* v2, size_t size) {
    return std::transform_reduce(std::execution::par,
        v1, v1 + size,
        v2,
        int(0),
        std::plus<int>(),
        std::multiplies<int>());
}

// Функция для умножения двух матриц MatrixManager2dStorage
MatrixManager2dStorage multiply_matrices_to_2dstorage_seq(const Matrix& mat1, const Matrix& mat2) {
    // Проверяем, что количество столбцов первой матрицы равно количеству строк второй матрицы
    if (mat1.get_cols() != mat2.get_rows()) {
        std::cerr << "Невозможно умножить матрицы: неправильные размеры" << std::endl;
        return MatrixManager2dStorage();
    }

    const MatrixManager2dStorage mat2T = transpose_matrix(mat2);

    int rows = mat1.get_rows();
    int cols = mat2.get_cols();
    int common_dim = mat1.get_cols(); // или mat2.get_rows()

    // Создаем новую матрицу для хранения результата умножения
    MatrixManager2dStorage result(rows, cols);

    // Умножение матриц
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.at(i, j) = scalar_product_seq(mat1[i], mat2[j], (size_t)mat1.get_cols());
        }
    }

    return result;
}

// Функция для умножения двух матриц MatrixManager2dStorage
MatrixManager2dStorage multiply_matrices_to_2dstorage_par(const Matrix& mat1, const Matrix& mat2) {
    // Проверяем, что количество столбцов первой матрицы равно количеству строк второй матрицы
    if (mat1.get_cols() != mat2.get_rows()) {
        std::cerr << "Невозможно умножить матрицы: неправильные размеры" << std::endl;
        return MatrixManager2dStorage();
    }

    const MatrixManager2dStorage mat2T = transpose_matrix(mat2);

    int rows = mat1.get_rows();
    int cols = mat2.get_cols();
    int common_dim = mat1.get_cols(); // или mat2.get_rows()

    // Создаем новую матрицу для хранения результата умножения
    MatrixManager2dStorage result(rows, cols);

    // Умножение матриц
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.at(i, j) = scalar_product_par(mat1[i], mat2[j], (size_t)mat1.get_cols());
        }
    }

    return result;
}

// Функция для умножения двух матриц MatrixManager2dStorage
MatrixManager2dStorage multiply_matrices_to_2dstorage_par_unseq(const Matrix& mat1, const Matrix& mat2) {
    // Проверяем, что количество столбцов первой матрицы равно количеству строк второй матрицы
    if (mat1.get_cols() != mat2.get_rows()) {
        std::cerr << "Невозможно умножить матрицы: неправильные размеры" << std::endl;
        return MatrixManager2dStorage();
    }

    const MatrixManager2dStorage mat2T = transpose_matrix(mat2);

    int rows = mat1.get_rows();
    int cols = mat2.get_cols();
    int common_dim = mat1.get_cols(); // или mat2.get_rows()

    // Создаем новую матрицу для хранения результата умножения
    MatrixManager2dStorage result(rows, cols);

    // Умножение матриц
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.at(i, j) = scalar_product_par_unseq(mat1[i], mat2[j], (size_t)mat1.get_cols());
        }
    }

    return result;
}