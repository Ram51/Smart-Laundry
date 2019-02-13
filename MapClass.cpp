
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<fstream>
#include<cstdio>
#include<utility>

using namespace std;
class Map{
	private :
		string city;
		int vertex;
		int edges;
		int laundry;
		vector<pair<int,int> > laundries;
	public :
		int getVertex()
		{
			return vertex;
		}
		int getEdges()
		{
			return edges;
		}
		int getLaundry()
		{
			return laundry;
		}
		vector<pair<int,int> > getLaundries()
		{
			return laundries;
		}
		void createMap()
		{
			cout<<"-------------**Map Genration**-------------"<<endl;
			bool flag=true;
			while(flag)
			{
				cout<<"City : ";
				cin>>city;
				string temp = city+".map";
				ifstream file;
				file.open(temp.c_str());
				if(file)
				{
					cout<<"Sorry This city already exit.......Please Try another one"<<endl;
				}
				else
					flag=false;
				file.close();
			}
			cout<<"Number of nodes/vertex : ";
			cin>>vertex;
			cout<<"Number of edges/ways : ";
			cin>>edges;
			cout<<"Number of laundries : ";
			cin>>laundry;
			laundries.assign(vertex+1,make_pair<int,int> (0,0)); //first attribute for current , second for maximum
			for(int i=0;i<laundry;i++)
			{
				cout<<"Laundry location code for Laundry Number "<<i+1<<" : ";
				int x;
				cin>>x;
				(laundries[x].first)++;
				(laundries[x].second)++;
			}
			
			/*saving data into file*/
			
			string temp = city+".map";
			ofstream file;
			file.open(temp.c_str());
			
			char arr[200]; //for converting string into character array
			strcpy(arr,city.c_str());
			file<<arr<<"\n";
			
			file<<vertex<<"\n";
			file<<edges<<"\n";
			file<<laundry<<"\n";
			
			for(int i=0;i<=vertex;i++){
				file<<laundries[i].first<<"\n";
				file<<laundries[i].second<<"\n";
			}
			file.close();
			
			/*now creating new file only for storing edges*/
			temp=city+".edg";
			file.open(temp.c_str());
			
			cout<<endl<<"\t----------------**Entries for Edges**----------------"<<endl<<endl;
			for(int i=0;i<edges;i++)
			{
				cout<<"\t<< For Edge No "<<i+1<<" >>\t"<<endl;
				int a,b,w;
				cout<<"a(source) : ";
				cin>>a;
				cout<<"b(destination) : ";
				cin>>b;
				cout<<"w(distance/weight) : ";
				cin>>w;
				file<<a<<"\n";
				file<<b<<"\n";
				file<<w<<"\n";
			}
			file.close();
			system("CLS");
			cout<<"*********Map succesfully created............."<<endl;
			this->showMap(city);
			//getch();
		}
		
		bool loadMetaData(string s)
		{
			string temp=s+".map";
			ifstream file;
			file.open(temp.c_str());
			if(file)
			{
				getline(file,city);
				file>>vertex;
				file>>edges;
				file>>laundry;
				laundries.assign(vertex+1,make_pair<int,int> (0,0));
				for(int i=0;i<=vertex;i++){
					int x,y;
					file>>x;
					file>>y;
					laundries[i].first=x;
					laundries[i].second=y;
				}
				cout<<"\tMetaData loaded ........"<<endl;
				return true;
			}
			else
			{
				cout<<"Sorry!!!!!!! Map not found for city : "<<s<<endl;
				return false;
			}
		}
		
