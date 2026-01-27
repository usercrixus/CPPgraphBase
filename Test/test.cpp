#include "../Graph/Graph.hpp"
#include "../Graph/Node.hpp"
#include "GLink.hpp"

int main(int argc, char const *argv[])
{
	Graph<GLink> g(true);
	Node<GLink>& n0 = g.createNode();
	Node<GLink>& n1 = g.createNode();
	Node<GLink>& n2 = g.createNode();
	Node<GLink>& n3 = g.createNode();
	n0.link(n1, GLink());
	n0.link(n2, GLink());
	n1.link(n0, GLink());
	n1.link(n3, GLink());
	n2.link(n3, GLink());
	n3.link(n3, GLink());
	g.print();
	return 0;
}
