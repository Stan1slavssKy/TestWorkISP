#include "pool.hpp"

namespace pool{
class Pool::Related_pool_info
{
public:
    std::size_t nmb_valid_pools    = 0;
    std::size_t total_water_volume = 0;
    std::vector<Pool*> pools;
};

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
        reattach_info(info, other_pool->info);
    else 
        reattach_info(other_pool->info, info);

    info->nmb_valid_pools = info->pools.size();
}

void Pool::reattach_info(Related_pool_info* lhs, Related_pool_info* rhs)
{
    Related_pool_info* attachable_info = lhs;

    for (auto& it : attachable_info->pools)
    {
        it->info = rhs;
    }
    rhs->pools.insert(rhs->pools.end(), attachable_info->pools.begin(), attachable_info->pools.end());
    rhs->total_water_volume += attachable_info->total_water_volume;

    delete attachable_info;
}

std::size_t Pool::get_water_volume() const
{
    return info->total_water_volume / info->pools.size();
}

void Pool::add_water(std::size_t volume_to_add)
{
    info->total_water_volume += volume_to_add;
}
} //namespace pool
