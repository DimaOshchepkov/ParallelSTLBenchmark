#include "Matrix.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <execution>

using std::string;

MatrixManager2dStorage::MatrixManager2dStorage() : matrix(nullptr), rows(0), cols(0) {}


MatrixManager2dStorage::MatrixManager2dStorage(const MatrixManager2dStorage& other)
    : rows(other.rows), cols(other.cols) {
    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

MatrixManager2dStorage::MatrixManager2dStorage(MatrixManager2dStorage&& other) noexcept
    : matrix(other.matrix), rows(other.rows), cols(other.cols) {
    other.matrix = nullptr;
    other.rows = 0;
    other.cols = 0;
}

MatrixManager2dStorage& MatrixManager2dStorage::operator=(const MatrixManager2dStorage& other) {
    if (this != &other) {
        if (matrix != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        rows = other.rows;
        cols = other.cols;
        matrix = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    return *this;
}

MatrixManager2dStorage& MatrixManager2dStorage::operator=(MatrixManager2dStorage&& other) noexcept {
    if (this != &other) {
        if (matrix != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        matrix = other.matrix;
        rows = other.rows;
        cols = other.cols;

        other.matrix = nullptr;
        other.rows = 0;
        other.cols = 0;
    }
    return *this;
}

MatrixManager2dStorage::MatrixManager2dStorage(int row, int col, int num) : rows(row), cols(col) {
    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = num;
        }
    }
}

MatrixManager2dStorage::~MatrixManager2dStorage() {
    if (matrix != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

bool MatrixManager2dStorage::read_matrix_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
        return false;
    }

    file >> rows >> cols;

    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            if (!(file >> matrix[i][j])) {
                std::cerr << "Ошибка чтения данных из файла " << filename << std::endl;
                for (int k = 0; k < i; ++k) {
                    delete[] matrix[k];
                }
                delete[] matrix;
                return false;
            }
        }
    }

    file.close();
    return true;
}

int* MatrixManager2dStorage::operator[](int row) {
    return matrix[row];
}

const int* MatrixManager2dStorage::operator[](int row) const {
    return matrix[row];
}

int& MatrixManager2dStorage::at(int row, int column)
{
    return matrix[row][column];
}

const int& MatrixManager2dStorage::at(int row, int column) const
{
    return matrix[row][column];
}

int MatrixManager2dStorage::get_rows() const {
    return rows;
}

int MatrixManager2dStorage::get_cols() const {
    return cols;
}


MatrixManager1dStorage::MatrixManager1dStorage() : matrix(nullptr), arr(nullptr), rows(0), cols(0) {}

MatrixManager1dStorage::MatrixManager1dStorage(int row, int col, int num) : rows(row), cols(col) {
    arr = new int[rows * cols];
    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = arr + i * cols;
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
        }
    }
}

MatrixManager1dStorage::MatrixManager1dStorage(const MatrixManager1dStorage& other)
    : rows(other.rows), cols(other.cols) {
    arr = new int[rows * cols];
    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = arr + i * cols;
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

MatrixManager1dStorage::MatrixManager1dStorage(MatrixManager1dStorage&& other) noexcept
    : matrix(other.matrix), arr(other.arr), rows(other.rows), cols(other.cols) {
    other.matrix = nullptr;
    other.arr = nullptr;
    other.rows = 0;
    other.cols = 0;
}

MatrixManager1dStorage& MatrixManager1dStorage::operator=(const MatrixManager1dStorage& other) {
    if (this != &other) {
        if (matrix != nullptr) {
            delete[] arr;
            delete[] matrix;
        }

        rows = other.rows;
        cols = other.cols;
        arr = new int[rows * cols];
        matrix = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = arr + i * cols;
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    return *this;
}

MatrixManager1dStorage& MatrixManager1dStorage::operator=(MatrixManager1dStorage&& other) noexcept {
    if (this != &other) {
        if (matrix != nullptr) {
            delete[] arr;
            delete[] matrix;
        }

        matrix = other.matrix;
        arr = other.arr;
        rows = other.rows;
        cols = other.cols;

        other.matrix = nullptr;
        other.arr = nullptr;
        other.rows = 0;
        other.cols = 0;
    }
    return *this;
}

MatrixManager1dStorage::~MatrixManager1dStorage() {
    delete[] arr;
    delete[] matrix;
}

bool MatrixManager1dStorage::read_matrix_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
        return false;
    }

    file >> rows >> cols;

    arr = new int[rows * cols];
    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = arr + i * cols;
        for (int j = 0; j < cols; ++j) {
            if (!(file >> matrix[i][j])) {
                std::cerr << "Ошибка чтения данных из файла " << filename << std::endl;
                delete[] arr;
                delete[] matrix;
                return false;
            }
        }
    }

    file.close();
    return true;
}

int* MatrixManager1dStorage::operator[](int row) {
    return matrix[row];
}

const int* MatrixManager1dStorage::operator[](int row) const {
    return matrix[row];
}

int& MatrixManager1dStorage::at(int row, int column)
{
    return arr[this->cols * row + column];
}

const int& MatrixManager1dStorage::at(int row, int column) const
{
    return arr[this->cols * row + column];
}


int MatrixManager1dStorage::get_rows() const {
    return rows;
}

int MatrixManager1dStorage::get_cols() const {
    return cols;
}





