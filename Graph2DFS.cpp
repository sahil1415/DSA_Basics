#include<iostream>
#include<stack>
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

    // DFS traversal of graph
    void dfsTraversal(int startVertex){
        vector<bool> visited(vertices, false);
        stack<int> s;
        visited[startVertex] = true;
        s.push(startVertex);

        while(!s.empty()){
            int vertex = s.top();
            cout<<vertex<<" ";
            s.pop();
        for(int neighbour : adjList[vertex]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                s.push(neighbour);
            }
        }
    }
}
};

int main(){
    // creating a graph
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    g.addEdge(2,4);
    g.addEdge(4,6);
    g.addEdge(4,5);
    g.printAdjacencyList();
    cout<<endl;
    cout<<"Traversing the graph - "<<endl;
    g.dfsTraversal(0);
}