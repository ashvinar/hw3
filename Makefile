CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec-test.o llrec.o
	$(CXX) $(CXXFLAGS) -o llrec-test llrec-test.o llrec.o

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp


llrec_tests: llrec_tests.o llrec.o
	$(CXX) $(CXXFLAGS) -o llrec_tests llrec_tests.o llrec.o

llrec_tests.o: llrec_tests.cpp llrec.h llrec_test_utils.h
	$(CXX) $(CXXFLAGS) -c llrec_tests.cpp

	
clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 