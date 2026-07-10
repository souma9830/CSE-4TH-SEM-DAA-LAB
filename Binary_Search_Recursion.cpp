#include<iostream>
using namespace std;
int binarysearch(int arr[],int left,int right,int key){
    if(left>right) return -1;
    int mid=left+(right-left)/2;
    if(arr[mid]==key) return mid;
    else if(key<arr[mid]){
       return binarysearch(arr,left,mid-1,key);
    }
    else{
       return binarysearch(arr,mid+1,right,key);
    }


}

int main(){
    int n;
    cout<<"Enter The Number Of element: ";
    cin>>n;
    int arr[n];
    cout<<endl<<"Enter The Elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Which element You want to find in the Array: ";
    cin>>k;

   int m= binarysearch(arr,0,n-1,k);
   if(m!=-1){
    cout<<"Element Found in the Array and the Position is: "<<m;
   }
   else{
    cout<<"Element not found in the Array";
   }
}