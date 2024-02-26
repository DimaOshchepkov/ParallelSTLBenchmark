#pragma once

#include <string>

class Matrix {
public:
    virtual ~Matrix() {}

    virtual bool read_matrix_from_file(const std::string& filename) = 0;
    virtual int* operator[](int row) = 0;
    virtual const int* operator[](int row) const = 0;
    virtual int get_rows() const = 0;
    virtual int get_cols() const = 0;
    virtual int& at(int row, int column) = 0;
    virtual const int& at(int row, int column) const = 0;
};

class MatrixManager2dStorage : public Matrix {
private:
    int** matrix;
    int rows;
    int cols;

public:
    MatrixManager2dStorage();
    MatrixManager2dStorage(const MatrixManager2dStorage& other);
    MatrixManager2dStorage(MatrixManager2dStorage&& other) noexcept;
    MatrixManager2dStorage& operator=(const MatrixManager2dStorage& other);
    MatrixManager2dStorage& operator=(MatrixManager2dStorage&& other) noexcept;
    MatrixManager2dStorage(int row, int col, int num = 0);
    ~MatrixManager2dStorage();

    bool read_matrix_from_file(const std::string& filename) override;
    int* operator[](int row) override;
    const int* operator[](int row) const override;
    int& at(int row, int column) override;
    const int& at(int row, int column) const override;
    int get_rows() const override;
    int get_cols() const override;
};

class MatrixManager1dStorage : public Matrix {
private:
    int** matrix;
    int* arr;
    int rows;
    int cols;

public:
    MatrixManager1dStorage();
    MatrixManager1dStorage(int row, int col, int num = 0);
    MatrixManager1dStorage(const MatrixManager1dStorage& other);
    MatrixManager1dStorage(MatrixManager1dStorage&& other) noexcept;
    MatrixManager1dStorage& operator=(const MatrixManager1dStorage& other);
    MatrixManager1dStorage& operator=(MatrixManager1dStorage&& other) noexcept;
    ~MatrixManager1dStorage();

    bool read_matrix_from_file(const std::string& filename) override;
    int* operator[](int row) override;
    const int* operator[](int row) const override;
    int& at(int row, int column) override;
    const int& at(int row, int column) const override;
    int get_rows() const override;
    int get_cols() const override;
};

MatrixManager2dStorage multiply_matrices_to_2dstorage_seq(const Matrix& mat1, const Matrix& mat2);