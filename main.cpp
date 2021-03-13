#include "CustomAllocator.h"
#include "slist.h"
#include <iostream>
#include <map>

template <typename Map>
void show(const Map&_map)
{
    for (auto pair : _map)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
};


long long factorial(int n)
{
    long long res = 1;
    for (int i = 1; i <= n; ++i)
    {
        res *= i;
    }
    return res;
};

void TestSTLMapWithSTLAllocator()
{
    std::cout << "TestSTLMapWithSTLAllocator" << std::endl;
    using Map = std::map<int, long long>;

    Map map;

    for (int i = 0; i < 10; ++i)
    {
        map[i] = factorial(i);
    }

    show(map);
};

void TestSTLMapWithCustomAllocator()
{
    std::cout << "TestSTLMapWithCustomAllocator" << std::endl;
    auto m = std::map<
        int,
        float,
        std::less<int>,
        CustomAllocator<
        std::pair<
        const int, long long
        >
        >
    >{};

    for (int i = 0; i < 10; ++i) {
        m[i] = factorial(i);
    }

    show(m);
};

void TestCustomListWithSTLAllocator()
{
    std::cout << "TestCustomListWithSTLAllocator" << std::endl;
    using List = SimpleList<int>;

    List list;

    for (int i = 0; i < 10; ++i)
    {
        list.Add(i);
    }

    std::cout << list;
};


int main(int, char *[]) {
    
    TestSTLMapWithSTLAllocator();
    TestSTLMapWithCustomAllocator();
    TestCustomListWithSTLAllocator();
    //TestCustomListWithCustomAllocator();
    return 0;
}
