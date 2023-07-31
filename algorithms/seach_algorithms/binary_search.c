#include <stdio.h>
int Binary_Search(int [],int,int,int);
int main(){
  int n;
  printf("Enter the size of your array : ");
  scanf("%d",&n);
  printf("Enter your array:");
  int arr[n];
  for (int i =0;i<n;i++)
	  scanf("%d",&arr[i]);
  int target;
  scanf("Enter the target:%d",&target);
  int index = Binary_Search(arr ,0 ,n , target);
  printf("the target is at %d index",index);
  return 0;
}
int Binary_Search(int arr[],int l,int n,int k)
{
   int r = n;
   int ind;
   int mid = (l+r)/2;
   while(l<r)
   {
      if(arr[mid]==k)
	 ind = mid; 

      else if(arr[mid]>k)
         Binary_Search(arr,l,(r/2)-1,k);

      else if(arr[mid]<k)
	 Binary_Search(arr,(r/2)+1,r,k);
   }
   return ind;
}
  
  
