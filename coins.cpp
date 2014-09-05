#include<cstdio>
#include<iostream>
#include<cassert>
#include<cstdarg>
using namespace std;
//program to find minimum coins that sum to n<5000, given infinite coins of value 1,
//3, and 5
int minint(int x,...)
{
  va_list args;
  va_start(args,x);
  int min = va_arg (args, int);
  for(int i = 1; i<x ; i++)
    {
      int temp = va_arg (args,int);
      if(min>temp) min = temp;
    }
}
int find(int n, int* a)
{
  if(n<0)
    return 10000;
  if(a[n]<10000)
    return a[n];
  return a[n] = 1 + minint(find(n-1,a),find(n-3,a),find(n-5,a));
}
int main(void)
{
  int n;
  scanf("%d",&n);
  assert(n<1000);
  int *a = new int[n+1];
  a[0]=0;
  for(int i=1;i<=n;i++)
    {
      a[i]=10000;
    }
  int i = n;
  printf("%d\n",find(n,a));
  
}
