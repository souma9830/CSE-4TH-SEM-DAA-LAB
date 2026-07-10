#include <iostream>
using namespace std;
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftarr[n1];
    int rightarr[n2];

    for (int i = 0; i < n1; i++)
    {
        leftarr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightarr[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftarr[i] < rightarr[j])
        {
            arr[k] = leftarr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = rightarr[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

    mergesort(arr, 0, n - 1);

    cout << "After Sorting the array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}