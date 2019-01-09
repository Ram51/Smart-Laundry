#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <set>
#include <utility>
#include <vector>
#include <conio.h>

#include "MapClass.cpp"
#include "LaundryClass.cpp"
#include "CustomerClass.cpp"
#include "GraphClass.cpp"

using namespace std;

class SmartLaundry{
	public :
				
/*=================================================================================================================================================*/


		SmartLaundry()
		{
			this->StartUpLoginBox();
		}
				
/*=================================================================================================================================================*/


		void StartUpLoginBox()
		{
			system("CLS");
			cout<<"\t\t\t    **Smart Laundry V.1**"<<endl<<endl;
			
			cout<<"\t-----------------------------------"<<endl;
			cout<<"\t| (A)dministrator ?                |"<<endl;
			cout<<"\t| (C)ustomer ?                     |"<<endl;
			cout<<"\t| (E)xit !                         |"<<endl;
			cout<<"\t-----------------------------------"<<endl;
			char ch;
			cin>>ch;
			if(ch=='a' || ch=='A')
				this->administratorOperations();
			else if(ch=='C' || ch=='c')
				this->customerStartupPage();
			else
				exit(0);
		}
				
/*=================================================================================================================================================*/

		void administratorOperations()
		{
			system("CLS");
			cout<<"\t\t\t    **Smart Laundry V.1**"<<endl<<endl;
			cout<<"\t--------------------------------------------------------------"<<endl;
			cout<<"\t|                                                             |"<<endl;
			cout<<"\t|    Hello Admin please login with Master Password........     |"<<endl;
			cout<<"\t|                                                             |"<<endl;
			cout<<"\t-------------------------------------------------------------- "<<endl;
			bool flag=true;
			do{
				cout<<endl<<"Password : ";
				string pass;
				cin.ignore();
				getline(cin,pass);
				if(!pass.compare("123"))
				{
					flag=false;
				}
				else
				{
					system("CLS");
					cout<<"\t\t\t    **Smart Laundry V.1**"<<endl<<endl;
					cout<<"\t-------------------------------------------------"<<endl;
					cout<<"\t|  (S)orry Incorrect password,try again!!!!!!   |"<<endl;
					cout<<"\t|  (O)r go Back to Home Page!!!!                |"<<endl;
					cout<<"\t-------------------------------------------------"<<endl;
					char ch;
					cin>>ch;
					if(ch=='o' || ch=='O')
						this->StartUpLoginBox();
				}
			}while(flag);
			
			do{
				system("CLS");
				cout<<"\t\t\t    **Smart Laundry V.1**"<<endl<<endl;
				cout<<"\t--------------------------------------"<<endl;
				cout<<"\t| (C)reate map                       |"<<endl;
				cout<<"\t| (A)dd Laundry                      |"<<endl;
				cout<<"\t| (G)et Laundry Detail               |"<<endl;
				cout<<"\t| (D)elete Laundry                   |"<<endl;
				cout<<"\t| (S)how Map Meta Data               |"<<endl;
				cout<<"\t| (L)og Out                          |"<<endl;
				cout<<"\t--------------------------------------"<<endl;
				char choice;
				cin>>choice;
				switch(choice)
				{
					case 'c':
					case 'C':
					{
						Map map;
						map.createMap();
					}
						break;
					case 'a':
					case 'A':
					{
						Laundry l;
						l.laundryRegistration();	
					}
						break;
						
					case 'g':
					case 'G':
					{
						Laundry l;
						cout<<"Enter SSN : ";
						string ssn;
						cin.ignore();
						getline(cin,ssn);
						l.showLaundry(ssn);
					}
						break;
					case 'D':
					case 'd':
					{
						Map map;
						cout<<"Enter city : ";
						string city;
						cin.ignore();
						getline(cin,city);
						map.updateLaundry(city);
						getch();
					}
						break;
					case 'S':
					case 's':
					{
						Map map;
						cout<<"Enter city : ";
						string city;
						cin.ignore();
						getline(cin,city);
						map.showMap(city);
						getch();
					}
						break;
					case 'l':
					case 'L':
						this->StartUpLoginBox();
						break;
				}
			}while(true);
		}
				
/*=================================================================================================================================================*/


