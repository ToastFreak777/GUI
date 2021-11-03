#include <iostream>
using namespace std;

int main()
{
	int input, Lhp, Latk, Ldef, FLhp, FLatk, FLdef;
	float ki = 0.0, BaseAttack = 0.0, BaseHp = 0.0, BaseDef = 0.0, LeaderSkill, percentage, TotalHP, Link[7];
	string name;

	cout << "What do you want to calc? \n 1.Team hp\n 2.Unit atk\n 3.Unit def" << endl;
	cin >> input;

	switch (input)
	{
	case 1:
		int input2;
		cout << "Do you have the total team Hp? (1.Yes/2.No) " << endl;
		cin >> input2;

		switch (input2)
		{
		case 1:
			cout << "What is the name of the category you're calcing" << endl;
			cin >> name;
			cout << "What is the total hp for " << name << endl;
			cin >> BaseHp;
			cout << "What is your leaderskill? " << endl;
			cin >> Lhp;
			cout << "What is your friend leaderskill? " << endl;
			cin >> FLhp;

			cout << "Calculating team hp..."
				<< "\n";

			LeaderSkill = Lhp + FLhp;
			percentage = (LeaderSkill / 100) + 1.0;

			TotalHP = BaseHp * percentage;

			cout << "The total hp for " << name << " is: " << TotalHP << endl;
			break;

		case 2:
			int Unit[7];
			for (int i = 0; i < 7; i++)
			{
				cout << "Unit " << i << " hp:" << endl;
				cin >> Unit[i];
				BaseHp += Unit[i];
			}

			cout << "What is the name of the category you're calcing" << endl;
			cin >> name;
			cout << "What is your leaderskill? " << endl;
			cin >> Lhp;
			cout << "What is your friend leaderskill? " << endl;
			cin >> FLhp;

			cout << "Calculating team hp..."
				<< "\n";

			LeaderSkill = Lhp + FLhp;
			percentage = (LeaderSkill / 100) + 1.0;

			TotalHP = BaseHp * percentage;

			cout << "The total hp for " << name << " is: " << TotalHP << endl;
			break;
		default:
			cout << "invalid choice"
				<< "\n";
		}

		break;

	case 2:

		break;

	case 3:

		break;

	default:
		cout << "Invalid choice" << endl;
	}

	return 0;
}