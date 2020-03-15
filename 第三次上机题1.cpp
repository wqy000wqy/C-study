#include<iostream>
#include<stdio.h>
using namespace std;
class Student
{
	private:
		long long numberofStudent;//学号 
		int gradeofStudent;//成绩 
	public:
		Student(long long num,int gra);
		void setNum(long long a)
		{
		numberofStudent=a;	
		}
		void setGrade(int a)
		{
		gradeofStudent=a;	
		}
		int showGrade()
		{
			return gradeofStudent;
		}
		long long showNumber()
		{
			return numberofStudent;
		}
		 
 }; 
 Student::Student(long long num,int gra)
		{
			numberofStudent=num;
			gradeofStudent=gra;
		}
	
	 void max(Student *pt, int n)   //max函数 
{
    Student *p=pt;Student ma(0,0);
    for (int i=0;i<n;i++)
    {  
	if(ma.showGrade()<p->showGrade())
	{
		ma.setGrade(p->showGrade());
		ma.setNum(p->showNumber());
	}
	p++;
        }
    cout<<"成绩最高的学生的信息： "<<"学号:"<<ma.showNumber()<<' '<<"成绩："<<ma.showGrade()<<endl;
}		
		 
	
 int main()
 {     
 	Student dd[5]=   //对象数组；
	 {
	 	Student(17030410014,99),
		 Student(17030410015,88),
		  Student(17030410016,20),
		   Student(17030410017,98),
		    Student(17030410018,97)
	 }; 
	 Student *stu,*temp;
	 stu=dd;
	  cout<<"学号："<<(*stu).showNumber()<<' '<<"成绩"<<(*stu).showGrade()<<endl;//输出1、3、5学生的数据。 
	  stu+=2;
	  cout<<"学号："<<(*stu).showNumber()<<' '<<"成绩"<<(*stu).showGrade()<<endl;
	   stu+=2;
	  cout<<"学号："<<(*stu).showNumber()<<' '<<"成绩"<<(*stu).showGrade()<<endl;
	   stu=dd; //重置指针 
	 
	   max(stu,5);
	 return 0; 
	                   
 }
