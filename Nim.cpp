// Nim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Board.h"
#include "Players.h"
#include "AiPlayer.h"

using namespace std;

int gameVer();
void greeting(Players, Players);
void turnNum(Players, Players, int);
bool AiorPlayer();

int main()
{
	int num;
	string name;
	bool test;
	bool choice;
	num = gameVer();
	choice = AiorPlayer();
	Board board1(num);/**/
	Players player1("Sean", "Flores");
	Players player2("", "");
	AiPlayer computer(num);
	if (choice == true)
	{
		player2.setFirstName("Computer");
		player2.setLastName("AI");
	}
	else
	{
		player2.setFirstName("Matt");
		player2.setLastName("Long");
	}
	/**/
	/*
	Players player1("", "");
	Players player2("", "");
	player1.setInfo();
	if (choice == 1)
	{
		Players player2("Computer", "Player");
	}
	else
	{
		Players player2("", "");

		player2.setInfo();
	}*/
 // ask for ther names
	greeting(player1, player2);
	int linesCount;
	board1.fillBoard();
	board1.showBoard();
	///////////////////////
	for (int i = 0; i < 4; i++)
	{
		linesCount = board1.getlines(i);
		computer.examineBoard(i, linesCount, num);
	}
	computer.display();
	/////////////////////
	int turn = 1;

	bool finalTest = false;
	bool quickTest = false;

	while (finalTest == false)
	{
		turnNum(player1, player2, turn);

		board1.showBoard();
		/////////////////////////
		for (int i = 0; i < 4; i++)
		{
			linesCount = board1.getlines(i);
			computer.examineBoard(i, linesCount, num);
		}
		computer.changeBoard();
		computer.display();
		computer.refresh(num);
		cout << endl;
		////////////////////////
		board1.setLineNum();
		board1.setAmountNum();
		test = board1.testing();

		if (test == false)
		{
			cout << "not possible" << endl;
		}
		else
		{
			board1.changBoard();
			board1.showBoard();
			finalTest = board1.testBoard();
			turn++;
		}

	}
	board1.showBoard();
	turn--;
	if (turn % 2 == 0)
		cout << player2.getFirstName() << " you have lost." << endl;
	else
		cout << player1.getFirstName() << " you have lost." << endl;
	cout << "the game is over";

    return 0;
}

int gameVer()
{
	int num;
	cout << "Which version? \n0: 3,5,7 \n1: 1,3,5,7" << endl;
	cin >> num;
	return num;
}

void greeting(Players player1, Players player2)
{
	cout << "Hello ";
	player1.displayName();
	cout << "and ";
	player2.displayName();
	cout << endl;
}

void turnNum(Players player1, Players player2, int turn)
{
//	if (turn != 1)
//	{
//		system("cls");
//	}
	cout << "Turn number " << turn << " ";
	if (turn % 2 == 0)
		cout << player2.getFirstName() << " it's your turn." << endl;
	else
		cout << player1.getFirstName() << " it's your turn." << endl;
}

bool AiorPlayer()
{
	int choice;
	cout << "Would you like to play against a the computer or a friend?" << endl;
	cout << "Computer 1\nFriend 2" << endl;
	cin >> choice;
	if (choice == 1)
		return true;
	else if (choice == 2)
		return false;
	else
		return false;
}