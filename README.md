# CPROGR 510, Assignment 5
## Logistics
In case of discrepancies between README.md and the assignment in Canvas, please alert the instructors!

After cloning this repo, create a branch off of main:

`git checkout -b Assignment5`

Do your work (modifications and additions of files) on the Assignment5 branch. 
Do include your code .cpp and .h files and your unit test .cpp files
Do not include exe, obj, or other results of compilation and linking. These would bloat the repository, and should not be under version control.
You may optionally turn in Visual Studio .vcproj and .sln files, or Makefiles (your-environment dependent).
`Commit` those changes to the Assignment5 branch. 

Push your changes up to `origin` (that is, to github).

When done, go to github.com and create a pull request to merge `Assignment5` branch to `main`.

## General Guidance

The header files for CppUnitLite are in the include\CppUnitLite directory.  In your project file or makefile, you will need to tell your compiler to seach this directory for headers

Microsoft Visual Studio: add this include directory to the "AdditionalIncludeDirectories"
makefile: add via the INC=-Iinclude/CppUnitLite flag

## The assignment
Write CppUnitLite tests to verify class functionality.

Define a class `CharQueue` with the public interface:
```
class CharQueue
{
public:
    CharQueue();
    CharQueue(size_t size);
    CharQueue(const CharQueue& src); // copy constructor

    void enqueue(char ch);
    char dequeue();

    bool isEmpty() const;
    void swap(CharQueue& src);

    size_t capacity() const;

    CharQueue& operator=(CharQueue src);
};
```
Copy the public interface above into two different versions of `CharQueue`:

`CharQueue1`: use a `std::unique_ptr<char[]>` array as the private data member. Use `std::make_unique` to grow the array used for the queue as needed. Add other private member variables as needed to track size and position. Overload the copy constructor and copy assignment operator to implement a deep copy. For the copy assignment use the 'copy and swap' idiom. Use the std::unique_ptr's swap operator in your implementation of `CharQueue::swap`
`CharQueue2`: use a `std::deque<char>` as the private data member. Use the compiler-generated copy constructor and assignment operator as a bitwise copy of the deque will perform a deep copy.
Place each class in two separate files named for the class. For example, for `CharQueue1` place the class declaration in `A5Q1_CharQueue1.h`. Place the class definition in `A5Q1_CharQueue1cpp`.

Create unit tests for `CharQueue1`. E.g., `A5Q1_CharQueue1Tests.cpp`. The identical tests will work for `CharQueue2`. Once you have a good set of unit tests for CharQueue1, copy them to `A5Q2_CharQueue2Tests.cpp`, and change the class names to test `CharQueue2`.

For all remaining assignments in the course we will follow this general convention. That is, place the class declaration into a .h file named for the class, and place the class definition in a .cpp file named for the class.