		void useService(Customer &c,string &s_ssn,Laundry &l)
		{
			int t_shirt,shirt,pant,bedsheet,woolen,shorts,dryclean,iron;
			while(true)
			{
				system("CLS");
				cout<<"\t\t\t    **Smart Laundry V.1**"<<endl<<endl;
				cout<<"\t-----------------------------------"<<endl;
				cout<<"\t|                                  |"<<endl;
				cout<<"\t|         Entre Details :          |"<<endl;
				cout<<"\t|                                  |"<<endl;
				cout<<"\t-----------------------------------"<<endl;
				
				
				cout<<"Number of T-shirts             : ";cin>>t_shirt;
				cout<<"Number of Shirts               : ";cin>>shirt;
				cout<<"Number of Pants                : ";cin>>pant;
				cout<<"Number of bedsheet             : ";cin>>bedsheet;
				cout<<"Number of Woolen               : ";cin>>woolen;
				cout<<"Number of Shorts               : ";cin>>shorts;
				cout<<"Number of DryClean Services    : ";cin>>dryclean;
				cout<<"Number of Ironing services     : ";cin>>iron;
				
				int ch;
				cout<<"To Confirm order press 1 else 0 : ";cin>>ch;
				if(ch==1)
					break;
			}
			
			system("CLS");
			cout<<"\t\t\t    **Smart Laundry V.1**"<<endl<<endl;
			
			int total=0;
			
			cout<<"\t  ============================================================="<<endl;
			cout<<"\t|                          INVOICE                             |"<<endl;
			cout<<"\t|--------------------------------------------------------------|"<<endl;
			cout<<"\t|  Customer Name : ";printf("%23s                     |",c.getName().c_str());cout<<endl;
			cout<<"\t|--------------------------------------------------------------|"<<endl;
			cout<<"\t|    Service     |   Rate(Rs.)    |   Quant    |   Amount      |"<<endl;
			cout<<"\t|--------------------------------------------------------------|"<<endl;
			cout<<"\t|   T-shirts     |"<<"       ";printf("%2d",l.getTshirtWash());cout<<"       "<<"|"<<"   ";printf("%4d",t_shirt);cout<<"     "<<"|       ";printf("%2d",t_shirt*l.getTshirtWash());cout<<"      |"<<endl;total+=t_shirt*l.getTshirtWash();
			cout<<"\t|   Shirts       |"<<"       ";printf("%2d",l.getShirtWash());cout<<"       "<<"|"<<"   ";printf("%4d",shirt);cout<<"     "<<"|       ";printf("%2d",shirt*l.getShirtWash());cout<<"      |"<<endl;total+=shirt*l.getShirtWash();
			cout<<"\t|   Pants        |"<<"       ";printf("%2d",l.getPantWash());cout<<"       "<<"|"<<"   ";printf("%4d",pant);cout<<"     "<<"|       ";printf("%2d",pant*l.getPantWash());cout<<"      |"<<endl;total+=pant*l.getPantWash();
			cout<<"\t|   Bedsheet     |"<<"       ";printf("%2d",l.getBedsheetWash());cout<<"       "<<"|"<<"   ";printf("%4d",bedsheet);cout<<"     "<<"|       ";printf("%2d",bedsheet*l.getBedsheetWash());cout<<"      |"<<endl;total+=bedsheet*l.getBedsheetWash();
			cout<<"\t|   Woolen       |"<<"       ";printf("%2d",l.getWoolenWash());cout<<"       "<<"|"<<"   ";printf("%4d",woolen);cout<<"     "<<"|       ";printf("%2d",woolen*l.getWoolenWash());cout<<"      |"<<endl;total+=woolen*l.getWoolenWash();
			cout<<"\t|   Shorts       |"<<"       ";printf("%2d",l.getShorts());cout<<"       "<<"|"<<"   ";printf("%4d",shorts);cout<<"     "<<"|       ";printf("%2d",shorts*l.getShorts());cout<<"      |"<<endl;total+=shorts*l.getShorts();
			cout<<"\t|   DryClean     |"<<"       ";printf("%2d",l.getDryclean());cout<<"       "<<"|"<<"   ";printf("%4d",dryclean);cout<<"     "<<"|       ";printf("%2d",dryclean*l.getDryclean());cout<<"      |"<<endl;total+=dryclean*l.getDryclean();
			cout<<"\t|   Ironing      |"<<"       ";printf("%2d",l.getIron());cout<<"       "<<"|"<<"   ";printf("%4d",iron);cout<<"     "<<"|       ";printf("%2d",iron*l.getIron());cout<<"      |"<<endl;total+=iron*l.getIron();
			cout<<"\t|--------------------------------------------------------------|"<<endl;
			cout<<"\t|                            Total Amount      |       "<<total<<"      |"<<endl;
			cout<<"\t  ============================================================="<<endl;
			
			
			
			
			
			c.setPreferedLaundry(l.getName());
			c.setL_ssn(s_ssn);
			c.saveCustomer();
		}
		
/*=================================================================================================================================================*/

