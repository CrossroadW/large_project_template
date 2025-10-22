#include <benchmark/benchmark.h>
#include <module_a/MyLib.h>
#include <gtest/gtest.h>

static void BM_MyFunction(benchmark::State& state) {
    MyLib mylib;
    for (auto _ : state) {
        int r = mylib.add(1,2); // 假设 MyLib 有个 `doSomething()` 方法
        assert(r == 3);
    }
}

BENCHMARK(BM_MyFunction);