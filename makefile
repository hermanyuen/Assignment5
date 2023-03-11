CC=g++
CFLAGS=-I. -I./include/CppUnitLite
CXXFLAGS += -std=c++20 -Wall -Werror
# -std=c++20: valid for g++ 10 and greater.
# -Wall: reports all warnings
# -Werror: warnings reported as errors

OBJ = CppUnitLite/Failure.o CppUnitLite/Test.o CppUnitLite/TestRegistry.o CppUnitLite/TestResult.o CppUnitLite/WFailure.o \
      Main.o \
      A5Q1_CharQueue1.o A5Q1_CharQueue1Test.o A5Q2_CharQueue2.o A5Q2_CharQueue2Test.o
	  
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(CXXFLAGS)

Assignment5: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(CXXFLAGS)


all: Assignment5

clean:
	rm *.o
	rm ./CppUnitLite/*.o
