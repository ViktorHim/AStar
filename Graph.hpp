#pragma once
#include <vector>
#include <iostream>
#include "Node.hpp"
#include "Edge.hpp"

template <typename T>
class Graph
{
	public:
		Graph()
		{

		}

		void addEdge(Node<T>* from, Node<T>* to, T weight)
		{
			Edge<T> newEdge = Edge<T>(weight, to);
			*from += newEdge;
		}

		void addEdgeByIndex(int from, int to, T weight)
		{
			if (from > nodes.size() - 1 || from < 0)
			{
				throw std::out_of_range("Index out of range: 'from' is not valid.");
			}
			if (to > nodes.size() - 1 || to < 0)
			{
				throw std::out_of_range("Index out of range: 'to' is not valid.");
			}

			Edge<T> newEdge = Edge<T>(weight, nodes[to]);
			*nodes[from] += newEdge;
		}

		void addNode(std::string name, T cost)
		{
			Node<T>* newNode = new Node<T>(name, cost);
			nodes.push_back(newNode);
		}

		std::vector<Node<T>*>& getNodes()
		{
			return nodes;
		}

		void print()
		{
			for (int i = 0; i < nodes.size(); i++)
			{
				std::cout <<"Node " << nodes[i]->getName() << "(" << nodes[i]->getCost() << ")" << " connected with";
				std::vector<Edge<T>> edges = nodes[i]->getEdges();

				for (int j = 0; j < edges.size(); j++)
				{
					std::cout << " " << edges[j].getNode()->getName() << "(" << edges[j].getNode()->getCost() << ")";
				}

				std::cout << " and has the following edges:";

				for (int j = 0; j < edges.size(); j++)
				{
					std::cout << " " << nodes[i]->getName() << edges[j].getNode()->getName() << "(" << edges[j].getWeight() << ")";
				}

				std::cout << std::endl;
			}
		}

		int size()
		{
			return nodes.size();
		}

		bool empty()
		{
			return nodes.empty();
		}

		void clear()
		{
			nodes.clear();
		}
	private:
		std::vector<Node<T>*> nodes;
};


