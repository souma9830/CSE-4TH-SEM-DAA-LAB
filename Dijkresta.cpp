#include <iostream>
using namespace std;
#define max 100
#define inf 999999

int main()
{
    int graph[max][max];
    int vertices;
    cout << "Enter the Number of Vertices: ";
    cin >> vertices;

    cout << endl
         << "Enter the adjacency elemtn: ";

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        }
    }

    int visited[max];
    int distance[max];

    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
        distance[i] = inf;
    }

    int source;
    cout << endl
         << "Enter the Source vertex: ";
    cin >> source;
    distance[source] = 0;

    for (int count = 0; count < vertices - 1; count++)
    {
        int min = inf;
        int u = -1;

        for (int v = 0; v < vertices; v++)
        {
            if (visited[v] == 0 && distance[v] < min)
            {
                min = distance[v];
                u = v;
            }
        }
        visited[u] = 1;

        for (int v = 0; v < vertices; v++)
        {
            if (graph[u][v] && visited[v] == 0 && distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = graph[u][v] + distance[u];
            }
        }
    }

    cout << "\nShortest distances from source vertex " << source << ":\n";

    for (int i = 0; i < vertices; i++)
    {
        cout << source << "  -->>  " << i << " ==" << distance[i] << endl;
    }
}