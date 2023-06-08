#include <iostream>
#include <vector>
using namespace std;

struct Node{
    //data type int called label
    int label;
};

    
struct Graph{
    
    int n; //number of nodes
    Node * nodes; //list of nodes
    vector< vector <int>> adjacencyMatrix;

    Graph(int numberofnodes){
        n=numberofnodes;
        //create the n*n adjacency matrix
        nodes = new Node[n];
        adjacencyMatrix.resize(n, vector<int>(n, 0));
    }  

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){
            nodes[i].label=i;
        }
    }

    void addedge(int u, int v, int weight){
        //add the element to the matrix
        adjacencyMatrix[u][v]=weight;
        adjacencyMatrix[v][u]=weight;
    }

    bool search(int i, vector<Node>& list){
        for(int j=0; j<list.size(); j++){
            if(list[j].label==i){
                return true;
            }
        }
        return false;
    }

    //implement prim's MST algorithm
    vector< vector<int>> primMST(int root){

        cout<<"Prim's MST starting from node "<<root<<endl;

        int minCost = 0;
        vector<Node> MST;
        MST.push_back(nodes[root]);
        vector< vector <int>> edges;

        while (MST.size()<n){ //while there is nodes left to visit
            int minWeight = INT_MAX;
            int parentIndex = -1;
            int minWeightNodeIndex = -1;

            for(Node parent : MST){ //iterate through MST
                for(int j=0; j<n; j++){ //iterate through all nodes to check edges with node i
                    
                    if((adjacencyMatrix[parent.label][j]!=0) && (adjacencyMatrix[parent.label][j]<minWeight) && !(search(j,MST))){ //if there is an edge to unvisited node j and if it is minimum
                        
                        minWeight = adjacencyMatrix[parent.label][j]; //set the minimum weight to the weight of the edge
                        minWeightNodeIndex = j; //set the minimum weight index to the index of the node j
                        parentIndex = parent.label; //set the parent index to the index of the node i
                    }
                }
            }
            cout<<"Edge : ("<<parentIndex<<","<<minWeightNodeIndex<<") weight : "<<minWeight<<endl;	
            minCost+=minWeight; //add the minimum weight to the minimum cost
            MST.push_back(nodes[minWeightNodeIndex]); //add the node mith minimum weight to the MST
            edges.push_back({parentIndex,minWeightNodeIndex}); //add the edge to the edges list
        }
        cout<<"Minimum cost : "<<minCost<<endl;
        return edges;
    }        
};

int main() {
    Graph * g = new Graph(6);
    g->intializenodes();
    //add edges for the graphs here.
    g->addedge(0,1,3);
    g->addedge(1,2,2);
    g->addedge(2,3,3);
    g->addedge(3,4,5);
    g->addedge(4,5,4);
    g->addedge(5,0,1);
    g->addedge(1,4,10);
    g->addedge(1,3,1);
    g->addedge(2,5,5);

    g->primMST(0);
    
    return 0;
}