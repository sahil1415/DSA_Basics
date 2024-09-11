#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Graph{
    // public:
    int vertices;
    vector<vector<int>> adjList;
    public: 

    // constructor initializing the no of vertices
    // and the size of the adjacency list vector
    Graph(int vertices){
        this->vertices = vertices;

        adjList.resize(vertices);
    }
    
    // adding a edge in the graph
    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // printing the adjacency list 
    void printAdjacencyList(){
        for(int i = 0; i<vertices; i++){
            cout<<"Adjacency List of vertex "<<i<<" : ";
            for(int neighbour : adjList[i]){
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }
    }

    // BFS traversal of graph
    void bfsTraversal( int startVertex){
        vector<bool> visited (vertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);
        while(!q.empty()){
            int vertex = q.front();
            cout<<vertex<<" ";
            q.pop();

            for(int neighbour: adjList[vertex]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

    }
};

int main(){
    // creating a graph
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,5);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.printAdjacencyList();

    cout<<endl;
    cout<<"Traversing the graph - "<<endl;
    g.bfsTraversal(0);
}