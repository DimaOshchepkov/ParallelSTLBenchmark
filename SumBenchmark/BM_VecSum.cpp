#include <benchmark/benchmark.h>
#include <random>
#include <cstdint> // Для int64_t
#include <algorithm>
#include <numeric>
#include <execution>

bool is_already_fill2 = false;

std::vector<int> vec2_10_8 = std::vector<int>(5 * 100'000'000);
std::vector<int> vec10_9 = std::vector<int>(1'000'000'000);
std::vector<int> vec2_10_9 = std::vector<int>(2 * 1'000'000'000);
// Фикстура для проведения бенчмарков
class SumFixture : public benchmark::Fixture {
public:

    void fillVectors() {
        if (is_already_fill2) {
            return;
        }
        fillVectorWithRandom(vec2_10_8, -100,100);
        fillVectorWithRandom(vec10_9, -100, 100);
        fillVectorWithRandom(vec2_10_9, -100, 100);
        is_already_fill2 = true;
    }

    void SetUp(const ::benchmark::State& state) {
        fillVectors();
    }

    void fillVectorWithRandom(std::vector<int>& vec, int minVal, int maxVal) {
        // Заполнение вектора случайными числами
        int range = maxVal - minVal + 1;
        for (int& num : vec) {
            num = minVal + rand() % range;
        }
    }
};

BENCHMARK_DEFINE_F(SumFixture, SeqBenchmark_vec2_10_8)(benchmark::State& state) {
    for (auto _ : state) {
        int result = std::reduce(vec2_10_8.begin(), vec2_10_8.end());
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(SumFixture, SeqBenchmark_vec10_9)(benchmark::State& state) {
    for (auto _ : state) {
        int result = std::reduce(vec10_9.begin(), vec10_9.end());
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(SumFixture, SeqBenchmark_vec2_10_9)(benchmark::State& state) {
    for (auto _ : state) {
        int result = std::reduce(vec2_10_9.begin(), vec2_10_9.end());
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_REGISTER_F(SumFixture, SeqBenchmark_vec2_10_8)->Unit(benchmark::kSecond);
BENCHMARK_REGISTER_F(SumFixture, SeqBenchmark_vec10_9)->Unit(benchmark::kSecond);
BENCHMARK_REGISTER_F(SumFixture, SeqBenchmark_vec2_10_9)->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(SumFixture, ParBenchmark_vec2_10_8)(benchmark::State& state) {
    for (auto _ : state) {
        int result = std::reduce(std::execution::par, vec2_10_8.begin(), vec2_10_8.end());
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(SumFixture, ParBenchmark_vec2_10_8)->Unit(benchmark::kSecond);

BENCHMARK_DEFINE_F(SumFixture, ParBenchmark_vec10_9)(benchmark::State& state) {
    for (auto _ : state) {
        int result = std::reduce(std::execution::par, vec10_9.begin(), vec10_9.end());
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(SumFixture, ParBenchmark_vec10_9)->Unit(benchmark::kSecond);

BENCHMARK_DEFINE_F(SumFixture, ParBenchmark_vec2_10_9)(benchmark::State& state) {
    for (auto _ : state) {
        int result = std::reduce(std::execution::par, vec2_10_9.begin(), vec2_10_9.end());
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(SumFixture, ParBenchmark_vec2_10_9)->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(SumFixture, ParUnseqBenchmark_vec2_10_8)(benchmark::State& state) {
    for (auto _ : state) {
        int result = std::reduce(std::execution::par_unseq, vec2_10_8.begin(), vec2_10_8.end());
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(SumFixture, ParUnseqBenchmark_vec2_10_8)->Unit(benchmark::kSecond);

BENCHMARK_DEFINE_F(SumFixture, ParUnseqBenchmark_vec10_9)(benchmark::State& state) {
    for (auto _ : state) {
        int result = std::reduce(std::execution::par_unseq, vec10_9.begin(), vec10_9.end());
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(SumFixture, ParUnseqBenchmark_vec10_9)->Unit(benchmark::kSecond);

BENCHMARK_DEFINE_F(SumFixture, ParUnseqBenchmark_vec2_10_9)(benchmark::State& state) {
    for (auto _ : state) {
        int result = std::reduce(std::execution::par_unseq, vec2_10_9.begin(), vec2_10_9.end());
        benchmark::DoNotOptimize(result);
    }
}
BENCHMARK_REGISTER_F(SumFixture, ParUnseqBenchmark_vec2_10_9)->Unit(benchmark::kSecond);

BENCHMARK_MAIN();