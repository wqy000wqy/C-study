#include<iostream>
#include <fstream>
#include<string>
#include<windows.h>
using namespace std;
int change(char *s){//���ļ���ÿ�е�ǰ4���ַ�ת��Ϊint�� 
    int b[3];
    for(int i=0;i<4;i++)
    {
            int j = (int)s[i]-48;
            b[i] = j; 
            }
    int temp = b[0]*1000+b[1]*100+b[2]*10+b[3];
    return temp;
    
}
int count1=0;
int count2=0;
int count3=0;
class Staff//����� 
{
protected:
        int id;
        int age;
        string name;        
public:
	   
       int getid();
       int getage();
       string getname();
       void add();
};           
class Saleman:virtual public Staff
{ 
protected:
        int sale_value;
public:
	  
	   void add();
	   int getid();
	   int getage();
	   string getname();
	   int getsale_value();
};
void Saleman::add(){
     cout<<"please input Saleman id name age sale_value:"<<endl;
     cin>>id>>name>>age>>sale_value;
     }
int Saleman::getid(){
    return id;
}
int  Saleman::getage(){
     return age;
     }
string Saleman::getname(){
       return name;
       }
int Saleman::getsale_value(){
    return sale_value;
}
class Manager : virtual public Staff
{
protected:
	string section;
public: 
   
	void add();
	int getid();
	int getage();
	string getname();
	string getsection();
     
};
void Manager::add(){
     cout<<"please input Manager id name age section:"<<endl;
     cin>>id>>name>>age>>section;
     }
int Manager::getid(){
    return id;
}
int  Manager::getage(){
     return age;
     }
string Manager::getname(){
       return name;
       }
string Manager::getsection(){
       return section;
       }
class SalesManager:public Saleman, public Manager
{	
public:
	  
	   void add();
	   int getid();
	   int getage();
	   string getname();
};
void SalesManager::add(){
      cout<<"please input SalesManager id name age:"<<endl;
     cin>>id>>name>>age;
     }
int SalesManager::getid(){
    return id;
}
int  SalesManager::getage(){
     return age;
     }
string SalesManager::getname(){
       return name;
       }
void addinfor(){
     ofstream ocout1, ocout2, ocout3;
     int chosenum;
     cout<<"��������������Ա�����ͱ���"<<endl;
     cout<<"1:����Ա   2������    3�����۾���"<<endl;
     cout<<"ע�⣺����Աid��1000~2000��"<<endl;
     cout<<"      ����id��2001~3000��"<<endl;
     cout<<"      ���۾���id��3001~4000��"<<endl; 
     cin>>chosenum;
     switch(chosenum){
                      case 1:
                           {
                           ocout1.open("Saleman.txt", ios::out|ios::app);
						   Saleman a;                                    
                           a.add();
                           ocout1<<a.getid()<<"\t";
                           ocout1<<a.getname()<<"\t";
                           ocout1<<a.getage()<<"\t";
                           ocout1<<a.getsale_value()<<endl;
                           count1++;
                           ocout1.close();
                           
                           }
                           break;
                      case 2:
                           {
                           ocout2.open("Manager.txt", ios::out|ios::app);
                           Manager b;                           
                           b.add();
                           ocout2<<b.getid()<<"\t";
                           ocout2<<b.getname()<<"\t";
                           ocout2<<b.getage()<<"\t";
                           ocout2<<b.getsection()<<endl;
                           count2++;
                           ocout2.close();                           
                           break;
                           }
                      case 3:
                           {
                           ocout3.open("SalesManager.txt", ios::out|ios::app);
                           SalesManager c;                           
                           c.add();
                           ocout3<<c.getid()<<"\t";
                           ocout3<<c.getname()<<"\t";
                           ocout3<<c.getage()<<endl;
                           ocout3.close();
                           count3++;
                           break;
                           }
                      default:
                              cout<<"�������˴���ı���!" ;
                              break;
                              } 
                              //break;                           
}
void deleteinf(){//���ļ��е�������Ϣ����Ҫɾ������Ϣ�Ƚϣ������Ҫɾ����д����һ���ļ���Ҫɾ������
                  //���ļ���д�롰delete����Ϊɾ����ǣ����ԭ�����ļ�ɾ������������Ϣ����ļ�����
                  //Ϊԭ�ļ��� 
     ifstream del1, del2, del3;
     ofstream filec, filea, fileb;
     int chosenum1;
     int temp;
     char a[100];
     cout<<"��������Ҫɾ����Ա��id��"<<endl;
     cin>>temp;
     if(temp<=2000)
                  chosenum1 = 1;
     else if(temp<=3000)
                  chosenum1 = 2;
     else
                  chosenum1 = 3;
     switch(chosenum1){
                       case 1:
                            {
                                del1.open("Saleman.txt", ios::in|ios::out);
                                filec.open("1.txt", ios::out|ios::app);
                                while(del1.getline(a, 100)){                                
                                                   if(temp != change(a))
                                                           filec<<a<<endl;
                                                   else
                                                       filec<<"deleted"<<endl; 
                                                       } 
                                 count1--;
                                 filec.close();
                                 del1.close();
                                 DeleteFile("Saleman.txt");
                                 rename("1.txt","Saleman.txt");  
                                 break;                          
                            }
                            case 2:
                            {
                                del2.open("Manager.txt", ios::in|ios::out);
                                filea.open("2.txt", ios::out|ios::app);
                                while(del2.getline(a, 100)){                                
                                                   if(temp != change(a))
                                                           filea<<a<<endl;
                                                   else
                                                       filea<<"deleted"<<endl; 
                                                       } 
                                 count2--;                                   
                                 filea.close();
                                 del2.close();
                                 DeleteFile("Manager.txt");
                                 rename("2.txt", "Manager.txt");
                                                            
                            }
                            break;
                            case 3:
                            {
                                del3.open("SalesManager.txt", ios::in|ios::out);
                                fileb.open("3.txt", ios::out|ios::app);
                                while(del3.getline(a, 100)){                                
                                                   if(temp != change(a))
                                                           fileb<<a<<endl;
                                                   else
                                                       fileb<<"deleted"<<endl; 
                                                       }
                                   count3--;  
                                 fileb.close();
                                 del3.close();
                                 DeleteFile("SalesManager.txt");
                                 rename("3.txt", "SalesManager.txt");
                                 break;                           
                            }
                            default:
                                    ;
                       }
                       
     } 
