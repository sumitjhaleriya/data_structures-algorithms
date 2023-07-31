#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;
    int arr[n] = {9,8,6,5,4,3};
    for(int i = 0 ; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
           if(arr[i]>arr[j]){
               swap(arr[i],arr[j]);
           }
        }
    }
   for(int j = 0 ; j < n; j++)
   {
    cout << arr[j] ;
   }
    return 0;
}