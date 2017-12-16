//
// Created by vivekkimi on 1/31/2016.
//

#ifndef C_TRIEDATASTRUCTURE_H
#define C_TRIEDATASTRUCTURE_H

#include <stddef.h>
#include <iostream>
#include "TrieNode.h"

class TrieDataStructure {
public:
    TrieDataStructure(){
        root =  new TrieNode();
        root->name = "Root";
    }
    void insert(std::string& iString, int iIndex);
    TrieNode* search(std::string& iWord);
private:
    TrieNode *root;
};


#endif //C_TRIEDATASTRUCTURE_H
