/* Dec, 2020
My first project in C++*///with some bugs)
#include<iostream>
using namespace std;
void exchange()//void function without return 
{
	int e;
	exchangemenu:// goto statement to imput again program number
	cout << "Please choose from what and to what currency you want to convert" << endl;
	cout << "Tap 1 to convert your Soums to Dollars" << endl;
	cout << "Tap 2 to convert your Soums to Russian Ruble" << endl;
	cout << "Tap 3 to convert your Russian Ruble to Soums" << endl;
	cout << "Tap 4 to convert your Russian Ruble to Dollars" << endl;
	cout << "Tap 5 to convert your Dollars to Soums" << endl;
	cout << "Tap 6 to convert your Dollars to Russian Ruble" << endl;
	cout << "Tap 7 to exit the Money Exchange Menu" << endl;
	cin >> e;
	switch (e)//switch statement to choose which currencies to convert mobey from and to
	{
	case 1:
	{
		cout << "The currency ratio of Soum to Dollar is 0.000096" << endl;// This tells the ratio between two choosen currencies
		cout << "How much Soums you want to convert to Dollars?" << endl;// asks for input the money
		double a, b;// these are variables of type double because the number will be decimal
		reinput1://goto statement for reinoutting when invalid number inputted
		cin >> a;//inputting the value for a
		if (a > 0)//if statement. validation check
		{
			goto here1;// goto statement when valid number inputted
		}
		else// when incalid, number less than 0 inputted, it will return to input again
		{
			cout << "Enter a valid amount of money" << endl;
			goto reinput1;// goto statement, works when wrong value is inputted
		}
		here1:// goto statement will come here when valid value inputted to a
		b = 0.000096 * a;// this is for exchanging currency. I took that number on internet
		cout << "Your Soums in Dollars will be: $" << b << endl;// this will print the result
		cout << "To go to Exchange Menu, tap 1" << endl;
		cout << "To go to Main Menu, tap 2" << endl;
		int k;// this is for choosing what program does next
		cin >> k;
		if (k == 1)// validation check for k.
			goto exchangemenu;//if 1 is unputted, then it will go to the beginning to change this currencies again
		else break;// otherwise it will go to mainmenu
	}
	case 2:// the things are the same as first for the following 5 (five) cases 
	{
		cout << "The currency ratio of Soum to Russian Ruble is 0.0071" << endl;
		cout << "How much Soums you want to convert to Russian Ruble?" << endl;
		double a, b;
	    reinput2:
		cin >> a;
		if (a > 0)
		{
			goto here2;
		}
		else
		{
			cout << "Enter a valid amount of money" << endl;
			goto reinput2;
		}
	    here2:
		b = 0.0071 * a;
		cout << "Your Soums in Ruble will be: " << b <<" Rubles"<< endl;
		cout << "To go to Exchange Menu, tap 1" << endl;
		cout << "To go to Main Menu, tap 2" << endl;
		int k;
		cin >> k;
		if (k == 1)
			goto exchangemenu;
		else break;

	}
	case 3:
	{
		cout << "The currency ratio of Russian Ruble to Soum is 141.72" << endl;
		cout << "How much Rubles you want to convert to Uzbek Soum?" << endl;
		double a, b;
	reinput3:
		cin >> a;
		if (a > 0)
		{
			goto here3;
		}
		else
		{
			cout << "Enter a valid amount of money" << endl;
			goto reinput3;
		}
	here3:
		b = 141.72 * a;
		cout << "Your Ruble in Soums will be: " << b << " Soums" << endl;
		cout << "To go to Exchange Menu, tap 1" << endl;
		cout << "To go to Main Menu, tap 2" << endl;
		int k;
		cin >> k;
		if (k == 1)
			goto exchangemenu;
		else break;
	}
	case 4:
	{
		cout << "The currency ratio of Russian Ruble to Dollars is 0.014" << endl;
		cout << "How much Rubles you want to convert to Dollars?" << endl;
		double a, b;
	reinput4:
		cin >> a;
		if (a > 0)
		{
			goto here4;
		}
		else
		{
			cout << "Enter a valid amount of money" << endl;
			goto reinput4;
		}
	here4:
		b = 0.014 * a;
		cout << "Your Ruble in Dollars will be: $" << b << endl;
		cout << "To go to Exchange Menu, tap 1" << endl;
		cout << "To go to Main Menu, tap 2" << endl;
		int k;
		cin >> k;
		if (k == 1)
			goto exchangemenu;
		else break;
	}
	case 5:
	{
		cout << "The currency ratio of Dollars to Uzbek Soums is 10441.5" << endl;
		cout << "How much Dollars you want to convert to Soums?" << endl;
		double a, b;
	reinput5:
		cin >> a;
		if (a > 0)
		{
			goto here5;
		}
		else
		{
			cout << "Enter a valid amount of money" << endl;
			goto reinput5;
		}
	here5:
		b = 10441.50 * a;
		cout << "Your Dollars in Uzbek Soums will be: " << b << " Soums" << endl;
		cout << "To go to Exchange Menu, tap 1" << endl;
		cout << "To go to Main Menu, tap 2" << endl;
		int k;
		cin >> k;
		if (k == 1)
			goto exchangemenu;
		else break;
	}
	case 6:
	{
		cout << "The currency ratio of Dollars to Russian Rubles is 73.67" << endl;
		cout << "How much Dollars you want to convert to Rubles?" << endl;
		double a, b;
	reinput6:
		cin >> a;
		if (a > 0)
		{
			goto here6;
		}
		else
		{
			cout << "Enter a valid amount of money" << endl;
			goto reinput6;
		}
	here6:
		b = 73.67 * a;
		cout << "Your Dollars in Rubles will be: " << b << " Rubles" << endl;
		cout << "To go to Exchange Menu, tap 1" << endl;
		cout << "To go to Main Menu, tap 2" << endl;
		int k;
		cin >> k;
		if (k == 1)
			goto exchangemenu;
		else break;
	}
	case 7:// when 7 is inputted for a, the program will go to main menu (main function)
	{
		break;
	}
	default: goto exchangemenu;// when any other number inputted, it will ask to input again
	}
}
double credit(double a, double b)// credit is type double and has return. parameters, values of a and b are inputted in the main function
{
	int i = 1;//i is type integer because used for loop number
	float percent = 10;// this is the initial value of percent
	while (i < b)// while loop. it will run untill loop number is equal to given month or year number
	{
		percent = percent + 5;// every span of time, it will be increased by 5 percent
		++i;// increment
		
	}
	return ((percent/100)*a)+a;// this will return the value to the main function
}
// the border between main and other functions to easily know when to stop scrolling

