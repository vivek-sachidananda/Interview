cmake_minimum_required(VERSION 3.3)
project(C__)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BOOST_ROOT "C:/local/boost_1_60_0")
set(BOOSTROOT "C:/local/boost_1_60_0")


find_package(Boost 1.60.0)

include_directories(${Boost_INCLUDE_DIRS})

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

set(SOURCE_FILES main.cpp Node.cpp Node.h BinarySearchTree.cpp BinarySearchTree.h BinarySearchTree.cpp BinarySearchTree.h TrieDataStructure.cpp TrieDataStructure.h TrieNode.cpp TrieNode.h TemplateSpecialization.cpp TemplateSpecialization.h ArrayNString.cpp ArrayNString.h LinkedList.cpp LinkedList.h TreeClassBST.cpp TreeClassBST.h MatrixBased.cpp MatrixBased.h NVI.cpp NVI.h StaticPolymorphismTemplate.cpp StaticPolymorphismTemplate.h MultipleBaseTemplateMetaProg.cpp MultipleBaseTemplateMetaProg.h MultiBaseClassWithNotCommonFunc.cpp MultiBaseClassWithNotCommonFunc.h Ikm.h)
add_executable(C__ ${SOURCE_FILES})
