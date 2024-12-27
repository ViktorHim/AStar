#pragma once
#include "Node.hpp"

template <typename T>
class Edge
{
	public:
		Edge(T weight, Node<T> * to) : weight(weight), to(to)
		{

		}

		void setWeight(T weight)
		{
			this->weight = weight;
		}

		T getWeight()
		{
			return weight;
		}

		Node<T> * getNode()
		{
			return to;
		}

	private:
		Node<T> * to;
		T weight;
};



