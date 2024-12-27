#include "AStar.hpp"
int main()
{
	Graph<int> graph = Graph<int>();

	graph.addNode("A", 13);
	graph.addNode("B", 15);
	graph.addNode("C", 16);
	graph.addNode("D", 19);

	graph.addEdgeByIndex(0, 1, 5); //AB
	graph.addEdgeByIndex(0, 3, 7); //AD
	graph.addEdgeByIndex(1, 2, 19); // BC
	graph.addEdgeByIndex(1, 3, 9); // BD
	graph.addEdgeByIndex(2, 0, 22); // CA
	graph.addEdgeByIndex(3, 0, 33); // DA

	graph.print();

	std::vector<std::string> path = AStar::Find(graph.getNodes(), graph.getNodes()[0], graph.getNodes()[3]);

	AStar::PrintPath(path);

	return 0;
}