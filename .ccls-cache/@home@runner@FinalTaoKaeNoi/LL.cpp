#include <exception>
#include <iostream> 
#include <cmath>
#include"NODE.h"
#include"machine.h"
#include"LL.h"
using namespace std;
#include "exception.h"

#define BLACK "\e[30m"
#define ANSI_COLOR_RED "\x1b[31;1m"
#define ANSI_COLOR_GREEN "\x1b[32;2m"
#define ANSI_COLOR_YELLOW "\x1b[33;3m"
#define ANSI_COLOR_BLUE "\e[34;4m"
#define ANSI_COLOR_MAGENTA "\x1b[35;5m"
#define ANSI_COLOR_CYAN "\x1b[36;6m"
#define ANSI_COLOR_WHITE "\x1b[37;7m"
#define ANSI_COLOR_RESET "\x1b[0m"

LL::LL()
{
  hol=NULL;
  size=0;
  size_m1=0;
  size_m2=0;
  money = 15000;
  month=0;
  levelmachine1=0; 
  levelmachine2=0;
}

LL::~LL()
{
  int i;
	NODE *t;
	for(i=0;i<size;i++)
  {
		t=hol;
		hol=hol->move_next();
		delete t;
	}

cout<<ANSI_COLOR_CYAN "\n\n            ) ) )                     ) ) )"<<endl;
cout<<"        ( ( (                      ( ( ("<<endl;
cout<<"      ) ) )                       ) ) )"<<endl;
cout<<"   (~~~~~~~~~)                 (~~~~~~~~~)"<<endl;
cout<<"    | POWER |                   | POWER |"<<endl;
cout<<"    |       |                   |       |"<<endl;
cout<<"    I      _._                  I       _._"<<endl;
cout<<"    I    /\'   `\\                I     /\'   `\\"<<endl;
cout<<"    I   |   N   |               I    |   N   |        \\ Bye~~/"<<endl;
cout<<"    f   |   |~~~~~~~~~~~~|    f    |    |~~~~~~~~~~~~|    ☻/"<<endl;
cout<<"  .\'    |   ||~~~~~~~~|  |  .\'     |    | |~~~~~~~~| |   /▌"<<endl;
cout<<"/'______|___||__###___|__|/'_______|____|_|__###___|_|   /\\ \n\n"
  ANSI_COLOR_RESET <<endl;

  
}

int LL:: checkInput(){
  int c,a;
  my_cin myex;
  do {
      a = 0;

      try {
        cout << ANSI_COLOR_MAGENTA "Enter your choice : " 
      ANSI_COLOR_RESET ;
        cin>>c;
        if (cin.fail())
          throw myex;


      }

      catch (exception &e) {
        cout << e.what();
        cout << endl;
        a = 1;

        cin.clear(); // error
        cin.ignore(10, '\n');
      }

    } while (a);
  return c;
  
}