		void search(Graph &g,Customer &c,vector<int> &dist)
		{
			
			g.dijkstra(c.getareaCode(),dist);
		
			set< pair<int,int> > result;//to store nodes distance vise
			
			for(int i=0;i<g.getV();i++)
			{
				result.insert(make_pair<int,int>(dist[i],i));
			}
			
			
			Map m;
			m.loadMetaData(c.getCity());		
			
			vector<pair<int,int> > laundries;
			
			laundries=m.getLaundries();
			
			while(true)
			{
				if(result.empty()){
					cout<<"End of result...."<<endl;
					break;
				}
				pair<int,int> temp=*result.begin();
				
				result.erase(result.begin());
				
				if(laundries[temp.second].first!=0)
				{	
					Laundry l;
					int count=temp.second;
					int i=1;
					while(i<=laundries[temp.second].second)
					{
						string t_str;
						char buff[100];
						
						t_str=t_str+c.getCity();
						t_str=t_str+"_";
						sprintf(buff,"%d",temp.second);
						t_str=t_str+buff;
						t_str=t_str+"_";
						sprintf(buff,"%d",i);
						t_str=t_str+buff;
						
						strcpy(buff,t_str.c_str());
						
						strcat(buff,".ld");
						
						
						ifstream file;
						file.open(buff);
						if(file)
						{
							system("CLS");
							cout<<"\t\t\t    **Smart Laundry V.1**"<<endl<<endl;
							
							cout<<endl<<"Best search for you >>>>"<<endl<<endl;
							l.showLaundry(t_str);
							
							cout<<"\t-------------------------------------"<<endl;
							cout<<"\t|    (N)ot happy!! Next Result ?     |"<<endl;
							cout<<"\t|    (U)se services of this laundry  |"<<endl;
							cout<<"\t|    (E)xit !!                       |"<<endl;
							cout<<"\t--------------------------------------"<<endl;
							
							char ch3;
							cin>>ch3;
							if(ch3=='n' || ch3=='N'){
								//do nothing
							}
							else if(ch3=='U' || ch3=='u')
							{
								this->useService(c,t_str,l);
								getch();
								return;
							}
							else
								return ;
						}
						i++;
					}
					//break;
				}
			}
		}
				
/*=================================================================================================================================================*/

