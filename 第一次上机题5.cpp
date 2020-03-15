#include<iostream>
using namespace std;
class Date
{
	 private:
	 int year;
	 int month;
	 int day;
	 public:
	 void setDate(int a,int b,int c)
	 {
	 	year=a;
	 	month=b;
	 	day=c;
	  } 
	  void showDate();
};
void Date::showDate()
{
	cout<<year<<' '<<month<<' '<<day<<endl;
}
 int main()
 {
 	Date t;
 	int a,b,c;
 	cin>>a>>b>>c;
 	t.setDate(a,b,c);
 	t.showDate();
 }
