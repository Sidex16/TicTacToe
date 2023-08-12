#include <iostream>
#include <cstdlib>
using namespace std;

class TicTacToe
{
public:
	void ui()
	{
		enter();

		while (true)
		{
			system("cls");
			display();
			excahngex();
			if (winx == 1)
			{
				break;
			}
			system("cls");
			display();
			excahngeo();
			if (wino == 1)
			{
				break;
			}
		}
		displayw();
	}

private:
	char field[4][4];
	int winx = 0, wino = 0;

	void clearScreen()
	{
#ifdef _WIN32
		system("cls");
#else
		system("clear");
#endif
	}

	void enter()
	{
		for (int i = 1; i < 4; i++)
		{
			for (int j = 1; j < 4; j++)
			{
				field[i][j] = '#';
			}
		}
	}

	void display()
	{
		line();
		for (int i = 1; i < 4; i++)
		{
			cout << '\t' << "     ";
			for (int j = 1; j < 4; j++)
			{
				cout << field[i][j] << " ";
			}
			cout << endl;
		}
	}

	void displayw()
	{
		clearScreen();
		display();
		line();
		if (wino == 1)
			cout << '\t' << "Player 'o' wins!" << endl;

		if (winx == 1)
			cout << '\t' << "Player 'x' wins!" << endl;

		line();
	}

	void excahngex()
	{
		int x, y;
	x:
		line();
		cout << "Player x's turn!" << endl;
		cout << "Enter the column (x coordinate):" << endl;
		cin >> x;
		cout << "Enter the row (y coordinate):" << endl;
		cin >> y;
		line();

		if (x < 1 || x > 3 || y < 1 || y > 3 || field[y][x] != '#')
		{
			clearScreen();
			cout << "Enter a valid cell!" << endl;
			display();
			goto x;
		}

		field[y][x] = 'x';
		checkWin('x');
		display();
	}

	void excahngeo()
	{
		int x, y;
	o:
		line();
		cout << "Player o's turn!" << endl;
		cout << "Enter the column (x coordinate):" << endl;
		cin >> x;
		cout << "Enter the row (y coordinate):" << endl;
		cin >> y;
		line();

		if (x < 1 || x > 3 || y < 1 || y > 3 || field[y][x] != '#')
		{
			clearScreen();
			cout << "Enter a valid cell!" << endl;
			display();
			goto o;
		}

		field[y][x] = 'o';
		checkWin('o');
		display();
	}

	void checkWin(char player)
	{
		for (int i = 1; i <= 3; i++)
		{
			if (field[i][1] == player && field[i][2] == player && field[i][3] == player)
			{
				if (player == 'x')
					winx = 1;
				else
					wino = 1;
				return;
			}

			if (field[1][i] == player && field[2][i] == player && field[3][i] == player)
			{
				if (player == 'x')
					winx = 1;
				else
					wino = 1;
				return;
			}
		}

		if (field[1][1] == player && field[2][2] == player && field[3][3] == player)
		{
			if (player == 'x')
				winx = 1;
			else
				wino = 1;
			return;
		}

		if (field[1][3] == player && field[2][2] == player && field[3][1] == player)
		{
			if (player == 'x')
				winx = 1;
			else
				wino = 1;
			return;
		}
	}

	void line()
	{
		cout << "<----------------------------->" << endl;
	}
};

int main()
{
	TicTacToe ti;
	ti.ui();
	return 0;
}
