#include <iostream>
#include <list>
#include <tuple>
#include <vector>
#include <unordered_map>

#include "TopologicalSort.h"
#include "Ms.hpp"

using namespace std;

int main()
{
    cout << "test" << endl;
//
//    TopologicalSort aTopo;
//
//    aTopo.runTopologicalSort();


    Ms aMs;
    IMaze aImaze;

    cout << "Cheese found ? : " << aMs.findCheese(aImaze) << endl;



    getchar();

    return 0;
}