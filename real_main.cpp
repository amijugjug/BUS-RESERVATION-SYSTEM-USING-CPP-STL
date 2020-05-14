#include<bits/stdc++.h>
#include"BRS.h"
#include"Accounts.h"
using namespace std;
using namespace Bus_namespace;
using namespace Accounts_namespace;
//Varrible to hold screen
char stop;
//For Administrator Login
void AdminChoice(string usr_nm,string password)
{
    if(usr_nm!="Admin" || password!="Admin")
    {
    	system("clear");
        cout<<"\a\a\a\n";
        cout<<"\t\t\tValid Identity not found\n"
            <<"\t\t\tfor Administrator Portal\n";
        return;
    }
    Bus bus;
    char choice;
    string num;
    while(1)
    {
        system("clear");
        again:
        cout<<"\n\n\n";
        cout<<"\t\t\t1.Allot Bus\n\t\t\t"
            <<"2.Remove Bus\n\t\t\t"
            <<"3.Reservation\n\t\t\t"
            <<"4.Check seats\n\t\t\t"
            <<"5.Check bus\n\t\t\t"
            <<"6.Show all users\n\t\t\t"
            <<"7.Make a user Profile\n\t\t\t"
            <<"8.Modify a user Profile\n\t\t\t"
            <<"9.Delete a user Profile\n\t\t\t"
            <<"0.Logout";
        cout<<"\n\t\t\tEnter your choice:-> ";
        cin>>choice;
        switch(choice)
        {
            case '1':
                //To alot a bus
                num=bus.Allot_Bus(bus);
                Bus_data[num]=bus;
            break;
            case '2':
                //Remove bus by checking the bus number
                bus.Remove_Bus();
            break;
            case '3':
               //Reservation of seats in a bus
                bus.Allot_Seat();
            break;
            case '4':
                //Show availble seats in a bus
                bus.Show_seats();
            break;
            case '5':
                //Show availble buses
                bus.Show_Buses();
            break;
            case '6':
                showallProfile();
            break;
            case '7':
                makeAccount();
            break;
            case '8':
            {
            	string user_name;
            	cout<<"\nEnter the username of user : ";
            	cin>>user_name;
            	modifyProfile(user_name);
            }
            break;
            case '9':
            {
            	string user_name;
            	cout<<"\nEnter the username of user : ";
            	cin>>user_name;
            	deleteProfile(user_name);
            }
            break;
            case '0':
            	return;
            break;
            default:
                cout<<"\t\t\tYou pressed a wrong key\n";
            break;
        }
        cout<<"\n\t\t\tPress any key then hit enter to continue : ";
      	cin>>stop;
    }
}
//For User login
void UserChoice(string usr_nm)
{
   Bus bus;
   char choice;
   string num;
   while(1)
   {
       system("clear");
       again:
       cout<<"\n\n\n";
       cout<<"\t\t\t1.Reserve Seats\n\t\t\t"
           <<"2.Check seats\n\t\t\t"
           <<"3.Check buses\n\t\t\t"
           <<"4.View own Profile\n\t\t\t"
           <<"5.Edit Profile\n\t\t\t"
           <<"6.Delete Profile\n\t\t\t"
           <<"7.Logout";
       cout<<"\n\t\t\tEnter your choice:-> ";
       cin>>choice;
       switch(choice)
        {
            case '1':
            //Reservation of seats in a bus
                bus.Allot_Seat();
            break;
            case '2':
                //Show availble seats in a bus
                bus.Show_seats();
            break;
            case '3':
                //Show availble buses
                bus.Show_Buses();
            break;
            case '4':
                showProfile(usr_nm);
                showProfile(usr_nm);
            break;
            case '5':
                modifyProfile(usr_nm);
            break;
            case '6':
            	deleteProfile(usr_nm);
            	return;
            break;
            case '7':
            	system("clear");
                return;
            break;
            default:
                cout<<"\t\t\tYou pressed a wrong key\n";
            break;
        }
		cout<<"\n\t\t\tPress any key then hit enter to continue : ";
		cin>>stop;
    }
}
int main()
{
	char choice;
	string usr_name,password;
	while(1)
	{
		system("clear");
		again:
		cout<<"\n\t\tPress 0 to enter through Admin Portal\n"
			<<"\t\t\tPress 1 to Login \n"
			<<"\t\t\tPress 2 to Register\n"
			<<"\t\t\tOr any key to exit.\n"
			<<"\t\t\tEnter your choice :";
		cin>>choice;
		switch(choice)
		{
			case '0':
				system("clear");
				cout<<"\t\t\tEnter the admin username :";
				cin>>usr_name;
				cout<<"\t\t\tEnter the password :";
				cin>>password;
				AdminChoice(usr_name,password);
				goto again;
			break;
			case '1':
			{
				while(1)
				{
					usr_name=Login();
					if(usr_name!="\0")
					{
						UserChoice(usr_name);
						goto again;
					}
					else
					{
						cout<<"\n\t\t\tPress 1 to Register \n"
							<<"\t\t\tOr any key to exit\n"
							<<"\t\t\tEnter your choice :";
						cin>>choice;
						switch(choice)
						{
							case '1':
								makeAccount();
								cout<<"\n\t\t\tNow,Login to Continue.";
								goto again;
							default:
								exit(0);
						}
					}
				}
			}
			break;
			case '2':
				makeAccount();
				goto again;		
			break;
			default:
				exit(0);
		}
	}
	return 0;
}
