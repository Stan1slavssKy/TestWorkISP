#include "pool.hpp"

namespace pool{
Pool::Pool()
{
    info = new Related_pool_info {};
    info->pools.push_back(this);
    info->nmb_valid_pools = 1;
}

Pool::~Pool()
{
    if (--(info->nmb_valid_pools) == 0)
    {
        delete info;
    }
}

void Pool::connect(Pool* other_pool)
{
    if (info == other_pool->info)
        return;

    if (other_pool->info->pools.size() > info->pools.size())
    {
        Related_pool_info* attachable_info = info;

        for (auto& it : attachable_info->pools)
        {
            it->info = other_pool->info;
        }
        other_pool->info->pools.insert(other_pool->info->pools.end(), attachable_info->pools.begin(), attachable_info->pools.end());

        delete attachable_info;
    }
    else 
    {
        Related_pool_info* attachable_info = other_pool->info;

        for (auto& it : attachable_info->pools)
        {
            it->info = info;
        }
        info->pools.insert(info->pools.end(), attachable_info->pools.begin(), attachable_info->pools.end());

        delete attachable_info;
    }

    info->nmb_valid_pools = info->pools.size();
    info->recalculation_of_water();
}

std::size_t Pool::get_water_volume() const
{
    return water_volume;
}

void Pool::add_water(std::size_t volume_to_add)
{
    water_volume += volume_to_add;
}

std::size_t Related_pool_info::recalculation_of_water()
{
    size_t water_sum = 0;

    for (auto& it : pools)
    {
        water_sum += it->water_volume;
    }

    cur_water_volume = water_sum / pools.size();

    for (auto& it : pools)
    {
        it->water_volume = cur_water_volume;
    }
    return cur_water_volume;
}
} //namespace pool
