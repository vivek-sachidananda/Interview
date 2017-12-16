//
// Created by vivek on 6/12/2016.
//

#ifndef C_IKM_H
#define C_IKM_H

class ExBase
{
private:
    static int stat;
public:
    static int GetStat(){ return stat; }
};

//class ExDer1 : public ExBase
//{
//public:
//    friend int Der1Fn(){ return ExBase::stat; }
//};

class ExDer2 : public ExBase{};

//class ExDer : public ExDer1, public ExDer2{};

#endif //C_IKM_H


