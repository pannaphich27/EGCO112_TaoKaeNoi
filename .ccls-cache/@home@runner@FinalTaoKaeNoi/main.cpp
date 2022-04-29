#include "LL.h"
#include <exception>
#include <iostream>
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


void intro();
void ByeBye();
void Bankrupt();

int main() {
  LL A;
  int c;
  my_cin myex;

  intro();
  A.account();
  // choice select
  while (1) {

    cout << ANSI_COLOR_BLUE "Plese select you choice \n" ANSI_COLOR_RESET ;
    cout << "1.Upgrade machine 🦾\n";
    cout << "2.Buy machine 👨‍🏭\n";
    cout << "3.Show Account 👁\n";
    cout << "4.Show All Machine 🔎\n";
    cout << "5.Exit 💨\n";

    
    c= A.checkInput();
    switch (c) {
    case 1:
      cout << "Upgrade machine \n";
      if(A.payupgrade()) return 0;
      break;
    case 2:
      cout << "Buy machine \n";
      if(A.paybuymachine()) return 0;    //if bankrupt--> exit
      break;
    
     case 3:
       cout << "===================\n";
         cout << "Show Account \n";
      A.account();
      break;

      case 4:
       cout << "===================\n";
         cout << "Show All Machine \n";
      A.show_all();
      break;

      case 5:
      return 0;
      break;
    
    default:
      cout << ANSI_COLOR_RED "\nPlese select 1-5 \n" ;
      cout << "_______________________________\n\n"
         ANSI_COLOR_RESET ;
      break;
    }
  }
}

void intro(){
 
cout<<ANSI_COLOR_BLUE"╔════╗───────╔╗╔═╗────────╔═╗─╔╗"<<endl;
cout<<"║╔╗╔╗║───────║║║╔╝────────║║╚╗║║"<<endl;
cout<<"╚╝║║╠╩═╦══╗──║╚╝╝╔══╦══╗──║╔╗╚╝╠══╦╗"<<endl;
cout<<"──║║║╔╗║╔╗╠══╣╔╗║║╔╗║║═╬══╣║╚╗║║╔╗╠╣"<<endl;
cout<<"──║║║╔╗║╚╝╠══╣║║╚╣╔╗║║═╬══╣║─║║║╚╝║║"<<endl;
cout<<"──╚╝╚╝╚╩══╝──╚╝╚═╩╝╚╩══╝──╚╝─╚═╩══╩╝"
    ANSI_COLOR_RESET<<endl;
cout<<ANSI_COLOR_YELLOW"  ╔═════════════════════════════╗"<<endl;
cout<<"   Ａｍａｚｉｎｇ ｆａｃｔｏｒｙ "<<endl;
cout<<"  ╚═════════════════════════════╝"
    ANSI_COLOR_RESET<<endl;

}


