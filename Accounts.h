#include<bits/stdc++.h>
using namespace std;
namespace Accounts_namespace
{
	ofstream fout;
	ifstream fin;
	class Register
	{
		public :
			pair<string,string>name;
			pair<string,string>id_pass;
			string email,phone_no;
	};
	//Contains all the validation functions of Account
	namespace Account_validation_namespace
	{
		bool isValidEmail(string email)
		{
			const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		    return regex_match(email,pattern);
		}
		bool isValidPhone(string pno) 
		{ 
		    const regex pattern("[0/91]?[6-9][0-9]{9}");
		    return regex_match(pno,pattern);
		}
		//To check for file is empty
		bool is_empty(std::ifstream& pFile)
		{
	    	return pFile.peek() == std::ifstream::traits_type::eof();
		}
		bool isExist(string usr)
		{
			Register ob;
			fin.open("Accounts_info", ios::in);
	 		while(fin >> ob.id_pass.first)
	 			if(ob.id_pass.first==usr)
	 				return 1;
	 		fin.close();
	 		return 0;
	 	}
	}
	using namespace Account_validation_namespace;
	//To create horizontal lines
	void hline(char ch)
	{
	  for (int i=120;i>0;i--)
	    cout<<ch;
	}
	//User Function	
 	void makeAccount()
 	{
 		Register ob;
 		cin.ignore();
 		fout.open("Accounts_info", ios::app);
 		cout<<"Enter your first name :";
 		getline(cin,ob.name.first);
 		cout<<"Enter your second name :";
 		getline(cin,ob.name.second);
 		USERNAME :
	 		cout<<"Enter the user name : ";
	 		getline(cin,ob.id_pass.first);
	 		if(isExist(ob.id_pass.first))
	 		{
	 			cout<<"This user name already exist!!! Try another\n";
	 			goto USERNAME;
	 		}
 		cout<<"Enter the password : ";
 		getline(cin,ob.id_pass.second);
 		PHONE :
	 		cout<<"Enter the phone number : ";
	 		getline(cin,ob.phone_no);
	 		if(!isValidPhone(ob.phone_no))
	 		{
	 			cout<<"Phone number not correct!!! Try again\n";
	 			goto PHONE;
	 		}
 		EMAIL :
 			cout<<"Enter your email address : ";
 			getline(cin,ob.email);
 			if(!isValidEmail(ob.email))
 			{
 				cout<<"Email not correct!!! Try again\n";
 				goto EMAIL;
 			}
 		fout<<ob.name.first<<" "<<ob.name.second<<" "<<ob.id_pass.first<<" "
 			<<ob.id_pass.second<<" "<<ob.phone_no<<" "<<ob.email<<"\n";
 		system("clear");
 		cout<<"\n\t\t\tAccount created succesfully,\n\t\t\tLogin to continue\n";
 		fout.close(); 
 	}
 	//User Function
 	void showProfile(string usr_nm)
 	{
 		Register ob;
 		system("clear");
 		fin.open("Accounts_info",ios::in);
 		while(fin >> ob.name.first >> ob.name.second >> ob.id_pass.first >>ob.id_pass.second >>ob.phone_no>>ob.email)
 			if(ob.id_pass.first==usr_nm)
 				cout<<"\nName : "<<ob.name.first<<" "<<ob.name.second
 					<<"\nUsername : "<<ob.id_pass.first
 					<<"\nPassword : "<<ob.id_pass.second
 					<<"\nPhone Number : "<<ob.phone_no
 					<<"\nEmail : "<<ob.email
 					<<endl;	
 		fin.close();
 	}
 	//Admin Funtction
 	void showallProfile()
 	{
 		Register ob;
 		fflush(stdin);
 		fin.open("Accounts_info", ios::in);
 		if(is_empty(fin))
 		{
 			cout<<"\n\t\t\tNot any user registered till now.\n";
 			return;
 		}
 		cout<<"\n\n\t\tThese are the users profile who registered.\n\n";
 		hline('*');
 		while(fin >> ob.name.first >> ob.name.second >> ob.id_pass.first >>ob.id_pass.second >>ob.phone_no>>ob.email)
 		{
 			cout<<endl;
 			cout<<" Name : "<<ob.name.first<<" "<<ob.name.second
 				<<" Username : "<<ob.id_pass.first
 				<<" Password : "<<ob.id_pass.second
 				<<" Phone Number : "<<ob.phone_no
 				<<" Email : "<<ob.email
 				<<endl;
 			hline('-');
 		}
 		cout<<endl;
 		hline('*');
 		fin.close();
 	}
 	//User Function
 	string Login()
 	{
 		system("clear");
 		cout<<"\n\t\t\tPlease,Login to continue.\n";
 		string usr_nm,password;
 		cout<<"\t\tEnter your user name : ";
 		cin>>usr_nm;
 		cout<<"\t\tEnter your password : ";
 		cin>>password;
 		Register ob;
 		fflush(stdin);
 		fin.open("Accounts_info", ios::in);
 		while(fin >> ob.id_pass.first >>ob.id_pass.second)
 		{
 			if(ob.id_pass.first==usr_nm && ob.id_pass.second==password)
 				return usr_nm;	
 			else if(ob.id_pass.first==usr_nm && ob.id_pass.second!=password)
 			{
 				cout<<ob.id_pass.first<<"  "<<ob.id_pass.second<<endl;
 				fin.close();
 				cout<<"\t\t\tPassword Incorrect\n";
 				return "\0";
 			}
 		}
 		cout<<"\t\tYour account doesn't exist\n\t\tRegister to continue";
 		fin.close();
 		return "\0";
 	}
 	//User Function
 	void modifyProfile(string usr_nm)
 	{
 		Register ob;
 		fin.open("Accounts_info",ios::in);
 		fout.open("temp",ios::out);
 		while(fin >> ob.name.first >> ob.name.second >> ob.id_pass.first >>ob.id_pass.second >>ob.phone_no>>ob.email)
 		{
 			if(ob.id_pass.first!=usr_nm)
 				fout<<ob.name.first<<" "<<ob.name.second<<" "<<ob.id_pass.first<<" "
 					<<ob.id_pass.second<<" "<<ob.phone_no<<" "<<ob.email<<"\n";
 			else
 			{
 				cout<<"\t\tNote : You can't modify your username\n";
 				cin.ignore();
 				cout<<"Enter your first name :";
 				getline(cin,ob.name.first);
 				cout<<"Enter your second name :";
 				getline(cin,ob.name.second);
 				cout<<"Enter the password : ";
 				getline(cin,ob.id_pass.second);
 				PHONE :
			 		cout<<"Enter the phone number : ";
			 		getline(cin,ob.phone_no);
			 		if(!isValidPhone(ob.phone_no))
			 		{
			 			cout<<"Phone number not correct!!! Try again\n";
			 			goto PHONE;
			 		}
		 		EMAIL :
		 			cout<<"Enter your email address : ";
		 			getline(cin,ob.email);
		 			if(!isValidEmail(ob.email))
		 			{
		 				cout<<"Email not correct!!! Try again\n";
		 				goto EMAIL;
		 			}
 				fout<<ob.name.first<<" "<<ob.name.second<<" "<<ob.id_pass.first<<" "
 					<<ob.id_pass.second<<" "<<ob.phone_no<<" "<<ob.email<<"\n";
 			}
 		}
 		fin.close();
 		fout.close();
 		remove("Accounts_info");
 		rename("temp","Accounts_info");
 		cout<<"\n\t\tAccount data modified";
 	}
 	//User Function
 	void deleteProfile(string usr_nm)
 	{
 		Register ob;
 		fin.open("Accounts_info",ios::in);
 		fout.open("temp",ios::out);
 		while(fin >> ob.name.first >> ob.name.second >> ob.id_pass.first >>ob.id_pass.second >>ob.phone_no>>ob.email)
 		{
 			if(ob.id_pass.first!=usr_nm)
 				fout<<ob.name.first<<" "<<ob.name.second<<" "<<ob.id_pass.first<<" "
 					<<ob.id_pass.second<<" "<<ob.phone_no<<" "<<ob.email<<"\n";
 		}
 		fin.close();
 		fout.close();
 		remove("Accounts_info");
 		rename("temp","Accounts_info");
 		cout<<"\n\t\tProfile with username : "<<usr_nm<<" deleted";
 	}
}

