#include "pool.hpp"

int main()
{
    pool::Pool A_pool;
    pool::Pool B_pool;
    pool::Pool C_pool;

    A_pool.add_water(5);
    A_pool.add_water(5);
    B_pool.add_water(20);
    C_pool.add_water(30);
    A_pool.connect(&B_pool);
    A_pool.connect(&C_pool);
    B_pool.connect(&C_pool);

    std::cout << "first\n";
    std::cout << A_pool.get_water_volume() << std::endl;
    std::cout << B_pool.get_water_volume() << std::endl;
    std::cout << C_pool.get_water_volume() << std::endl;

    pool::Pool E_pool;
    pool::Pool F_pool;
    pool::Pool G_pool;

    E_pool.add_water(40);
    F_pool.add_water(50);
    G_pool.add_water(60);
    E_pool.connect(&F_pool);
    E_pool.connect(&G_pool);
    G_pool.connect(&F_pool);

    std::cout << "second\n";
    std::cout << E_pool.get_water_volume() << std::endl;
    std::cout << F_pool.get_water_volume() << std::endl;
    std::cout << G_pool.get_water_volume() << std::endl;

    G_pool.connect(&A_pool);

    std::cout << "out\n";
    std::cout << A_pool.get_water_volume() << std::endl;
    std::cout << G_pool.get_water_volume() << std::endl;

    return 0;
}
