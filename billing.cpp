
#include "main.h"
#include "database.h"
#include "billing.h"



cart::cart()
{
    numberofitems=0;
    i = new item[50];
    for(int j=0; j < 50; j++)
    {
        strcpy(i->name," ");
        i->prz = 0;
        i->qty = 0;
    }

}
void cart::displaycart()
{
    double total = 0;
         cout <<endl <<  std::setfill( '-' ) << std::setw( 85 ) << '-'
               << std::setfill(' ') << std::endl;
    cout  << "| " << setw(5) << left <<"SNO" << "| " << setw(30) << left << "NAME"
        << "| " << setw(20) << left << "PRICE" << "| " << setw(20) << left << "QTY" << "|"  <<endl<<  std::setfill( '-' )<< std::setw( 85 ) << "-" ;
        cout << std::setfill(' ');
        if(numberofitems == 0)
            cout << "\nNO ITEMS";
        for(int j=0; j < numberofitems; j++)
        {
             cout  <<endl << "| " << setw(5) << left <<j+1 << "| " << setw(30) << left << i[j].name
        << "| " << setw(20) << left << i[j].prz << "| " << setw(20) << left << i[j].qty << "|";
        total+=i[j].prz*i[j].qty;
        }
        cout <<endl << std::setfill( '-' ) << std::setw( 85 )
              << '-' ;
        cout << "\nTOTAL: " << total;
}
void cart::buy()
{
    int exit = 0;
    int ch;
    item it;
    int id;
    do
    {
        system("cls");
        displaycart();
        cout << "\n\t\t Buy Menu\n\n";
        cout << "1.Enter id\n";
        cout << "2.Enter name\n";
        cout << "3.Enter category\n";
        cout << "4.Exit\n";
        cout << "Enter your choice:";
        cin >> ch;
        switch(ch)
        {
    case 2:
        {
            cout << "\nEnter the name:";
            char name[20];
            gets(name);
        }
        case 1:
            {

                cout << "\nEnter id:";
                cin >> id;
                cout << "\nEnter quantity:";
                cin >> it.qty;
                int alpresent = 0;

                it.buy_by_id(id);
                if(it.prz == 0)
                {cout << "\nIt is not a valid item.";
                continue;}
                for(int j=0; j < numberofitems; j++)
                {
                    if(strcmp(i[j].name,it.name)==0)
                        {
                            i[j].qty+=it.qty;
                            alpresent = 1;
                        }

                }
                if(!alpresent)
                {
                    i[numberofitems] = it;
                    numberofitems++;
                }
                system("pause");
            }
        break;

        case 4:
            exit =1;
        }
    }while(exit == 0);
}
void item::buy_by_id(int id)
{
    prz = 0;
    strcpy(name," ");
    fstream file;
    saree s;
    file.open("saree.dat",ios::in|ios::out|ios::ate);
    file.seekg(0,ios::beg);
    while(true)
    {
        file.read((char*)&s,sizeof(saree));
        if(!file)
            break;
        else if(s.pno == id)
        {
            if(qty > s.stock)
            {
                cout << "\nYou can't buy more than " << s.stock << ".\n";
                return;
            }
            strcpy(name,s.name);
            prz = s.price;
            s.stock -= qty;
            file.seekp(-(int)sizeof(saree),ios::cur);
            file.write((char*)&s,sizeof(saree));
            file.close();
            return;
        }

    }
    file.close();

    tops t;
    file.open("tops.dat",ios::in|ios::out|ios::ate);
    file.seekg(0,ios::beg);
    while(true)
    {
        file.read((char*)&t,sizeof(tops));
        if(!file)
            break;
        else if(t.pno == id)
        {
            if(qty > t.stock)
            {
                cout << "\nYou can't buy more than " << t.stock << ".\n";
                return;
            }
            strcpy(name,t.name);
            prz = t.price;
            t.stock -= qty;
            file.seekp(-(int)sizeof(tops),ios::cur);
            file.write((char*)&t,sizeof(tops));
            file.close();
            return;
        }

    }
    file.close();

    jewel j;
    file.open("jewel.dat",ios::in|ios::out|ios::ate);
    file.seekg(0,ios::beg);
    while(true)
    {
        file.read((char*)&j,sizeof(jewel));
        if(!file)
            break;
        else if(j.pno == id)
        {
            if(qty > j.stock)
            {
                cout << "\nYou can't buy more than " << j.stock << ".\n";
                return;
            }
            strcpy(name,j.name);
            prz = j.price;
            j.stock -= qty;
            file.seekp(-(int)sizeof(jewel),ios::cur);
            file.write((char*)&j,sizeof(jewel));
            file.close();
            return;
        }

    }
    file.close();

    foot f;
    file.open("foot.dat",ios::in|ios::out|ios::ate);
    file.seekg(0,ios::beg);
    while(true)
    {
        file.read((char*)&f,sizeof(foot));
        if(!file)
            break;
        else if(f.pno == id)
        {
            if(qty > f.stock)
            {
                cout << "\nYou can't buy more than " << f.stock << ".\n";
                return;
            }
            strcpy(name,f.name);
            prz = f.price;
            f.stock -= qty;
            file.seekp(-(int)sizeof(foot),ios::cur);
            file.write((char*)&s,sizeof(foot));
            file.close();
            return;
        }

    }
    file.close();

    cosmetics c;
    file.open("cosmetics.dat",ios::in|ios::out|ios::ate);
    file.seekg(0,ios::beg);
    while(true)
    {
        file.read((char*)&c,sizeof(cosmetics));
        if(!file)
            break;
        else if(c.pno == id)
        {
            if(qty > c.stock)
            {
                cout << "\nYou can't buy more than " << c.stock << ".\n";
                return;
            }
            strcpy(name,c.name);
            prz = c.price;
            c.stock -= qty;
            file.seekp(-(int)sizeof(cosmetics),ios::cur);
            file.write((char*)&s,sizeof(cosmetics));
            file.close();
            return;
        }

    }
    file.close();
    return;
}

