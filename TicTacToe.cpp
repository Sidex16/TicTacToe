#include <iostream>
#include <cstdlib>
using namespace std;

class TicTacToe
{
public:
	void ui()
	{
		enter();

		display();

		while (true)
		{
			excahngex();
			if (winx == 1)
			{
				break;
			}

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

	void enter() {
		for (int i = 1; i < 4; i++) 
		{
			for (int j = 1; j < 4; j++)
			{
				field[i][j] = '#';
			}

		}


	}
	void display() {
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
	x:
		line();
		int x, y;
		cout << "Player x's turn!" << endl;
		cout << "Enter the collon (x coordinate):" << endl;
		cin >> x;
		cout << "Enter the row (y coordinate):" << endl;
		cin >> y;
		line();
		if (field[y][x] == '#')
			field[y][x] = 'x';
		else {
			clearScreen();
			cout << "Enter the correct cell!" << endl;
			display();
			goto x;
		}

		clearScreen();

		if (field[1][1] == 'x' and field[1][2] == 'x' and field[1][3] == 'x') 
		{
			winx = 1;
		}

		if (field[2][1] == 'x' and field[2][2] == 'x' and field[2][3] == 'x')
		{
			winx = 1;
		}

		{
			winx = 1;
		}

		if (field[1][1] == 'x' and field[2][1] == 'x' and field[3][1] == 'x')
		{
			winx = 1;
		}

		if (field[1][2] == 'x' and field[2][2] == 'x' and field[3][2] == 'x')
		{
			winx = 1;
		}

		if (field[1][3] == 'x' and field[2][3] == 'x' and field[3][3] == 'x') 
		{
			winx = 1;
		}

		if (field[1][1] == 'x' and field[2][2] == 'x' and field[3][3] == 'x') 
		{
			winx = 1;
		}

		if (field[1][3] == 'x' and field[2][2] == 'x' and field[3][1] == 'x') 
		{
			winx = 1;
		}

		display();

	}
	void excahngeo() 
	{
	o:
		line();
		int x, y;
		cout << "Player o's turn!" << endl;
		cout << "Enter the collon (x coordinate):" << endl;
		cin >> x;
		cout << "Enter the row (y coordinate):" << endl;
		cin >> y;
		line();

		if (field[y][x] == '#')
			field[y][x] = 'o';
		else 
		{
			clearScreen();
			cout << "Enter the correct cell!" << endl;
			display();
			goto o;
		}

		clearScreen();

		if (field[1][1] == 'o' and field[1][2] == 'o' and field[1][3] == 'o') 
		{
			wino = 1;
		}

		if (field[2][1] == 'o' and field[2][2] == 'o' and field[2][3] == 'o') 
		{
			wino = 1;
		}

		if (field[3][1] == 'o' and field[3][2] == 'o' and field[3][3] == 'o')
		{
			wino = 1;
		}

		if (field[1][1] == 'o' and field[2][1] == 'o' and field[3][1] == 'o') 
		{
			wino = 1;
		}

		if (field[1][2] == 'o' and field[2][2] == 'o' and field[3][2] == 'o')
		{
			wino = 1;
		}

		if (field[1][3] == 'o' and field[2][3] == 'o' and field[3][3] == 'o')
		{
			wino = 1;
		}

		if (field[1][1] == 'o' and field[2][2] == 'o' and field[3][3] == 'o')
		{
			wino = 1;
		}

		if (field[1][3] == 'o' and field[2][2] == 'o' and field[3][1] == 'o')
		{
			wino = 1;
		}
		display();
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