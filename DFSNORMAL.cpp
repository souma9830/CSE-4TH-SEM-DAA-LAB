#include<iostream>
using namespace std;
#define max 100

int stackarr[max];
int top=-1;

void push(int val){
    if(top==max-1){
        cout<<"Stack overflow"<<endl;
    }
    stackarr[++top]=val;
}

int pop(){
    if(top==-1) return -1;
    return stackarr[top--];
}
bool isempty(){
    return top==-1;
}

void DFS(int graph[max][max],int verties,int start){
    int visited[max]{0};
    push(start);
    while(!isempty()){
        int current=pop();
        if(visited[current]==0){
            visited[current]=1;
            cout<<current;

            for(int i=verties-1;i>=0;i--){
                if(graph[current][i]==1 && visited[i]==1){
                    push(i);
                }
            }
        }
    }
}

int main()
{
    int graph[max][max];
    int vertices;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "\nEnter the Adjacency Matrix elements:\n";

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "\nEnter the starting index: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(graph, vertices, start);

    return 0;
}