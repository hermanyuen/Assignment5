#pragma once
#include <deque>

class CharQueue2
{
public:
    CharQueue2();
    CharQueue2(size_t size);
    CharQueue2(const CharQueue2& src); // copy constructor

    void enqueue(char ch);
    char dequeue();

    bool isEmpty() const;
    void swap(CharQueue2& src);

    size_t capacity() const;

    CharQueue2& operator=(CharQueue2 src);
	
private:
    //add private members as per assignment	
};
