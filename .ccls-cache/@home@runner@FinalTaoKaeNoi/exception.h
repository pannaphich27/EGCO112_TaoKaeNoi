
class my_cin: public exception 
{ public:
     virtual const char* what() const throw() { 
		 if(cin.fail()) return "Input's not a number, try again";
     else return "\n !! You're balance is now negative !!";
     } 

}; 