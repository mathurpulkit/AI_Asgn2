#include"a_star.h"

using namespace std;

typedef pair<int, vector<int>> pq_pair;

// implement A* search algorithm, return the path
// use prim function from mst.h as heuristic
vector<int> a_star(vector<vector<int>> graph, int startingPoint) {
    // create a priority queue, which is a min heap, represents the fringe list
    priority_queue<pq_pair, vector<pq_pair>, greater<pq_pair>> fringe;
    // create a set to store the visited paths
    set<vector<int>> visited;
    // initialise fringe list
    fringe.push(make_pair(0, vector<int>(startingPoint)));
    // loop until fringe list is empty
    while(!fringe.empty()){
        // get the path with the lowest cost
        vector<int> path = fringe.top().second;
        // check if the path is already visited
        if (visited.find(path) == visited.end()) {
            // if not visited, add the path to the visited set
            visited.insert(path);
            // check if the path is a complete path
            if (path.size() == graph.size()) {
                // if the path is complete, return the path
                return path;
            }
            // if the path is not complete, expand the path
            else {
                // get the last node in the path
                int lastNode = path.back();
                // loop through the graph
                for (int i = 0; i < graph.size(); i++) {
                    // if i in path, continue
                    if (find(path.begin(), path.end(), i) != path.end()) {
                        continue;
                    }
                    // check if the node is connected to the last node in the path
                    if (graph[lastNode][i] != MAXINT) {
                        // if connected, create a new path
                        vector<int> newPath = path;
                        // add the new node to the new path
                        newPath.push_back(i);
                        // calculate the cost of the new path
                        int cost = fringe.top().first + graph[lastNode][i];
                        // create a subgraph for the unvisited nodes
                        vector<int> unvisitedNodes;
                        unvisitedNodes.push_back(i);
                        for (int j = 0; j < graph.size(); j++) {
                            if (find(path.begin(), path.end(), j) == path.end()) {
                                unvisitedNodes.push_back(j);
                            }
                        }
                        vector<vector<int>> subgraph;
                        for (int j = 0; j < unvisitedNodes.size(); j++) {
                            subgraph.insert(subgraph.begin() + j, vector<int>());
                            for (int k = 0; k < unvisitedNodes.size(); k++) {
                                subgraph[j].insert(subgraph[j].begin() + k, graph[unvisitedNodes[j]][unvisitedNodes[k]]);
                            }
                        }
                        cost += prim(subgraph, 0);
                        // add the new path to the fringe list
                        fringe.push(make_pair(cost, newPath));
                    }
                }
            }
        }
        // remove the path with the lowest cost from the fringe list
        fringe.pop();
    }
    return vector<int>();
}