#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int partition(int arr[],int low,int high){
    int pivotidx=low+ rand()% (high-low+1);
    swap(arr[pivotidx],arr[high]);
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int index=partition(arr,low,high);
        quicksort(arr,low,index-1);
        quicksort(arr,index+1,high);
    }
}

int main(){
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