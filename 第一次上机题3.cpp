#include<iostream>
using namespace std;
void sort(int a[],int n)
{
  int i,j;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n-1-i;j++)
    	   if (a[j]>a[j + 1])
		       { //�Ƚ����ڵ�����Ԫ��

				int tmp; //��ʱ����

				tmp = a[j]; //����

				a[j] = a[j + 1];

				a[j + 1] = tmp;
				} 
	}
}
void sort(float a[],int n)
{
  int i,j;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n-1-i;j++)
    	   if (a[j]>a[j + 1])
		       { //�Ƚ����ڵ�����Ԫ��

				float tmp; //��ʱ����

				tmp = a[j]; //����

				a[j] = a[j + 1];

				a[j + 1] = tmp;
				} 
	}
}
int main()
  {   
int a[10],n;//�����Ԫ�ظ��� 
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
   float b[10],m;//�����Ԫ�ظ��� 
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
