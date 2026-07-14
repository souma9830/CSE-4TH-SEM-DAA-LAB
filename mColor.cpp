#include<iostream>
#include<vector>
using namespace std;
#define max 100
bool isSafe(int node,int color[],bool graph[max][max],int n, int col){
    for(int k=0;k<n;k++){
        if(k!=node && graph[k][node]==1 && color[k]==col){
            return false;
        }
    }
    return true;
}
bool solve(int node,int color[],int m,int n,bool graph[max][max]){
    if(node==n){
        return true;
    }

    for(int col=1;col<=m;col++){
        if(isSafe(node,color,graph,n,col)){
            color[node]=col;

            if(solve(node+1,color,m,n,graph)){
                return true;
            }
            color[node]=0;
        }
    }
    return false;

}

int main(){
    int n;
    cout<<"Enter the number of Vertices: ";
    cin>>n;
    bool graph[max][max];
    cout<<endl<<"Enter the Adjacency List: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }

    int m;
    cout<<endl<<"Enter the Number Of color: ";
    cin>>m;
    int color[max]={0};

    if(solve(0,color,m,n,graph)){
        cout<<endl<<"Color assign: "<<endl;
        for(int i=0;i<n;i++){
            cout<<"Vertex: "<<i<<" -->color: "<<color[i]<<endl;
        }
    }
    else{
        cout<<"not found ";
    }
}