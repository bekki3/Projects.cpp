/*OOP_Project
Names: Shukhratov Bekhzod     U2010259
       Azizullo Temirov       U2010277
	   Shavkatbekov Abdulaziz U2010254    */
#include<iostream>
#include<fstream>             // to work with files
#include<string>
#include<Windows.h>           //to sleep, change color
using namespace std;
string signin;                   // global variables
string chars = "!@#$%^&*()_+-=";           // to check if ID contains character
void textflow(string k, int t)    //for better look :)
{
	int s = k.size();
	for (int n = 0; n <= s; n++)
	{
		cout << k[n];
		Sleep(t);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
class Courses    //to store percentages
{
private:
	double depositp, withdrawalp, dollarc;
public:
	Courses()      //default constructor
	{
		depositp = 11.2;
		withdrawalp = 12.2;
		dollarc = 10495;
	}
	void setdep()  //to set deposit yearly percentage
	{
		ofstream depobj;
		depobj.open("depositfile.txt");
		textflow("\n\t\t\t Please set the yearly deposit percentage : ", 20);
		cin >> depositp;
		textflow("\n\t\t\t Deposit Percentage set to: ", 20);
		cout << depositp;
		textflow("% successfully by ", 20);
		cout << signin;
		cout << endl;
		depobj << depositp;    //to store percentage in a file
		depobj.close();
		Sleep(1200);
		system("cls");
	}
	void setwith()        //to set withdrawal percentage
	{
		ofstream withobj;
		withobj.open("withdrawalfile.txt");      // simple file, not binary
		textflow("\n\t\t\t Please set the yearly withdrawal percentage : ", 20);
		cin >> withdrawalp;
		textflow("\n\t\t\t Withdrawal Percentage set to: ", 20);
		cout << withdrawalp;
		textflow("% successfully by ", 20);
		cout << signin;
		cout << endl;
		withobj << withdrawalp;      //to store the value in a file
		withobj.close();
		Sleep(1200);
		system("cls");
	}
	void setdollarc()        // to set the course of dollar to sums
	{
		ofstream dollarobj;
		dollarobj.open("dollarfile.txt");
		textflow("\n\t\t\tEnter the current dollar course ($1 in Sums): ", 20);
		cin >> dollarc;
		textflow("\n\t\t\tDollar course set to: ", 20);
		cout << dollarc;
		textflow(" successfully by ", 20);
		cout << signin;
		cout << endl;
		dollarobj << dollarc;// to store the value
		dollarobj.close();
		Sleep(1200);
		system("cls");
	}
	double getdep()     // so, values of class private variables can be accessed in the main func
	{
		return depositp;
	}
	double getwith()
	{
		return withdrawalp;
	}
	double getdollarc()
	{
		return dollarc;
	}
	//~Courses() 
	//{
	//	cout << "Class Courses Variables terminated" << endl;
	//	Sleep(100);
	//}//simple destructor
	friend void currencyexchange();//this function is a friend so it can access class members
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class StaffID
{
private:
	string ID, PW;
public:
	StaffID(){}   //not parametrized empty constructor
	void setdata(string ID, string PW)
	{
		this->ID = ID;
		this->PW = PW;
	}
	string getID()
	{
		return ID;
	}
	string getPW()
	{
		return PW;
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CustomerID
{
private:
	string ID, PW;
public:
	CustomerID()
	{
		ID = "defaultID";
		PW = "defaultPW";
	}
	void setdata(string i, string p)
	{
		ID = i;
		PW = p;
	}
	string getID()
	{
		return ID;
	}
	string getPW()
	{
		return PW;
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void currencyexchange()
{
	Courses crs;
	textflow("\n\t\t\t1. Dollar to Sums", 20);
	cout << endl;
	textflow("\n\t\t\t2. Sums to Dollar", 20);
	cout << endl;
	textflow("\n\n\t\t\t# Your option : ", 20);
	int k;
	double finalsum, money;
	cin >> k;
	switch (k)
	{
	case 1:
	{
		system("cls");
		cout << ("\n        O N L I N E   B A N K                                    D O L L A R   TO   S U M       \n");
		cout << "____________________________________________________________________________________________________\n\n";

		textflow("\n\t\t\tHow much money you want to convert? : ", 20);
		cin >> money;
		finalsum = money * crs.dollarc;       ///accessing class private variable in a function
		textflow("\n\t\t\tYour money in Sums will be: $", 20);
		cout << finalsum << endl;
		Sleep(2000);
		system("cls");
		break;


	}
	case 2:
	{
		system("cls");
		cout << ("\n        O N L I N E   B A N K                                  S U M   T O   D O L L A R            \n");
		cout << "____________________________________________________________________________________________________\n\n";
		textflow("\n\t\t\tHow much money you want to convert? : ", 20);
		cin >> money;
		finalsum = money / crs.dollarc;
		textflow("Your money in Dollar will be: ", 20);
		cout << finalsum;
		textflow(" Sums", 20);
		cout << endl;
		Sleep(2000);
		system("cls");
		break;


	}
	default:
	{
		system("Color 0C");
		textflow("\n\t\t\tPlease choose available option!", 20);
		cout << endl;
		system("Color 0A");
		Sleep(1200);
		system("cls");
		currencyexchange(); ///it will call itself intil valid option chosen
	}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void staffent()   /// when staff entered the system successfully
{
	system("cls");
	cout << ("\n        O N L I N E   B A N K                                             S T A F F   M E N U       \n");
	cout << "____________________________________________________________________________________________________\n\n";
	textflow("\n\t\t  | | | | | Please choose one of the following options! | | | | |\n", 15);
	cout << endl;
	textflow("\n\t\t\t 1. To set Yearly Deposit Interest Percentage", 15);
	cout << endl;
	textflow("\n\t\t\t 2. To set Yearly Withdrawal Interest Percentage", 15);
	cout << endl;
	textflow("\n\t\t\t 3. To set Course of Dollar to Uzbek Sums", 15);
	cout << endl;
	textflow("\n\t\t\t 0. To exit the Bank", 15);
	cout << endl;
	textflow("\n\n\t\t\t # Your option : ", 15);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cusent()    //when customer entered the system successfully
{
	system("cls");
	cout << ("\n        O N L I N E   B A N K                                       C U S T O M E R   M E N U       \n");
	cout << "____________________________________________________________________________________________________\n\n";
	textflow("\n\t\t  | | | | | Please choose one of the following options! | | | | |\n", 15);
	cout << endl;
	textflow("\n\t\t\t 1. Currency exchange", 15);
	cout << endl;
	textflow("\n\t\t\t 2. Making Savings", 15);
	cout << endl;
	textflow("\n\t\t\t 3. Taking out a loan", 15);
	cout << endl;
	textflow("\n\t\t\t 4. Apply for a credit card", 15);
	cout << endl;
	textflow("\n\t\t\t 0. To Exit the bank", 15);
	cout << endl;
	textflow("\n\n\t\t\t # Your option : ", 15);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	ofstream dollarf;  // opening a file to store course of dollar and so
	dollarf.open("dollarfile.txt");
	ofstream depositper;
	depositper.open("depositfile.txt");
	ofstream withdrawalper;
	withdrawalper.open("withdrawalfile.txt");
	ofstream inobj1;
	ofstream inobj2;
	ofstream inobj3;
	ofstream inobj4;
	ifstream outobj1;     //opening a file to acces stored data
	ifstream outobj2;
	StaffID s;
	CustomerID c;
	Courses objc;
	bool switcher;// this is used to exit from loop when finished
	system("Color 0a");   // to make font light green
	dollarf << objc.getdollarc();    //storing default values in a file by default
	depositper << objc.getdep();
	withdrawalper << objc.getwith();
startingpoint:;
	switcher = true;
	while (signin != "n" && switcher)
	{
		cout << ("\n        O N L I N E   B A N K                                             R E G I S T R A T I O N       \n");
		cout << "____________________________________________________________________________________________________\n\n";
		textflow("\n\t\t   | Please enter your ID if you have, or get a new one: |\n", 20);
		cout << endl;

		textflow("\n\t\t\t\t- Input [Y] to Get ID", 15);
		cout << endl;

		textflow("\n\t\t\t\t- Input [N] to Exit\n", 15);
		cout << endl;

		textflow("\n\t\t   # Input ID or choose one of the options : ", 15);

		cin >> signin;   // main variable to navigate throughprogram
		if (signin == "Y" || signin == "y" && switcher)   // is Y or y is inputted
		{
			system("cls");
			cout << ("\n        O N L I N E   B A N K                                             G E T T I N G   I D       \n");
			cout << "____________________________________________________________________________________________________\n\n";
			textflow("\n\n\t\t\t     | Please choose the type of ID |", 30);
			cout << endl;
			textflow("\n\t\t\t\t  1. To get Staff ID", 20);
			cout << endl;
			textflow("\n\t\t\t\t  2. To get Customer ID", 20);
			cout << endl;
			textflow("\n\n\t\t\t     # Your option (1/2) : ", 20);
			int temp1;
			cin >> temp1;
			system("cls");
			switch (temp1)
			{
			case 1:
			{
			case1:         // to get Staff ID
				string staffid, staffpw, temp2;
				cout << ("\n        O N L I N E   B A N K                                             S T A F F   I D       \n");
				cout << "____________________________________________________________________________________________________\n\n";
				textflow("\n\n\t\t\t   | Please enter 4 character ID |", 20);
				cout << endl;
				textflow("\n\t\t\t\tID: ", 20);
				cin >> staffid;
				for (int i = 0; i < staffid.size(); i++)  // checking for characters in the ID
				{
					for (int j = 0; j < chars.size(); j++)
					{
						if (staffid[i] == chars[j])
						{
							system("Color 0C");
							textflow("\n\t\t\t  * ID cannot contain symbols!", 20);
							cout << endl;
							Sleep(1200);
							system("cls");
							system("Color 0A");
							goto case1;
						}
					}
				}
				if (staffid.size() != 4)   //Staff ID is 4 characters
				{
					system("Color 0C");
					textflow("\n\t\t\t   | Staff ID should be 4 characters |", 20);
					cout << endl;
					Sleep(1200);
					system("cls");
					system("Color 0A");
					goto case1;
				}
				textflow("\n\t\t\t   - Please enter a password : ", 20);

				cin >> staffpw;
				textflow("\n\t\t\t   - Please confirm your password : ", 20);

				cin >> temp2;
				if (staffpw == temp2)// IF passwords match each other
				{
					s.setdata(staffid, staffpw);
					inobj1.open("staffid.txt", ios::app | ios::binary);
					inobj1.write((char*)&s, sizeof(s));
					inobj1.close();
					textflow("\n\t\t\t | Staff Account Created Successfully |", 20);
					cout << endl;
					Sleep(1200);
					system("cls");
					goto startingpoint;
				}
				else
				{
					system("color 0c");
					textflow("\n\t\t\t * Passwords do not match", 20);
					cout << endl;
					system("color 0a");
					Sleep(1200);
					system("cls");
					goto case1;
				}
				break;
			}
			case 2:
			{
			case2://// to get customer ID
				string customerid, customerpw, temp8;
				cout << ("\n        O N L I N E   B A N K                                             C U S T O M E R   I D       \n");
				cout << "____________________________________________________________________________________________________\n\n";
				textflow("\n\n\t\t\t   | Please enter 6 character ID |", 30);
				textflow("\n\n\t\t\t\tID: ", 20);

				cin >> customerid;
				for (int i = 0; i < customerid.size(); i++)      
				{
					for (int j = 0; j < chars.size(); j++)
					{
						if (customerid[i] == chars[j])
						{
							system("Color 0C");
							textflow("\n\t\t\t  * ID cannot contain symbols!", 20);
							cout << endl;
							system("Color 0a");
							Sleep(1200);
							system("cls");
							goto case2;
						}
					}
				}
				if (customerid.size() != 6)   //customer ID should be 6 characters
				{
					system("Color 0C");
					textflow("\n\t\t\t * Customer ID should be 6 characters", 20);
					system("Color 0a");
					Sleep(1200);
					system("cls");
					goto case2;
				}
				textflow("\n\t\t\t   - Please enter a password : ", 20);

				cin >> customerpw;
				textflow("\n\t\t\t   - Please confirm your password : ", 20);

				cin >> temp8;
				if (customerpw == temp8)   // verifying the passwords
				{
					c.setdata(customerid, customerpw);
					inobj3.open("customerid.txt", ios::app | ios::binary);
					inobj3.write((char*)&c, sizeof(c));
					inobj3.close();
					textflow("\n\t\t\t | Customer Account Created Successfully |", 20);
					cout << endl;
					Sleep(1200);
					system("cls");
					goto startingpoint;
				}
				else
				{
					system("Color 0c");
					textflow("\n\t\t\t * Passwords do not match", 20);
					cout << endl;
					system("Color 0a");
					Sleep(1200);
					system("cls");
					goto case2;
				}
				break;
			}
			default:
			{
				break;
			}
			}
		}
		//registration for staff id
		else if (signin.size() == 4 && switcher)   // if ID is 4 characters, then it is Staff id
		{
			inobj2.open("staffid.txt", ios::app | ios::binary);
			inobj2.write((char*)&s, sizeof(s));
			inobj2.close();
			outobj1.open("staffid.txt", ios::binary);
			bool temp6 = true;
			string pwnotfound="";
			while (outobj1.read((char*)&s, sizeof(s)) && temp6)// searching for given ID
			{
				if (s.getID() == signin && switcher)  // if ID is found
				{
					temp6 = false;
					textflow("\n\t\t   Please enter your password : ", 20);
					string temp4;
					cin >> temp4;
					if (s.getPW() == temp4 && switcher)// IF password matches
					{
					STA://after tasks done staff come here
						staffent();   //it prints instructions
						int temp5;
						cin >> temp5;
						while (true)
						{
							switch (temp5)
							{
							case 1:
							{
								system("cls");
								cout << ("\n        O N L I N E   B A N K                                               D E P O S I T       \n");
								cout << "____________________________________________________________________________________________________\n\n";

								objc.setdep();    // to set deposit percentage
								goto STA;
								break;
							}
							case 2:
							{
								system("cls");
								cout << ("\n        O N L I N E   B A N K                                               W I T H D R A W A L       \n");
								cout << "____________________________________________________________________________________________________\n\n";

								objc.setwith();    // to set withdrawal percentage
								goto STA;
								break;
							}
							case 3:
							{
								system("cls");
								cout << ("\n        O N L I N E   B A N K                                       D O L L A R   C O U R S E       \n");
								cout << "____________________________________________________________________________________________________\n\n";

								objc.setdollarc();      //to set dollar course
								goto STA;
								break;
							}
							case 0:
							{
								textflow("\n\t\t\tThank You for Using our Service!", 20);   //if staff wants to exit
								Sleep(2000);
								return 0;
							}
							default:
							{
								cout << endl;
								system("color 0c");
								textflow("Please choose available option", 20);
								Sleep(1000);
								system("color 0a");
								goto STA;
							}
							}
						}
						outobj1.close();
					}
					else   // when password does not match
					{
						system("Color 0c");
						textflow("\t\t\t\Wrong Password, Enter again", 20);
						system("Color 0a");
						Sleep(1000);
					}
					break;
				}
				else
				{
					pwnotfound = "\t\t\t\tGiven ID is not found";
				}
			}
			system("cls");
			cout << endl;
			system("Color 0c");
			textflow(pwnotfound, 20);
			Sleep(1200);
			system("cls");
			system("Color 0a");
		}
		//registration for customer id
		else if (signin.size() == 6 && switcher)   /// IF ID is 6 charcters, then it is customer ID
		{
			inobj4.open("customerid.txt", ios::app | ios::binary);// opening a binary file in append mode
			inobj4.write((char*)&c, sizeof(c));
			inobj4.close();
			outobj2.open("customerid.txt", ios::binary);
			string idnotfound="";
			while (outobj2.read((char*)&c, sizeof(c)) && switcher)   //to run through the file record
			{
				if (signin == c.getID() && switcher)// if id is found
				{
					textflow("\n\t\t   Please enter your password : ", 20);
					string temp9;
					cin >> temp9;
					if (temp9 == c.getPW() && switcher)
					{
					CUS:
						cusent();
						int temp10;
						cin >> temp10;
						if (temp10 == 1)   // simple switch method// currency ec=xchange
						{
							system("cls");
							cout << ("\n        O N L I N E   B A N K                                C U R R E N C Y   E X C H A N G E       \n");
							cout << "____________________________________________________________________________________________________\n\n";

							currencyexchange();
							goto CUS;
						}
						else if (temp10 == 2) // deposit part
						{
							Courses tmp1;
							system("cls");
							cout << ("\n        O N L I N E   B A N K                                               S A V I N G      \n");
							cout << "____________________________________________________________________________________________________\n\n";

							textflow("\n\t\t\tHow much money you want to save? : ", 20);
							double savingm, totalmoney;
							cin >> savingm;
							while (savingm <= 0)
							{
								system("Color 0c");
								textflow("\n\t\t\tYou cannot save that money, enter again", 20);
								cout << endl;
								system("Color 0A");
								cin >> savingm;
							}
							textflow("\n\t\t\tAfter how many years you will take your money back? : ", 20);
							int years;
							cin >> years;
							while (years <= 0)
							{
								system("Color 0c");
								textflow("\n\t\t\tPeriod must be at least 1 year : ", 20);
								system("Color 0a");
								cin >> years;
							}
							totalmoney = savingm;
							double temp12 = tmp1.getwith();
							for (int i = 0; i <= years; i++)
							{
								totalmoney += (savingm * temp12 / 100);// to calculate the final amount of saving
							}
							textflow("\n\t\t\tMoney saved successfully, after ", 20);
							cout << years;
							textflow(" years, you will get ", 20);
							cout << totalmoney << endl;
							ofstream savemoney;
							savemoney.open("Savings.txt", ios::app);
							savemoney << signin << temp9 << totalmoney;  //ID, Password and amount of money is stored
							savemoney.close();
							switcher = false;
							Sleep(2000);
							goto CUS;
							break;
						}
						else if (temp10 == 3)  // borrowing money part
						{
							Courses tmp2;
							system("cls");
							cout << ("\n        O N L I N E   B A N K                                                      L O A N       \n");
							cout << "____________________________________________________________________________________________________\n\n";

							textflow("\n\t\t\tHow much money you want to borrow? : ", 20);
							double loanm, overallm;
							cin >> loanm;
							while (loanm <= 0)
							{
								system("Color 0c");
								textflow("\n\t\t\tYou cannot take that loan, enter again : ", 20);
								system("Color 0a");
								cin >> loanm;
							}
							textflow("\n\t\t\tAfter how many years you want to return money? : ", 20);
							int years1;
							cin >> years1;
							while (years1 <= 0)
							{
								system("Color 0c");
								cout << "\n\t\t\tPeriod must be at least 1 year" << endl;
								system("Color 0a");
								cin >> years1;
							}
							overallm = loanm;
							double temp11 = tmp2.getwith();
							for (int i = 0; i <= years1; i++)
							{
								overallm += (loanm * temp11 / 100);
							}
							textflow("\n\t\t\tYou will have to return ", 20);
							cout << overallm;
							textflow(" after ", 20);
							cout << years1;
							textflow(" years", 20);
							cout << endl;
							ofstream saveloan;
							saveloan.open("Loans.txt", ios::app);
							saveloan << signin << temp9 << overallm;// to store the data
							saveloan.close();
							switcher = false;
							Sleep(2000);
							goto CUS;
							break;
						}
						else if (temp10 == 4)   // credit card part
						{
							system("cls");
							cout << ("\n        O N L I N E   B A N K                                           C R E D I T   C A R D       \n");
							cout << "______________________________________________________________________________________________\n\n";

							textflow("\n\t\t\tEnter Your Passport Serie Number : ", 20);
							string psn;
							cin >> psn;
							while (psn.size() != 9)// passposts have 9 character serial number
							{
								system("Color 0c");
								textflow("\n\t\t\tSerie should be in format: AA0000000 : ", 20);
								system("Color 0A");
								cin >> psn;
							}
							textflow("\n\t\t\tThe serial number of your credit card : ", 20);
							cout << c.getID() << psn << endl;
							string ccpw = "no", temp12 = "NA";
							while (temp12 != ccpw)
							{
								textflow("\n\t\t\tMake up a password for your Credit Card : ", 20);
								cin >> temp12;
								textflow("\n\t\t\tConfirm your password : ", 20);
								cin >> ccpw;
								if (temp12 != ccpw)// validation
								{
									system("Color 0c");
									system("cls");
									cout << endl << endl << endl;
									textflow("\t\t\t\t\tPassword Mismatch!", 20);
									Sleep(1000);
									system("cls");
									system("COlor 0a");
								}
							}
							//textflow("\t\t\t\tCredit Card Obtaiend Successfully!", 20);
							cout << endl;
							double balance = 0, temp14;
							textflow("\n\t\t\tIf you want to add to your balance, type y : ", 20);
							string temp13;
							cin >> temp13;
							if (temp13 == "y" || temp13 == "Y")
							{
								textflow("\n\t\t\tHow much you want to add to your balance? : ", 20);//to add money to credit card
								cin >> temp14;
								balance += temp14;
							}
							ofstream CCard;
							CCard.open("CreditCards.txt", ios::app);
							CCard << c.getID() << psn << ccpw << balance;
							CCard.close();
							textflow("\n\t\t\tCredit card obtained successfully by ", 20);
							cout << signin;
							switcher = false;
							Sleep(2000);
							goto CUS;
							break;
						}
						else if (temp10 == 0) // to exit
						{
							textflow("\n\t\t\tThank You for Using our Service!", 20);
							Sleep(2000);
							return 0;
						}
						else
						{
							system("Color 0c");
							textflow("\n\t\t\t * Wrong Input! Try Again.", 20);
							cout << endl;
							system("Color 0a");
							Sleep(1200);
							goto CUS;

						}

					}
				}
				else
				{
				idnotfound = "\t\t\t\tGiven ID is not found";
				}
			}
			system("cls");
			cout << endl;
			system("Color 0c");
			textflow(idnotfound, 20);
			Sleep(1200);
			system("cls");
			system("Color 0a");

		}
		else if (signin == "N" || signin == "n" && switcher)
		{
			return 0;
		}
		else
		{
			system("Color 0c");
			textflow("\n\t\t\t * Wrong Input! Try Again.", 20);
			cout << endl;
			system("Color 0a");
			Sleep(1200);
			system("cls");
			goto startingpoint;
		}
	}
	dollarf.close();
	depositper.close();
	withdrawalper.close();
	system("pause");
}