#include <benchmark/benchmark.h>

#include "CountDiv.h"

bool is_already_fill = false;

std::vector<int> vec5_10_5 = std::vector<int>(5 * 100'000);
std::vector<int> vec10_6 = std::vector<int>(1'000'000);
std::vector<int> vec2_10_6 = std::vector<int>(2 * 1'000'000);
// Фикстура для проведения бенчмарков
class DivisorsFixture : public benchmark::Fixture {
public:

    void fillVectors() {
        if (is_already_fill) {
            return;
        }
        fillVectorWithRandom(vec5_10_5, 100'000, 1'000'000);
        fillVectorWithRandom(vec10_6, 100'000, 1'000'000);
        fillVectorWithRandom(vec2_10_6, 100'000, 1'000'000);
        is_already_fill = true;
    }

    void SetUp(const ::benchmark::State& state) {
        fillVectors();
    }
};

BENCHMARK_DEFINE_F(DivisorsFixture, SeqBenchmark_vec5_10_5)(benchmark::State& state) {
    for (auto _ : state) {
        auto result = createDivisorsVectorSeq(vec5_10_5);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(DivisorsFixture, SeqBenchmark_vec10_6)(benchmark::State& state) {
    for (auto _ : state) {
        auto result = createDivisorsVectorSeq(vec10_6);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(DivisorsFixture, SeqBenchmark_vec2_10_6)(benchmark::State& state) {
    for (auto _ : state) {
        auto result = createDivisorsVectorSeq(vec2_10_6);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_REGISTER_F(DivisorsFixture, SeqBenchmark_vec5_10_5)->Unit(benchmark::kSecond);
BENCHMARK_REGISTER_F(DivisorsFixture, SeqBenchmark_vec10_6)->Unit(benchmark::kSecond);
BENCHMARK_REGISTER_F(DivisorsFixture, SeqBenchmark_vec2_10_6)->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(DivisorsFixture, ParBenchmark_vec5_10_5)(benchmark::State& state) {
    for (auto _ : state) {
        auto result = createDivisorsVectorPar(vec5_10_5);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(DivisorsFixture, ParBenchmark_vec10_6)(benchmark::State& state) {
    for (auto _ : state) {
        auto result = createDivisorsVectorPar(vec10_6);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(DivisorsFixture, ParBenchmark_vec2_10_6)(benchmark::State& state) {
    for (auto _ : state) {
        auto result = createDivisorsVectorPar(vec2_10_6);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_REGISTER_F(DivisorsFixture, ParBenchmark_vec5_10_5)->Unit(benchmark::kSecond);
BENCHMARK_REGISTER_F(DivisorsFixture, ParBenchmark_vec10_6)->Unit(benchmark::kSecond);
BENCHMARK_REGISTER_F(DivisorsFixture, ParBenchmark_vec2_10_6)->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(DivisorsFixture, ParUnseqBenchmark_vec5_10_5)(benchmark::State& state) {
    for (auto _ : state) {
        auto result = createDivisorsVectorParUnseq(vec5_10_5);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(DivisorsFixture, ParUnseqBenchmark_vec10_6)(benchmark::State& state) {
    for (auto _ : state) {
        auto result = createDivisorsVectorParUnseq(vec10_6);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(DivisorsFixture, ParUnseqBenchmark_vec2_10_6)(benchmark::State& state) {
    for (auto _ : state) {
        auto result = createDivisorsVectorParUnseq(vec2_10_6);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_REGISTER_F(DivisorsFixture, ParUnseqBenchmark_vec5_10_5)->Unit(benchmark::kSecond);
BENCHMARK_REGISTER_F(DivisorsFixture, ParUnseqBenchmark_vec10_6)->Unit(benchmark::kSecond);
BENCHMARK_REGISTER_F(DivisorsFixture, ParUnseqBenchmark_vec2_10_6)->Unit(benchmark::kSecond);

// Запускаем бенчмарки
//BENCHMARK_MAIN();