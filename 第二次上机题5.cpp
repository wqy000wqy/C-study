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
	cout<<"请输入账号户名密码进行注册"<<endl; 
	cin>>account1>>name1>>password1;
	currentAccount test(account1,name1,password1);
	while(1)
	{   int func;
	cout<<"存钱输入1，取钱输入2，计算年利息请按3，打印账户相关信息请按4，退出请按5" <<endl ;
	    cin>>func;
		if(func==1)
		{    float num;
			cout<<"请输入存入金额"<<endl;
			cin >>num;
			test.saveMoney(num);
			test.printfInfo();
			
		}
		else if(func==2)
		{
		float num;
			cout<<"请输入取出金额"<<endl;
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
