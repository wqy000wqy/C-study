#include<iostream>
using namespace std;
class currentAccount
{  private:
	string account;
	string name;
	string password;
	float money;
	float annualInterrestRate;
	public:
	 currentAccount(string account1,string name1,string password1)	
	 {   
	    money=1000;
	    annualInterrestRate=0.06;
	 	account=account1;
	 	name=name1;
	 	password=password1;
	 }
	 void saveMoney(float num)
	 {
	 	money+=num;
	 }
	 void getOutMoney(float num)
	 {
	 	money-=num;
	 }
	 float getRateofYear()
	 {
	 	return money*annualInterrestRate; 
	 }
	 void printfInfo()
	 {
	 	cout<<"account:"<<account<<' '<<"name:"<<name<<' '<<"money:"<<money<<endl;
	 }
	 
	
};
int main()
{

	string account1,name1,password1;
	cout<<"�������˺Ż����������ע��"<<endl; 
	cin>>account1>>name1>>password1;
	currentAccount test(account1,name1,password1);
	while(1)
	{   int func;
	cout<<"��Ǯ����1��ȡǮ����2����������Ϣ�밴3����ӡ�˻������Ϣ�밴4���˳��밴5" <<endl ;
	    cin>>func;
		if(func==1)
		{    float num;
			cout<<"�����������"<<endl;
			cin >>num;
			test.saveMoney(num);
			test.printfInfo();
			
		}
		else if(func==2)
		{
		float num;
			cout<<"������ȡ�����"<<endl;
			cin >>num;
			test.getOutMoney(num);
			test.printfInfo();	
		}
		else if(func==3)
		{   float num=test.getRateofYear();
			cout<<num<<endl;
		}
		else if(func==4)
		{
			test.printfInfo();	
		}
		else if(func==5)
		break;
	}

}
