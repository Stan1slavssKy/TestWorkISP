#ifndef POOL_POOL_HPP_INCLUDED
#define POOL_POOL_HPP_INCLUDED

#include <iostream>
#include <vector>

namespace pool {
class Pool
{
public:
    Pool();
    ~Pool();
    
    std::size_t get_water_volume() const;
    void connect(Pool* other_pool);
    void add_water(std::size_t volume_to_add);

private:
    class Related_pool_info;

    static void reattach_info(Related_pool_info* lhs, Related_pool_info* rhs);

    Related_pool_info* info = nullptr;
};
} // namespace pool
#endif // POOL_POOL_HPP_INCLUDED
