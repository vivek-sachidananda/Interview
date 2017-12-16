#include <iostream>
#include <list>
#include <tuple>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    cout << "test" << endl;


    std::unordered_map<char, size_t> aMap;

    std::string aStr1, aStr2;
    aStr1 = "abbc";
    aStr2 = "babc";

    std::vector<char> aVec1(aStr1.begin(), aStr1.end()), aVect2(aStr2.begin(), aStr2.end());

    for (size_t i = 0; i < aStr1.length(); ++i)
    {
        ++aMap[aVec1[i]];
        --aMap[aVect2[i]];
    }

    std::unordered_map<char, size_t>::const_iterator aIter = aMap.begin();
    std::unordered_map<char, size_t>::const_iterator aEndIter = aMap.end();

    while (aIter != aEndIter)
    {
        cout << aIter->first << " " << aIter->second << endl;
        ++aIter;
    }

    return 0;
}