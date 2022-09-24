#include"a_star.h"

using namespace std;

struct gnode {
    int cost;
    vector<int> path;
};

struct gnodepqueue {
    bool operator()(const gnode &a, const gnode &b) {
        return a.cost > b.cost;
    }
};


// implement A* search algorithm, return the path
// use prim function from mst.h as heuristic
vector<int> a_star(vector<vector<int>> graph, int startingPoint) {
    // create a priority queue, which is a min heap, represents the fringe list
    priority_queue<gnode, vector<gnode>, gnodepqueue> fringe;
    // create a set to store the visited paths
    set<vector<int>> visited;
    // initialise fringe list
    gnode start;
    start.cost = 0;
    start.path.push_back(startingPoint);
    fringe.push(start);
    // loop until fringe list is empty
    while (!fringe.empty()) {
        // get the path with the lowest cost
        vector<int> path = fringe.top().path;
        int cost = fringe.top().cost;
        // check if path is complete
        if (path.size() == graph.size()) {
            // add the starting point to the path
            path.push_back(startingPoint);
            return path;
        }
        int lastNode = path.back();
        // loop through the nodes to find children of the path graph
        for (int i = 0; i< graph.size(); i++){
            // check if i is in path
            if (find(path.begin(), path.end(), i) == path.end()) {
                if (graph[path.back()][i] == MAXINT) {
                    continue;
                }
                // create a new path
                vector<int> newPath = path;
                newPath.push_back(i);
                // check if the new path is in visited
                if (visited.find(newPath) == visited.end()) {
                    // add the new path to visited
                    visited.insert(newPath);
                    // calculate the cost of the new path
                    int newCost = cost + graph[lastNode][i] + prim(graph, i);
                    // add the new path to fringe list
                    struct gnode temp = {newCost, newPath};
                    fringe.push(temp);
                }
            }
            else {
                continue;
            }
        }
        fringe.pop();
    }
    return vector<int>();
}