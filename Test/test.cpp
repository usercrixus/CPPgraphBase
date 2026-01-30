#include "../Graph/Graph.hpp"
#include "../Graph/Node.hpp"
#include "GLink.hpp"
#include <stdexcept>

static Node &byName(Graph &g, const std::string &name)
{
	std::vector<Node*> matches = g.getNodeByName(name);
	if (matches.empty() || matches[0] == nullptr)
		throw std::runtime_error("No node found with name: " + name);
	return *matches[0];
}

int main(int argc, char const *argv[])
{
	Graph g(true);
	g.createNode("0");
	g.createNode("1");
	g.createNode("2");
	g.createNode("3");
	{
		GLink l01;
		GLink l02;
		GLink l10;
		GLink l13;
		GLink l23("l23");
		GLink l33;

		byName(g, "0").link(byName(g, "1"), l01);
		byName(g, "0").link(byName(g, "2"), l02);
		byName(g, "1").link(byName(g, "0"), l10);
		byName(g, "1").link(byName(g, "3"), l13);
		byName(g, "2").link(byName(g, "3"), l23);
		byName(g, "3").link(byName(g, "3"), l33);
	}
	g.print();

	std::cout << "\n\nDelete n0 n2 by ref\n\n"
			  << std::endl;
	byName(g, "0").unlink(byName(g, "2"));
	g.print();

	std::cout << "\n\nDelete n1 n3 by link id\n\n"
			  << std::endl;
	byName(g, "1").unlink(4294967297UL);
	g.print();

	std::cout << "\n\nDelete n3 n3 by link reference\n\n"
			  << std::endl;
	byName(g, "3").unlink(byName(g, "3").getLinks()[0]);
	g.print();

	std::cout << "\n\nDelete n2 n3 by link name\n\n"
			  << std::endl;
	byName(g, "2").unlink(byName(g, "2").getLinks()[0].second->name);
	g.print();

	return 0;
}
