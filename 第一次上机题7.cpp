#include<iostream>
using namespace std;
class volume
{
	private:
	float a[3][3];

	public:
    void setdata(int m,int n,float data)
    {
    	a[m][n]=data;
	}
	float getvolume(int m)
	{
		cout<<a[m][0]*a[m][1]*a[m][2]<<endl;
		
	}
	
};
int main()
{   int m,n;
    volume t;
    for(m=0;m<3;m++)
    {
    	for(n=0;n<3;n++)
    	{    float temp;
    	    cin>>temp;
    		t.setdata(m,n,temp);
		}
	}
	for(m=0;m<3;m++)
	{
		t.getvolume(m);
	}
    
   

    
}
