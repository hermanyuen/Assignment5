#include "A5Q1_CharQueue1.h"
#include <iostream>


    CharQueue1::CharQueue1() = default;

    CharQueue1::CharQueue1(size_t size) {

        if (myArray != nullptr){
            return;
        }

        //this->size = size;
        mySize = size;
        index = 0;
        myArray = std::make_unique<char[]>(mySize);
    }
    CharQueue1::CharQueue1(const CharQueue1& src) : mySize{ src.mySize } { // copy constructor
        this->myArray = std::make_unique<char[]>(mySize);
        //std::copy(src.myArray, src.myArray + mySize, myArray);
        //std::cout << src.myArray << " Hello World \n";
        for (int i = 0; i < mySize; ++i) {
            myArray[i] = src.myArray[i];
        }
        //auto myArr{ src.myArray };
        //this->myArray = src.myArray;
        /*CharQueue1 temp1 = src; //calls default constructor recursively
        std::cout << temp1.myArray << "\n";*/
        //for (int i = 0; i < mySize; ++i) {
            //myArray[i] = temp1.CharQueue1::dequeue();
            //can't access src's array since it's private and const makes src object unmodifiable
            //....so I'm stumped. Nevermind...src array is still accessible since it's in the same class(friend)
        //}
    }

    void CharQueue1::enqueue(char ch) {
        if (myArray == nullptr) {
            return;
        }
        auto temp = std::make_unique<char[]>(++mySize);
        
        for (int i = 0; i < mySize; ++i) {
            temp[i] = myArray[i];
        }
        myArray = std::move(temp);
        myArray[index] = ch;
        index++;
        /*std::cout << mySize << "  mySize\n";
        std::cout << myArray << "  myArray\n";*/
    }
    char CharQueue1::dequeue() {
        if (myArray == nullptr) {
            return NULL;
        }
        char charPop = myArray[--mySize];
        auto temp = std::make_unique<char[]>(mySize);

        for (int i = 0; i < mySize; ++i) {
            temp[i] = myArray[i];
        }
        myArray = std::move(temp);
        /*std::cout << mySize << "  mySize\n";
         std::cout << myArray << "  myArray\n";*/
        return charPop;
    }

    bool CharQueue1::isEmpty() const {
        bool empty = false;
        if (mySize == 0) {
            empty = true;
        }
        return empty;
        /*std::cout << mySize << "\n";
        return mySize;*/
    }

    //need to spend more time on this one.
    void CharQueue1::swap(CharQueue1& src) { 
        using std::swap;
        std::swap(myArray, src.myArray);
       
        //int srcSize = src.mySize;
        //if (srcSize > mySize) {
        //    //this->myArray = std::make_unique<char[]>(mySize);
        //    auto temp = std::make_unique<char[]>(srcSize);
        //    for (int i = 0; i < mySize; ++i) {
        //        temp[i] = src.myArray[i];
        //    }
        //    src.myArray = std::make_unique<char[]>(mySize); //doesn't seem to resize...
        //    for (int i = 0; i < mySize; ++i) {
        //        src.myArray[i] = myArray[i];
        //        std::cout << src.myArray[i] << " = cId \n";
        //    }
        //    myArray = std::make_unique<char[]>(srcSize);
        //    for (int i = 0; i < srcSize; ++i) {
        //        myArray[i] = temp[i];
        //    }
        //}
        //else {
        //    auto temp = std::make_unique<char[]>(mySize);
        //    for (int i = 0; i < mySize; ++i) {
        //        temp[i] = src.myArray[i];
        //    }
        //    src.myArray = std::make_unique<char[]>(mySize);

        //    for (int i = 0; i < mySize; ++i) {
        //        src.myArray[i] = myArray[i];
        //        std::cout << src.myArray[i] << " = cId \n";
        //    }
        //    myArray = std::make_unique<char[]>(srcSize);
        //    for (int i = 0; i < srcSize; ++i) {
        //        myArray[i] = temp[i];
        //    }
        //}
     
        //std::copy(src.myArray, src.myArray + mySize, myArray);
       /* std::cout << src.mySize << " srs size \n";
        std::cout << src.myArray << " srcArray \n";
        std::cout << myArray << " bye World \n";*/
    }

    size_t CharQueue1::capacity() const {
        return mySize;
    }

    CharQueue1& CharQueue1::operator=(CharQueue1 src) {
        CharQueue1 deepCopy = src;
        return deepCopy;
       // return src;
    }
