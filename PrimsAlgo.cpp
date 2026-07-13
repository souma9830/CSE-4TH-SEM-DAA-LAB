#include<iostream>
using namespace std;
#define MAX 100
#define INF 999999
int main(){
    int graph[MAX][MAX];
    int vertices;
    cout<<"Enter the Number of vertices: ";
    cin>>vertices;

    cout<<endl<<"Enter the Adjacency Matrix: "<<endl;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cin>>graph[i][j];
        }
    }

    int parent[MAX];
    int visited[MAX];
    int key[MAX];

    for(int i=0;i<vertices;i++){
        key[i]=INF;
        visited[i]=0;
    }

    parent[0]=-1;
    key[0]=0;

    for(int count=0;count<vertices-1;count++){

        int min=INF;
        int u;

        for(int v=0;v<vertices;v++){
            if(visited[v]==0 && key[v]<min){
                min=key[v];
                u=v;
            }
        }

        visited[u]=1;

        for(int v=0;v<vertices;v++){
            if(graph[u][v] && visited[v]==0 && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }

    int toatalcost=0;
    cout<<"\n Edge in MIN spanning tree: "<<endl;
    for(int i=1;i<vertices;i++){
        cout<<parent[i]<<" - "<<i<<" : "<<graph[i][parent[i]]<<endl;
        toatalcost+=graph[i][parent[i]];
    }

    cout<<"Total cost is: "<<toatalcost;
}