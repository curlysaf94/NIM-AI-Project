#pragma once
#include <iostream>

using namespace std;

class AiPlayer
{
public:
	AiPlayer(int num)
	{
		int start = 7;
		for (int i = 0; i < 4; i++)
		{
			lines[i] = start;
			
			start -= 2;
		}
		setTheBoard(num);

	}
	void examineBoard(int i, int num, int ver)
	{
		lines[i] = lines[i] - num;
		if (ver == 0)
			lines[3] = 0;

	//	cout << lines[i];
	}
	void refresh(int num)
	{
		int start = 7;
		for (int i = 0; i < 4; i++)
		{
			lines[i] = start;
			start -= 2;
		}
		if (num == 0)
			lines[3] = 0;
	}
	void setTheBoard(int num)
	{
		board[0][0] = true;		//7
		board[0][1] = true;
		board[0][2] = true;

		board[1][0] = true;		//5
		board[1][1] = false;
		board[1][2] = true;

		board[2][0] = false;		//3
		board[2][1] = true;
		board[2][2] = true;

		board[3][0] = false;		//1
		board[3][1] = false;
		if (num == 0)
			board[3][2] = false;
		else
			board[3][2] = true;
	}
	void display()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == true)
				{
					if (j == 0)
						cout << "||||\t";
					else if (j == 1)
						cout << "||\t";
					else
						cout << "|";
				}
				else
					cout << "\t";
			}
			cout << endl;
		}
	}
	void changeBoard()
	{
		for (int i = 0; i < 4; i++)
		{
//			cout << lines[i];
			switch (lines[i])
			{
			case 7:board[i][0] = true;
				board[i][1] = true;
				board[i][2] = true;
				break;
			case 6:board[i][0] = true;
				board[i][1] = true;
				board[i][2] = false;
				break;
			case 5:board[i][0] = true;
				board[i][1] = false;
				board[i][2] = true;
				break;
			case 4:board[i][0] = true;
				board[i][1] = false;
				board[i][2] = false;
				break;
			case 3:board[i][0] = false;
				board[i][1] = true;
				board[i][2] = true;
				break;
			case 2:board[i][0] = false;
				board[i][1] = true;
				board[i][2] = false;
				break;
			case 1:board[i][0] = false;
				board[i][1] = false;
				board[i][2] = true;
				break;
			case 0: board[i][0] = false;
				board[i][1] = false;
				board[i][2] = false;
				break;
			default: cout << "Error in code" << endl;
				break;
			}
		}
	}
	int filledLines()
	{
		int filledLines = 0;
		bool filledTest = false;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)		// run throu the board
			{									
				if (board[i][j] == true)
					filledTest = true;
			}
			if (filledTest == true)
			{
				filledLines++;			// a line still has lines.
				filledTest = false;		// reset for next line
			}
		}
		return filledLines;
	}
	void leaveOne()				// when ther is one line the AI will take all but one
	{

	}
	void removeAll()				// two lines where has more then one and another only has one.
	{

	}
	void removeOne()				// each line only has one, remove one
	{

	}
private:
	int lineToRemove;
	int amountToRemove;
	int lines[4];
	bool board[4][3];
};