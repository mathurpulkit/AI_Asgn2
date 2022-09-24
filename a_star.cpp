#include"a_star.h"

using namespace std;

vector<int> a_star(vector<vector<int>> graph, int startingPoint) {
    // implement the A* algorithm on the graph to solve the traveling salesman problem
    // heuristic function is using prim on the nodes that are not visited, and the startingPoint
    // return the path that the salesman should take
    vector<int> ans;
    // create the vector to track the path, it gets continuously modified as the algorithm progresses
    vector<int> path;
    path.push_back(startingPoint);
    // create the expanded list to track the nodes that have been expanded
    set<vector<int>> expanded; // expanded[i] stores the path that has been expanded, eg: 1,2,5,4
    // create the priority queue to store the nodes that are to be expanded, it should store path, judge by cost of path
    
    // loop till the path is not complete or the priority queue is not empty
    while(path.size() != graph.size() && !pq.empty()) {
        // get the path from the top of the priority queue
        vector<int> temp = pq.top();
        pq.pop();
        // check if the path has already been expanded
        if (expanded.find(temp) != expanded.end()) {
            continue;
        }
        // add the path to the expanded list
        expanded.insert(temp);
        // get the last node in the path
        int lastNode = temp[temp.size() - 1];
        // loop through all the nodes in the graph
        for (int i = 0; i < graph.size(); i++) {
            // check if the node is already in the path
            if (find(temp.begin(), temp.end(), i) != temp.end()) {
                continue;
            }
            // create a new path by adding the node to the current path
            vector<int> newPath = temp;
            newPath.push_back(i);
            // calculate the cost of the path
            int cost = 0;
            for (int j = 0; j < newPath.size() - 1; j++) {
                cost += graph[newPath[j]][newPath[j + 1]];
            }
            // add the heuristic cost to the cost
            // create the subgraph of unexpanded nodes
            vector<vector<int>> subgraph;
            for (int j = 0; j < graph.size(); j++) {
                if (find(newPath.begin(), newPath.end(), j) == newPath.end()) {
                    subgraph.push_back(graph[j]);
                }
            }
            // add the mst cost to the cost
            cost += prim(subgraph, i);
            // add the path and cost to the priority queue
            pq.push({cost, newPath});
        }
    }
    return ans;
}