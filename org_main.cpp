#include <iostream>
#include <memory>
#include <map>
#include "Node.h"
#include "boost/shared_ptr.hpp"
#include "BinarySearchTree.h"
#include "TrieDataStructure.h"
#include "TemplateSpecialization.h"
#include "ArrayNString.h"
#include "LinkedList.h"
#include "TreeClassBST.h"
#include "NVI.h"
#include "StaticPolymorphismTemplate.h"
//#include "MultipleBaseTemplateMetaProg.h"

using namespace std;



int main() {

    BinarySearchTree aBST;

    aBST.add(3);

    aBST.add(200);

    aBST.add(99);

    aBST.add(201);

    aBST.add(2);

    aBST.add(1);

    aBST.add(-1);

    aBST.add(-8);

    aBST.add(100);
    aBST.add(97);
    aBST.add(105);
    aBST.add(96);
    aBST.add(99);
    aBST.add(104);
    aBST.add(106);

    aBST.print();

    std::cout << "VIV: childCount " << aBST.childCount() << std::endl;

    std::cout << "VIV: maxDepth: " << aBST.maxDepth() << std::endl;

    std::cout << "VIV: isBalanced: " << aBST.isBalanced() << std::endl;

    std::cout << "VIV: " << "BFS: " << std::endl;
    aBST.breadthFirstSearch();
    std::cout << "VIV: " << "-------------------" << std::endl;


//    TrieDataStructure aTrie;
//
//    std::string aStr1("vivek");
//    std::string aStr2("kimi");
//    std::string aStr3("vikas");
//
//    aTrie.insert(aStr1, 1);
//    aTrie.insert(aStr2, 2);
//    aTrie.insert(aStr3, 3);
//
//    aTrie.search(aStr1);
    TemplateSpecialization aTemp;
    std::cout << "VIV: Fibo " << aTemp.callFibo() << std::endl;
    std::cout << "VIV: Functor " << aTemp.callFunctor(3) << std::endl;
    std::cout << "VIV: Lambda " << aTemp.callLambda(3) << std::endl;
    std::cout << "VIV: Lambda Sum " << aTemp.sumLambda() << std::endl;

    ArrayNString aObj;

    aObj.execute();

    LinkedList<int> aLl;
    LinkedList<int> aL2;

    aLl.addValue(1);
    aLl.addValue(4);
    aLl.addValue(5);


    aL2.addValue(9);
    aL2.addValue(4);
    aL2.addValue(5);

    aLl.print();

    (aLl + aL2).print();

//    aBST.clearTree();

//    std::vector<int> aListInt = {2,4,5,6,7,8,9,10,123,444,999};
//    aBST.add(aListInt);
//    aBST.print();
//    aBST.breadthFirstSearch();
    TreeClassBST<int> aTreeBST;
    std::vector<int> aVectoInt = {30,344,5,99,40};
    aTreeBST.add(aVectoInt[0]);
    aTreeBST.add(aVectoInt[1]);
    aTreeBST.add(aVectoInt[2]);
    aTreeBST.add(aVectoInt[3]);

    aTreeBST.print();

    std::string aStr("Test");
    NVI *basePtr = new NVIDerived(aStr);

    std::cout << "NVI: " << basePtr->getName() << std::endl;

//    StaticPolymorphismTemplate *ptr = new StaticPolymorphismTemplate(aStr);
//    std::cout << "Static Template Poly: " << ptr->getName();

//    MultipleBaseTemplateMetaProg aMetaProg;
//    aMetaProg.print();


    std::map<int, std::string> aMapOrdered;

    aMapOrdered.insert(std::pair<int, std::string>(9, "Nine"));
    aMapOrdered.insert(std::pair<int, std::string>(2, "Two"));
    aMapOrdered.insert(std::pair<int, std::string>(10, "Ten"));

    std::map<int, std::string>::const_iterator aIter = aMapOrdered.begin();
    std::map<int, std::string>::const_iterator aEndIter = aMapOrdered.end();

    while(aIter != aEndIter)
    {
        std::cout<< "Map ordered: " << aIter->second << std::endl;
        ++aIter;
    }

    std::vector<int> aIntVect{1,3,5,9,10,12,2,4,6};

    std::map<int, int> aMapInt;
    size_t  aSize = aIntVect.size();

    int aSum(13);

    for(size_t i = 0; i < aSize; ++i)
    {
        std::map<int, int>::const_iterator aIter = aMapInt.begin();

        std::map<int, int>::const_iterator aEndIter = aMapInt.end();
        aMapInt.insert(std::make_pair(aIntVect[i], i));

        aIter = aMapInt.find(aSum - aIntVect[i]);

        if (aIter != aEndIter && aIter->second != i)
            std::cout << "Pair: " << aIntVect[i] << ":" << aIter->first << std::endl;
    }

    return 0;
}

