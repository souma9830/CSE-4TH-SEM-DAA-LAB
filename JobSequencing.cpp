#include <iostream>
using namespace std;

struct Job
{
    char id;
    int profit;
    int deadline;
};

int main()
{
    int n;
    cout << "Enter the Number of Job: ";
    cin >> n;
    Job job[100];
    cout << "Enter the Job Details Job id job profit and job deadline: ";
    for (int i = 0; i < n; i++)
    {

        cin >> job[i].id >> job[i].profit >> job[i].deadline;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (job[j].profit < job[j + 1].profit)
            {
                Job temp = job[j];
                job[j] = job[j + 1];
                job[j + 1] = temp;
            }
        }
    }

    int maxdeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxdeadline < job[i].deadline)
        {
            maxdeadline = job[i].deadline;
        }
    }

    int slot[100];

    for (int i = 0; i < maxdeadline; i++)
    {
        slot[i] = -1;
    }

    int totalprofit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = job[i].deadline - 1; j >= 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                totalprofit += job[i].profit;
                break;
            }
        }
    }

    for (int i = 0; i < maxdeadline; i++)
    {
        if (slot[i] != -1)
        {
            cout << job[slot[i]].id << " ";
        }
    }
    cout << "Total Profit: " << totalprofit;
}
