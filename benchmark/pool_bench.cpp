#include <benchmark/benchmark.h> // NOLINT
#include <random>
#include "../pool.hpp"

void pool_bench()
{
    size_t number_of_pools    = 8e6;
    size_t nmb_of_connections = 10e6;
    size_t nmb_add_water      = 50e6;

    std::random_device rd;
    std::mt19937 rand_nmb(rd());
    std::uniform_int_distribution<size_t> rand_nmb_from_interval(0, number_of_pools - 1);

    pool::Pool* pools = new pool::Pool[number_of_pools];

    for (size_t i = 0; i < number_of_pools; ++i)
    {
        pools[i].add_water(10);
    }

    for (size_t i = 0; i < nmb_of_connections; ++i)
    {
        pools[rand_nmb_from_interval(rand_nmb)].connect(&pools[rand_nmb_from_interval(rand_nmb)]);
    }
    
    for (size_t i = 0; i < number_of_pools; ++i)
    {
        pools[i].get_water_volume();
    }

    for (size_t i = 0; i < nmb_add_water - number_of_pools; ++i)
    {
        pools[rand_nmb_from_interval(rand_nmb)].add_water(10);
    }

    for (size_t i = 0; i < number_of_pools; ++i)
    {
        pools[i].get_water_volume();
    }

    delete[] pools;

}

static void BM_pool_bench(benchmark::State& state)
{
    for (auto _ : state) 
    { 
        pool_bench();
    }
}
BENCHMARK(BM_pool_bench)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN(); // NOLINT
