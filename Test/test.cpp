#include "../Graph/Graph.hpp"
#include "../Graph/Node.hpp"
#include "GLink.hpp"

int main(int argc, char const *argv[])
{
	Graph g(true);
	Node& n0 = g.createNode();
	Node& n1 = g.createNode();
	Node& n2 = g.createNode();
	Node& n3 = g.createNode();
	GLink l01;
	GLink l02;
	GLink l10;
	GLink l13;
	GLink l23;
	GLink l33;
	n0.link(n1, l01);
	n0.link(n2, l02);
	n1.link(n0, l10);
	n1.link(n3, l13);
	n2.link(n3, l23);
	n3.link(n3, l33);
	g.print();
	return 0;
}
