#include<iostream>
#include <fstream>
#include<string>
#include<windows.h>
using namespace std;
int change(char *s){//将文件中每行的前4个字符转换为int型 
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
class Staff//虚基类 
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
     cout<<"请输入您想加入的员工类型编码"<<endl;
     cout<<"1:销售员   2：经理    3：销售经理"<<endl;
     cout<<"注意：销售员id（1000~2000）"<<endl;
     cout<<"      经理id（2001~3000）"<<endl;
     cout<<"      销售经理id（3001~4000）"<<endl; 
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
                              cout<<"你输入了错误的编码!" ;
                              break;
                              } 
                              //break;                           
}
void deleteinf(){//将文件中的所有信息与需要删除的信息比较，如果不要删除则写入另一个文件，要删除在另
                  //的文件中写入“delete”作为删除标记，最后将原本的文件删除，将复制信息后的文件改名
                  //为原文件名 
     ifstream del1, del2, del3;
     ofstream filec, filea, fileb;
     int chosenum1;
     int temp;
     char a[100];
     cout<<"请输入想要删除的员工id："<<endl;
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
void updateinf()//更新数据同样是比较，不需要更新则 写入另外的文件中，需要更新则将更新的一行数据写入                                                   
                 //文件中，最后将原文件删除，重命名新的文件为原文件名。 
{
     fstream updat1, updat2, updat3;
     ofstream file1;
     int chosenum2;
     char a[100];
     int temp;
     cout<<"请输入想要更新的员工id："<<endl;
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
                                cout<<"请输入想要更新的数据：(id,name,age,sale_value)"<<endl;
                                int id, age, sale_value;
                                string name;
                                while(updat1.getline(a, 100)){                                
                                                   if(temp != change(a))
                                                           file1<<a<<endl;
                                                   else{
                                                        cout<<"请输入原id"<<endl; 
                                                        cin>>id;                                                         
                                                        file1<<id<<"\t";
                                                        cout<<"请输入新name"<<endl; 
                                                        cin>>name;
                                                        file1<<name<<"\t";
                                                        cout<<"请输入新age"<<endl; 
                                                        cin>>age;
                                                        file1<<age<<"\t";
                                                        cout<<"请输入新sale_value"<<endl; 
                                                        cin>>sale_value;
                                                        file1<<sale_value<<endl;
                                                        cout<<"update 成功"<<endl;
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
                                cout<<"请输入想要更新的数据：(id,name,age,sction)"<<endl;
                                string name, section;
                                int id, age;
                                while(updat2.getline(a, 100)){                                
                                                   if(temp != change(a))
                                                           file1<<a<<endl;
                                                   else{
                                                        cout<<"请输入原id"<<endl; 
                                                        cin>>id;                                                         
                                                        file1<<id<<"\t";
                                                        cout<<"请输入新name"<<endl; 
                                                        cin>>name;
                                                        file1<<name<<"\t";
                                                        cout<<"请输入新age"<<endl; 
                                                        cin>>age;
                                                        file1<<age<<"\t";
                                                        cout<<"请输入新section"<<endl;
                                                        cin>>section;
                                                        file1<<section<<endl; 
                                                        cout<<"update 成功"<<endl;
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
                                cout<<"请输入想要更新的数据：(id,name,age)"<<endl;
                                string name;;
                                int id, age;
                                while(updat3.getline(a, 100)){                                
                                                   if(temp != change(a))
                                                           file1<<a<<endl;
                                                   else{
                                                        cout<<"请输入原id"<<endl; 
                                                        cin>>id;                                                         
                                                        file1<<id<<"\t";
                                                        cout<<"请输入新name"<<endl; 
                                                        cin>>name;
                                                        file1<<name<<"\t";
                                                        cout<<"请输入新age"<<endl; 
                                                        cin>>age;
                                                        file1<<age<<endl;
                                                        cout<<"update 成功"<<endl;
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
     cout<<"请输入员工id"<<endl;
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
                                           cout<<"未找到员工信息"<<endl; 
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
                                           cout<<"未找到员工信息"<<endl; 
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
                                           cout<<"未找到员工信息"<<endl; 
                               out3.close();
                               }
                               break;
                  }
     } 
void searchnum()
{     int num;
	  cout<<"1:查询员工（总）人数,2:查询销售员人数"<<endl;
	  cout<<"3.查询经理人数，4：查询销售经理人数"<<endl;
	  cin>>num;
	   switch(num){
                            case 1:
                               cout<<"员工（总）人数为"<<count1+count2+count3<<endl;
                                 break;
                            case 2:
                               cout<<"销售员人数为"<<count1<<endl;
                                 break;
                            case 3:
                                 cout<<"经理人数为"<<count2<<endl;
                                 break;
                            case 4:
                                 cout<<"销售经理人数为"<<count3<<endl;
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
                cout<<"请选择下列服务项目编号：***********"<<endl;
                cout<<"1.增加员工             2.删除员工"<<endl;
                cout<<"3.更新员工数据         4.重组文件"<<endl;
                cout<<"5.查询员工数据         6.查询人数"<<endl;
                  cout<<"7.退出"<<endl;
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

