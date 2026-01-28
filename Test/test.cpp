#include "../Graph/Graph.hpp"
#include "../Graph/Node.hpp"
#include "GLink.hpp"

int main(int argc, char const *argv[])
{
	Graph g(true);
	Node &n0 = g.createNode();
	Node &n1 = g.createNode();
	Node &n2 = g.createNode();
	Node &n3 = g.createNode();
	n0.link(n1, GLink());
	n0.link(n2, GLink());
	n1.link(n0, GLink());
	n1.link(n3, GLink());
	n2.link(n3, GLink());
	n3.link(n3, GLink());
	g.print();

	std::cout << "\n\nDelete n0 n2 by ref\n\n" << std::endl;
	n0.unlink(n2);
	g.print();


	return 0;
}
