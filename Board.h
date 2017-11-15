#pragma once
#include <iostream>
#include "AiPlayer.h"

using namespace std;

class Board
{
public:
	Board(int num1)
	{
		version = num1;
		if (num1 == 0)
		{
			numCoins = 15;
			totalRows = 3;
		}
		else
		{
			numCoins = 16;
			totalRows = 4;
		}
		end = false;
		for (int i = 0; i < 4; i++)
		{
			lines[i] = 0;
		}

		linesLim[0] = 7;
		linesLim[1] = 5;
		linesLim[2] = 3;
		linesLim[3] = 1;
	}
	// fill the board with X's
	void fillBoard()
	{
		int rowAmount = 7;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < rowAmount; j++)
			{
				boardArr[i][j] = 'X';
			}
			rowAmount = rowAmount - 2;
		}
		if (numCoins == 15)
			boardArr[3][0] = '_';
	}
	// show the board to the user
	void showBoard()
	{
		int row = 1;
		int rowAmount = 7;
		cout << endl;
		for (int i = 0; i < totalRows; i++)
		{
			cout << "Line " << row << " ";
			addSpaces(row);
			for (int j = 0; j < rowAmount; j++)
			{
				cout << boardArr[i][j] << " ";
			}
			cout << endl;
			row++;
			rowAmount = rowAmount - 2;
		}
		cout << endl;
	}
	// add spaces to create a pyramide
	void addSpaces(int row)
	{
		int spaces;
		switch (row)
		{
		case 1: spaces = 0;
			break;
		case 2: spaces = 1;
			break;
		case 3: spaces = 2;
			break;
		case 4: spaces = 3;
			break;
		default: cout << "error in Program";
		}
		for (int i = 0; i < spaces; i++)
		{
			cout << "  ";
		}
	}
	// set the private int lineNum with the line that will be changed
	void setLineNum()
	{
		cout << "which Line: ";
		cin >> lineNum;
		lineNum = lineNum - 1;
	}
	// set the private int amountNum to show how many X's will be removed
	void setAmountNum()
	{
		cout << "How many: ";
		cin >> amountNum;
	}
	//
	int getLineNum()
	{
		return lineNum;
	}
	//
	int getAmountNum()
	{
		return amountNum;
	}
	//
	void changBoard()
	{
	//	cout << lineNum;
		int start = lines[lineNum];
		for (int i = 0; i < amountNum; i++)
		{
			boardArr[lineNum][start] = '_';
			start++;
		}
		lines[lineNum] = start;
	}
	//
	bool getEnd()
	{
		return end;
	}
	// test to see if the input move is legal			Done
	bool testing()
	{
//		if(lines[lineNum] - amountNum < 0;
		if (lines[lineNum] + amountNum > linesLim[lineNum])
		{
			cout << "the amount is too high" << endl;
			return false;
		}
		else
			return true;
	}
	// final test to see if game is over
	bool testBoard()
	{	
		for (int i = 0; i < totalRows; i++)
		{
			if (lines[i] != linesLim[i])
				return false;
		}
		cout << "testboard\n";
		return true;
		/*
		int row = 0;
		int limit = 7;

		for (int i = 0; i < totalRows; i++)
		{
			if (boardArr[row][limit] == 'X')
				return false;
			limit = limit - 2;				
		}
		return true;*/
	}
	int getlines(int num)
	{
		return lines[num];
	}
///////////////////////////////////////////////////////////////////
private:
	int numCoins;
	int totalRows;
	
	char boardArr[4][7];		// holds the charecters 

	int version;
	int line1;
	int lines[4];			// holds how many cards have been removed
	int linesLim[4];			// holds the limit of each row;

	int lineNum, amountNum;
	bool end;
};