

#ifndef BILLING_H
#define BILLING_H

class item
{
public:
    char name[50];
    float prz;
    int qty;
    void buy_by_id(int);
};

class cart
{
  struct item *i;
  int numberofitems;

public:

    cart();
    void buy();
    void displaycart();


};


#endif



