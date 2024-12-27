#pragma once
#include "Graph.hpp"
#include <set>
#include <map>
class AStar
{
public:
	static std::vector<std::string> Find(std::vector<Node<int>*>& nodes, Node<int>* start, Node<int>* goal)
	{
        std::vector<std::string> failure = { "FAILURE" };

        std::set<std::pair<Node<int>*, int>> openSet;

        std::map< Node<int> *, Node<int> *> cameFrom;

        std::map<Node<int>*, int> gScore; // gScore - длина пути в сторону (->CNode)
        std::map<Node<int>*, int> fScore; // fScore = gScore + Heuristic(CNode)

        for (int i = 0; i < nodes.size(); i++) {
            gScore[nodes[i]] = INT_MAX;
            fScore[nodes[i]] = INT_MAX;
        }

        gScore[start] = 0;
        fScore[start] = start->getCost();

        openSet.insert({ start, fScore[start] });

        while (!openSet.empty()) {

            Node<int>* cur = FindLowestFScoreNode(openSet);

            std::cout << "\ncur->m_Name: " << cur->getName() << std::endl;
            std::cout << "cur->fScore(): " << fScore[cur] << std::endl;
            std::cout << "goal->fScore(): " << fScore[goal] << std::endl;

            if (cur == goal) {
                return ReconstructPath(cameFrom, cur);
            }
            openSet.erase({ cur, fScore[cur] });

            for (Edge<int>& edge : cur->getEdges()) {

                int tentativeGScore = gScore[cur] + edge.getWeight();

                std::cout << "edge.m_Target: " << edge.getNode()->getName() << "; tentativeGScore = " << tentativeGScore << "; gScore[edge.m_Target] = " << gScore[edge.getNode()] << std::endl;

                if (tentativeGScore < gScore[edge.getNode()]) {
                    cameFrom[edge.getNode()] = cur;
                    gScore[edge.getNode()] = tentativeGScore;
                    fScore[edge.getNode()] = tentativeGScore + edge.getNode()->getCost();

                    bool isIn = openSet.find({ edge.getNode(), fScore[edge.getNode()]}) != openSet.end();
                    if (!isIn) {
                        openSet.insert({ edge.getNode(), fScore[edge.getNode()]});
                    }
                }

            }

        }

        return failure;

	}

    static Node<int>* FindLowestFScoreNode(std::set<std::pair<Node<int>*, int>> openSet)
    {
        Node<int>* minNode = nullptr;

        int minCost = INT_MAX;

        for (auto& item : openSet)
        {
            if (item.second < minCost)
            {
                minCost = item.second;
                minNode = item.first;
            }
        }
    }

    static std::vector<std::string>& ReconstructPath(std::map<Node<int>*, Node<int>*>& cameFrom, Node<int>* cur)
    {
        std::vector<std::string>* totalPath = new std::vector<std::string>;

        int len = 0;

        while (cameFrom.find(cur) != cameFrom.end()) {

            for (int i = 0; i < cameFrom[cur]->getEdges().size(); i++) {
                if (cameFrom[cur]->getEdges()[i].getNode()->getName() == cur->getName()) {
                    len += cameFrom[cur]->getEdges()[i].getWeight();
                }
            }

            cur = cameFrom[cur];
            totalPath->push_back(cur->getName());
        }

        std::cout << "\nДлина: " << len;

        return *totalPath;

    }

	static void PrintPath(std::vector<std::string> path)
	{
        std::reverse(path.begin(), path.end());

        for (auto& item : path)
        {
            std::cout << item << "->" << std::endl;
        }
	}
};

