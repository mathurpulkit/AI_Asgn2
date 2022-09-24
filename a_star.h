#ifndef A_STAR_H
#define A_STAR_H

#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include"mst.h"

const int MAXINT = numeric_limits<int>::max();

using namespace std;

// A* search algorithm
// input: graph, starting point
// output: path
// declaration for a_star function
vector<int> a_star(vector<vector<int>>, int, int&);

#endif