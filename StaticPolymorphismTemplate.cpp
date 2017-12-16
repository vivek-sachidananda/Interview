//
// Created by vivek on 3/3/2016.
//

#include "StaticPolymorphismTemplate.h"

template <typename T>
BaseStaticPoly<T>::BaseStaticPoly() { }

template <typename T>
BaseStaticPoly<T>::BaseStaticPoly(std::string &iName):_name(iName) { }

template<typename T>
std::string BaseStaticPoly<T>::getName() { return getName().append(getClass()); }

template<typename T>
std::string BaseStaticPoly<T>::getClass() {
    return static_cast<T*>(this)->getClass();
}

std::string StaticPolymorphismTemplate::getClass() { return "Derived Class"; }

StaticPolymorphismTemplate::StaticPolymorphismTemplate(std::string &iName):BaseStaticPoly(iName) { }

// Template initialization
template std::string BaseStaticPoly<StaticPolymorphismTemplate>::getClass();
template std::string BaseStaticPoly<StaticPolymorphismTemplate>::getName();