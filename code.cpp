#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Vertex {
    int color; 
    vector<int> neighbors; 
};


void graphColoring(vector<Vertex>& graph) {
    int n = graph.size(); 
    int color = 1; 

    
    for (int i = 0; i < n; ++i) {
        if (graph[i].color != 0) continue; 

        
        bool available[n+1]; 
        fill(available, available + n+1, true);
        for (int neighbor : graph[i].neighbors) {
            if (graph[neighbor].color != 0) {
                available[graph[neighbor].color] = false;
            }
        }

        
        for (int c = 1; c <= n; ++c) {
            if (available[c]) {
                graph[i].color = c;
                break;
            }
        }
    }
}


void printColors(const vector<Vertex>& graph) {
    for (int i = 0; i < graph.size(); ++i) {
        cout << "Vertex " << i << " -> Color " << graph[i].color << endl;
    }
}

int main() {
    
    vector<Vertex> graph = {
        {0, {1, 2}},
        {0, {0, 3}},
        {0, {0}},
        {0, {1}}
    };

    graphColoring(graph);
    printColors(graph);

    return 0;
}