		void showMap(string s)
		{
			if(this->loadMetaData(s)){
				cout<<"\t**------MetaData for city : "<<city<<"------**"<<endl<<endl;
				cout<<"Number of loaction(vertex) : "<<vertex<<endl;
				cout<<"Number of edges(ways) : "<<edges<<endl;
				cout<<"Number of laundries : "<<laundry<<endl;
				cout<<"Laundries are ::: "<<endl<<endl;
				cout<<"-----------------------------------"<<endl;
				cout<<"AreaCode   :    Number of Laundries"<<endl;
				cout<<"-----------------------------------"<<endl;
				for(int loc=0;loc<=vertex;loc++)
				{
					if(laundries[loc].first){
						cout<<"      "<<loc<<"    :    "<<laundries[loc].first<<"( ";
						for(int j=1;j<=laundries[loc].second;j++)
						{
							char buf[10];
							sprintf(buf,"%d",loc);
							string temp_ssn = city+"_"+buf;
							sprintf(buf,"%d",j);
							temp_ssn=temp_ssn+"_"+buf;
							string t=temp_ssn;
							temp_ssn=temp_ssn+".ld";
							ifstream file(temp_ssn.c_str());
							if(file)
							{
								cout<<t<<", ";
							}
							file.close();
						}
						cout<<")"<<endl;
					}
				}
				
				cout<<endl<<endl<<"Information about edges(way) ::::::::::: "<<endl<<endl;
				string temp = city+".edg";
				ifstream file;
				file.open(temp.c_str());
				for(int i=0;i<edges;i++)
				{
					int a,b,w;
					file>>a;
					file>>b;
					file>>w;
					cout<<a<<" -->> "<<b<<" "<<"( "<<w<<" )"<<endl;
				}
				file.close();
			}
		}
		void updateLaundry(string s)
		{
			if(this->loadMetaData(s))
			{
				cout<<"\t**------MetaData for city : "<<city<<"------**"<<endl<<endl;
				cout<<"Number of loaction(vertex) : "<<vertex<<endl;
				cout<<"Number of edges(ways) : "<<edges<<endl;
				cout<<"Number of laundries : "<<laundry<<endl;
				cout<<"Laundries are ::: "<<endl<<endl;
				cout<<"-----------------------------------"<<endl;
				cout<<"AreaCode   :    Number of Laundries"<<endl;
				cout<<"-----------------------------------"<<endl;
				for(int loc=0;loc<=vertex;loc++)
				{
					if(laundries[loc].first){
						cout<<"      "<<loc<<"    :    "<<laundries[loc].first<<"( ";
						for(int j=1;j<=laundries[loc].second;j++)
						{
							char buf[10];
							sprintf(buf,"%d",loc);
							string temp_ssn = city+"_"+buf;
							sprintf(buf,"%d",j);
							temp_ssn=temp_ssn+"_"+buf;
							string t=temp_ssn;
							temp_ssn=temp_ssn+".ld";
							ifstream file(temp_ssn.c_str());
							if(file)
							{
								cout<<t<<", ";
							}
							file.close();
						}
						cout<<")"<<endl;
					}
				}
				
				cout<<endl<<endl<<"<< To add Laundry press 1 else 0 >>"<<endl;
				int ch;
				cin>>ch;
				cout<<"Enter area code : ";
				int x;
				cin>>x;
				if(ch)
				{
					laundries[x].first++;
					laundries[x].second++;
					laundry++;
					cout<<"!!!!!!Laundry Successfully added......"<<endl;
					
					/*saving Data*/
						
						string temp=s+".map";
						ofstream file;
						file.open(temp.c_str());
						char arr[200]; //for converting string into character array
						strcpy(arr,city.c_str());
						file<<arr<<"\n";
				
						file<<vertex<<"\n";
						file<<edges<<"\n";
						file<<laundry<<"\n";
			
						for(int i=0;i<=vertex;i++){
							file<<laundries[i].first<<"\n";
							file<<laundries[i].second<<"\n";
						}
						file.close();
				}
				else
				{
					string ssn;
					cin.ignore();
					cout<<"Please Enter ssn : ";
					getline(cin,ssn);
					ssn=ssn+".ld";
					
					if( remove( ssn.c_str() ) != 0 )
    					cout<<"Sorry No file found,Laundry Can't Be Removed"<<endl;
  					else{
    					puts( "File successfully deleted" );
    					(laundries[x].first)--;
						laundry--;
						cout<<"!!!!!!Laundry Successfully removed......"<<endl;
						
						/*saving Data*/
						
						string temp=s+".map";
						ofstream file;
						file.open(temp.c_str());
						char arr[200]; //for converting string into character array
						strcpy(arr,city.c_str());
						file<<arr<<"\n";
				
						file<<vertex<<"\n";
						file<<edges<<"\n";
						file<<laundry<<"\n";
			
						for(int i=0;i<=vertex;i++){
							file<<laundries[i].first<<"\n";
							file<<laundries[i].second<<"\n";
						}
						file.close();
    				}
				}
			}
		}
		int getNumberOfLaundriesAtLocation(int loc)
		{
			return laundries[loc].second;
		}
};

int main()
{
	Map m;
	m.updateLaundry("Indore");
	m.createMap();
	m.showMap("Indore");
}



