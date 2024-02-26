#include <benchmark/benchmark.h>
#include <random>
#include <cstdint> // Для int64_t
#include <algorithm>
#include <numeric>
#include <execution>
#include <iostream>

void fillVectorWithRandom(std::vector<int>& vec, int minVal, int maxVal) {
        // Заполнение вектора случайными числами
        int range = maxVal - minVal + 1;
        for (int& num : vec) {
            num = minVal + rand() % range;
        }
    }

std::vector<int> vec10_5 = std::vector<int>(10'000'000);
std::vector<int> vec10_6 = std::vector<int>(100'000'000);
std::vector<int> vec10_7 = std::vector<int>(1'000'000'000);
// Фикстура для проведения бенчмарков
class Fixture10_5 : public benchmark::Fixture {
public:
    void SetUp(const ::benchmark::State& state) {
    }  
};

class Fixture10_6 : public benchmark::Fixture {
public:
    void SetUp(const ::benchmark::State& state) {
    }
};

class Fixture10_7 : public benchmark::Fixture {
public:
    void SetUp(const ::benchmark::State& state) {
    }
};

BENCHMARK_DEFINE_F(Fixture10_5, SeqBenchmark_vec10_5)(benchmark::State& state) {
    auto vec = vec10_5;
    for (auto _ : state) {
        std::sort(vec.begin(), vec.end());
    }
}

BENCHMARK_DEFINE_F(Fixture10_6, SeqBenchmark_vec10_6)(benchmark::State& state) {
    auto vec = vec10_6;
    for (auto _ : state) {
        std::sort(vec.begin(), vec.end());
        
    }
}

BENCHMARK_DEFINE_F(Fixture10_7, SeqBenchmark_vec10_7)(benchmark::State& state) {
    auto vec = vec10_7;
    for (auto _ : state) {
        std::sort(vec.begin(), vec.end());
        
    }
}

BENCHMARK_REGISTER_F(Fixture10_5, SeqBenchmark_vec10_5)->Unit(benchmark::kSecond);
BENCHMARK_REGISTER_F(Fixture10_6, SeqBenchmark_vec10_6)->Unit(benchmark::kSecond);
BENCHMARK_REGISTER_F(Fixture10_7, SeqBenchmark_vec10_7)->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(Fixture10_5, ParBenchmark_vec10_5)(benchmark::State& state) {
    auto vec = vec10_5;
    for (auto _ : state) {
        std::sort(std::execution::par, vec.begin(), vec.end());
        
    }
}
BENCHMARK_REGISTER_F(Fixture10_5, ParBenchmark_vec10_5)->Unit(benchmark::kSecond);

BENCHMARK_DEFINE_F(Fixture10_6, ParBenchmark_vec10_6)(benchmark::State& state) {
    auto vec = vec10_6;
    for (auto _ : state) {
        std::sort(std::execution::par, vec.begin(), vec.end());
        
    }
}
BENCHMARK_REGISTER_F(Fixture10_6, ParBenchmark_vec10_6)->Unit(benchmark::kSecond);

BENCHMARK_DEFINE_F(Fixture10_7, ParBenchmark_vec10_7)(benchmark::State& state) {
    auto vec = vec10_7;
    for (auto _ : state) {
        std::sort(std::execution::par, vec.begin(), vec.end());
        
    }
}
BENCHMARK_REGISTER_F(Fixture10_7, ParBenchmark_vec10_7)->Unit(benchmark::kSecond);


BENCHMARK_DEFINE_F(Fixture10_5, ParUnseqBenchmark_vec10_5)(benchmark::State& state) {
    auto vec = vec10_5;
    for (auto _ : state) {
        std::sort(std::execution::par_unseq, vec.begin(), vec.end());
        
    }
}
BENCHMARK_REGISTER_F(Fixture10_5, ParUnseqBenchmark_vec10_5)->Unit(benchmark::kSecond);

BENCHMARK_DEFINE_F(Fixture10_6, ParUnseqBenchmark_vec10_6)(benchmark::State& state) {
    auto vec = vec10_6;
    for (auto _ : state) {
        std::sort(std::execution::par_unseq, vec.begin(), vec.end());
        
    }
}
BENCHMARK_REGISTER_F(Fixture10_6, ParUnseqBenchmark_vec10_6)->Unit(benchmark::kSecond);

BENCHMARK_DEFINE_F(Fixture10_7, ParUnseqBenchmark_vec10_7)(benchmark::State& state) {
    auto vec = vec10_7;
    for (auto _ : state) {
        std::sort(std::execution::par_unseq, vec.begin(), vec.end());
        
    }
}
BENCHMARK_REGISTER_F(Fixture10_7, ParUnseqBenchmark_vec10_7)->Unit(benchmark::kSecond);

int main(int argc, char** argv) {
    fillVectorWithRandom(vec10_5, -100, 100);
    fillVectorWithRandom(vec10_6, -100, 100);
    fillVectorWithRandom(vec10_7, -100, 100);

    ::benchmark::Initialize(&argc, argv);
    ::benchmark::RunSpecifiedBenchmarks();
}