#include<iostream>
using namespace std;
class People
{
    protected:
       int age;
	   float height;
	   float weight;
	   static int num;//定义静态数据成员num 
	public:
	    People(int age=24,float height=176.0,float weight=66.5):age(age),height(height),weight(weight)//用参数的初始化表初始化 ,构造函数不需要返回类型 
		{ 
		};
		~People()
		{
			cout<<"Destructor called."<<endl;
		}
		void Eating()
		{
		    weight++;
		};
		void Sporting()
		{
		    height++;
		};
		void Sleeping()
		{
		    age++;
		    height++;
		    weight++;
		};
	 	void Show()
		{
		    cout<<"age="<<age<<' '<<"height"<<height<<' '<<"weight"<<weight<<endl;
		};
	 	static void ShowNum();//声明静态成员函数 
	 	
	
 } ; 
 int People::num=4;//初始化静态数据成员 
 void People::ShowNum()//用静态成员函数操作静态数据成员 
 {
        cout<<"num of People="<<num<<endl;	
 }
 int main()
 {
 	People t1;
 	t1.ShowNum();
 	t1.Show(); 
 	t1.Eating();
 	t1.Show();
 	t1.Sleeping();
 	t1.Show();
 	t1.Sporting();
 	t1.Show();
 	
  } 
