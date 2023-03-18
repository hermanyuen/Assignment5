#pragma once
#include <memory>

class CharQueue1
{
public:
    CharQueue1();
    CharQueue1(size_t size);
    CharQueue1(const CharQueue1& src); // copy constructor
   // ~CharQueue1() {}

    void enqueue(char ch);
    char dequeue();

    bool isEmpty() const;
    void swap(CharQueue1& src);

    size_t capacity() const;

    CharQueue1& operator=(CharQueue1 src);
	
private:
    //add private members as per assignment	
    std::unique_ptr<char[]> myArray;
    int mySize{  };
    int index{  };
};