int LL::payupgrade()  //จ่าย upgrade
{
  //watt
  if(size<1){
    cout<< ANSI_COLOR_RED "You don't have any machine!"<<endl; ANSI_COLOR_RESET;
    //balanceAccount();
    return 0;
  }
  int yn, mc;
  int i=0, j=0;
  int costupgrade1, costupgrade2;     //cost upgrade
 
  costupgrade1 = 426+(levelmachine1*levelmachine1);   //***
  costupgrade2 = 508+(levelmachine2*levelmachine2);
  cout << "===================\n";
  //balanceAccount();
  cout<< ANSI_COLOR_GREEN "You have "<<money<<" baht" ANSI_COLOR_RESET <<endl;//print money
  cout<<"Cost to upgrade machine1 is "<<costupgrade1<<endl;
  cout<<"Cost to upgrade machine2 is "<<costupgrade2<<endl;

  if(money < costupgrade1 && money<costupgrade2){
    cout<< ANSI_COLOR_RED"You don't have enough money!"<<endl<<endl; ANSI_COLOR_RESET;
  return balanceAccount();
    }
  
  while(j==0)    //สำหรับ choice machine
    {

      cout<<"Which machine do you want to upgrade?"<<endl;
      cout<<"1. machine1"<<endl<<"2. machine2"<<endl;   
      mc = checkInput();

      switch(mc)
      {
        case 1:

          if(size_m1<1){
            cout<<ANSI_COLOR_RED"You don't have any machine1!"<<endl<<endl; ANSI_COLOR_RESET;
            return 0;           
          }
          if(money < costupgrade1){
          cout<< ANSI_COLOR_RED"You don't have enough money for upgrade machine1!"<<ANSI_COLOR_RESET<<endl<<endl;
            break;
            }
          
          while(i==0)
              {
                cout<<"[Upgrade]"<<endl;
                cout<<"1. Yes"<<endl<<"2. No"<<endl;
                yn = checkInput();
                switch(yn)
                {
                  case 1:
                    i=1;
                    
                    money=money-costupgrade1;
                    cout<<"!!! UPGRADE SUCCESS !!!"<<endl;
                    upgrade1();
                      month+=1;
                    return balanceAccount(); 
                    break;
                  case 2: 
                    i=1;
                    break;
                  default:
                    cout <<ANSI_COLOR_RED  "\nPlese select 1-2 \n" ;
                    cout << "===================\n\n"
                      ANSI_COLOR_RESET;
                    break;
                }
              }  //machine2
          j=1;
          break;
        case 2: 
        if(size_m2<1){
            cout<<ANSI_COLOR_RED "You don't have any machine2!"<<endl<<endl; ANSI_COLOR_RESET;
            return 0;           
          }
          if(money < costupgrade2){
          cout<< ANSI_COLOR_RED"You don't have enough money for upgrade machine2!"<<ANSI_COLOR_RESET<<endl<<endl;
            break;
            }
          while(i==0)
              {
                cout<<"[Upgrade]"<<endl;
                cout<<"1. Yes"<<endl<<"2. No"<<endl;
                 yn = checkInput();
                switch(yn)
                {
                  case 1:
                    i=1;
                    money=money-costupgrade2;
                    cout<<"!!! UPGRADE SUCCESS !!!"<<endl;
                    upgrade2();
                       month+=1;
                    return balanceAccount(); 
                    break;
                  case 2: 
                    i=1;
                    break;
                  default:
                     cout <<ANSI_COLOR_RED  "\nPlese select 1-2 \n" ;
                    cout << "===================\n\n"
                      ANSI_COLOR_RESET;
                    break;
                }
              } //machine2
          j=1;
          break;
        default:
           cout <<ANSI_COLOR_RED  "\nPlese select 1-2 \n" ;
                    cout << "===================\n\n"
                      ANSI_COLOR_RESET;
          break;
      }
    }
  return 0;  //มาทบบิลค่าไฟหลัง upgrade
}

int LL::paybuymachine()//function จ่ายเพื่อซื้อmachine 
{
  int yn, mc, i=0, j=0;
  NODE *t;
  int costmachine1, costmachine2;
  costmachine1 = 800+((426*(levelmachine1+1))/2); // ราคา //*** เพิ่มตาม lv
  costmachine2 = 1000+((508*(levelmachine2+1))/2); 
  cout << "===================\n";
  //balanceAccount();
  cout<<ANSI_COLOR_GREEN"You have "<<money<<" baht" ANSI_COLOR_RESET <<endl;   //print money
  cout<<"Machine1 price is "<<costmachine1<<endl;
  cout<<"Machine2 price is "<<costmachine2<<endl;

  if(money < costmachine1 && money<costmachine2){
    cout<< ANSI_COLOR_RED"You don't have enough money!"<<endl<<endl; ANSI_COLOR_RESET;
    
  return balanceAccount();
    }
  while(j==0)
    {
      cout<<"Which machine do you want to buy?"<<endl;
      cout<<"1. machine1"<<endl<<"2. machine2"<<endl;
      mc = checkInput();
      switch(mc)
      {
        case 1:
          if(money < costmachine1){
          cout<< ANSI_COLOR_RED"You don't have enough money for machine1!"<<endl<<ANSI_COLOR_RESET<<endl;
    
            break;
          }
          
          while(i==0)
              {
                cout<<"[Buy machine]"<<endl;
                cout<<"1. Yes"<<endl<<"2. No"<<endl;
                yn = checkInput();
                switch(yn)
                {
                  case 1:
                    i=1;
                    money=money-costmachine1;
                    cout<<"!!! PAYMENT SUCCESS !!!"<<endl;
                    
                       t = new machine1();
                       add_node(t);
                       month+=1;
                    return balanceAccount();  //ค่อยมาทบบิลหลังซื้อ
                    break;
                  case 2: 
                    i=1;
                    break;
                  default:
                    cout <<ANSI_COLOR_RED  "\nPlese select 1-2 \n" ;
                    cout << "===================\n\n"
                      ANSI_COLOR_RESET;
                    break;
                }
              }
          j=1;
          break;
        case 2: 
          if(money < costmachine2){
          cout<< ANSI_COLOR_RED"You don't have enough money for machine2!"<<ANSI_COLOR_RESET<<endl<<endl;
    
            break;
          }
          while(i==0)
              {
                cout<<"[Buy machine]"<<endl;
                cout<<"1. Yes"<<endl<<"2. No"<<endl;
                yn = checkInput();
                switch(yn)
                {
                  case 1:
                    i=1;
                    money=money-costmachine2;
                    cout<<"!!! PAYMENT SUCCESS !!!"<<endl;
                 
                      t = new machine2();
                      add_node(t);
                    month+=1;
                    return balanceAccount();  //ค่อยมาทบบิลหลังซื้อ
                    break;
                  case 2: 
                    i=1;
                    break;
                  default:
                    cout <<ANSI_COLOR_RED  "\nPlese select 1-2 \n" ;
                    cout << "===================\n\n"
                      ANSI_COLOR_RESET;
                    break;
                }
              }
          j=1;
          break;
        default:
           cout <<ANSI_COLOR_RED  "\nPlese select 1-2 \n" ;
                    cout << "===================\n\n"
                      ANSI_COLOR_RESET;
          break;
      }
    }
  return 0;  //ค่อยมาทบบิลหลังซื้อ
}

