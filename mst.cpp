#include"mst.h"

using namespace std;

int prim(vector<vector<int>> graph, int startingPoint) {
    // initialize the open list
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> openList;
    // initialize the closed list
    vector<bool> closedList(graph.size(), false);
    // initialize the path
    vector<int> path;
    // add the starting point to the open list
    openList.push(make_pair(0, startingPoint));
    // while the open list is not empty
    while (!openList.empty()) {
        // get the node with the lowest f value from the open list
        int currentNode = openList.top().second;
        openList.pop();
        // add the node to the closed list
        closedList[currentNode] = true;
        // if the node is the goal node
        if (path.size() == graph.size()) {
            // add the node to the path
            path.push_back(currentNode);
            // return the path cost
            //return path;
            int ans=0;
            for(int i = 0; i < path.size(); i++) {
                ans += path[i];
            }
            return ans;
        }
        // for each neighbor of the node
        for (int i = 0; i < graph.size(); i++) {
            // if the neighbor is not in the closed list
            if (!closedList[i]) {
                // if the neighbor is not in the open list
                if (graph[currentNode][i] != 0 && graph[currentNode][i] != numeric_limits<int>::max()) {
                    // add the neighbor to the open list
                    openList.push(make_pair(graph[currentNode][i], i));
                }
            }
        }
    }
    // return the path length
    //return path;
    int ans=0;
    for(int i=0;i<path.size();i++){
        ans+=path[i];
    }
    return ans;
}