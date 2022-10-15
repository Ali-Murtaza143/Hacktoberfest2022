//BSEF19M034 Ahmad Sarwar
#include<iostream>
#include<conio.h>
#include <stdio.h>
#include<iomanip>
#include<Windows.h>
HANDLE co = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Cu;			//To handle Martain Ship and Star ship
HANDLE XX = GetStdHandle(STD_OUTPUT_HANDLE);
COORD YY;			//To handle Rocket
HANDLE co0 = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Cu0;			//To handle Start Screen
HANDLE co1 = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Cu1;			//To handle Martain Ship fireballs and Star ship fireballs
HANDLE co2 = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Cu2;			//To handle Rocket Fireballs
using namespace std;
int liveg = 3;
int mar1;
int star1;
int mar2;
int star2;
class spaceship
{
protected:
	int xlo;
	int yloc;
	static int score;
public:
	virtual void draw(int) = 0;//Pure Virtaul Fucntion
	virtual int get_x() = 0;//Pure Virtaul Fucntion
	virtual int get_y() = 0;//Pure Virtaul Fucntion
	virtual void fire(int, int, int);
	virtual void move(int, int, int);
	void set(int);
	int get();
};
int spaceship::score = 0;
void spaceship::set(int a)//to set score
{
	score = score + a;
}
int spaceship::get()//to get score
{
	return score;
}

