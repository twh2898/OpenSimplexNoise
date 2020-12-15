#include <OpenSimplexNoise.h>
#include <benchmark/benchmark.h>

static void BM_OpenSimplexNoise_2D(benchmark::State & state) {
    OpenSimplexNoise::Noise noise(0);
    for (auto _ : state) {
        auto i = state.iterations();
        double ret = noise.eval(i, i);
    }
}
BENCHMARK(BM_OpenSimplexNoise_2D);

static void BM_OpenSimplexNoise_3D(benchmark::State & state) {
    OpenSimplexNoise::Noise noise(0);
    for (auto _ : state) {
        auto i = state.iterations();
        double ret = noise.eval(i, i, i);
    }
}
BENCHMARK(BM_OpenSimplexNoise_3D);

static void BM_OpenSimplexNoise_4D(benchmark::State & state) {
    OpenSimplexNoise::Noise noise(0);
    for (auto _ : state) {
        auto i = state.iterations();
        double ret = noise.eval(i, i, i, i);
    }
}
BENCHMARK(BM_OpenSimplexNoise_4D);

BENCHMARK_MAIN();

