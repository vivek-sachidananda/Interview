//
// Created by vivekkimi on 1/31/2016.
//

#ifndef C_TRIENODE_H
#define C_TRIENODE_H

#include <iostream>
#include <vector>

#define ALPHABETS 26

class TrieNode {
public:
    std::string name;
    TrieNode* parent;
    TrieNode* children[ALPHABETS];
    std::vector<int> occurences;
};


#endif //C_TRIENODE_H
