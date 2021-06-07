//Shukhratov Bekhzod MathGame Dec, 2020
#include <stdlib.h>     /* srand, rand */
#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>
using namespace std;
void textflow(string k, int t)//for better look.
{
	int s = size(k);
	for (int n = 0; n <= s; n++)
	{
		cout << k[n];
		Sleep(t);
	}
}
int main()
{
	fstream recobj;
	string textwel = "Welcome to the game of geniuses!";
	cout << endl << endl << "\t\t\t\t\t";
	textflow(textwel, 70);
	Sleep(1500);
	system("cls");
	start:
	int res, sub, sum, mul, num, div, a, b, lives, corrects=0, op, range, level=1, t=100, t2=2500, dif, lo, cdown=0, record=0;// lo last option
	string textgm;
	recobj.open("Recordfile.txt");
	cout << endl << endl << "\t\t\t\t\tChoose the difficulty of the game!" << endl;
	cout << endl << "\t\t\t\t\tEasy:     1" << endl;
	cout << endl << "\t\t\t\t\tNormal:   2" << endl;
	cout << endl << "\t\t\t\t\tHard:     3" << endl;
	cout << endl << "\t\t\t\t\tInsane:   4" << endl;
	rechoose:
	cin >> dif;// difficulty
	Sleep(300);
	system("cls");
	if (dif == 1)
	{
		lives = 5;
		range = 2;
	}
	else if (dif == 2)
	{
		lives = 3;
		range = 5;
	}
	else if (dif == 3)
	{
		lives = 2;
		range = 20;
	}
	else if (dif == 4)
	{
		lives = 1;
		range = 30;
	}
	else
	{
		cout << "Please choose a valid option" << endl;
		goto rechoose;
	}
startingpoint:
	cout << "\t       ";
	cout << "Lives remaining: " << lives << "     Corrects answers: " << corrects << "     Level: " << level << "     Total Score: "<<cdown<<endl;
	srand(time(NULL));
	op = rand() % 5 + 1;
	a = rand() % range;
	b = rand() % range+1;
	switch (op)
	{
	case 1: res = a - b;
		break;
	case 2: res = a + b;
		break;
	case 3: res = a * b;
		break;
	case 4: res = a % b;
		break;
	case 5: res = a / b;
		break;
	}
	//----------------------------------------------------------------------------------------------
	cout << a;
	Sleep(t);
	if (op == 1)
		cout << "-";
	else if (op == 2)
		cout << "+";
	else if (op == 3)
		cout << "*";
	else if (op == 4)
		cout << "%";
	else
		cout<< "/";
	Sleep(t);
	cout << b;
	Sleep(t);
	cout << " =" << endl;
	//----------------------------------------------------------------------------------------------
	cin >> num;
	if (num == res)
	{
		cout << "Correct :)" << endl << endl;
		corrects++;
		cdown = cdown + 10;
		//string tempint;
		ifstream obj;
		obj.open("Recordfile.txt");
		//getline(obj, tempint);
		int someintt;
		//someintt = stoi(tempint);
		/*if (corrects > someintt)
		{
			record = corrects;
		}*/
		if (corrects == 6)
		{
			range+=5;//10
			system("cls");
			cout << endl << endl << endl << "\t\t\t\t\t" << "You have reached Level 2" << endl;
			Sleep(t2);
			level++;
		}
		else if (corrects == 11)
		{
			range+=6;//15
			system("cls");
			cout << endl << endl << endl << "\t\t\t\t\t" << "You have reached Level 3" << endl;
			Sleep(t2);
			level++;
		}
		else if (corrects == 16)
		{
			range += 7;//20
			system("cls");
			cout << endl << endl << endl << "\t\t\t\t\t" << "You have reached Level 4" << endl;
			Sleep(t2);
			level++;
		}
		else if (corrects == 21)
		{
			range += 8;//25
			system("cls");
			cout << endl << endl << endl << "\t\t\t\t\t" << "You have reached Level 5" << endl;
			Sleep(t2);
			level++;
		}
		else if (corrects == 26)
		{
			range += 9;//30
			system("cls");
			cout << endl << endl << endl << "\t\t\t\t\t" << "You have reached the Highest Level" << endl;
			Sleep(t2);
			level++;
		}
	}
	else if (num!=res)
	{
		cout << "Wrong :(" << endl<<endl;
		cout << "Correct answer was: " << res;
		Sleep(2000);
		lives--;
		if (lives == 0)
			goto exit;
		cdown = cdown - 10;
	}
	Sleep(500);
	system("cls");
	goto startingpoint;
exit:
	cout << endl << endl << "\t\t\t\t\t\t     ";
	textgm = "GAME OVER";
	textflow(textgm, 100);
	cout << endl << endl;
	cout << "Your score is: " <<corrects<< endl;
	cout << endl << endl;
	cout << "To play again, tap 1" << endl << "To exit the game, tap any button!";
	cin >> lo;
	system("cls");
	if (lo == 1)
	{
		goto start;
	}
	else
	{
		cout << "See you next time!" << endl << endl;
		recobj << record;
	}
}