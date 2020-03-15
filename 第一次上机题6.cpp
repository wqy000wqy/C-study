#include<iostream>
using namespace std;
class Circle
{
	private:
	float radius;

	public:
	 Circle(){
		radius=6.0;
	}
	float GetArea()
	{
		return 3.1415926*radius*radius;
	 } 
};
int main()
{   float m;
	Circle t;
    m=t.GetArea();
    cout<<m;
    
}
