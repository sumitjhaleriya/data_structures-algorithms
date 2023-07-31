#include <stdio.h>
void ls(int arr[],int m,int k);
int main()
{
   int n;
   int key;
   scanf("Enter the size of array:%d",&n);
   int arr[n];
   for(int j = 0;j<n;j++)
   {
     scanf("%d",&arr[j]);
   }
   ls(arr,n,key);
   return 0;
}
void ls(int arr[];int m,int k)
{
   int p;
   int i = 0;
   for(i=0;i<m;i++)
   {
      if(arr[i]==k)
	 p = i ;
   }
   printf("Your target is on %d index",p);
}
