#include <iostream>
using namespace std;

#define max 100
#define inf 99999

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

            if (i != j && graph[i][j] == 0)
            {
                graph[i][j] = inf;
            }
        }
    }

    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    cout << "\nShortest Distance Matrix:\n";

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (graph[i][j] == inf)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}