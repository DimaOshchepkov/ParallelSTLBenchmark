#pragma once
#include "Matrix.h"

MatrixManager2dStorage multiply_matrices_to_2dstorage_seq(const Matrix& mat1, const Matrix& mat2);

MatrixManager2dStorage multiply_matrices_to_2dstorage_par(const Matrix& mat1, const Matrix& mat2);

MatrixManager2dStorage multiply_matrices_to_2dstorage_par_unseq(const Matrix& mat1, const Matrix& mat2);