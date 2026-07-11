#include<iostream>
using namespace std;
#define max 100

int front=-1;
int rear=-1;
int adjmat[max];

void enqueue(int value){
    if(rear==max-1){
        cout<<"Queue Overflow "<<endl;
    }
    if(front==-1){
        front=0;
    }
    adjmat[++rear]=value;
}

int deque(){
    if(front==-1 || front>rear){
        return -1;
    }
    return adjmat[front++];
}

bool isempty(){
    return front==-1 || front>rear;
}

void BFS(int graph[max][max],int vertices,int start){

    int visited[max]={0};
    visited[start]=1;
    enqueue(start);
    while (!isempty())
    {
        int current=deque();
        cout<<current<<" ";
        for(int i=0;i<vertices;i++){
            if(graph[current][i]==1 && visited[i]==0){
                visited[i]=1;
                enqueue(i);
            }
        }
    }
    


}

int main(){
    int graph[max][max];
    int vertices;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    cout<<endl<<"Enter the array element: "<<endl;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cin>>graph[i][j];
        }
    }

    int start;
    cout<<endl<<"Enter the starting index: ";
    cin>>start;
    cout<<"BFS Traversal: ";
    BFS(graph,vertices,start);

}