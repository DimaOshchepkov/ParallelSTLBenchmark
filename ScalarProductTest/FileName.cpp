
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <benchmark/benchmark.h>
#include <execution>

// Scalar product function using std::transform_reduce

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

// Function to generate random vector
std::vector<int> generate_random_vector(size_t size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    std::vector<int> vec(size);
    for (size_t i = 0; i < size; ++i) {
        vec[i] = dis(gen);
    }
    return vec;
}

// Benchmark for measuring scalar product computation time
static void BM_scalar_product_par_unseq(benchmark::State& state) {
    // Generate random vectors of size state.range(0)
    std::vector<int> v1 = generate_random_vector(state.range(0));
    std::vector<int> v2 = generate_random_vector(state.range(0));

    // Measure computation time
    for (auto _ : state) {
        benchmark::DoNotOptimize(scalar_product_par_unseq(v1.data(), v2.data(), v1.size()));
    }
}

// Benchmark for measuring scalar product computation time
static void BM_scalar_product_par(benchmark::State& state) {
    // Generate random vectors of size state.range(0)
    std::vector<int> v1 = generate_random_vector(state.range(0));
    std::vector<int> v2 = generate_random_vector(state.range(0));

    // Measure computation time
    for (auto _ : state) {
        benchmark::DoNotOptimize(scalar_product_par(v1.data(), v2.data(), v1.size()));
    }
}

// Benchmark for measuring scalar product computation time
static void BM_scalar_product_seq(benchmark::State& state) {
    // Generate random vectors of size state.range(0)
    std::vector<int> v1 = generate_random_vector(state.range(0));
    std::vector<int> v2 = generate_random_vector(state.range(0));

    // Measure computation time
    for (auto _ : state) {
        benchmark::DoNotOptimize(scalar_product_seq(v1.data(), v2.data(), v1.size()));
    }
}

// Register the benchmark
BENCHMARK(BM_scalar_product_par_unseq)->Arg(512)->Arg(1024)->Arg(2048)->Arg(1000000);
BENCHMARK(BM_scalar_product_par)->Arg(512)->Arg(1024)->Arg(2048)->Arg(1000000);
BENCHMARK(BM_scalar_product_seq)->Arg(512)->Arg(1024)->Arg(2048)->Arg(1000000);

// Run the benchmark
BENCHMARK_MAIN();