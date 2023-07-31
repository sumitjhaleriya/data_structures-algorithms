
#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[],int n){
  for(int i = 0;i<n;i++){
    cout<< arr[i] <<" ";
  }
}
void Sort01(int arr[],int n){
  int a=0;
  int b=n-1;
  while(a<b){
    if(arr[a]==0 && a<b)
      a++;
    if(arr[b]==1 && a<b)
      b--;
    if(arr[a]==1 && arr[b]==0 && a<b){
      swap(arr[a],arr[b]);
      a++;
      b--;
    }
  }
  printArray(arr,n);
}
void Sort012(int a[],int n){
   int lo = 0;
    int hi = n - 1;
    int mid = 0;
  
    // Iterate till all the elements
    // are sorted
    while (mid <= hi) {
        switch (a[mid]) {
  
        // If the element is 0
        case 0:
            swap(a[lo++], a[mid++]);
            break;
  
        // If the element is 1 .
        case 1:
            mid++;
            break;
  
        // If the element is 2
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
         printArray(a,n);
         cout<<endl;
    }
  printArray(a,n);
}
void FindUnique(int arr[],int n){
  int xo = 0;
  for(int i =0;i<n;i++){
    xo = xo^arr[i];
  }
  cout<<"The unique element is :"<<xo<<endl;
}
void FindDuplicates(int arr[],int n){
  int xo = 0;
  
  for(int i =0;i<n;i++){
    xo = xo^arr[i];
  }
  for(int i =1;i<n;i++){
    xo = xo^i;
  }
  cout<<"The duplicate element is :"<<xo<<endl;
}

void Swapalternate(int arr[],int n){
   for(int i =0;i<n;i=i+2){
      if(i+1<n){
        swap(arr[i],arr[i+1]);
      }
   }
  printArray(arr,n); 
}

void ReverseArray(int arr[],int n){
  int low = 0;
  int high = n-1;
  while(low<high){
    swap(arr[low],arr[high]);
    low++;
    high--;
  }
  printArray(arr,n);
}

int main()
{
    int size;
    cout<<"Enter the size :"<<endl;
    cin >>size;
    int arr[size] ;
    for(int i = 0; i<size;i++){ 
     cin>> arr[i];
    } 
    //ReverseArray(arr,size);
    //Swapalternate(arr,size);
    //FindUnique(arr,size);
    //FindDuplicates(arr,size);
    Sort012(arr,size);
    return 0;
}