#include <iostream>
using namespace std;
#include"NODE.h"

NODE::NODE(int x, int prod, int m_price, int w){       //constructor NODE
      type=x;
      price = m_price;
      product=prod;
      watt_node=w;
      watt= (watt_node*24)/1000 * 4*30; 
      next=NULL;
      level =0;

}
  NODE:: ~NODE(){
      cout<<"NODE machine "<<type+1<<" is being removed"<<endl;   //แก้
}
NODE* NODE::move_next(){
      return next;
}
void  NODE:: show_node(){
        
         cout<<" :Sales= "<<calinflation()<< " lv="<<level<<endl; 
           
 }
void NODE::insert(NODE*& x){
     x->next=this;
     }

float NODE::calBill(){   
return watt;
}

float  NODE::calinflation() 
{
  float p;
  p = price*product;
  return  p;
}

void NODE::upgrade(){  //level++
  level++;   //level ต่อnode
  price = price+(5*level*level); 
}

void NODE::upgradewatt(){  //level++
  watt_node=watt_node+13*level;   //level ต่อnode
}

int NODE::return_type(){
  return type;
}
