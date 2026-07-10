#include <iostream>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int res = partition(arr, low, high);
        quicksort(arr, low, res - 1);
        quicksort(arr, res + 1, high);
    }
}
int main()
{
    int n;
    cout << "Enter The Number of element in the array: ";
    cin >> n;
    int arr[n];
    cout << endl
         << "Enter the array element: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);
    cout << "After Sorting the array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}