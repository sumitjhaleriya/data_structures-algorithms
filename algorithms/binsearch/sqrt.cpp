#include <iostream>
using namespace std;
double squareInt(int n,int prc,int sol){
   double factor = 1;
   double Ans = sol;
   for (int i = 0; i < prc; i++)
   {
     factor = factor/10;
      for (double j = 0; j*j < n; j+=factor)
      {
        Ans = j;
      }
   }
   return Ans;
}
int sqR(int n)
{
  int start = 0;
  int end = n;
  long long int mid = start + (end - start )/2;
  long long int ans;
  while(start<end)
  {
    long long int sq = mid*mid;
    if(sq == n)
      return mid;
    if (sq > n )
      end = mid -1;
    if (sq < n)
    {
      ans = mid;
      start = mid +1;
    }
    mid = start + (end - start )/2;
    // cout<<"start "<<"end "<<"mid "<<" sq"<<endl;
    // cout<<start <<" " <<end <<" "<<mid<<" "<<sq<<endl;
  }
   return start;
}
int main(){
    int root = sqR(27);
    cout<<root<<endl;
    double ans = squareInt(27,3,root);
    cout<<ans<<endl;
}
