#include<iostream>
using namespace std;
int main() 
{   int a,b,c;
	cin>>a>>b>>c;
	int &a1=a,&b1=b,&c1=c;
	for(int i=0;i<4;i++)
	{
		if(a>b)
		{
			int temp;
			temp=b;
			b=a;
			a=temp;
		}
		if(b>c)
			{
			int temp;
			temp=c;
			c=b;
			b=temp;
		}
		
	}
	cout<<a1<<' '<<b1<<' '<<c1;
	return 0;
}
