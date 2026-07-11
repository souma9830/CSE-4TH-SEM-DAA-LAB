#include<iostream>
using namespace std;
struct maxMin
{
    int max;
    int min;
};

maxMin findmaxmin(int arr[], int low, int high){
    maxMin result,right,left;
    if(low==high){
        result.max=result.min=arr[low];
        return result;
    }
    else if(high==low+1){
        if(arr[low]<arr[high]){
            result.max=arr[high];
            result.min=arr[low];
            return result;
        } 
        else{
            result.max=arr[low];
            result.min=arr[high];
            return result;
        }
    }
    int mid=(low+high)/2;
    left= findmaxmin(arr,low,mid);
    right=findmaxmin(arr,mid+1,high);

    result.min=(left.min<right.min)? left.min:right.min;
    result.max=(left.max>right.max)?left.max:right.max;
    return result;
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

    maxMin result=findmaxmin(arr,0,n-1);
    cout<<"The Min element in the array is: "<<result.min<<endl;
    cout<<"The Max Element in the array is : "<<result.max;

}