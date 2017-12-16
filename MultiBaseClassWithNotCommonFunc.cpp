//
// Created by vivek on 3/21/2016.
//

#include "MultiBaseClassWithNotCommonFunc.h"

template <typename Type, class Base> void Derived<Type, Base>::callFuncNotCommonInBase()
{
    Base::functionCall();
//    Base::functionCall();
}

template <> void Derived<int16_t, Base1>::callFuncNotCommonInBase()
{
//      functionCallDiff();
//    Base::functionCall();
}

template class Derived<int16_t , Base1>;
template class Derived<int16_t , Base2>;