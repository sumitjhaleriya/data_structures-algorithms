#include <iostream>
using namespace std;
int main()
{
  int a;
  cout<<"Enter the size of arrays:"<<endl;
  cin>>a;
  int key;
  int arr[a];
  cout<<"Enter the elements of your array:"<<endl;
  for(int i =0 ;i<a;i++)
	  cin>>arr[i];
  cout<<"Enter the target : "<<endl;
  cin>>key;
  int index;
  for(int j =0;j<a;j++)
  {
     if(arr[j]==key)
	   index = key;
  }
  printf("The target is on %d index",index);
}

