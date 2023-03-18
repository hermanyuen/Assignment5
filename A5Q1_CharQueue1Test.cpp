#include "TestHarness.h"

#include "A5Q1_CharQueue1.h"
#include <iostream>

TEST(enqueueDequeue, CharQueue1)
{
	CharQueue1 test1(0);
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

TEST(deepCopy, CharQueue1copy)
{
	CharQueue1 test1(0);
	test1.enqueue('h');
	test1.enqueue('e');
	test1.enqueue('l');
	test1.enqueue('l');
	test1.enqueue('o');

	CharQueue1 test2(test1);
	CHECK_EQUAL('o', test2.dequeue());
	CHECK_EQUAL(4, test2.capacity());
}

TEST(deepCopySwap, CharQueue1Swap)
{
	CharQueue1 test1(0);
	test1.enqueue('h');
	test1.enqueue('e');
	test1.enqueue('l');
	test1.enqueue('l');
	test1.enqueue('o');

	CharQueue1 test2(test1);
	test2.enqueue('w');
	test2.enqueue('o');
	test2.enqueue('r');
	test2.enqueue('l');
	test2.enqueue('d');
	test1.swap(test2);
	//std::cout << test2.dequeue() << "what?!?!?!\n";
	CHECK_EQUAL('d', test1.dequeue());
	CHECK_EQUAL(4, test1.capacity());
	//CHECK_EQUAL('o', test2.dequeue());
	CHECK_EQUAL(10, test2.capacity());
}
