// program to take undirected graph and the starting point as an input, solve the TSP problem, and print the solution

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include"a_star.h"
#include"mst.h"

using namespace std;

// function to read the input file and store the graph in a 2D vector
void readInputFile(ifstream &inp_file, vector<vector<int>> &graph) {
    string line;
    int i = 0;
    while (getline(inp_file, line)) {
        istringstream iss(line);
        int j = 0;
        graph.insert(graph.begin() + i, vector<int>());
        for (string line; iss >> line;) {
            string temp = line;
            if (temp == "inf") {
                graph[i].insert(graph[i].begin() + j, MAXINT);
            }
            else {
                graph[i].insert(graph[i].begin() + j, stoi(temp));
            }
            j++;
        }
        i++;
    }
}

void printGraph(vector<vector<int>> graph) {
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    // check if the input file is provided
    // read the input file and store the graph in a 2D vector
    vector<vector<int>> graph;
    ifstream inputFile;
    int startingPoint;
    if (argc == 3){
        inputFile.open(argv[1]);
        readInputFile(inputFile, graph);
        startingPoint = stoi(argv[2]);
    }
    else {
        cout << "Please provide the input file and the starting point as an argument" << endl;
        string filename;
        cin >> filename;
        cin >> startingPoint;
        inputFile.open(filename);
        readInputFile(inputFile, graph);
    }
    // print the graph
    printGraph(graph);
    // solve the TSP problem
    // get the path from the a_star function
    vector<int> path = a_star(graph, startingPoint);
    // print the solution
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    return 0;
}