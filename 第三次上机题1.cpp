#include<iostream>
#include<stdio.h>
using namespace std;
class Student
{
	private:
		long long numberofStudent;//ѧ�� 
		int gradeofStudent;//�ɼ� 
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
	
	 void max(Student *pt, int n)   //max���� 
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
    cout<<"�ɼ���ߵ�ѧ������Ϣ�� "<<"ѧ��:"<<ma.showNumber()<<' '<<"�ɼ���"<<ma.showGrade()<<endl;
}		
		 
	
 int main()
 {     
 	Student dd[5]=   //�������飻
	 {
	 	Student(17030410014,99),
		 Student(17030410015,88),
		  Student(17030410016,20),
		   Student(17030410017,98),
		    Student(17030410018,97)
	 }; 
	 Student *stu,*temp;
	 stu=dd;
	  cout<<"ѧ�ţ�"<<(*stu).showNumber()<<' '<<"�ɼ�"<<(*stu).showGrade()<<endl;//���1��3��5ѧ�������ݡ� 
	  stu+=2;
	  cout<<"ѧ�ţ�"<<(*stu).showNumber()<<' '<<"�ɼ�"<<(*stu).showGrade()<<endl;
	   stu+=2;
	  cout<<"ѧ�ţ�"<<(*stu).showNumber()<<' '<<"�ɼ�"<<(*stu).showGrade()<<endl;
	   stu=dd; //����ָ�� 
	 
	   max(stu,5);
	 return 0; 
	                   
 }
