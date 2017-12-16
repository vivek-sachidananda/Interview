//
// Created by vivek on 3/3/2016.
//

#ifndef C_STATICPOLYMORPHISMTEMPLATE_H
#define C_STATICPOLYMORPHISMTEMPLATE_H

#include "string"

template <typename  T>
class BaseStaticPoly
{
public:
    BaseStaticPoly();
    BaseStaticPoly(std::string& iName);
    std::string getName();
    std::string getClass();
private:
    std::string _name;
};

class StaticPolymorphismTemplate : public BaseStaticPoly<StaticPolymorphismTemplate>{
public:
    StaticPolymorphismTemplate(std::string& iName);
    std::string getClass();
};


#endif //C_STATICPOLYMORPHISMTEMPLATE_H
