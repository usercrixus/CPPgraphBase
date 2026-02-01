SRCS = Test/test.cpp Graph/Link.cpp Graph/Graph.cpp Graph/Node.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

CXX = g++
CXXFLAGS = -std=c++17 -MMD -MP -Wall -Wextra -Werror

test.out: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o test.out

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: test.out
	./test.out

fclean:
	rm -fr test.out $(OBJS) $(DEPS)

.PHONY: test fclean

-include $(DEPS)
