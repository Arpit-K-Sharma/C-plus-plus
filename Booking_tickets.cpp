#include <iostream>
using namespace std;

class Tickets
{
public:
    static int total_ticket, count;

    static void book(int num)
    {
    total_ticket -= num;
    count += 1;
    }

    static void cancel(int num)
    {
    total_ticket += num;
    }

    static int val()
    {
    return total_ticket;
    }
};

int Tickets :: total_ticket = 100;
int Tickets :: count = 0;
int main()
{
Tickets T1;
int choice,ticket,cancel_tic;
int total_tic_book = 0,total_tic_cancel = 0,c=1;
while (c==1)
{
cout<<"Choose whether you want to book or cancel the tickets "<<endl;
cout<<"1. Book Tickets"<<endl;
cout<<"2. Cancel Tickets"<<endl;
cout<<"3. Exit"<<endl;
cin>>choice;
switch (choice)
{
case 1:
    cout<<"Enter the number of tickets you want to book."<<endl;
    cin>>ticket;
    cout<<"\n";
    if (ticket<=T1.val() && ticket>=0)
    {
    T1.book(ticket);
    total_tic_book += ticket;
    cout<<"The number of ticket you have book is "<<ticket<<endl;
    cout<<"The remaining number of tickets are "<<T1.val()<<endl;
    cout<<"\n";
    }
    else
    {
    cout<<"Booking Failed. The number of tickets you want to book exceeds the total tickets allocated."<<endl;
    }
    break;

case 2:
    if(T1.count > 0)
    {
    cout<<"Enter the number of tickets you want to cancel "<<endl;
    cin>>cancel_tic;
    cout<<"\n";
    if(total_tic_book > cancel_tic)
    {
    total_tic_cancel+=cancel_tic;
    if(total_tic_book > total_tic_cancel && total_tic_cancel<T1.total_ticket)
    {
    T1.cancel(cancel_tic);
    cout<<"The number of ticket you have cancelled is "<<cancel_tic<<endl;
    cout<<"The remaining number of tickets are "<<T1.val()<<endl;
    cout<<"\n";
    }
    else
    {
    cout<<"Cancelling of tickets can't be proceeded as cancelling seats is more than the booked seat.1"<<endl;
    }
    }
    else
    {
    cout<<"The number of tickets you want to cancel exceeds the total number of tickets you have booked."<<endl;
    }
    }
    else
    {
    cout<<"Ticket Cancel Failed. Ticket should be booked before cancelling."<<endl;
    cout<<"\n";
    }
    break;

case 3:
    c = 2;
    cout<<"\n";
    cout<<"Thanks! For Using our booking system.";

default:
    break;
}
}
return 0;
}