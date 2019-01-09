#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

class Customer{
	private:
		string userId;
		string passWord;
		string name;
		string city;
		int areaCode;
		string preferedLaundry;
		string l_ssn;
	public :
		/* since for new customer will have no history thats why preferedlaundry will be null
		the purpose for customer class is to register the user and access data from file*/
		Customer()
		{
			preferedLaundry=preferedLaundry+"No Data Found.....";
		}
		
		/*all set methods*/
		void setL_ssn(string str)
		{
			l_ssn=str;
		}
		void setpassWord(const string &pass)
		{
			passWord=pass;
		}
		void setuserId(const string &userId)
		{
			this->userId=userId;
		}
		void setName(const string &name)
		{
			this->name=name;
		}
		void setCity(const string &city)
		{
			this->city=city;
		}
		void setareaCode(const int &areaCode)
		{
			this->areaCode=areaCode;
		}
		void setPreferedLaundry(string str)
		{
			preferedLaundry=str;
		}
		
		//------------------------------------------------------------------------------------------------------------
		/*all get methods*/
		
		string getuserId()
		{
			return userId;
		}
		string getName()
		{
			return name;
		}
		string getCity()
		{
			return city;
		}
		int getareaCode()
		{
			return areaCode;
		}
		string getPassWord()
		{
			return passWord;
		}
		string getPreferedLaundry()
		{
			return preferedLaundry;
		}
		string getL_ssn()
		{
			return l_ssn;
		}
		/*To save user*/
		void saveCustomer()
		{
			string temp=userId+".cust";
			ofstream file;
			file.open(temp.c_str());
			char temparr[200];
			
			strcpy(temparr,passWord.c_str());
			file<<temparr<<"\n";
			
			strcpy(temparr,userId.c_str());
			file<<temparr<<"\n";
			
			strcpy(temparr,name.c_str());
			file<<temparr<<"\n";
			
			strcpy(temparr,city.c_str());
			file<<temparr<<"\n";
			
			file<<areaCode;
			
			strcpy(temparr,preferedLaundry.c_str());
			file<<temparr<<"\n";
			
			strcpy(temparr,l_ssn.c_str());
			file<<temparr<<"\n";
			
			file.close();
			cout<<"Customer information saved......."<<endl;
		}
		
		/*to get information from user*/
		void custRegister()
		{
			cout<<endl<<"---------**Customer Registration**---------"<<endl;
			bool flag=false;
			do{
				cout<<"User_Id : ";
				cin>>userId;
				ifstream file;
				string temp=userId+".cust";
				file.open(temp.c_str());
				if(file){
					flag=true;
					cout<<"UserId already exist please try another one......"<<endl;
				}
				else
					flag=false;
				file.close();
			}while(flag==true);
			
			cin.ignore();
			cout<<"PassWord : ";
			cin>>passWord;
			
			cin.ignore();
			cout<<"Name : ";
			getline(cin,name);
			
			cout<<"City : ";
			cin>>city;
			
			cout<<"Area Code : ";
			cin>>areaCode;
			this->saveCustomer();
		}
		
		/*To load a customer*/
		bool loadCustomer(const string Id)
		{
			
			string temp =Id+".cust";
			ifstream file(temp.c_str());

			/*if user is not registered or programe is unable to read the file*/
			if(!file)
			{
				cout<<"\tSorry......Unable to load file!!"<<endl;
				return false;
			}
			else
			{
				getline(file,passWord);
				getline(file,userId);
				getline(file,name);
				getline(file,city);
				file>>areaCode;
				getline(file,preferedLaundry);
				getline(file,l_ssn);
			}
		}
		/* first load file then call this method*/
		void showCustDetail()
		{
			cout<<endl<<"---------**Customer Deatails**---------"<<endl;
			cout<<"\tUser_id : "<<userId<<endl;
			cout<<"\tName : "<<name<<endl;
			cout<<"\tCity : "<<city<<endl;
			cout<<"\tAreaCode : "<<areaCode<<endl;
			cout<<"\tPrefered Laundry : "<<preferedLaundry<<endl;
			cout<<"\tL_ssn : "<<l_ssn<<endl;
		}
};
