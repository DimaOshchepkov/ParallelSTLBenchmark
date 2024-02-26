#include <benchmark/benchmark.h>
#include <iostream>
#include "Matrix.h"
#include "Mult.h"

class MatrixFixture : public benchmark::Fixture {
public:
    static void SetUpTestCase() {
        if (!is_already_process) {
            mat2d512.read_matrix_from_file("m512.txt");
            mat2d1024.read_matrix_from_file("m1024.txt");
            mat2d2048.read_matrix_from_file("m2048.txt");

            mat1d512.read_matrix_from_file("m512.txt");
            mat1d1024.read_matrix_from_file("m1024.txt");
            mat1d2048.read_matrix_from_file("m2048.txt");
            is_already_process = true;
        }
    }

    void SetUp(const ::benchmark::State& state) override {
        // Вы можете выполнить другие действия, если необходимо
    }

    void TearDown(const ::benchmark::State& state) override {
        // Optionally clean up resources if needed
    }

    static MatrixManager2dStorage mat2d512;
    static MatrixManager2dStorage mat2d1024;
    static MatrixManager2dStorage mat2d2048;

    static MatrixManager2dStorage mat1d512;
    static MatrixManager2dStorage mat1d1024;
    static MatrixManager2dStorage mat1d2048;

    static bool is_already_process;
};

MatrixManager2dStorage MatrixFixture::mat2d512;
MatrixManager2dStorage MatrixFixture::mat2d1024;
MatrixManager2dStorage MatrixFixture::mat2d2048;

MatrixManager2dStorage MatrixFixture::mat1d512;
MatrixManager2dStorage MatrixFixture::mat1d1024;
MatrixManager2dStorage MatrixFixture::mat1d2048;

bool MatrixFixture::is_already_process = false;


BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_2d_seq_512x512)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_2dstorage_seq(mat2d512, mat2d512);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_2d_seq_512x512)
->Unit(benchmark::kSecond);

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_2d_seq_1024x1024)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_2dstorage_seq(mat2d1024, mat2d1024);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_2d_seq_1024x1024)
->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_2d_seq_2048x2048)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_2dstorage_seq(mat2d2048, mat2d2048);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_2d_seq_2048x2048)
->Unit(benchmark::kSecond);







BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_2d_par_512x512)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_2dstorage_par(mat2d512, mat2d512);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_2d_par_512x512)
->Unit(benchmark::kSecond);

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_2d_par_1024x1024)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_2dstorage_par(mat2d1024, mat2d1024);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_2d_par_1024x1024)
->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_2d_par_2048x2048)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_2dstorage_par(mat2d2048, mat2d2048);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_2d_par_2048x2048)
->Unit(benchmark::kSecond);








BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_2d_par_unseq_512x512)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_2dstorage_par_unseq(mat2d512, mat2d512);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_2d_par_unseq_512x512)
->Unit(benchmark::kSecond);

BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_2d_par_unseq_1024x1024)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_2dstorage_par_unseq(mat2d1024, mat2d1024);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_2d_par_unseq_1024x1024)
->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(MatrixFixture, BM_MatrixMultiplication_2d_par_unseq_2048x2048)(benchmark::State& state) {
    SetUpTestCase();
    for (auto _ : state) {
        auto result = multiply_matrices_to_2dstorage_par_unseq(mat2d2048, mat2d2048);
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(MatrixFixture, BM_MatrixMultiplication_2d_par_unseq_2048x2048)
->Unit(benchmark::kSecond);

BENCHMARK_MAIN();