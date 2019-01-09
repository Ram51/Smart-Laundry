/*
using namespace std;
*/
class Laundry{
	private :
		string ssn;
		string name;
		string city;
		int areaCode;
		//float rating;
		
		/*rate list*/ 
		int tshirtWash;
		int shirtWash;
		int pantWash;
		int bedsheetWash;
		int woolenWash;
		int shorts;
		int dryclean;
		int iron;
		
	public :
		string getName()
		{
			return name;
		}
		int getTshirtWash()
		{
			return tshirtWash;
		}
		int getShirtWash()
		{
			return shirtWash;
		}
		int getPantWash()
		{
			return pantWash;
		}
		int getBedsheetWash()
		{
			return bedsheetWash;
		}
		int getWoolenWash()
		{
			return woolenWash;
		}
		int getShorts()
		{
			return shorts;
		}
		int getDryclean()
		{
			return dryclean;
		}
		int getIron()
		{
			return iron;
		}
		
		
		void saveLaundry()
		{
			ofstream file;
			string temp=ssn+".ld";
			file.open(temp.c_str());
			char arr[100];
			strcpy(arr,ssn.c_str());
			file<<arr<<"\n";
			
			strcpy(arr,name.c_str());
			file<<arr<<"\n";
			
			strcpy(arr,city.c_str());
			file<<arr<<"\n";
			
			file<<areaCode<<"\n";
			file<<tshirtWash<<"\n";
			file<<shirtWash<<"\n";
			file<<pantWash<<"\n";
			file<<bedsheetWash<<"\n";
			file<<woolenWash<<"\n";
			file<<shorts<<"\n";
			file<<dryclean<<"\n";
			file<<iron<<"\n";
			file.close();
			cout<<"!!!!!!Data saved........"<<endl;
		}
		void laundryRegistration()
		{
			cout<<"\t*************Registration Form*************"<<endl<<endl;
			cout<<"Laundry Name : ";
			cin.ignore();
			getline(cin,name);
			
			bool flag=true;
			while(flag){ 
				cout<<"city : ";
				cin>>city;
				string temp= city+".map";
				ifstream file(temp.c_str());
				if(file)
				{
					flag=false;
					file.close();
				}
				else
				{
					cout<<"Sorry No Such city exit ......Try again!!!"<<endl;
				}
			}
			cout<<"Area Code : ";
			cin>>areaCode;
			
			cout<<"\t<< Rate List >>"<<endl<<endl;
			cout<<"Tshirt Wash : ";
			cin>>tshirtWash;
			
			cout<<"Shirt Wash : ";
			cin>>shirtWash;
			
			cout<<"Pant Wash : ";
			cin>>pantWash;
			
			cout<<"Bedsheet Wash : ";
			cin>>bedsheetWash;
			
			cout<<"Woolen Wash : ";
			cin>>woolenWash;
			
			cout<<"Shorts : ";
			cin>>shorts;
			
			cout<<"Dry Cleaning : ";
			cin>>dryclean;
			
			cout<<"Iron : ";
			cin>>iron;
			
			Map m;
			m.updateLaundry(city); // to load and update data in matadata of map
			
			/*all this stuff is for generating ssn*/
			
			int x=m.getNumberOfLaundriesAtLocation(areaCode);
			char buffer[10];
			sprintf(buffer,"%d",areaCode); //to convert integer into string
			ssn=city+"_"+buffer;
			sprintf(buffer,"%d",x); //to convert integer into stirng
			ssn=ssn+"_"+buffer;
			cout<<"Your Social Security Number : "<<ssn<<endl;
			this->saveLaundry();
			getch();
		}
		bool loadLaundry(string s)
		{
			s=s+".ld";
			ifstream file;
			file.open(s.c_str());
			if(file){
			getline(file,ssn);
			getline(file,name);
			getline(file,city);
			
			file>>areaCode;
			file>>tshirtWash;
			file>>shirtWash;
			file>>pantWash;
			file>>bedsheetWash;
			file>>woolenWash;
			file>>shorts;
			file>>dryclean;
			file>>iron;
			return true;
		}
		else
		{
			cout<<"Sorry No data found........"<<endl;
			return false;
		}
	}
	
	void showLaundry(string s) //s=ssn
	{
		if(this->loadLaundry(s)){
			cout<<endl<<"********* Laundry Details*********"<<endl<<endl;
			cout<<"Social Security Number : "<<ssn<<endl;
			cout<<"Laundry name : "<<name<<endl;
			cout<<"City : "<<city<<endl;
			cout<<"Area Code : "<<areaCode<<endl;
			
			cout<<"<<\tRate List\t>>"<<endl;
			cout<<"-------------------------------------"<<endl;
			cout<<"Service       :      Rate"<<endl;
			cout<<"-------------------------------------"<<endl;
			cout<<"Tshirt Wash   :     "<<tshirtWash<<endl;
			cout<<"Shirt Wash    :     "<<shirtWash<<endl;
			cout<<"Pant Wash     :     "<<pantWash<<endl;
			cout<<"Bedsheet Wash :     "<<bedsheetWash<<endl;
			cout<<"Woolen wash   :     "<<woolenWash<<endl;
			cout<<"Shorts Wash   :     "<<shorts<<endl;
			cout<<"Dry Cleaning  :     "<<dryclean<<endl;
			cout<<"Iron          :     "<<iron<<endl;
			cout<<"-------------------------------------"<<endl;
		}
		getch();
	}
};
/*int main()
{
	Laundry l;
	l.laundryRegistration();
	//l.showLaundry("Indore_0_1");
}*/
