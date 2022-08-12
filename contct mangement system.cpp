#include <iostream>
		#include <fstream>
		#include <string>
		#include <stdlib.h>
		#include <conio.h>
		#include <cctype>
		#include <iomanip>
		#include <windows.h>

		using namespace std;

		void menu();
		void check_input(string &);
		void check_name(string &);
		void check_number(string &);
		void add();
		void show();
		void edit();
		void find_rec();
		void delete_rec();

		int main()
		{
		    char input;
		    system("color 3F");
		    do
		    {
		        system("cls");

		    menu();
		    cout<<"\t\t Choose From Above || ";
		    cin>>input;
		    input = toupper(input);
		    switch(input)
		    {
		    case 'A':
		        add();
		        break;
		    case 'S':
		        show();
		        break;
		    case 'F':
		        find_rec();
		        break;
		    case 'D':
		        delete_rec();
		        break;

		    }
		    }while(input!='X');
		}


		void menu(){

			cout<<endl;
			cout<<"\t\t ========================"<<endl;
			cout<<"\t\t **MENU**"<<endl;
			cout<<"\t\t ========================"<<endl;
			cout<<"\t\t [A] Add Phone Record"<<endl;
			cout<<"\t\t [S] Show Phone Record"<<endl;
			cout<<"\t\t [E] Edit Phone Record"<<endl;
			cout<<"\t\t [F] Find Phone Record"<<endl;
			cout<<"\t\t [D] Delete Phone Record"<<endl;
			cout<<"\t\t [x] To Exit"<<endl;
			cout<<"\t\t ========================="<<endl;
		}

		void check_name(string &name) {

			while(name.length()<7){

					cout<<"\t\t Enter Name Again(More Than 7 Characters) || "; getline(cin,name);
			}
		}
		void check_number(string &number){

			int i,j,n=0;

			if(number.length() >= 11){

				for(i=0; i<11; i++){

						if(isdigit(number[i])){

							break;
						}
						else{

							cout<<"\t\t Enter Number(11 digit) || "; getline(cin,number);

							break;
						}

				}
			}
			else if(number.length() < 11){

				while(number.length() != 11){

					for(i=0; i<=11; i++){

						    if(isdigit(number[i])){

							    break;
						    }
						    else{

							    cout<<"\t\t Enter Number(11 digit) || "; getline(cin,number);

							    break;
						    }

				   }
				}
			}

		}



		void add()
		{
		     int i=0,n=1,store[50];
		    bool saved = false;

		    string name[50];
		    string number[50];

				    cout<<endl;
			        cout<<"\t\t ========================="<<endl;
			        cout<<"\t\t **ADD CONTACTS*"<<endl;
			        cout<<"\t\t ========================="<<endl;

		ofstream myfile("file.txt",ios::app);
		if(myfile.is_open()){

		            cin.ignore();
		            for(i=0; i<=n; i++){

			        	cout<<"\t\t Enter Name(More Than 7 Characters) || ";
			        	getline(cin, name[i]);
			        	check_name(name[i]);

			        	cout<<"\t\t Enter Number(11 digit) || ";
						 getline(cin,number[i]);
						check_number(number[i]);


			        	myfile<<name[i]<<endl;
			        	myfile<<number[i]<<endl;
			        	saved = true;
		                break;
					}


		 }
		 myfile.close();
		            if (saved == true)
		                {
		                    cout<<endl;
		                    cout<<"\t\t =============================="<<endl;
		                    cout<<"\t\t ****"<<endl;
		                    cout<<"\t\t Your Contact Saved Successfully"<<endl;
		                    cout<<"\t\t ****"<<endl;
		                    cout<<"\t\t =============================="<<endl;
		                    cout<<endl;
		                    cout<<"\t\t Press Enter To Continue";
						    cin.ignore();
		                    cin.get();

		                }


		}



		void show()
		{

					cout<<endl;
				    cout<<"\t\t ========================="<<endl;
			        cout<<"\t\t **SHOW CONTACTS**"<<endl;
			        cout<<"\t\t ========================="<<endl;

		  string line, line2, line3;
		  ifstream myfile("file.txt");
		   cout<<"\t\tName";
		   cout<<"\t\tNumber"<<endl;




		   while(myfile>>line>>line2>>line3)
		   {

		       cout<<endl;
		       cout<<"\t\t"<<line<<' '<<line2<<"\t"<<line3<<endl;

		   }
		   cout<<"\t\t Press Enter To Continue";
						    cin.ignore();
		                    cin.get();

		   myfile.close();

		}
		void edit()
		{
	            bool isfound = false;
		    string line, line2, line3;
		  ifstream myfile("file.txt");
		  ofstream myfile2("file2.txt");


				    cout<<endl;
				    cout<<"\t\t ========================="<<endl;
			        cout<<"\t\t *EDIT CONTACT**"<<endl;
			        cout<<"\t\t ========================="<<endl;

					cout<<endl;

					string search1, search2;

					cout<<endl;
				    cout<<"\t\t ========================="<<endl;
			        cout<<"\t\t *Search For EDIT*"<<endl;
			        cout<<"\t\t ========================="<<endl;
		            cin.ignore();
			        cout<<"\t\t Enter Old Name(More Than 7 Characters) ||  "; cin>>search1>>search2;


					while(myfile>>line>>line2>>line3){
			            if(search1 == line&& search2 ==line2){
			                cout<<"\t\t Name"; cout<<"\t\t Number"<<endl;

			            	cout<<"\t\t ****"<<endl;
			            	cout<<"\t\t "<<line<<' '<<line2<<"\t "<<line3<<endl;
			            	cout<<"\t\t ****"<<endl;
		                    isfound = true;
			            	cout<<"\t\t Enter New Name(More Than 7 Characters) ||  ";cin>>line>>line2;

			            	cout<<endl;

		                    cin.ignore();

			            		cout<<"\t\t Enter Number(11 digit) || "; getline(cin,line3);

			            		check_number(line3);

		                    myfile2<<line<<' '<<line2<<endl;
		                    myfile2<<line3<<endl;
							}


						else{
		                    myfile2<<line<<' '<<line2<<endl;
		                    myfile2<<line3<<endl;
						}

					}
					if (isfound == false)
		            {
		                cout<<"\t\t Sorry Search Again "<<endl;
		                cout<<"\t\t Press Enter To Continue";
						    cin.ignore();
		                    cin.get();

		            }

					myfile.close();
					myfile2.close();

					remove("file.txt");
					rename("file2.txt", "file.txt");
		}

		void find_rec()
		{
		    bool isfound = false;
		    string line, line2, line3;
		  ifstream myfile("file.txt");
		  ofstream myfile2("file2.txt");


					cout<<endl;
				    cout<<"\t\t ========================="<<endl;
			        cout<<"\t\t *FIND CONTACT**"<<endl;
			        cout<<"\t\t ========================="<<endl;

					string search1, search2;

					cout<<"\t\t Enter Name For Search(More Than 7) || "; cin>>search1>>search2;


					while(myfile>>line>>line2>>line3){

		            if(search1 == line&& search2 ==line2){
		                    cout<<"\t\t Name"; cout<<"\t\t Number"<<endl;
			            	cout<<"\t\t ****"<<endl;
			            	cout<<"\t\t "<<line<<' '<<line2<<"\t "<<line3<<endl;
			            	cout<<"\t\t ****"<<endl;


						    cout<<endl;
						    cout<<"\t\t =============================="<<endl;
						    cout<<"\t\t ****"<<endl;
					        cout<<"\t\t Your Contact Exist Don't Worry"<<endl;
					        cout<<"\t\t ****"<<endl;
					        cout<<"\t\t =============================="<<endl;
					        cout<<endl;
					        isfound = true;
					        cout<<"\t\t Press Enter To Continue";
						    cin.ignore();
		                    cin.get();

						}



					}
					if (isfound == false){

							cout<<"\t\t Sorry This No. does not Exist "<<endl;
		                    cout<<"\t\t Press Enter To Continue";
						    cin.ignore();
		                    cin.get();
						}
		}

		void delete_rec()
		{
		        bool isfound = false;
		    string line, line2, line3;
		  ifstream myfile("file.txt");
		  ofstream myfile2("file2.txt");

					cout<<endl;
				    cout<<"\t\t ========================="<<endl;
			        cout<<"\t\t *DELETE CONTACT*"<<endl;
			        cout<<"\t\t ========================="<<endl;

					string search1, search2;

					cout<<endl;
				    cout<<"\t\t ========================="<<endl;
			        cout<<"\t\t Search FOR DELETE"<<endl;
			        cout<<"\t\t ========================="<<endl;

					cout<<"\t\t Enter Name For Delete(More Than 7) || "; cin>>search1>>search2;;


			    while(myfile>>line>>line2>>line3){
			        if(search1 != line&& search2 !=line2)
			        {
			            myfile2<<line<<' '<<line2<<endl;
		                myfile2<<line3<<endl;
		                isfound = true;
			        }

					}
					if(isfound == false)
					{
					    Sleep(500);
	                        cout<<endl;
		                    cout<<"\t\t =============================="<<endl;
		                    cout<<"\t\t ****"<<endl;
		                    cout<<"\t\t Your Contact Deleted Successfully"<<endl;
		                    cout<<"\t\t ****"<<endl;
		                    cout<<"\t\t =============================="<<endl;
		                    Sleep(500);
	                        cout<<"\t\t Press Enter To Continue";
						    cin.ignore();
		                    cin.get();
					}

					myfile.close();
					myfile2.close();

					remove("file.txt");
					rename("file2.txt", "file.txt");
		}
