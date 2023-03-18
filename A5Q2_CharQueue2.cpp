#include "A5Q2_CharQueue2.h"

CharQueue2::CharQueue2() = default;

CharQueue2::CharQueue2(size_t size) : mySize{ size } {
    if (myArray.empty()) {
        return;
    }
    myArray.resize(mySize);
}

CharQueue2::CharQueue2(const CharQueue2& src) : mySize{ src.mySize } { // copy constructor
    //std::copy(src.myArray, src.myArray + mySize, myArray);
    //std::cout << src.myArray << " Hello World \n";
    myArray.resize(mySize);
    for (int i = 0; i < mySize; ++i) {
        myArray.at(i) = src.myArray.at(i);
    }
}

void CharQueue2::enqueue(char ch) {
    myArray.push_front(ch);
    mySize++;
}

char CharQueue2::dequeue() {
    if (myArray.empty()) {
        return NULL;
    }
    char cReturn = myArray.front();
    myArray.pop_front();
    mySize--;
    return cReturn;
}

bool CharQueue2::isEmpty() const {
    bool empty = false;
    if (myArray.empty()) {
        empty = true;
    }
    return empty;
    /*std::cout << mySize << "\n";
    return mySize;*/
}
void CharQueue2::swap(CharQueue2& src) {
   /* using std::swap;
    swap(myArray, src.myArray);*/
    myArray.std::deque<char>::swap(src.myArray);
}

size_t CharQueue2::capacity() const {
    return mySize;
}

CharQueue2& CharQueue2::operator=(CharQueue2 src) {
    CharQueue2 deepCopy = src;
    return deepCopy;
    // return src;
}