		void customerOperations(Customer &c)
		{
			do{
				
				system("CLS");
				cout<<"\t\t\t    **Smart Laundry V.1**"<<endl<<endl;
			
				cout<<"\tWelcome : "<<c.getName()<<endl;
				cout<<"\t-----------------------------------"<<endl;
				cout<<"\t|    (M)y Account                  |"<<endl;
				cout<<"\t|    (F)ind a Laundry              |"<<endl;
				cout<<"\t|    (L)og Out                     |"<<endl;
				cout<<"\t------------------------------------"<<endl;
				
				char ch1;
				cin>>ch1;
				switch(ch1)
				{
					case 'm':
					case 'M':
					{
						c.showCustDetail();
						getch();
					}
						break;
					case 'f':
					case 'F':
					{
						Graph g;
						g.createGraph(c.getCity());
						if(!c.getL_ssn().empty())
						{
							system("CLS");
							cout<<"\t\t\t    **Smart Laundry V.1**"<<endl<<endl;
							cout<<"\they "<<c.getName()<<"!!!!!"<<endl;
							cout<<"\tBased on your previous transaction prefered laundry is : "<<c.getPreferedLaundry()<<endl<<endl<<endl;
							do{
								cout<<"\t----------------------------------------"<<endl;
								cout<<"\t|  (G)et details of prefered laundry    |"<<endl;
								cout<<"\t|  (U)se services of prefered laundry   |"<<endl;
								cout<<"\t|  (N)ot haappy ?? want more ??         |"<<endl;
								cout<<"\t|  (E)xit                               |"<<endl;
								cout<<"\t-----------------------------------------"<<endl;
							
								char ch2;
								cin.ignore();
								cin>>ch2;
							
								if(ch2=='G' || ch2=='g')
								{
									system("CLS");
									cout<<"\t\t\t    **Smart Laundry V.1**"<<endl<<endl;
									Laundry l;
									l.showLaundry(c.getL_ssn());
									getch();
								}
								else if (ch2=='U' || ch2=='u')
								{
									Laundry l;
									l.loadLaundry(c.getL_ssn());
									string temp=c.getL_ssn();
									this->useService(c,temp,l);
									getch();
									break;
								}
								else if(ch2=='N' || ch2=='n')
								{
									vector<int> dist;
									this->search(g,c,dist);
									break;
								}
								else 
								{
									break;
								}
							}while(true);
						}
						else
						{
							vector<int> dist;
							this->search(g,c,dist);
							getch();
						}
						//getch();
					}
						break;
					case 'l':
					case 'L':
						this->StartUpLoginBox();
				}
			}while(true);
		}
				
/*=================================================================================================================================================*/


		void custLogInPage()
		{
				system("CLS");
				cout<<"\t\t\t    **Smart Laundry V.1**"<<endl<<endl;
				cout<<"\t-----------------------------------"<<endl;
				cout<<"\t|                                  |"<<endl;
				cout<<"\t|         Customer Login           |"<<endl;
				cout<<"\t|                                  |"<<endl;
				cout<<"\t-----------------------------------"<<endl;
				
				string u_id;
				string pass;
				cout<<"\tUser Id : ";
				cin.ignore();
				getline(cin,u_id);
				
				Customer c;
				if(c.loadCustomer(u_id))
				{
					cout<<"\tPassword : ";
					getline(cin,pass);
					if(pass.compare(c.getPassWord()))
					{
						cout<<"\tIncorrect Password !!!!!";
						getch();
						this->customerStartupPage();
					}
					else
					{
						this->customerOperations(c);
					}
				}
				else
				{
					getch();
					this->customerStartupPage();
				}
				
		}
				
/*=================================================================================================================================================*/


		void customerStartupPage()
		{
			do{
				system("CLS");
				cout<<"\t\t\t    **Smart Laundry V.1**"<<endl<<endl;
				cout<<"\t-----------------------------------"<<endl;
				cout<<"\t| (L)ogin   ?                     |"<<endl;
				cout<<"\t| (S)ign Up ?                     |"<<endl;
				cout<<"\t| (E)xit    !                     |"<<endl;
				cout<<"\t-----------------------------------"<<endl;
			
				char ch;
				cin>>ch;
				if(ch=='s' || ch=='S')
				{
					Customer c;
					c.custRegister();
					getch();
				}
				else if(ch=='L' || ch=='l')
				{
					this->custLogInPage();
					getch();
				}
				else
					exit(0);
			}while(true);
		}
};
		
/*=================================================================================================================================================*/


int main()
{
	SmartLaundry sl;
}
