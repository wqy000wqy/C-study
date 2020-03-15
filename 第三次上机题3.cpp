#include<iostream>
#include<stdio.h>
using namespace std;
class Array
{ public:
	int a[2][3];
	Array(int pp)
	{
	for(int i=0;i<2;i++)
{
	for(int j=0;j<3;j++)
	{ 
	a[i][j]=pp;
	pp++;
		
	}
}	
	}
};
 istream & operator >>(istream & input,Array& d) {

	for (int i=0; i<2; i++)

		{
		for (int j=0; j<3; j++)

			{
			input>>d.a[i][j];
            }
        }
	return input;

}
ostream& operator <<(ostream& output,Array& c)
{
for(int i=0;i<2;i++)
{
	for(int j=0;j<3;j++)
	{
		output<<c.a[i][j]<<' ';
		
	}
}
return output;	
}


int main()

{  Array c(3);
	cin>>c;
	cout<<c;
	return 0;
	
}