// Includes
//#include "iostream"
//#include "list"
//#include "numeric"
//#include "vector"
//
///////////////////////////////////////////////////////////////////////////////
//
///* ABOUT THIS TEST - READ CAREFULLY
//
//   Grading: This test is graded based on two parameters:
//
//   1) Correctness - your implementation should follow the
//   specification, and answers to the questions below should be right.
//
//   2) Speed - the faster you can do this test, the better
//
//   Timing: You have at most 60 minutes time for this test, after which
//   you must send the test back by e-mail. If you do not accomplish
//   everything to your satisfaction in that time, you must still submit
//   the result in 60 minutes, with what-ever sections you have
//   accomplished.
//
//   General: The code below may contain any number of bugs. Part of
//   your job is to fix them as you go.
//
//   Tools: You need a working C++ compiler for this test. All normal/modern
//   compilers should work - gcc, clang, msvc etc.
//
//   You are allowed to use any on-line/written reference material that
//   helps you.
//
//  */
//
///////////////////////////////////////////////////////////////////////////////
//// First Part: Basic C++ and STL.
//
//class Animal
//{
//public:
//    Animal() {}
//    virtual ~Animal(){}
//    virtual void makeNoise() { std::cout << "This animal makes no sound." << std::endl; }
//};
//
//class Cat : public Animal
//{
//public:
//    virtual ~Cat(){}
//    void makeNoise() { std::cout << "This cat meows!" << std::endl; }
//};
//
//class Dog : public Animal
//{
//public:
//    virtual ~Dog(){}
//    void makeNoise() { std::cout << "This dog barks!" << std::endl; }
//};
//
///////////////////////////////////////////////////////////////////////////////
//// Start here
//
//void animals()
//{
//    // Using std::vector, create an array integers and fill it with numbers
//    // from 0 to 99 and print the numbers to console.
//    std::vector<int> aIntVector(100);
//    int aInitValue = 0;
//
//    //fill the vector
//    std::iota (std::begin(aIntVector), std::end(aIntVector), aInitValue);
//
//    // print
//    for (auto iValue: aIntVector)
//        std::cout << iValue << ' ';
//
//    std::cout << std::endl;
//
//    // Inherit two classes, called Cat and Dog from the Animal class and
//    // overload the makeNoise() function in both of them. Make the Cat and Dog print
//    // different messages in their makeNoise().
//    Animal *anAnimal1, *anAnimal2;
//    anAnimal1 = new Dog();
//    anAnimal2 = new Cat();
//
//    // Below is a list of Animal objects. Insert one Cat and one Dog object into
//    // the end of the list.
//    std::list<Animal*> listOfAnimals;
//
//    listOfAnimals.push_back(anAnimal1);
//    listOfAnimals.push_back(anAnimal2);
//
//    // Iterate over the contents of the list and call makeNoise() for each item.
//    // Explain the results.
//    for (std::list<Animal*>::iterator iAnimalItr = listOfAnimals.begin(), end = listOfAnimals.end(); iAnimalItr != end; ++iAnimalItr) {
//        (*iAnimalItr)->makeNoise();
//    }
//
//    delete(anAnimal1);
//    delete(anAnimal2);
//
//}
//
//// Here is a simple Goomba class. It just keeps track of how many Goombas are alive.
//class Goomba
//{
//public:
//    static int liveGoombas;
//
//    Goomba() {
//        std::cout << "VIV: constructor: "<< liveGoombas << std::endl;
//        liveGoombas++; };
//    ~Goomba() {
//        std::cout << "VIV: destructor: "<< liveGoombas << std::endl;
//        liveGoombas--; }
//};
//
//int Goomba::liveGoombas = 0;
//
//// And a Goomba legion class. Please don't change this class.
//class GoombaLegion
//{
//public:
//    void add(Goomba goomba)
//    {
//        goombas.push_back(goomba);
//    }
//
//private:
//    std::vector<Goomba> goombas;
//};
//
//void goombas()
//{
//    {
//        // Below is a legion of Goombas. Please add 100 Goombas to it. Please don't
//        // modify the GoombaLegion class.
//        GoombaLegion legion;
//        size_t aCount = 0;
//        while (aCount < 3)
//        {
//            legion.add(Goomba());
//            ++aCount;
//        }
//        std::cout << "VIV: Legion going out of scope" << std::endl;
//    }
//
//    // The legion went out of scope and was destroyed. But how many Goombas are alive?
//    // Please explain what happens and then fix the code.
//
//    // In fact, since the goomba are created locally, they are destructed once the object goes oout of scope, and then we make copies into the vector so we will also destruct them once legion goes out of scope.
//    // Hence, We have more than double the destructor being called. Hence, the static var goes into negative count of 200+.
//    // In short, destructor of object created is called and also the copies of goomba kept in the vectors are also destructed once legion goes out of scope.
//
//    // Fix, is the keep the pointers so that they are alive. But in anycase we need to delete them to avoid leaks in memory.
//    std::cout << "There are " << Goomba::liveGoombas << " live goombas" << std::endl;
//}
//
//int main()
//{
//    animals();
//    goombas();
//
//}

