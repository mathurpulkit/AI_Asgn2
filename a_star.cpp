#include"a_star.h"

using namespace std;

vector<int> a_star(vector<vector<int>> graph, int startingPoint) {
    // use prim as the heuristic function
    // use prim to get the MST of the subgraph of all the nodes not visited yet, and the starting point
    // initialize the open list
    set <pair<int, int>> openList;
    // initialize the closed list
    set <int> closedList;
    // initialize the path
    vector<int> path;
    // add the starting point to the open list
    openList.insert(make_pair(0, startingPoint));
    // while the open list is not empty
    while (!openList.empty()) {
        // get the node with the lowest f value from the open list
        int currentNode = openList.begin()->second;
        // add the node to the closed list
        closedList.insert(currentNode);
        // remove the node from the open list
        openList.erase(openList.begin()); // GIVES WRONG ANSWER, BUT THIS IS PROBABLY RIGHT
        if (closedList.size() == graph.size()) {
            // add the node to the path
            path.push_back(currentNode);
        }
        // for each neighbor of the node
        for (int i = 0; i < graph.size(); i++) {
            // if the neighbor is not in the closed list
            if (closedList.find(i) == closedList.end()) {
                // if the neighbor is not in the open list
                if (graph[currentNode][i] != 0 && graph[currentNode][i] != numeric_limits<int>::max()) {
                    // add the neighbor to the open list
                    // compute the heuristic value
                    // get the subgraph of all the nodes not visited yet, and the starting point
                    vector<vector<int>> subGraph(graph.size(), vector<int>(graph.size(), 0));
                    for (int j = 0; j < graph.size(); j++) {
                        for (int k = 0; k < graph.size(); k++) {
                            if (closedList.find(j) == closedList.end() && closedList.find(k) == closedList.end()) {
                                subGraph[j][k] = graph[j][k];
                            }
                        }
                    }
                    // starting point for the prim is the neighbor
                    openList.insert(make_pair(graph[currentNode][i] + prim(subGraph, i), i));
                }
                // if the neighbor is in the open list
                else {
                    // if the neighbor's g value is greater than the current g value
                    // compute the heuristic value
                    // get the subgraph of all the nodes not visited yet, and the starting point
                    vector<vector<int>> subGraph(graph.size(), vector<int>(graph.size(), 0));
                    for (int j = 0; j < graph.size(); j++) {
                        for (int k = 0; k < graph.size(); k++) {
                            if (closedList.find(j) == closedList.end() && closedList.find(k) == closedList.end()) {
                                subGraph[j][k] = graph[j][k];
                            }
                        }
                    }
                    if (graph[currentNode][i] + prim(subGraph, i) < graph[currentNode][i]) {
                        // update the neighbor's g value
                        graph[currentNode][i] = graph[currentNode][i] + prim(subGraph, i);
                        // update the neighbor's parent
                        graph[i][currentNode] = currentNode;
                    }
                }
            }
        }
    }
    // return the path
    // convert set to vector for returning
    return path;
}