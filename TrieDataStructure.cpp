//
// Created by vivekkimi on 1/31/2016.
//

#include <stdlib.h>
#include "TrieDataStructure.h"

void TrieDataStructure::insert(std::string& iString, int iIndex) {
    std::vector<char> aCharVect(iString.begin(), iString.end());

    std::cout << "VIV: " << aCharVect.size() << std::endl;

    TrieNode *temp = root;

    size_t  aStrLen = aCharVect.size();
    size_t  iWordIndex = 0;

    while (iWordIndex < aStrLen)
    {
        int aLocalIndex = aCharVect[iWordIndex] - 'a';

        std::cout << "VIV: aLocalIndex: " << aLocalIndex << " char: "<< aCharVect[iWordIndex] << std::endl;

        if (temp->children[aLocalIndex] == NULL)
        {
            std::cout << "VIV: " << "Add the node" << std::endl;
            temp->children[aLocalIndex] =  (TrieNode*) calloc(1, sizeof(TrieNode));
            temp->children[aLocalIndex]->name = "Child: " + aCharVect[iWordIndex];
            temp->children[aLocalIndex]->parent = temp;
        }

        temp = temp->children[aLocalIndex];

        std::cout << "VIV: Node: " << temp->name << std::endl;

        ++iWordIndex;
    }
    temp->occurences.push_back(iIndex);
}

TrieNode* TrieDataStructure::search(std::string &iWord) {
    std::vector<char> aCharVect(iWord.begin(), iWord.end());

    TrieNode *temp = root;

    size_t  aStrLen = aCharVect.size();
    size_t  iWordIndex = 0;

    while (iWordIndex < aStrLen)
    {
        int aLocalIndex = aCharVect[iWordIndex] - 'a';

        if (temp->children[aLocalIndex] != NULL)
        {
            std::cout << "VIV: found : " << aCharVect[iWordIndex] << std::endl;

            temp = temp->children[aLocalIndex];
            aCharVect.erase(aCharVect.begin(), aCharVect.begin()+1);
        }
        std::cout << "VIV: vector size: " << aCharVect.size() << std::endl;
        ++iWordIndex;
    }

    if (aCharVect.size() == 0)
    {
        std::cout << "VIV: " << "Found the string" << std::endl;
        return temp;
    }

    return NULL;
}