//
// Created by vivek on 3/21/2016.
//

#ifndef C_MULTIBASECLASSWITHNOTCOMMONFUNC_H
#define C_MULTIBASECLASSWITHNOTCOMMONFUNC_H

#include <iostream>

class Base1
{
public:
    void functionCall()
    {
        std::cout << "Base1: functionCall" << std::endl;
    }
};

class Base2
{
public:
    void functionCallDiff()
    {
        std::cout << "Base1: functionCallDiff" << std::endl;
    }

    void functionCall()
    {
        std::cout << "Base1: functionCall" << std::endl;
    }
};

template <typename Type, class Base>
class Derived : public Base
{
public:
    // Many...many other members

    void callFuncNotCommonInBase();
//    using Base::functionCall;
};

class MultiBaseClassWithNotCommonFunc {

};


#endif //C_MULTIBASECLASSWITHNOTCOMMONFUNC_H
