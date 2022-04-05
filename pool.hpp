#ifndef POOL_POOL_HPP_INCLUDED
#define POOL_POOL_HPP_INCLUDED

#include <iostream>
#include <vector>

namespace pool {
struct Related_pool_info;

class Pool
{
public:
    Pool();
    ~Pool();
    
    std::size_t get_water_volume() const;
    void connect(Pool* other_pool);
    void add_water(std::size_t volume_to_add);

    std::size_t water_volume = 0;

private:
    Related_pool_info* info;
};

struct Related_pool_info
{
    std::size_t recalculation_of_water();
    
    std::size_t nmb_valid_pools  = 0;
    std::size_t cur_water_volume = 0;
    std::vector<Pool*> pools;
};
} // namespace pool
#endif // POOL_POOL_HPP_INCLUDED
