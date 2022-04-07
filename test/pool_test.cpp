#include "../pool.hpp"

#include <gtest/gtest.h> // NOLINT

TEST(Pool, GetWaterVolume)
{
    pool::Pool a;
    pool::Pool b;
    a.add_water(10);
    b.add_water(20);
    ASSERT_EQ(a.get_water_volume(), 10);
    ASSERT_EQ(b.get_water_volume(), 20);
}

TEST(Pool, Connect) // NOLINT
{
    pool::Pool a;
    pool::Pool b;
    a.connect(&b);

    for (std::size_t i = 0; i < 100000; ++i)
    {
        a.add_water(10);
        b.add_water(20);
        ASSERT_EQ(a.get_water_volume(), b.get_water_volume());
        ASSERT_EQ(a.get_water_volume(), 30 * (i + 1) / 2);
    }
}

TEST(Pool, СircularСonnection)
{
    pool::Pool a;
    pool::Pool b;
    pool::Pool c;

    a.add_water(10);
    b.add_water(20);
    c.add_water(45);

    a.connect(&b);
    ASSERT_EQ(a.get_water_volume(), 15);
    b.connect(&c);
    ASSERT_EQ(a.get_water_volume(), 25);
    c.connect(&a);
    ASSERT_EQ(a.get_water_volume(), 25);
}

TEST(Pool, ConnectTwoRelatedSystems)
{
    pool::Pool a;
    pool::Pool b;
    pool::Pool c;

    a.add_water(10);
    b.add_water(20);
    c.add_water(45);

    pool::Pool d;
    pool::Pool e;
    pool::Pool f;

    d.add_water(100);
    e.add_water(100);
    f.add_water(103);

    a.connect(&b);
    b.connect(&c);
    c.connect(&a);

    d.connect(&e);
    e.connect(&f);
    f.connect(&d);

    a.connect(&d);
    ASSERT_EQ(a.get_water_volume(), 63);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv); // NOLINT

    return RUN_ALL_TESTS(); // NOLINT
}
