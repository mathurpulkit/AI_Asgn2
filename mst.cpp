#include"mst.h"
#include<set>
using namespace std;

int prim(vector<vector<int>> graph, int startingPoint) {
    vector<vector<int>> mst(graph.size(), vector<int>(graph.size(), 0));
    set<int> visited;
    visited.insert(startingPoint);
    while(visited.size()<graph.size()){
        int minEdge = numeric_limits<int>::max();
        int minEdgeStartingPoint = 0;
        int minEdgeEndingPoint = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (visited.find(i) != visited.end()) {
                for (int j = 0; j < graph.size(); j++) {
                    // if the node is not in the set of visited nodes
                    if (visited.find(j) == visited.end()) {
                        if (graph[i][j] < minEdge) {
                            minEdge = graph[i][j];
                            minEdgeStartingPoint = i;
                            minEdgeEndingPoint = j;
                        }
                    }
                }
            }
        }
        mst[minEdgeStartingPoint][minEdgeEndingPoint] = minEdge;
        mst[minEdgeEndingPoint][minEdgeStartingPoint] = minEdge;
        visited.insert(minEdgeEndingPoint);
    }
    int totalWeight = 0;
    for (int i = 0; i < mst.size(); i++) {
        for (int j = 0; j <= i; j++) {
            totalWeight += mst[i][j];
        }
    }
    // return the total weight of the minimum spanning tree
    return totalWeight;
}