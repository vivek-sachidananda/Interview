//
// Created by vivekkimi on 1/31/2016.
//

#ifndef C_TEMPLATESPECIALIZATION_H
#define C_TEMPLATESPECIALIZATION_H

#include <search.h>
#include <vector>
#include <algorithm>
template <size_t  n>
struct fibo;

template<>
struct fibo<0>
{
    const static int value = 1;
};

template<>
struct fibo<1>
{
    const static int value = 1;
};

template <size_t n>
struct fibo
{
    const static int value = fibo<n-1>::value + fibo<n-2>::value;
};



class TemplateSpecialization {
    struct multiplesOfFunctor
    {
        multiplesOfFunctor(int multiples):_multiples(multiples)
        {
        }
        bool operator()(int x)
        {
            return  !(x % _multiples);
        }
        int _multiples;
    };
public:
    TemplateSpecialization():aVect({1,23,4,5,2,7,9,20,26,72,88,55,99,54,35})
    {
    }

    int callFibo()
    {
        return fibo<10>::value;
    }

    int callFunctor(int multiplesOf)
    {
        return std::count_if(aVect.begin(), aVect.end(), multiplesOfFunctor(multiplesOf));
    }
    // = is the default specialization
    int callLambda(int multiplesOf)
    {
        return std::count_if(aVect.begin(), aVect.end(), [=](int num){ return !(num % multiplesOf);});
    }

    int sumLambda()
    {
        int sum = 0;
        std::for_each(aVect.begin(), aVect.end(), [&sum](int x) { sum += x;});
        return sum;
    }
    std::vector<int> aVect;
};


#endif //C_TEMPLATESPECIALIZATION_H