void LL::upgrade1()
{
  levelmachine1++;
  NODE* t=hol;
  int i;
  for(i=0;i<size;i++)
  {
    if(t->return_type() == 0){  //machine1
      t->upgrade();
      t->upgradewatt();
    }
    
	  t=t->move_next();    
     }
  
  //watt1=watt1+13;
}

void LL::upgrade2()
{
  levelmachine2++;
  NODE* t=hol;
  int i;
  for(i=0;i<size;i++)
  {
    if(t->return_type() == 1){  //machine2 
      t->upgrade();
      t->upgradewatt();
    }
    
	  t=t->move_next();    
     }
  
  //watt2=watt2+15;
}


void LL::add_node(NODE *&new_node){//done

          hol->insert(new_node);// new_next->next=hol;
          hol=new_node;        

       size++;
  if(hol->return_type()==0) size_m1++;
  else size_m2++;

 }

float LL::calinflation()
{
    NODE* t=hol;
     int i;
  float Pprice=0,pinflation;
  for(i=0;i<size;i++)
  {
    Pprice+=t->calinflation();  
	      t=t->move_next();    
     }
  pinflation = Pprice*pow(1.04, (int)month/3);
   
  return pinflation;
}

float LL::calBill(){    //คำนวณค่าไฟทั้งโรงงาน
  NODE* t=hol;
     int i;
     float cost=0,einflation;
     for(i=0;i<size;i++){
        cost += t->calBill();  //need "polymorphism"
	      t=t->move_next();    
     }

  einflation = cost* pow(1.04, (int)month/3);
  
return einflation;
}
void LL:: account()
{
  //calinflation();
  
  cout<<"month: "<<(month%12)+1; if(month%3==0&&month!=0) cout<<" +inflation 4%";
  cout<<endl;
  cout<<"Electronic bill this month :"<<calBill()<<endl;
  cout<<"Sales this month :"<<calinflation()<<endl;
  cout<< ANSI_COLOR_GREEN "Money :" 
   << money<<  ANSI_COLOR_RESET << endl;
  cout << "===================\n";
}

int LL::balanceAccount(){
  float balance = -calBill()+calinflation();
  my_cin myex;
  try{
  if(money+balance <0) throw myex;
  money=money-calBill()+ calinflation();  //ยอดขาย-ค่าไฟ
  }

    catch(exception &e){
      cout<<e.what()<<endl;
      cout<< ANSI_COLOR_RED "\n╔══╗─────╔╗──────╔╗╔╦╗"<<endl;
cout<<"║╔╗╠═╗╔═╦╣╠╦╦╦╦╦═╣╚╣║║"<<endl;
cout<<"║╔╗║╬╚╣║║║═╣╔╣║║╬║╔╣║║"<<endl;
cout<<"╚══╩══╩╩═╩╩╩╝╚═╣╔╩═╬╬╣"<<endl;
cout<<"───────────────╚╝──╚╩╝" 
ANSI_COLOR_RESET<<endl;
    return 1;
      //delete this;
      //exit(0);
    }
  return 0;
}

void LL::show_all(){
     NODE* t=hol;
     int i;
     for(i=0;i<size;i++){
        t->show_node();
	      t=t->move_next();    
     }
}
