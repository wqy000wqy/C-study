#include<iostream>
using namespace std;
class People
{
    protected:
       int age;
	   float height;
	   float weight;
	   static int num;//���徲̬���ݳ�Աnum 
	public:
	    People(int age=24,float height=176.0,float weight=66.5):age(age),height(height),weight(weight)//�ò����ĳ�ʼ�����ʼ�� ,���캯������Ҫ�������� 
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
	 	static void ShowNum();//������̬��Ա���� 
	 	
	
 } ; 
 int People::num=4;//��ʼ����̬���ݳ�Ա 
 void People::ShowNum()//�þ�̬��Ա����������̬���ݳ�Ա 
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
