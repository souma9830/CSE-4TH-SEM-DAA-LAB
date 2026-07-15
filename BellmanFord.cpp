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

    cout << "\nEnter the Adjacency Matrix:\n";

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        }
    }

    int distance[max];

    for (int i = 0; i < vertices; i++)
    {
        distance[i] = inf;
    }

    int source;
    cout << "\nEnter Source Vertex: ";
    cin >> source;

    distance[source] = 0;

    for (int count = 0; count < vertices - 1; count++)
    {
        for (int u = 0; u < vertices; u++)
        {
            for (int v = 0; v < vertices; v++)
            {
                if (graph[u][v] != 0 &&
                    distance[u] != inf &&
                    distance[u] + graph[u][v] < distance[v])
                {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }
    }

    // Check for negative cycle
    bool negativeCycle = false;

    for (int u = 0; u < vertices; u++)
    {
        for (int v = 0; v < vertices; v++)
        {
            if (graph[u][v] != 0 &&
                distance[u] != inf &&
                distance[u] + graph[u][v] < distance[v])
            {
                negativeCycle = true;
            }
        }
    }

    if (negativeCycle)
    {
        cout << "\nGraph contains Negative Weight Cycle";
    }
    else
    {
        cout << "\nShortest distances from source vertex "
             << source << ":\n";

        for (int i = 0; i < vertices; i++)
        {
            cout << source << " -> " << i
                 << " = " << distance[i] << endl;
        }
    }

    return 0;
}