void updateinf()//��������ͬ���ǱȽϣ�����Ҫ������ д��������ļ��У���Ҫ�����򽫸��µ�һ������д��                                                   
                 //�ļ��У����ԭ�ļ�ɾ�����������µ��ļ�Ϊԭ�ļ����� 
{
     fstream updat1, updat2, updat3;
     ofstream file1;
     int chosenum2;
     char a[100];
     int temp;
     cout<<"��������Ҫ���µ�Ա��id��"<<endl;
     cin>>temp;
     if(temp<=2000)
                  chosenum2 = 1;
     else if(temp<=3000)
                  chosenum2 = 2;
     else
                  chosenum2 = 3;
     switch(chosenum2){
                       case 1:
                            {
                                updat1.open("Saleman.txt", ios::in|ios::out);
                                file1.open("4.txt", ios::out|ios::app);
                                cout<<"��������Ҫ���µ����ݣ�(id,name,age,sale_value)"<<endl;
                                int id, age, sale_value;
                                string name;
                                while(updat1.getline(a, 100)){                                
                                                   if(temp != change(a))
                                                           file1<<a<<endl;
                                                   else{
                                                        cout<<"������ԭid"<<endl; 
                                                        cin>>id;                                                         
                                                        file1<<id<<"\t";
                                                        cout<<"��������name"<<endl; 
                                                        cin>>name;
                                                        file1<<name<<"\t";
                                                        cout<<"��������age"<<endl; 
                                                        cin>>age;
                                                        file1<<age<<"\t";
                                                        cout<<"��������sale_value"<<endl; 
                                                        cin>>sale_value;
                                                        file1<<sale_value<<endl;
                                                        cout<<"update �ɹ�"<<endl;
                                                       }
                                                       }
                                 file1.close();
                                 updat1.close();
                                 DeleteFile("Saleman.txt");
                                 rename("4.txt","Saleman.txt");                    
                                 break; 
                            }
                       case 2:
                            {
                                updat2.open("Manager.txt", ios::in|ios::out);
                                file1.open("5.txt", ios::out|ios::app);
                                cout<<"��������Ҫ���µ����ݣ�(id,name,age,sction)"<<endl;
                                string name, section;
                                int id, age;
                                while(updat2.getline(a, 100)){                                
                                                   if(temp != change(a))
                                                           file1<<a<<endl;
                                                   else{
                                                        cout<<"������ԭid"<<endl; 
                                                        cin>>id;                                                         
                                                        file1<<id<<"\t";
                                                        cout<<"��������name"<<endl; 
                                                        cin>>name;
                                                        file1<<name<<"\t";
                                                        cout<<"��������age"<<endl; 
                                                        cin>>age;
                                                        file1<<age<<"\t";
                                                        cout<<"��������section"<<endl;
                                                        cin>>section;
                                                        file1<<section<<endl; 
                                                        cout<<"update �ɹ�"<<endl;
                                                        }
                                                       } 
                                file1.close();
                                updat2.close();
                                 DeleteFile("Manager.txt");
                                 rename("5.txt","Manager.txt"); 
                                break;
                            }
                       case 3:
                            {
                                updat3.open("SalesManager.txt", ios::in|ios::out);
                                file1.open("6.txt", ios::out|ios::app);
                                cout<<"��������Ҫ���µ����ݣ�(id,name,age)"<<endl;
                                string name;;
                                int id, age;
                                while(updat3.getline(a, 100)){                                
                                                   if(temp != change(a))
                                                           file1<<a<<endl;
                                                   else{
                                                        cout<<"������ԭid"<<endl; 
                                                        cin>>id;                                                         
                                                        file1<<id<<"\t";
                                                        cout<<"��������name"<<endl; 
                                                        cin>>name;
                                                        file1<<name<<"\t";
                                                        cout<<"��������age"<<endl; 
                                                        cin>>age;
                                                        file1<<age<<endl;
                                                        cout<<"update �ɹ�"<<endl;
                                                       }
                                                       } 
                                file1.close();
                                updat3.close();
                                DeleteFile("SalesManager.txt");
                                rename("6.txt","SalesManager.txt");                       
                                break;
                            }
                       default:
                               ;
                       }
}
void request(){
     fstream out1, out2, out3;
     char a[100];
     cout<<"������Ա��id"<<endl;
     int temp, cho;
     cin>>temp;
     if(temp<=2000)
                  cho = 1;
     else if(temp<=3000)
                  cho = 2;
     else
                  cho = 3;
     switch(cho){
                  case 1:{
                          int count = 0;
                          out1.open("Saleman.txt", ios::out|ios::in);
                          while(out1.getline(a, 100)){                                
                               if(temp == change(a)){
                                       cout<<"id      name      age    sale_value"<<endl;                            
                                       cout<<a<<endl;
                                       count++;
                                       }                                                            
                               }
                               if(count==0)
                                           cout<<"δ�ҵ�Ա����Ϣ"<<endl; 
                               out1.close();
                               }
                               break;
                  case 2:{
                          int count = 0;
                          out2.open("Manager.txt", ios::out|ios::in);
                          while(out2.getline(a, 100)){                                
                               if(temp == change(a)){
                                       cout<<"id      name    age    section"<<endl;                            
                                       cout<<a<<endl;
                                       count++;
                                       }                                                            
                               }
                               if(count==0)
                                           cout<<"δ�ҵ�Ա����Ϣ"<<endl; 
                               out2.close();
                               }
                               break;
                  case 3:{
                          int count = 0;
                          out3.open("SalesManager.txt", ios::out|ios::in);
                          while(out3.getline(a, 100)){                                
                               if(temp == change(a)){
                                       cout<<"id      name      age    "<<endl;                            
                                       cout<<a<<endl;
                                       count++;
                                       }                                                            
                               }
                               if(count==0)
                                           cout<<"δ�ҵ�Ա����Ϣ"<<endl; 
                               out3.close();
                               }
                               break;
                  }
     } 
