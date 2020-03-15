#include<iostream>
#include<stdio.h>
using namespace std;
class Date;
class Time
{
	private:
		int hour;
		int minute;
		int second;
		public:
			Time(int a,int b,int c)
			{
				hour=a;
				minute=b;
				second=c;
			}
			void display(Date &);//如果在这里就声明会报错，为什么？	
};
class Date
{
	private:
		int year;
		int month;
		int day;
		public:
			Date(int a,int b,int c)
			{
				year=a;
				month=b;
				day=c;
			}
			friend void Time::display(Date &d);
			
}; 
void Time::display(Date &d)
			{
				cout<<d.year<<"/"<<d.month<<"/"<<d.day<<endl;
				cout<<hour<<':'<<minute<<':'<<second<<endl; 
			}

int main()
{
	Date wqy(2019,11,13);
	Time wqyy(0,10,0);
	wqyy.display(wqy);
	return 0;
}

