#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*  grocery list creation project
    1> customer with list i.e item he want to purchase
    2> he added the item
    3> total sum of amount he want to pay
    4> if he wish to remove item due to over budget delete
    5> actual amount to be pay by customer
*/

   int i=0;
   int item [100];
   int cost [100];
   int amount[100];

class grocery
{
    public:
    int cnt=0;
    void itemandcost();
    void additeminlist();
    int  totalsum();
    double discount(int);
    void removeitem();
    void showlist();

};

void grocery::itemandcost()
{
    cout<<"the item and its cost"<<endl;
    cout<<"\n--------------------------------\n"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<"item :"<<i+1<<"  ";
        item[i]=i+1;
        cout<<"cost :"<<(i+1)*20<<endl;
        cost[i]=(i+1)*20;
    }
    cout<<"\n--------------------------------\n"<<endl;
}
int m=0;
void grocery::additeminlist()
{
    int num;int flag=1;char res;
    cout<<"enter the item number to add in list:";
    cin>>num;
    amount[m++]=cost[num-1];
    if(num <=0 && num > 10)
    {
        cout<<"please enter valid choice"<<endl;
    }
    else{
    while(flag){
    ++cnt;
    cout<<"do you wish to add more items [ y / n ] :";
    cin>>res;
    if(res=='y'){
       flag=1;
    }
       else{
       flag=0;
        }
        if(flag){
    cout<<"enter the item number to add in list:";
    cin>>num;
    amount[m++]=cost[num-1];
        }
    }
    }
}

int grocery::totalsum()
{    int sum=0;
    for(i=0;i<cnt;i++)
    {
        sum=sum+amount[i];
    }
    return sum;
}
int flag=0;
double grocery::discount(int value)
{
    int a=0;flag++;
    if(value > 500 && flag)
    {
        a=(value * 10 )/100;
        cout<<"10 % discount applied "<<a<<" Rs saved on purchase"<<endl;
    }
    else
    {
        cout<<"you are "<<(500-value)<<" RS away to get 10 % discount purchase more item"<<endl;
    }
    return double(a) ;
}
void grocery::showlist()
{
    for(i=0;i<cnt;i++)
    {
        cout<<i+1<<" item is "<<amount[i]<<" its price."<<endl;
    }
}

void grocery::removeitem()
{
    int rem;int i;
    cout<<"enter the item number to be removed:";
    cin>>rem;
    for(i=0;i<cnt;i++)
    {
        if(i+1 == rem){
        amount[i]=0;
        break;
        }
    }
    cout<<i+1<<" "<<"successfully removed from your list"<<endl;
}

using namespace std;

int main()
{
    grocery g;
    int ch,value=0,finalamount=0;
    cout<<"WELECOME TO THE GROCERY STORE"<<endl;
    while(1){
    cout<<"\n=========================================\n"<<endl;

    cout<<" 1>item and its cost\n 2>add the item in list"<<endl;
    cout<<" 3>remove the item\n 4>discount\n 5>total sum"<<endl;
    cout<<" 6>actual amount pay\n 7>your list\n 8>all item purchased "<<endl;

    cout<<"\n=========================================\n"<<endl;
    cout<<"enter your choice :"<<endl;
    cin>>ch;
    cout<<"\n=========================================\n"<<endl;
    switch(ch)
    {
    case 1:
        g.itemandcost();
        break;
    case 2:
        g.additeminlist();
        break;
    case 3:
        g.removeitem();
        break;
    case 4:
        finalamount=g.discount(value);
        break;
    case 5:
        value=g.totalsum();
        if(value>=500){
            cout<<"you are applicable for 10% discount"<<endl;}
        cout<<"your total item cost is :"<<value<<endl;
        break;
    case 6:
        cout <<" you grocery final bill = " <<value-finalamount<<endl;
        break;
    case 7:
        cout<<"your grocery list is:"<<endl;
        g.showlist();
        break;
    case 8:
        cout<<"thanks for visiting our grocery store"<<endl;
        cout<<"VISIT AGAIN !!!"<<endl;
        exit(0);
    default:
        cout<<"enter the proper choice from 1 to 7"<<endl;
    }
}
    return 0;

}
