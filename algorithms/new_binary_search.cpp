#include <iostream>
using namespace std;
int getPivot(int arr[],int n){
  int l = 0;
  int h = n-1;
  int mid = l + (h-l)/2;
  while(l<h){
    if(arr[mid]>=arr[0]){
       l = mid+1;
    }  
    else
       h = mid;
    mid = l + (h-l)/2;
  }
  return l;
}
int pivotIndex(int a[],int n){
  int i=0,j=n-1;
  int sum1=0,sum2=0;
  int mid = i + (j-i)/2;
  // cout<<mid<<endl;
  while(i<=j){
    for (int it = 0; it <= mid-1; it++)
       sum1+=a[it];
    for (int it = mid+1; it <= n-1; it++)
       sum2+=a[it];
    
    if(sum1>sum2)
       j = mid-1;
    else if(sum1<sum2) 
       i = mid+1;
    mid = i + (j-i)/2;
    // // sum1 = 0;
    // // sum2 = 0;
    // cout<<"mid:"<<mid<<",i:"<<i<<",j:"<<j<<",sum1:"<<sum1<<",sum2:"<<sum2<<endl;
    if(sum1==sum2)
       return mid;
    // sum1 = 0;
    // sum2 = 0;
  }
  return -1;
}
int peakIndex(int a[],int n){
  int i = 0;
  int j = n-1;
  int mid = i + (j-i)/2;
  while(i<j){
    if(a[mid]<a[mid+1]){
      i = mid + 1;
    }
    else{
      j = mid;
    }
    mid = i + (j-i)/2;
  }
   return i;
}

int firstOcc(int a[],int n,int k){
    int l = 0;
    int h = n-1;
    int ans1;
    int mid = l + (h-l)/2;
    while (l<=h)
    {
        if(a[mid]==k){
            ans1 = mid;
            h = mid -1;
        }
        else if (k>a[mid])
        {
          l = mid+1;
        }
        else if (k<a[mid])
        {
          h = mid-1;
        }
        mid = l + (h-l)/2;
    }
}
int LastOcc(int a[],int n,int k){
    int l = 0;
    int h = n-1;
    int ans2 = -1;
    int mid = l + (h-l)/2;
    while (l<=h)
    {
        if(a[mid]==k){
            ans2 = mid;
            l = mid+1;
        }
        else if (k>a[mid])
        {
          l = mid+1;
        }
        else if (k<a[mid])
        {
          h = mid-1;
        }
        mid = l + (h-l)/2;
    }
    return ans2;
}
int B_S(int a[],int n,int k){
    int l = 0;
    int h = n-1;
    int mid = l + (h-l)/2;
    while (l<=h)
    {
        if(a[mid]==k)
          return mid;
        else if (k>a[mid])
        {
          l = mid+1;
        }
        else if (k<a[mid])
        {
          h = mid-1;
        }
        mid = l + (h-l)/2;
    }
    return -1;
}
int main(){
    int a[10]={1,3,5,6,7,8,11,14,17,18};
    int ne[7] = {1,2,3,3,3,4,5};
    int p[4] = {0,10,5,0};
    int ip[6] = {1,7,3,6,5,6};
    int test[5]={3,8,10,17,1};
    // int r = B_S(a,10,17);
    // cout<<"17 is at "<<r+1<<"ind";
    // int ans1 = firstOcc(ne,8,3);
    // int ans2 = LastOcc(ne,7,3);
    // cout<<"first most occurance : "<<ans1<<endl;
    // cout<<"last most occurance : "<<ans2<<endl;
    // cout<<"number of occurance : "<<ans2-ans1<<endl;
    // int res = peakIndex(p,4);
    // cout<<"The peak Index is at "<<res<<endl;
    // int pai = pivotIndex(test,3);
    // cout<<pai<<endl;
    //  int sciew = getPivot(test,5);
    //   cout<<sciew<<endl;
}