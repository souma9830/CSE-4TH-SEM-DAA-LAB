#include <iostream>
using namespace std;
#define max 100

void dfs(int graph[max][max], int visited[], int current, int vertices)
{
    visited[current] = 1;
    cout << current << " ";

    for (int i = 0; i < vertices; i++)
    {
        if (graph[current][i] == 1 && visited[i] == 0)
        {
            dfs(graph, visited, i, vertices);
        }
    }
}
int main()
{
    int graph[max][max];
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << endl
         << "Enter the array element: " << endl;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        }
    }
    int visited[max] = {0};
    int start;
    cout << "Enter the start vertices: ";
    cin >> start;
    cout << "After DFS: ";
    dfs(graph, visited, start, vertices);
}