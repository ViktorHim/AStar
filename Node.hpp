#pragma once
#include <vector>

template <typename T>
class Edge;

template <typename T>
class Node
{
	public:
		Node(std::string name, T cost) : cost(cost), name(name)
		{

		}

		void setCost(T cost)
		{
			this->cost = cost;
		}

		T getCost()
		{
			return cost;
		}

		std::string getName()
		{
			return name;
		}

		std::vector<Edge<T>>& getEdges()
		{
			return edges;
		}

		Node<T>& operator+=(const Edge<T>& other)
		{
			this->edges.push_back(other);

			return *this;
		}
	private:
		T cost;
		std::string name;
		std::vector<Edge<T>> edges;
};

