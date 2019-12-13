#include "ship.h"
#include <utility>

int main(void)
{
    std::pair<int,int> a = std::make_pair(1,2);

    Ship temp(a, 3, true);

    return 0;
}