int main()
{
	int k;// k is used to choose which program to perform
	startingpoint://goto statement. this is used to use the program again or for validation
	cout << "Good Day dear customer, Welcome to Bekhzod's Bank and Accounting" << endl;
	cout << "If you want to exchange your money with other Currency, Tap 1" << endl;
	cout << "If you want to borrow money as credit with additional fee, Tap 2" << endl;
	cout << "If you want to keep your money in Bekhzod's Bank with profit, Tap 3" << endl;
	cout << "If you are looking for Exit door of the Bekhzod's Bank, Tap 4" << endl;
	cin >> k;// here we input the value to k
	switch (k)// switch statement to choose program
	{
	case 1:
	{
		cout << "Currency exchange" << endl;
		exchange();// this will call the excahnge function
		goto startingpoint;// after the program ends, it will go to the main menu to ask what to do next
	}
	case 2:
	{
		cout << "Good Day dear Customer. Welcome to Credit Giving Section of Bekhzod's Bank" << endl;
		cout << "Our credit system is unique. You ask a sum of money and choose in how many years you will return the Credit" << endl;
		cout << "We give credits by 10 percent additional fee for the first year." << endl;
		cout << "And all the next years there will be 5 percent addition to 10 percent" << endl;
		cout<<"For example, if you want to borrow 100,000 soums for 2 years, "<<endl;
		cout << "then you will have to return it by 15 percent additional fee, 115,000 soums" << endl;
	creditmenu:// this is used when user wants to borrow money again
		cout << "How Much money in Soums you want to borrow?" << endl;
		double a, b;/// the amount of money will be decimal
		positivemoney:// validation check. money cannot be not positive number
		cin >> a;
		if (a <= 0)//validation check
		{
			goto positivemoney;// if money is <0 than it will goto input again
			cout << "Your money must be more than 0, please input valid sum of money" << endl;
		}
		cout << "In how many Years you will pay the money back?" << endl;
		cin >> b;
		credit(a, b);
		cout << "By the end of " << b << " years you will have to pay " << credit(a, b) << " Soums" << endl << endl;//this will show the result
		cout << "To borrow money again, type 1" << endl << "To go to Main Menu, type any number" << endl;///this will ask what to do next
		int j;// for choosing
		cin >> j;
		switch (j)
		{
		case 1:
		{
			goto creditmenu;// if use types 1 then he can borrow money again
		}
		default: goto startingpoint;// if user wants to go to main menu, he will type 2
		}

		goto startingpoint;// this is not needed actually
	}
	case 3:
	{

		double money, ip;// ip is interest percentage. my bank can convert decimal numbers too
		int year;//years are integer numbers
		cout << "Good Day dear Customer" << endl;
		cout <<"Welcome to the 'Keep your Money at Bekhzod's Bank with Deposit' Section" << endl;
		cout << "Here you can save your money with Monthly or Yearly Interest" << endl;
	depositmenu:// this is used to make deposit again
		cout << "To choose Monthly interest, type 1" << endl << "To choose Yearly interest, type 2" << endl;
		int l;
		cin >> l;
		if (l>2||l<1)// this is for choosing either yearly or monthly interest
		{
			cout << "Please choose a valid Duration of Interest" << endl;
			goto depositmenu;// validation check. goes to the input part
		}
		cout << "Just enter how much money you want to deposit!" << endl;
		validmoney:// money validation
		cin >> money;
		if (money <=0)
		{
			cout << "You cannot save not positive sum of money, please enter a valid value for money" << endl;
			goto validmoney;
		}
		cout << "Enter the Deposit Percentage" << endl;
		cin >> ip;
		cout << "Enter after how many";
		if (l == 2)/// this is for user friendliness. this is for identifying month or year used and then display
		{
			cout << " years";
		}
		else if (l == 1)
		{
			cout << " months";
		}
		cout<<" you want to get your money back" << endl;
		cin >> year;// this sets the period
		double b;
		b = ip / 100 + 1;// this is formula to find deposit. 
		for (int a = 0; a < year; ++a)// for loop
		{
			money *= b;// every month/year out money will be multiplied by b (percentage/100+1)
		}
		//This part is for user friendliness it will add s to year or month when in plural----------------
		cout << "After " << year;
		if (l == 2)
		{
			if (year == 1)
			{
				cout << " year";
			}
			else
			{
				cout << " years";
			}
		}
		else if (l == 1)
		{
			if (year == 1)
			{
				cout << " month";
			}
			else
			{
				cout << " months";
			}
		}//-----------------------------------------------------------------------------------------------
		cout<<", your Money will be: " << money;// displays the final value of our money
		
		cout<< endl << endl;
		options:// this is for what to do next
		cout << "To make Deposit again, tap 1" << endl << "To go to Main Menu, tap 2" << endl;
		int g;
		cin >> g;
		if (g == 1)
		{
			goto depositmenu;// goes to deposit menu again to make deposit
		}
		else if (g == 2)
		{
			goto startingpoint;// goes to main menu
		}
		else// or prints input a valid device when other numbers entered
		{
			cout << "Please choose a valid option" << endl<<endl;
			goto options;
		}
	}
	case 4:
	{
		goto exit;// this is for exiting the whole program
	}
	default: 
	{
		cout << "Please choose a valid option!" << endl;// validation check
		goto startingpoint;
	}

	}

exit:
	cout << "Thank you for using Bekhzod's Bank" << endl << "We hope you will come again :)" << endl;
	// this is for userfriendliness)


	system("pause");
	return 0;
}
