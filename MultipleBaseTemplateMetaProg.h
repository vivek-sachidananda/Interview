//
// Created by vivek on 3/14/2016.
//

#ifndef C_MULTIPLEBASETEMPLATEMETAPROG_H
#define C_MULTIPLEBASETEMPLATEMETAPROG_H

#include <iostream>

enum Base{ One, Two, Three};

template<class T>
struct type_is
{
    using type = T;
};

template<Base, class T, class>
struct IF_t : type_is<T> {};

template<class T, class F>
struct IF_t<One, T, F> : type_is<F> {};

class Base1
{
public:
    void print()
    {
        std::cout << "Base 1" << std::endl;
    }
};

class Base2
{
public:
    void print()
    {
        std::cout << "Base 2" << std::endl;
    }
};

template <int q>
class Derived : public IF_t<(q > 0), Base1, Base2, Base3>::type
{
};

template class Derived<1>;

class MultipleBaseTemplateMetaProg {
public:
    void print()
    {
        Derived<1> aDerivedTrue;
        aDerivedTrue.print();
        Derived<-1> aDerivedFalse;
        aDerivedFalse.print();
    }
};


#endif //C_MULTIPLEBASETEMPLATEMETAPROG_H
