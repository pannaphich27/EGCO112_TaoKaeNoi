#ifndef MACHINE_H
#define MACHINE_H


#include<iostream>
#include"NODE.h"
using namespace std;



class machine1:public NODE{ //ผลิต
    int watt  ;    // เก็บไว้   
    int product ; //จำนวนสินค้าที่ผลิตได้
    int price ;  //ราคาต่อสินค้า 1 ตัว
    int level ; 
    string name ;
public:
    machine1(int = 720,int = 5,int =120,int =0,string = "Seaweed",int = 0);
    ~machine1();
   
    void show_node(){
        cout<<"machine "<<name<<": electricBill= "<<calBill();
        NODE::show_node();
    }
     void upgrade();   
     float calBill();  
    void upgradewatt();   
    


};

machine1::machine1(int w ,int pro,int pri,int lev,string na,int type) :NODE(type,pro,pri,w)
{
    watt = w;
    product = pro;
    price = pri;
    level = lev; 
    name = na;
     cout<<"adding SEAWEED machine. lv"<<level<<endl;
}
   machine1::~machine1()
{
  cout << "destruct " << name << " lv"<<level<<endl; 
}

 void machine1::upgrade(){   //เพิ่ม price;
   level++;
   price = price+(5*level*level); 
   NODE::upgrade();  //polymorphism
 }


float machine1::calBill(){   //return ค่าไฟ ต่อ node
float cost=((float)watt*24)/1000 *4*30;
return cost;
}

void machine1::upgradewatt(){  //level++
  watt=watt+13*level;   //level ต่อnode
  NODE::upgradewatt();
}


//***************************************
class machine2:public NODE{  //รถบรรทุกขนส่ง
    int watt  ;
    int distance; //ระยะทาง
    int price ; //ราคาต่อระยะทาง
    

public:
   machine2(int = 500,int = 10 ,int = 30,int = 1);
    ~machine2();
    void show_node(){
      cout<<"machine 2: "<<" electricBill= "<<calBill();
      NODE::show_node();
    }
    //void upgrade();   //polymorphism;
    float calBill();
    void upgradewatt();
    void upgrade();
};

machine2::machine2(int w ,int dis,int pri,int type) :NODE(type,dis,pri,w)
{
    watt = w;   
    distance = dis;
    price = pri;   //เก็บค่าขนส่งจากลูกค้า
    cout<<"adding TRUCK machine. "<<endl;
}

  machine2::~machine2()
{
  cout<< "destruct" << "Truck" << endl; 
}

float machine2::calBill(){   //return ค่าไฟ ต่อ node
float cost=((float)watt*24)/1000 * 4*30;
return cost;
}

void machine2::upgradewatt(){  //level++
  watt=watt+15;   //level ต่อnode
  NODE::upgradewatt();
}

void machine2::upgrade(){   //เพิ่ม price;
   price = price+5; 
   NODE::upgrade();  
 }

#endif