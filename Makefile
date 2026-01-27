test.out: Test/test.cpp
	g++ -std=c++17 Test/test.cpp -o test.out

test: test.out
	./test.out

fclean:
	rm -fr test.out

.PHONY: Test fclean