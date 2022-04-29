#ifndef NODE_H
#define NODE_H

class NODE{
      int type;   
      int price;   
      int product; 
      float watt;  
      int watt_node;
      int level;
      NODE* next;
public:
        NODE(int ,int ,int, int);    
        virtual void show_node();
        void insert(NODE*&);
        NODE* move_next();
        virtual ~NODE();
        virtual float calBill();   
        float calinflation();
        virtual void upgrade();   
        virtual void upgradewatt();     
        int return_type();
      };

#endif
