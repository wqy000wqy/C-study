#include<iostream>
#include<string.h>
using namespace std;
class Dog
{
    public:
	int weight;
	int age;
     string sex;
	 string *name;
		void setWeight(int a)
		{
			weight=a;
		}
		void setAge(int b)
		{
			age=b;
		}
		void setSex(string c)
		{
			sex=c;
		 } 
		 void setName(string name1)
		 {name=&name1;
		 	
		 }
		 void showname()
		 {
		 	cout<<"name:"<<*name<<' '<<"weight:"<<weight<<' '<<"sex:"<<sex<<' '<<"age:"<<age<<endl; 
		  } 
		
	 
};
int main()
{
	int weight,age;
	cin>>weight>>age; 
	string sex,name;
	cin>>sex>>name; 
	Dog test;   //定义对象 
	Dog *p1;  //定义对象指针 
	p1=&test;
	p1->setWeight(weight);
	p1->setSex(sex);
	p1->setName(name);
	p1->setAge(age);
	p1->showname();
	
}
 
