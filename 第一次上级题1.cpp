#include<iostream>
using namespace std;
int maxofNum(int a,int b,int c=0) {
	
	return (a>b?a:b)>c?(a>b?a:b):c; 
}
int main()
{   
    int a,b,c,fc; 
    
     cout<<"please input 2 or 3"<<endl;
     cin>>fc;
	 
      if (fc==3)
       {
        cin>>a>>b>>c;
        }
		else if(fc==2) 
		{
        cin>>a>>b;
        }
        else 
        {
        	cout<<"ERROR";
		}
	    cout<<maxofNum(a,b,c);
	return 0;
 } 
