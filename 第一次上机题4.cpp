#include<iostream>
using namespace std;
template < typename T,typename T1>
void sort(T a[],T1 n)
{
  int i,j;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n-1-i;j++)
    	   if (a[j]>a[j + 1])
		       { //比较相邻的两个元素

				T tmp; //临时变量

				tmp = a[j]; //交换

				a[j] = a[j + 1];

				a[j + 1] = tmp;
				} 
	}
}

int main()
  {   
int a[10],n;//输入的元素个数 
   cin>>n;
   for(int i=0;i<n;i++)
   {
     cin>>a[i];
   }
  sort(a,n);
   for(int i=0;i<n;i++)
   {
   	cout<<a[i]<<' ';
   	
   }
   float b[10];int m;//输入的元素个数 
   cin>>m;
   for(int i=0;i<m;i++)
   {
     cin>>b[i];
   }
 sort(b,m);
   for(int i=0;i<m;i++)
   {
   	cout<<b[i]<<' ';
   	
   }
   

}