void spaceship::fire(int, int, int)
{
	//Virtual fucntion for the use in Derived Class
}
void spaceship::move(int, int, int)
{
	//Virtual fucntion for the use in Derived Class
}
class fireballs
{
private:
	int xloc;
	int yloc;
public:
	void Draw();
	void fire(int, int, bool, int, int, int, int, int);
};
void fireballs::Draw()
{
	cout << "!\n";//Drawing The Built
}
void fireballs::fire(int x, int y, bool s, int a1, int b1, int c1, int rx, int ry)
{
	if (a1 == 1)
	{	//Setting and moving the X and Y Coordinates for FireBall of rocket
		static int a = y - 1;
		if (s == true)
		{
			a = y - 1;
		}
		Cu2.Y = a;
		Cu2.X = x + 1;
		a--;
		SetConsoleCursorPosition(co2, Cu2);
		Draw();//Calling Draw fucntioin after setting
	}
	if (a1 == 0)
	{
		if (c1 == 1)
		{
			//Setting and moving the X and Y Coordinates for FireBall of Starship
			static int a = y + 6;
			if (b1 == 27)
			{
				a = y + 6;
			}
			Cu1.X = x + 5;
			Cu1.Y = a;
			if (rx == 65 || rx == 64 || rx == 63 || rx == 125 || rx == 124 || rx == 123)
			{
				if (Cu1.Y == ry)
				{
					liveg--;
				}
			}
			a++;
			SetConsoleCursorPosition(co1, Cu1);
			Draw();//Calling Draw fucntioin after setting
		}
		if (c1 == 2)
		{
			//Setting and moving the X and Y Coordinates for FireBall of MartainSjip
			static int a = y + 2;
			if (b1 == 27)
			{
				a = y + 2;
			}
			Cu1.X = x + 3;
			Cu1.Y = a;
			if (rx == 33 || rx == 32 || rx == 31 || rx == 93 || rx == 92 || rx == 91)
			{
				if (Cu1.Y == ry - 4)
				{
					liveg--;
				}
			}
			a++;
			SetConsoleCursorPosition(co1, Cu1);
			Draw();//Calling Draw fucntioin after setting
		}
	}
}
class martinship : public spaceship
{
private:
	fireballs f[200];//Array of fire Balls it contains 100 fire balls only
public:
	int get_x();
	int get_y();
	void draw(int);
	void move(int, int, int);
	void fire(int, int, int);
};
int martinship::get_x()//Getting x coordinate
{
	return xlo;
}
int martinship::get_y()//Getting y coordinate
{
	return yloc;
}
void martinship::draw(int a1)
{
	int n = yloc;
	Cu.X = a1;
	for (int i = 0; i < 5; i++)		//Drawing Martain ship at the position according to x and y
	{
		Cu.Y = n;
		SetConsoleCursorPosition(co, Cu);
		for (int j = 0; j < 7; j++)
		{
			if (i == 0 || i == 1)
			{
				cout << "*";
			}
			if (i == 2)
			{
				if (j == 3)
				{
					cout << " ";
				}
				else
				{
					cout << "*";
				}
			}
			if (i == 3)
			{
				if (j == 2 || j == 3 || j == 4)
				{
					cout << " ";
				}
				else
				{
					cout << "*";
				}
			}
			if (i == 4)
			{
				if (j == 1 || j == 2 || j == 3 || j == 4 || j == 5)
				{
					cout << " ";
				}
				else
				{
					cout << "*";
				}
			}
		}
		cout << "\n";
		n++;//Inscrease the y coordinate to Print each row of spaceship
	}
}
void martinship::move(int a1, int rx, int ry)
{
	static int i1 = 0;
	static int ch = 0;
	if (i1 <= 10)//Move Spaceship 10 steps down
	{
		for (int j = 0; j < ch; j++)
		{
			Cu.Y = ch;
		}
		yloc = ch;
		ch++;
	}
	static int a = 10;
	if (i1 <= 20 && i1 > 10)//Then move ship 10 steps up
	{
		for (int i = a; i >= 0; i--)
		{
			Cu.Y = a;
		}
		yloc = a;
		a--;
	}
	if (i1 == 20)
	{
		i1 = -1;
		a = 10;
		ch = 0;
	}
	i1++;
	SetConsoleCursorPosition(co, Cu);
	draw(a1);//Calling Draw fucntion after setting postion
	fire(a1, rx, ry);//Calling fire fucntion
}
void martinship::fire(int a1, int rx, int ry)
{
	static int fo2 = 0;
	static int a = 0;
	if (a == 27)	//Moves the fire 27 points downward towards rocket
	{
		a = 0;
		fo2++;
	}
	a++;
	if (fo2 < 200)
	{
		f[fo2].fire(a1, yloc, true, 0, a, 2, rx, ry);
	}
}
class starship : public spaceship
{
private:
	fireballs f[200];//Array of fires total 100 fires available
public:
	int get_x();
	int get_y();
	void draw(int);
	void move(int, int, int);
	void fire(int, int, int);
};
int starship::get_x()//getting x xoordinate
{
	return xlo;
}
int starship::get_y()//getting y coordinate
{
	return yloc;
}
void starship::draw(int a1)
{
	int n = yloc;
	Cu.X = a1;
	for (int i = 0; i < 5; i++)	//Drawing Star ship at the position according to x and y
	{
		Cu.Y = n;
		SetConsoleCursorPosition(co, Cu);
		for (int j = 0; j < 5; j++)
		{
			if (i == 0 && j == 0 || i == 4 && j == 0)
			{
				cout << "<<<";
			}
			if (i == 1 && j == 0 || i == 2 && j == 0 || i == 3 && j == 0)
			{
				cout << "   ";
			}
			cout << "*";
			if (i == 0 && j == 4 || i == 4 && j == 4)
			{
				cout << ">>>";
			}
		}
		cout << "\n";
		n++;//Incrasing y to print the complete spsce ship
	}
}
void starship::move(int a1, int rx, int ry)
{
	static int i1 = 0;
	static int ch = 0;
	if (i1 <= 10)//Moving 10 steps down
	{
		for (int j = 0; j < ch; j++)
		{
			Cu.Y = ch;
		}
		yloc = ch;
		ch++;
	}
	static int a = 10;
	if (i1 <= 20 && i1 > 10)//Moving 10 steps up
	{
		for (int i = a; i >= 0; i--)
		{
			Cu.Y = a;
		}
		yloc = a;
		a--;
	}
	if (i1 == 20)
	{
		i1 = -1;
		a = 10;
		ch = 0;
	}
	//s = yloc;
	i1++;
	SetConsoleCursorPosition(co, Cu);
	draw(a1);//Calling draw fucntion
	fire(a1, rx, ry);//Calling fire
}
void starship::fire(int a1, int rx, int ry)
{
	static int fo = 0;
	static int a = 0;
	if (a == 27)//Moving fire 27 stpes downwards
	{
		a = 0;
		fo++;
	}
	a++;
	if (fo < 200)
	{
		f[fo].fire(a1, yloc, true, 0, a, 1, rx, ry);
	}
}
class rocket
{
private:
	int score;
	int live;
	int xloc;
	int yloc;
	static int fo1;
	fireballs fire1[20];//Array of fires it have only 20 fires
public:
	rocket()
	{
		score = 0;
	}
	int get_x();
	int get_y();
	int get_score();
	int get_lives();
	void draw();
	void move(int);
	void fire();
	int get_fires();
};
int rocket::get_x()//Getting x coordinate
{
	return xloc;
}
int rocket::get_y()//Getting y coordinate
{
	return yloc;
}
int rocket::get_score()//Getting Score
{
	return score;
}
int rocket::get_lives()//Getting lives
{
	live = liveg;
	return live;
}
int rocket::get_fires()//To get fires in main
{
	return fo1;
}
void rocket::draw()//To draw the rocket at specific location
{
	YY.X = xloc;
	int check = yloc;
	for (int i = 0; i < 7; i++)
	{
		YY.Y = check;
		SetConsoleCursorPosition(XX, YY);
		for (int j = 0; j < 1; j++)
		{
			if (i == 0)
			{
				cout << ".A.";
			}
			if (i > 0 && i <= 5)
			{
				cout << "[|]";
			}
			if (i == 6)
			{
				cout << ">^<";
			}

		}
		cout << "\n";
		check++;
	}
}
void rocket::move(int a)
{
	static int n = 33;
	static int m = 80;
	if (a == 72)//it moves upwards
	{
		n = n - 1;
	}
	if (a == 80)//it moves downwards
	{
		n = n + 1;
	}
	if (a == 77)//it move right
	{
		m = m + 1;
	}
	if (a == 75)//it moves left
	{
		m = m - 1;
	}
	YY.Y = n;
	yloc = n;
	xloc = m;
	SetConsoleCursorPosition(XX, YY);
	draw();				//Calling draw and fire both in move
	if (a == 'f')
	{
		fire();
	}

}
void rocket::fire()
{
	spaceship* s;//Onject that counts the score
	s = new starship();
	spaceship* P[4];
	P[0] = new martinship();
	P[1] = new starship();
	P[2] = new martinship();
	P[3] = new starship();
	bool c = false;
	static int M1 = 0;
	static int M2 = 0;
	static int S1 = 0;
	static int S2 = 0;
	if (mar1 != 5)//Checking and increaing the firs on spaceship by Rocket
	{
		if (xloc + 1 >= 30)
		{
			if (xloc + 1 <= 36)
			{
				M1++;
				mar1 = M1;
			}
		}
	}
	if (mar2 != 5)//Checking and increaing the firs on spaceship by Rocket
	{
		if (xloc + 1 >= 90)
		{
			if (xloc + 1 <= 96)
			{
				M2++;
				mar2 = M2;
			}
		}
	}
	if (star1 != 3)//Checking and increaing the firs on spaceship by Rocket
	{
		if (xloc + 1 >= 120)
		{
			if (xloc + 1 <= 130)
			{
				S1++;
				star1 = S1;
			}
		}
	}
	if (star2 != 3)//Checking and increaing the firs on spaceship by Rocket
	{
		if (xloc + 1 >= 60)
		{
			if (xloc + 1 <= 70)
			{
				S2++;
				star2 = S2;
			}
		}
	}
	if (M1 == 5)//Inscrasing score According to Spaceship shot down
	{
		s->set(10);
		M1 = 0;
	}
	if (M2 == 5)//Inscrasing score According to Spaceship shot down
	{
		s->set(10);
		M2 = 0;
	}
	if (S1 == 3)//Inscrasing score According to Spaceship shot down
	{
		s->set(5);
		S1 = 0;
	}
	if (S2 == 3)//Inscrasing score According to Spaceship shot down
	{
		s->set(5);
		S2 = 0;
	}
	score = s->get();//Storing score in variable
	static bool ok1 = true;
	static bool ok2 = true;
	static bool ok3 = true;
	static bool ok4 = true;
	for (int i = 0; i < yloc; i++)//Loop to briny the fire upto spaceship
	{
		c = false;
		cout << "\nYour Score is: " << score << "\n";
		cout << "Your Lives are: " << get_lives() << "\n";
		cout << "Rocket Fires: " << get_fires() << "/20\n";
		if (mar1 == 5)
		{
			if (i > P[0]->get_y() + 15)//Checking if spaceship is destoried it will not show it
			{
				ok1 = false;
			}
			else
			{
				if (ok1 != false)
				{
					P[0]->move(30, xloc, yloc);
				}
			}
		}
		else
		{
			P[0]->move(30, xloc, yloc);
		}
		if (mar2 == 5)//Checking if spaceship is destoried it will not show it
		{
			if (i > P[2]->get_y() + 15)
			{
				ok2 = false;
			}
			else
			{
				if (ok2 != false)
				{
					P[2]->move(90, xloc, yloc);
				}
			}
		}
		else
		{
			P[2]->move(90, xloc, yloc);
		}
		if (star1 == 3)//Checking if spaceship is destoried it will not show it
		{
			if (i > P[1]->get_y() + 15)
			{
				ok3 = false;
			}
			else
			{
				if (ok3 != false)
				{
					P[1]->move(120, xloc, yloc);
				}
			}
		}
		else
		{
			P[1]->move(120, xloc, yloc);
		}
		if (star2 == 3)//Checking if spaceship is destoried it will not show it
		{
			if (i > P[3]->get_y() + 15)
			{
				ok4 = false;
			}
			else
			{
				if (ok4 != false)
				{
					P[3]->move(60, xloc, yloc);
				}
			}
		}
		else
		{
			P[3]->move(60, xloc, yloc);
		}
		move(2);
		if (i == yloc - 1)
		{
			c = true;
		}
		if (fo1 < 20)
		{
			fire1[fo1].fire(xloc, yloc, c, 1, 0, 0, -1, -1);
		}
		if (i < yloc - 1)
		{
			system("cls");
		}
	}
	fo1++;
}
int rocket::fo1 = 0;
int main()
{	//Setting the instruction screen
	Cu0.X = 65;
	Cu0.Y = 2 + 13;
	SetConsoleCursorPosition(co0, Cu0);
	cout << "~~~~~ISNTRUCTION REGRADING GAME~~~~~\n";
	Cu0.X = 55;
	Cu0.Y = 6 + 13;
	SetConsoleCursorPosition(co0, Cu0);
	cout << "1-Make Sure You Have Opened the Full Screen Of Console\n";
	Cu0.X = 55;
	Cu0.Y = 8 + 13;
	SetConsoleCursorPosition(co0, Cu0);
	cout << "2-Use Arrow keys to move the Rocket and Press 'f' to fire\n";
	Cu0.X = 60;
	Cu0.Y = 12 + 13;
	SetConsoleCursorPosition(co0, Cu0);
	cout << "Enter 'K' if you have read the Above Instruction\n";
	char a2;
	a2 = _getch();
	if (a2 == 'k' || a2 == 'K')//Taking input to  start after Instruction window
	{	//Presenting the screen with rocket and game name
		system("cls");
		int n = 10;
		Cu0.X = 60;
		for (int i = 0; i < 3; i++)
		{	 
			Cu0.Y = n;
			SetConsoleCursorPosition(co0, Cu0);
			if (i == 0)
			{
				cout << "~~~}------------------------>>\n";
			}
			if (i == 1)
			{
				cout << "~~~}|     ROCKET GAME      |>>>\n";
			}
			if (i == 2)
			{
				cout << "~~~}------------------------>>\n";
			}
			n++;
		}
		n = 20;
		int space = 6;
		int dots = 1;
		Cu0.X = 70;
		for (int i = 0; i < 10; i++)
		{
			Cu0.Y = n;
			SetConsoleCursorPosition(co0, Cu0);
			for (int n = 0; n < space; n++)
			{
				cout << " ";
			}
			if (i < 3 || i>6)
			{
				space--;
			}
			for (int j = 0; j < dots; j++)
			{
				cout << "*";
			}
			if (i < 3 || i>6)
			{
				dots = dots + 2;
			}
			cout << "\n";
			n++;
		}
		Cu0.X = 30;
		n = 25;
		for (int i = 0; i < 5; i++)
		{
			Cu0.Y = n;
			SetConsoleCursorPosition(co0, Cu0);
			for (int j = 0; j < 5; j++)
			{
				if (i == 0 && j == 0 || i == 4 && j == 0)
				{
					cout << "<<<";
				}
				if (i == 1 && j == 0 || i == 2 && j == 0 || i == 3 && j == 0)
				{
					cout << "   ";
				}
				cout << "*";
				if (i == 0 && j == 4 || i == 4 && j == 4)
				{
					cout << ">>>";
				}
			}
			cout << "\n";
			n++;
		}
		n = 25;
		Cu0.X = 110;
		for (int i = 0; i < 5; i++)
		{
			Cu0.Y = n;
			SetConsoleCursorPosition(co0, Cu0);
			for (int j = 0; j < 7; j++)
			{
				if (i == 0 || i == 1)
				{
					cout << "*";
				}
				if (i == 2)
				{
					if (j == 3)
					{
						cout << " ";
					}
					else
					{
						cout << "*";
					}
				}
				if (i == 3)
				{
					if (j == 2 || j == 3 || j == 4)
					{
						cout << " ";
					}
					else
					{
						cout << "*";
					}
				}
				if (i == 4)
				{
					if (j == 1 || j == 2 || j == 3 || j == 4 || j == 5)
					{
						cout << " ";
					}
					else
					{
						cout << "*";
					}
				}
			}
			cout << "\n";
			n++;
		}
		rocket r1;
		spaceship* p[4];
		p[0] = new martinship();
		p[1] = new starship();
		p[2] = new martinship();
		p[3] = new starship();
		int a = 0;;
		char a1;
		Cu0.X = 55;
		Cu0.Y = 35;
		SetConsoleCursorPosition(co0, Cu0);
		cout << "Enter 'S' if you want to Start the Game\n";
		a1 = _getch();
		if (a1 == 's' || a1 == 'S')//Taking input to start
		{
			while (1)
			{
				if (_kbhit())
				{
					a = _getch();//Input  to move the rocket
				}
				system("CLS");
				cout << "\nYour Score is: " << r1.get_score() << "\n";
				cout << "Your Lives are: " << r1.get_lives() << "\n";
				cout << "Rocket Fires: " << r1.get_fires() << "/20\n";
				if (mar1 != 5)
				{
					p[0]->move(30, r1.get_x(), r1.get_y());
				}
				if (mar2 != 5)
				{
					p[2]->move(90, r1.get_x(), r1.get_y());
				}
				if (star1 != 3)
				{
					p[1]->move(120, r1.get_x(), r1.get_y());
				}
				if (star2 != 3)
				{
					p[3]->move(60, r1.get_x(), r1.get_y());
				}
				r1.move(a);
				a = 0;
				if (r1.get_score() == 30 || r1.get_lives() == 0 || r1.get_fires()>20)
				{
					break;//Ending the game and showing results
				}
			}
			system("CLS");
			cout << "\n\n\n";
			cout << setw(90);
			if (r1.get_score() == 30)//Final results if
			{
				cout << "****YOU WON :)****\n";
			}
			if (r1.get_lives() == 0)//final result if lost
			{
				cout << "****GAME OVER :(****\n";
			}
			if (r1.get_fires() > 20)
			{
				cout << "****You are out of Fires :(****\n";
			}
			cout << "\n\n\n";
		}
		else
		{
			cout << "You Pressed Invalid Key, Kindly Restart the game and Enjoy\n";
		}
	}
	else
	{
		cout << "You Pressed Invalid Key, Kindly Restart the game and Enjoy\n";
	}
	return 0;
}