void searchnum()
{     int num;
	  cout<<"1:��ѯԱ�����ܣ�����,2:��ѯ����Ա����"<<endl;
	  cout<<"3.��ѯ����������4����ѯ���۾�������"<<endl;
	  cin>>num;
	   switch(num){
                            case 1:
                               cout<<"Ա�����ܣ�����Ϊ"<<count1+count2+count3<<endl;
                                 break;
                            case 2:
                               cout<<"����Ա����Ϊ"<<count1<<endl;
                                 break;
                            case 3:
                                 cout<<"��������Ϊ"<<count2<<endl;
                                 break;
                            case 4:
                                 cout<<"���۾�������Ϊ"<<count3<<endl;
                                 break;
                                 
                     } 
	    
}
void rebuild(){
     fstream re1, re2, re3;
     ofstream  re4, re5, re6;
     string s = "deleted";
     char a[100], b[100],c[100];
     re1.open("Saleman.txt", ios::in|ios::out);
     re4.open("1.txt", ios::out|ios::app);     
     while(re1.getline(a, 100)){                                
                          if(s!=a)
                          re4<<a<<endl;
                        
    } 
    re1.close();
    re4.close();
    re2.open("Manager.txt", ios::in|ios::out);
    re5.open("2.txt", ios::out|ios::app);     
    while(re2.getline(b, 100)){                                
                          if(s!=b)
                          re5<<b<<endl;
                        
    } 
    re2.close();
    re4.close();
    re3.open("SalesManager.txt", ios::in|ios::out);
    re6.open("3.txt", ios::out|ios::app);     
    while(re3.getline(c, 100)){                                
                          if(s!=c)
                          re6<<c<<endl;
                        
    } 
    re3.close();
    re6.close();
    DeleteFile("Saleman.txt");
    DeleteFile("Manager.txt");
    DeleteFile("SalesManager.txt");
    rename("1.txt","Saleman.txt" );
    rename("2.txt","Manager.txt" );
    rename("3.txt","SalesManager.txt" );
}
int main(){
    int cho;
     while(true){
                cout<<"��ѡ�����з�����Ŀ��ţ�***********"<<endl;
                cout<<"1.����Ա��             2.ɾ��Ա��"<<endl;
                cout<<"3.����Ա������         4.�����ļ�"<<endl;
                cout<<"5.��ѯԱ������         6.��ѯ����"<<endl;
                  cout<<"7.�˳�"<<endl;
                cin>>cho;
                
                     switch(cho){
                            case 1:
                                 addinfor();
                                 break;
                            case 2:
                                 deleteinf();
                                 break;
                            case 3:
                                 updateinf();
                                 break;
                            case 4:
                                 rebuild();
                                 break;
                            case 5:
                                 request();
                                 break;
                            case 6:
							     searchnum();
								 break; 
                            case 7:
                                 return 0;
                                 
                     }
                                
                }
    system("pause");
    return 0;
}

