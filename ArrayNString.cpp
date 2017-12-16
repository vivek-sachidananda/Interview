//
// Created by vivekkimi on 2/5/2016.
//
#include "string"
#include "ArrayNString.h"
#include "iostream"
#include <map>
#include <boost/lexical_cast.hpp>
#include "algorithm"
#include "stack"
#include <limits>

bool isUniqueString(std::string iString)
{
    size_t aLength = iString.size();
    bool aArray[256] = {false};

    for (int iIndex = 0; iIndex < aLength; iIndex++)
    {
        if (aArray[int(iString[iIndex])])
            return false;
        else
            aArray[int(iString[iIndex])] = true;
    }
    return true;
}

void reverseString(char *p)
{
  char *q = p;

  while(q && *q) ++q;
  for(--q; p < q; ++p, --q)
    *p = *p ^ *q,
    *q = *p ^ *q,
    *p = *p ^ *q;
}

struct CharacterCount
{
    CharacterCount(bool isIncrement, std::map<char , int> *iCharCountMap) : _isIncrement(isIncrement), _charCountMap(iCharCountMap)
    {
        std::cout << "VIV: constructor of CharacterCount "<< std::endl;
    }
    void operator()(char iChar)
    {
        if (_isIncrement)
        {
            std::cout << "VIV:iChar: " << iChar << std::endl;
            if (_charCountMap->find(iChar) != _charCountMap->end())
                ++(_charCountMap->find(iChar)->second);
            else
                _charCountMap->insert(std::pair<char, int>(iChar, 1));
        }
        else
        {
            if (_charCountMap->find(iChar) != _charCountMap->end())
                --(_charCountMap->find(iChar)->second);
            else
                return;
        }
        std::cout << "VIV: size: " << _charCountMap->size() << std::endl;
    }
    bool _isIncrement;
    std::map<char , int> *_charCountMap;
};

bool isAnagram(std::string iStr1, std::string iStr2)
{
    std::map<char , int> aMap;
//    std::for_each(iStr1.begin(), iStr1.end(), CharacterCount(true, &aMap));
//    std::for_each(iStr2.begin(), iStr2.end(), CharacterCount(false, &aMap));

    for(int i =0 ; i < iStr1.length(); i++)
    {
        if (aMap.find(iStr1[i]) != aMap.end())
            ++(aMap.find(iStr1[i])->second);
        else
            aMap.insert(std::pair<char, int>(iStr1[i], 1));

        if (aMap.find(iStr2[i]) != aMap.end())
            --(aMap.find(iStr2[i])->second);
        else
            aMap.insert(std::pair<char, int>(iStr2[i], -1));
    }
        std::map<char , int>::const_iterator aMapItr = aMap.begin();

        std::cout << "VIV: aMap.size(): " << aMap.size() << std::endl;
        while(aMapItr != aMap.end())
        {
            std::cout << "VIV: Map: " << aMapItr->first << ":" << aMapItr->second << std::endl;
            ++aMapItr;
        }

    size_t isAnagram = std::count_if(aMap.begin(), aMap.end(), [](std::pair<char, int> iPair)->bool{
        return iPair.second != 0;
    });

    return (isAnagram == 0);
}

void runLengthEncoding(std::string iString)
{
    std::string outputStr = std::string("");
    char last;
    last = iString[0];
    int  aCount = 1;
    for( int i = 1; i< iString.length(); i++)
    {
        std::cout << "VIV: last: " << last << "iString: " << iString[i] << " aCount: " << aCount << std::endl;
        if(last == iString[i])
        {
            ++aCount;
        }
        else
        {
            outputStr.push_back(last);
            outputStr.append(boost::lexical_cast<std::string>(aCount));
            aCount = 1;
            last = iString[i];
        }

        std::cout << "VIV: outputStr: " << outputStr << std::endl;
    }

    outputStr.push_back(last);
    outputStr.append(boost::lexical_cast<std::string>(aCount));

    std::cout << "VIV: final string: " << outputStr << std::endl;
}

size_t compare(std::string iString, bool iBoolArray[])
{
    size_t aCount[26] = {0};

    for (int i = 0; i< iString.length(); i++)
    {
        std::cout << "VIV: iString[i]: " << iString[i] << std::endl;
        if (iBoolArray[int(iString[i] - 'a')])
        {
            aCount[int(iString[i] - 'a')]++;
        }
    }
    std::cout << "VIV: iString : " << iString << " aCount: " << aCount << std::endl;

    return 0;
}

std::string findLengthyString(std::vector<std::string> iStringVector, std::vector<char> iCharVect)
{
    int aIndex = 0 ;
    size_t  aLength = std::numeric_limits<size_t>::min();

    bool aCharBool[26] = {false};

    for (int i =0 ; i < iCharVect.size(); i++)
    {
        std::cout << "VIV: icHar: " << int(iCharVect[i] - 'a') << std::endl;
        aCharBool[int(iCharVect[i] - 'a')] = true;
    }

    for (int i = 0; i < iStringVector.size(); i++)
    {
        std::string aString = iStringVector[i];

        size_t iCount = compare(aString, aCharBool);

        std::cout << "VIV: aLength: " << aLength << " iCount:" << iCount << std::endl;

        if (aLength < iCount)
        {
            std::cout << "VIV: aLength: " << aLength << " iCount: " << iCount << "aIndex :" << aIndex << std::endl;
            aLength = iCount;
            aIndex = i;
        }
    }

    return iStringVector[aIndex];
}

bool isUniqueCharString(std::string iStr)
{
    int aChecker = 0;
    int aValue;

    for(int i = 0; i < iStr.length(); i++)
    {
        aValue = iStr[i] - 'a';

        if((aChecker & (1 << aValue)) > 0)
            return false;

        aChecker |= (1 << aValue);
    }

    return true;
}

#include "cstring"

void replace2(char *c){
    if(c == NULL) return;
    int len = strlen(c);
    if(len == 0) return;
    int cnt = 0;
    for(int i=0; i<len; ++i)
    {
        if(c[i] == ' ')
            ++cnt;
    }
    int p = len + 2*cnt;
    c[p--] = '\0';//the space must be allocated first.
    for(int i=len-1; i>=0; --i)
    {
        if(c[i] == ' ')
        {
            c[p] = '0';
            c[p-1] = '2';
            c[p-2] = '%';
            p -= 3;
        }
        else
        {
            c[p] = c[i];
            --p;
        }
    }
}

void ArrayNString::execute() {

    // Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
    std::cout << "VIV: isUnique : " << isUniqueString("ABCDEF") << std::endl;
    std::cout << "VIV: isUnique : " << isUniqueString("ABCDEFA") << std::endl;

    char aStr[] = "ABCD";

    reverseString(aStr);
    std::cout << "VIV: isUnique : " << aStr << std::endl;

    std::cout << "VIV: isAnagram: " << isAnagram("ABCDE", "FCDBA") << std::endl;;

    runLengthEncoding("aaaaabbbbbcdeeefgghh");

    std::vector<std::string> aVectoString = {"abcdeeeddf", "abbcdefg", "aasdllldfdf", "aaaa"};
    std::vector<char> aVectoChar;
    aVectoChar.push_back('a');
    aVectoChar.push_back('b');

    std::cout << "VIV: lengthy: " << findLengthyString(aVectoString, aVectoChar) << std::endl;

    std::cout << "VIV: isUnique(str) : " << isUniqueCharString("abcdefghd") << std::endl;
}