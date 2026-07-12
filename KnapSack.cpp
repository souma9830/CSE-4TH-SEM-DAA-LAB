#include <iostream>
using namespace std;
struct Item
{
    int profit;
    int weight;
    float ratio;
};

int main()
{
    int n;
    cout << "Number of Element: ";
    cin >> n;
    Item items[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter The Profit and Weight of item: " << i + 1 << " : ";
        cin >> items[i].profit >> items[i].weight;
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    int capacity;
    cout << "Enter The Capacity Of The KnapSack: ";
    cin >> capacity;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        if(items[j].ratio<items[j+1].ratio)
        {
            Item temp = items[j];
            items[j] = items[j + 1];
            items[j + 1] = temp;
        }
    }
    float totalprofit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].weight < capacity)
        {
            totalprofit += items[i].profit;
            capacity -= items[i].weight;
            cout << "Complete Item With Profit: " << items[i].profit << " " << "and weight: " << items[i].weight << endl;
        }
        else
        {
            float fraction = (float)capacity / items[i].weight;
            capacity -= fraction;
            totalprofit += items[i].profit * fraction;
            cout << "Take: " << fraction * 100 << " Item With Profit: " << items[i].profit << " " << "and weight: " << items[i].weight << endl;
        }
    }
    cout << "\nMaximum Profit = " << totalprofit;
}