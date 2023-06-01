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

    vector<int> Dijstra(int Source){
        vector<Node> PriorityQueue;
        vector<int> distance;
        vector<int> parent;

        for(int i=0; i<n; i++){
            //initialize the distance to infinity and parent nodes to -1
            distance.push_back(INT_MAX);
            parent.push_back(-1);
        }

        distance[Source]=0; //distance from source to source is 0
        PriorityQueue.push_back(nodes[Source]); //add the source to the priority queue

        while(!PriorityQueue.empty()){

            int u = PriorityQueue[0].label;
            PriorityQueue.erase(PriorityQueue.begin()); //dequeue

            for(int i=0; i<n; i++){
                if(adjacencyMatrix[u][i]!=0){
                    if(distance[i]>distance[u]+adjacencyMatrix[u][i]){
                        distance[i]=distance[u]+adjacencyMatrix[u][i];
                        parent[i]=u;

                        if(!search(i, PriorityQueue)){
                            PriorityQueue.push_back(nodes[i]); //enqueue
                        }
                    }
                }
            }
        }

        return distance;
    }

    void printDetails(int Source){

        vector<int> distance = Dijstra(Source);
        double sum=0;
        for(int i=0; i<n; i++){
            if(i==Source){continue;}
            cout<<"Shortest time from "<<Source<<" to "<<i<<" is "<<distance[i]<<endl;
            sum+=distance[i];
        }
        cout<<"\nAverage time is "<<sum/(n-1)<<"\n"<<endl;
    }
          
};

int main() {
    Graph * g = new Graph(6);
    g->intializenodes();
    //add edges for the graphs here.
    g->addedge(0,1,10);
    g->addedge(0,4,15);
    g->addedge(0,5,5);
    g->addedge(1,2,10);
    g->addedge(1,3,30);
    g->addedge(2,4,5);
    g->addedge(2,3,12);
    g->addedge(3,5,20);

    g->printDetails(5); //change the source here

    return 0;
}