//TikTacToeGame Feb, 2021
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
void texteffect(string k)
{
	int p = size(k);
	for (int n = 0; n <= p; n++)
	{
		cout << k[n];
		Sleep(50);
	}
}
void displayres(string num)
{
	int a[10];
	cout << num;
	texteffect(" Player Won");
	cout << endl << endl;
	Sleep(1000);
}
int main()
{
	int num;
	string ch, a[10];
start:
	cout << "Type O to play" << endl << "Type X to exit" << endl;
	cin >> ch;
	if (ch == "o")
	{
		for (int i = 0; i < 10; i++)
		{
			a[i] = " ";
		}
		for (int j = 0; j < 9; j++)
		{
			system("cls");
			cout << "     |     |     " << endl;
			cout << "  " << a[7] << "  |  " << a[8] << "  |  " << a[9] << "  " << endl;
			cout << "-----------------" << endl;
			cout << "     |     |     " << endl;
			cout << "  " << a[4] << "  |  " << a[5] << "  |  " << a[6] << "  " << endl;
			cout << "-----------------" << endl;
			cout << "     |     |     " << endl;
			cout << "  " << a[1] << "  |  " << a[2] << "  |  " << a[3] << "  " << endl;
			texteffect("Enter Number");
			cin >> num;
			if (j % 2 == 0)
				a[num] = "X";
			else
				a[num] = "O";
			if ( a[1]==a[num] && a[2]==a[num] && a[3]==a[num]) 
			{
				displayres(a[num]);
				goto start;
			}
			else if (a[4] == a[num] && a[5] == a[num] && a[6] == a[num])
			{
				displayres(a[num]);
				goto start;
			}
			else if (a[7] == a[num] && a[8] == a[num] && a[9] == a[num])
			{
				displayres(a[num]);
				goto start;
			}
			else if (a[1] == a[num] && a[4] == a[num] && a[7] == a[num])
			{
				displayres(a[num]);
				goto start;
			}
			else if (a[2] == a[num] && a[5] == a[num] && a[8] == a[num])
			{
				displayres(a[num]);
				goto start;
			}
			else if (a[3] == a[num] && a[6] == a[num] && a[9] == a[num])
			{
				displayres(a[num]);
				goto start;
			}
			else if (a[1] == a[num] && a[5] == a[num] && a[9] == a[num])
			{
				displayres(a[num]);
				goto start;
			}
			else if (a[3] == a[num] && a[5] == a[num] && a[7] == a[num])
			{
				displayres(a[num]);
				goto start;
			}
		}
	}
	else if (ch == "x")
	{
		exit;
	}
	else
		goto start;
}