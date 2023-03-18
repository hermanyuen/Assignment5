#include "TestHarness.h"

#include "A5Q2_CharQueue2.h"
#include <iostream>
TEST(enqueueDequeue, CharQueue2)
{
	CharQueue2 test1(0);
	test1.enqueue('h');
	test1.enqueue('e');
	test1.enqueue('l');
	test1.enqueue('l');
	test1.enqueue('o');
	/*std::cout << "test1 is empty? " << test1.isEmpty() << "\n";
	std::cout << "test1 capacity? " << test1.capacity() << "\n";*/
	CHECK_EQUAL(false, test1.isEmpty());
	CHECK_EQUAL(5, test1.capacity());
	CHECK_EQUAL('o', test1.dequeue());
}

TEST(deepCopy, CharQueue2copy)
{
	CharQueue2 test1(0);
	test1.enqueue('h');
	test1.enqueue('e');
	test1.enqueue('l');
	test1.enqueue('l');
	test1.enqueue('o');

	CharQueue2 test2(test1);
	CHECK_EQUAL('o', test2.dequeue());
	CHECK_EQUAL(4, test2.capacity());
}

TEST(deepCopySwap, CharQueue2Swap)
{
	CharQueue2 test1(0);
	test1.enqueue('h');
	test1.enqueue('e');
	test1.enqueue('l');
	test1.enqueue('l');
	test1.enqueue('o');

	CharQueue2 test2(test1);
	test2.enqueue('w');
	test2.enqueue('o');
	test2.enqueue('r');
	test2.enqueue('l');
	test2.enqueue('d');
	test1.swap(test2);
	//std::cout << test2.dequeue() << "what?!?!?!\n";
	CHECK_EQUAL('d', test1.dequeue());
	CHECK_EQUAL(4, test1.capacity());
	CHECK_EQUAL('o', test2.dequeue());
	CHECK_EQUAL(9, test2.capacity());
}

	//The assignment just says "create unit tests".  Please consider carefully what set of unit tests
	//is needed to exercise your object's interface, including both normal, and boundary/edge cases.
	//
	//As the assignment says, you should be able to use the same set of test cases for CharQueue2 as for CharQueue1
	//(changing the names and changing the class that is tested, of course!)
