//
// Created by vivek on 3/3/2016.
//

#include "NVI.h"

NVI::NVI(std::string &iName): _name(iName) { }

NVI::~NVI() {}

std::string NVI::getClassName() {
    return " Base NVI";
}

std::string NVI::getName() {
    return _name.append(getClassName());
}

NVIDerived::NVIDerived(std::string &iName):NVI(iName) { }

std::string NVIDerived::getClassName() { return " Derived NVI"; }