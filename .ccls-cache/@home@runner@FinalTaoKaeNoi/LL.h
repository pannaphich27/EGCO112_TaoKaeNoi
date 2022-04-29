#include "NODE.h"
class LL {   //แทนตัวเถ้าแก่น้อย
      NODE*hol;
      int size;
      int size_m1; //จำนวน machine1
      int size_m2; //จำนวน machine2
      float money;  // ยอดเงินของเถ้าแก่น้อย
      int levelmachine1;
      int levelmachine2;
      int month;
public:
       void add_node(NODE*&);
       void show_all();
       int payupgrade();
       int paybuymachine();
       void upgrade1();
       void upgrade2();
      float calinflation();  
      void account();  
       float calBill();   //return ค่าไฟ
      int balanceAccount();  //money=money-echarge+ Pprice;
      int checkInput();
       ~LL();
       LL();
};
