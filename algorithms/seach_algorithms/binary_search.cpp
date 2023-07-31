#include<iostream>
using namespace std;
int Binary_Search(int a[],int n,int k)
{
   int l = 0;
   int r = n-1;
   int mid = l + (r-l)/2;
   int res;
   while(l<r)
   {
     if(a[mid]==k)
       res = mid;
     else if(k>a[mid]){
       l = mid +1;
     }
     else if(k<a[mid]){
       r = mid-1;
     }
      mid = l + (r-l)/2;
   }
   return res;
}
int main(){
  int arr[10]={1,3,5,7,8,11,13,15,17,18};
  int res = Binary_Search(arr,10,15);
  cout<<"15 is on "<<res<<"index"<<endl;
}
























// #include <iostream>
// #include <vector>
// using namespace std;
// int Binary_Search(vector<int>,int,int);
// int BinarySearch(vector<int>,int,int,int);
// int main()
// {
//     vector<int>array;
//     int a;  
//     int target;
//     array={1,2,3,4,5,8,10,12};
//     target=10;
//     // cout<<("enter the array in sorted array")<<endl;
//     // for(int i =0;i<array.size();i++)
//     // {
// 	  //   cin>>a;
// 	  //   array.push_back(a);
//     // }
//     // int target;
//     // cout<<"enter the target:"<<endl;
//     // cin>>target;
//     // //int result =  BinarySearch(array,0,array.size(),target);
//     int result =  Binary_Search(array,array.size(),target);
//     cout<<"the target is on "<<result<<"place"<<endl;
//     return 0;
// }
// int BinarySearch(vector<int>a,int l,int r,int k)
// {
//    int mid = (l+r)/2;
//    int res;
//    while(l<r)
//    {
//      if(a[mid]==k)
//        res = mid;
//      else if(a[mid]>k)
//        BinarySearch(a,0,mid-1,k);
//      else if(a[mid]<k)
//        BinarySearch(a,mid+1,r,k);
//    }
//    return res;
// }
// int Binary_Search(vector<int>a,int n,int k)
// {
//    int l = 0;
//    int r = n-1;
//    int mid = l + (r-l)/2;
//    int res;
//    while(l<r)
//    {
//      if(a[mid]==k)
//        res = mid;
//      else if(k>a[mid]){
//        l = mid +1;
//      }
//      else if(k<a[mid]){
//        r = mid-1;
//      }
//       mid = l + (r-l)/2;
//    }
//    return res;
// }
// pair<int,int> firstandLast(vector <int> arr,int k){
   
// }