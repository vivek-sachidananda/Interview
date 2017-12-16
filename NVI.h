//
// Created by vivek on 3/3/2016.
//

#ifndef C_NVI_H
#define C_NVI_H

#include<string>

class NVI {
public:
    NVI(std::string& iName);
    ~NVI();
    std::string getName();
private:
    std::string _name;
    virtual std::string getClassName();
};

class NVIDerived : public NVI
{
public:
    NVIDerived(std::string& iName);
private:
    std::string getClassName();
};

#endif //C_NVI_H
