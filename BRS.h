#include<bits/stdc++.h>
using namespace std;
namespace BUS_namespace
{
	class Bus
	{
	    private:
	        string busn, driver;
	        string seat[8][4];
	        pair<string,string>src_dest;
	        pair<string,string>arr_dep;
	    public:
	        Bus()
	        {
	            for(int i=0; i<8;i++)
	                for(int j=0;j<4;j++)
	                    seat[i][j]="Empty";
	        }
	        string Allot_Bus(Bus&);
	        void Remove_Bus();
	        void Show_Buses();
	        void Allot_Seat();
	        void Show_seats();
	        bool Search_Busses();
	        void check_seats(int,Bus&);
	};
	//Declaration of Map
	map<string,Bus>Bus_data;
	//To draw vertical lines
	void vline(char ch)
	{
	  for (int i=80;i>0;i--)
	    cout<<ch;
	}
	//To alot bus and driver to bus
	string Bus::Allot_Bus(Bus &bus)
	{
	    string arr,dep,from,to;
	    cin.ignore();
	    cout<<"Enter bus no: ";
	    getline(cin,bus.busn);
	    cout<<"Enter Driver's name: ";
	    getline(cin,bus.driver);
	    cout<<"Arrival time: ";
	    getline(cin,arr);
	    cout<<"Departure: ";
	    getline(cin,dep);
	    cout<<"From: ";
	    getline(cin,from);
	    cout<<"To: ";
	    getline(cin,to);
	    bus.src_dest=make_pair(from,to);
	    bus.arr_dep=make_pair(arr,dep);
	    return bus.busn;
	}
	//To search in busses
	bool Bus::Search_Busses()
	{
	    char ch;
	    cout<<"Press 1 to search Busses by Bus number\nPress 2 to search Busses by cities\n";
	    cout<<"Enter your choice : ";
	    cin>>ch;
	    if(ch=='1')
	    {
	        string num;
	        cout<<"Enter the bus number : ";
	        cin>>num;
	        if(Bus_data.find(num)!=Bus_data.end())
	        {
	            auto x=Bus_data.find(num);
	            Bus bus=x->second;
	            cout<<"\nBus no: "<<bus.busn<<"\nDriver: "<<bus.driver
	                <<"\t\tArrival time: "<<bus.arr_dep.first<<"\tDeparture Time: "
	                <<bus.arr_dep.second<<"\nFrom: "<<bus.src_dest.first<<"\t\tTo: "
	                <<bus.src_dest.second<<"\n";
	        }
	        else
	        {
	            cout<<"Sorry,no bus with this number availble";
             	return 0;
            } 
	        vline('*');
	    }
	    else if(ch=='2')
	    {
	        int flag=0;
	        string src,dest;
	        cin.ignore();
	        cout<<"Enter the source city : ";
	        getline(cin,src);
	        cout<<"Enter the destination city : ";
	        getline(cin,dest);
	        for(auto x : Bus_data)
	    	{
	            Bus bus=x.second;
	            fflush(stdin);
	            if(bus.src_dest.first==src && bus.src_dest.second==dest)
	            {
	                cout<<"\nBus no: "<<bus.busn<<"\nDriver: "<<bus.driver
	                    <<"\t\tArrival time: "<<bus.arr_dep.first<<"\tDeparture Time: "
	                    <<bus.arr_dep.second<<"\nFrom: "<<bus.src_dest.first<<"\t\tTo: "
	                    <<bus.src_dest.second<<"\n";
	                    flag=1;
	            }
	            vline('*');
	        }
	        if(!flag)
	        {
	            cout<<"No bus from "<<src<<" to "<<dest<<" availble";
	            return 0;
	        }
	    }
	    else
	    	cout<<"\n\t\t\tWrong Choice\n";
	}
	//To remove bus
	void Bus::Remove_Bus()
	{
	    if(Bus_data.empty())
	    {
	        cout<<"\n\t\t\tSorry no bus availble now\n";
	        return;
	    }
	    string number;
	    cout<<"Enter the bus number to be removed :";
	    cin.ignore();
	    getline(cin,number);
	    if(Bus_data.find(number)==Bus_data.end())
	        cout<<"No bus of number :"<<number<<" exist \n";
	    else
	    {
	        auto it=Bus_data.find(number);
	        Bus_data.erase(number);
	        cout<<"Bus with bus number : "<<number<<" has been removed \n";
	    }
	}
	//To book seats by the passenger
	void Bus::Allot_Seat()
	{
	    if(Bus_data.empty())
	    {
	        cout<<"\n\t\t\tSorry no bus availble now\n";
	        return;
	    }
	    int seat;
	    string number;
	    Bus bus;
	    cout<<"\nCheck your bus is availble or not\n";
	    if(bus.Search_Busses())
	    {
	    top:
	        cin.ignore();
	        cout<<"Bus no: ";
	        getline(cin,number);
	        int n;
	        if(Bus_data.find(number)==Bus_data.end())
	        {
	            char ch;
	            cout<<"No bus availble with bus number "<<number<<endl;
	            cout<<"Press 1 to check again else to cancel : ";
	            cin>>ch;
	            if(ch=='1')
	                goto top;
	        }
	        else
	        {
	            auto x=Bus_data.find(number);
	            bus=(*x).second;
	        }
	        while(Bus_data.find(number)!=Bus_data.end())
	        {
	            cout<<"\nSeat Number: ";
	            cin>>seat;
	            if(seat>32)
	                cout<<"\nThere are only 32 seats availble in this bus.";
	            else
	            {
	                if (bus.seat[seat/4][(seat%4)-1]=="Empty")
	                {
	                    cout<<"Enter passanger's name: ";
	                    cin>>bus.seat[seat/4][(seat%4)-1];
	                    Bus_data[number]=bus;
	                    break;
	                }
	                else
	                    cout<<"The seat no. is already reserved.\n";
	            }
	        }
	    }
	}
	//To check the availble seats
	void Bus::Show_seats()
	{
	    if(Bus_data.empty())
	    {
	        cout<<"\n\t\t\tSorry no bus availble now\n";
	        return;
	    }
	    int n;
	    char number[15];
	    cout<<"Enter bus no: ";
	    cin>>number;
	    if(Bus_data.find(number)==Bus_data.end())
	        cout<<"No bus availble with this number";
	    else
	    {
	        auto x= Bus_data.find(number);
	        Bus bus=(*x).second;
	        vline('*');
	        cout<<"\nBus no: "<<bus.busn<<"\nDriver: "<<bus.driver
	            <<"\t\tArrival time: "<<bus.arr_dep.first<<"\tDeparture Time: "
	            <<bus.arr_dep.second<<"\nFrom: "<<bus.src_dest.first<<"\t\tTo: "
	            <<bus.src_dest.second<<"\n";
	        vline('*');
	        //To check seats
	        bus.check_seats(n,bus);
	        int a=1;
	        for(int i=0; i<8; i++)
	        {
	            for(int j=0;j<4;j++)
	            {
	                a++;
	                if(bus.seat[i][j]!="Empty")
	                    cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus.seat[i][j]<<".";
	            }
	        }
	    }
	}
	//To select seats
	void Bus::check_seats(int l,Bus &bus)
	{
	    int seat_no=0,emp_seats=0;
	    //Rows
	    for (int i =0; i<8;i++)
	    {
	        cout<<"\n";
	        //Columns
	        for (int j = 0;j<4; j++)
	        {
	            seat_no++;
	            if(bus.seat[i][j]=="Empty")
	            {
	                cout.width(5);
	                cout.fill(' ');
	                cout<<seat_no<<".";
	                cout.width(10);
	                cout.fill(' ');
	                cout<<bus.seat[i][j];
	                emp_seats++;
	            }
	            else
	            {
	                cout.width(5);
	                cout.fill(' ');
	                cout<<seat_no<<".";
	                cout.width(10);
	                cout.fill(' ');
	                cout<<bus.seat[i][j];
	            }
	        }
	    }
	    cout<<"\n\nThere are "<<emp_seats<<" seats empty in Bus No: "<<bus.busn;
	}
	//Checking Availblity of busses
	void Bus::Show_Buses()
	{
	    if(!Bus_data.empty())
	    {
	        for(auto x : Bus_data)
	        {
	            Bus bus=x.second;
	            fflush(stdin);
	            vline('*');
	           cout<<"\nBus no: "<<bus.busn<<"\nDriver: "<<bus.driver
	                <<"\t\tArrival time: "<<bus.arr_dep.first<<"\tDeparture Time: "
	                <<bus.arr_dep.second<<"\nFrom: "<<bus.src_dest.first<<"\t\tTo: "
	                <<bus.src_dest.second<<"\n";
	            vline('*');
	        }
	    }
	    else
	        cout<<"\n\t\t\tSorry no bus availble now";
	}
}//End of namespace BUS