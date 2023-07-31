#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;
    int arr[n] = {1, 4, 2, 5, 3, 6};
    for(int i = 0 ; i < n-1; i++)
    {
       for(int j = i+1 ; j < n; j++)
       {
           if (arr[i]>arr[j])
           {
               swap(arr[i], arr[j]); /* code */
           }  
       }
    }
    for(int i = 0 ; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}