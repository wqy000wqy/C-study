#include<iostream>
#include<string>
#include<string.h>
using namespace std;
class Student
{   private:
char name[18]; //定义18长度赋值出现各种错误，很难解决 
	int num;
	int mathScore;
	int englishScore;
	static int count;
	static int mathTotalScore;
	static int englishTotalScore;
	
	public: 
	Student(char a[],int nu,int math,int english)
	{
    strcpy(name,a);
	num=nu;
	mathScore=math;
	englishScore=english;
	};
	~Student()
	{
		cout<<"destructer callde."<<endl;
	}

	void ShowBase()
	{
	    cout<<"name:"<<name<<' '<<"num:"<<num<<' '<<"mathScore:"<<mathScore<<' '<<"englishScore:"<<englishScore<<endl;
	};
	static void showStatic();
	void setTotalScore()
	{
		mathTotalScore+=mathScore;
		englishTotalScore+=mathScore;
	}
	
	
 };
 int Student::mathTotalScore=0;
 int Student::englishTotalScore=0;
 int Student::count=3;
   void Student::showStatic()
   {  
   	cout<<"count:"<<count<<' '<<"mathTotalScore:"<<mathTotalScore<<' '<<"englishTotalScore:"<<englishTotalScore<<endl;
   }
   
 int main()
 { char a[18]="wqy",b[18]="zxh",c[18]="lzk";
 	Student s1(a,16,90,100);
 	s1.setTotalScore();
 	s1.ShowBase();
 	s1.showStatic();
 	Student s2(b,15,99,100);
 	s2.setTotalScore();
 	s2.ShowBase();
 	s2.showStatic();
 	Student s3(c,14,100,100);
 	s3.setTotalScore();
 	s3.ShowBase();
 	s3.showStatic();
 	return 0; 
 }
