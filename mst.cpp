#include"mst.h"
#include<set>
using namespace std;

int prim(vector<vector<int>> graph, int startingPoint) {
    // use prim's algorithm to find the minimum spanning tree
    // initialize the minimum spanning tree
    vector<vector<int>> mst(graph.size(), vector<int>(graph.size(), 0));
    // initialize the set of visited nodes
    set<int> visited;
    // add the starting point to the set of visited nodes
    visited.insert(startingPoint);
    // while the set of visited nodes is not equal to the set of all nodes
    while(visited.size()<graph.size()){
        // initialize the minimum edge
        int minEdge = numeric_limits<int>::max();
        // initialize the minimum edge's starting point
        int minEdgeStartingPoint = 0;
        // initialize the minimum edge's ending point
        int minEdgeEndingPoint = 0;
        // for each node in the set of visited nodes
        for (int i = 0; i < graph.size(); i++) {
            if (visited.find(i) != visited.end()) {
                // for each node in the graph
                for (int j = 0; j < graph.size(); j++) {
                    // if the node is not in the set of visited nodes
                    if (visited.find(j) == visited.end()) {
                        // if the edge is smaller than the minimum edge
                        if (graph[i][j] < minEdge) {
                            // update the minimum edge
                            minEdge = graph[i][j];
                            // update the minimum edge's starting point
                            minEdgeStartingPoint = i;
                            // update the minimum edge's ending point
                            minEdgeEndingPoint = j;
                        }
                    }
                }
            }
        }
        // add the minimum edge to the minimum spanning tree
        mst[minEdgeStartingPoint][minEdgeEndingPoint] = minEdge;
        mst[minEdgeEndingPoint][minEdgeStartingPoint] = minEdge;
        // add the minimum edge's ending point to the set of visited nodes
        visited.insert(minEdgeEndingPoint);
    }
    // calculate the total weight of the minimum spanning tree
    int totalWeight = 0;
    for (int i = 0; i < mst.size(); i++) {
        for (int j = 0; j <= i; j++) {
            totalWeight += mst[i][j];
        }
    }
    // return the total weight of the minimum spanning tree
    return totalWeight;
}