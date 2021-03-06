#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

bool gameOver;
const int width = 50;
const int height = 20;
int snakeX, snakeY, fruitX, fruitY, score;
int tailX[100], tailY[100];
int tailLength;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;


void GameSetup()
{
	gameOver = false;
	dir = STOP;
	snakeX = width / 2;
	snakeY = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw()
{
	system("cls");
	for (int i = 0; i < width+2; i++)
		cout << "_";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "|";

			if (i == snakeY && j == snakeX)
				cout << "O";
			else
				if (i == fruitY && j == fruitX)
					cout << "*";
				else
				{
					bool printTail = false;
					for (int k = 0; k < tailLength; k++)
					{
						if (tailX[k] == j && tailY[k] == i)
						{
							cout << "o";
							printTail = true;
						}
					}
					if (!printTail)
						cout << " ";
				}
					

			if (j == width - 1)
				cout << "|";
		}
		cout << endl;
	}

	for (int i = 0; i < width+2; i++)
		cout << "-";
	cout << endl;
	cout << "Score: " << score << endl;
}

void KeyboardInput()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Movements()
{
	int previousX = tailX[0];
	int previousY = tailY[0];
	int previous2X, previous2Y;
	tailX[0] = snakeX;
	tailY[0] = snakeY;

	for (int i = 1; i < tailLength; i++)
	{
		previous2X = tailX[i];
		previous2Y = tailY[i];
		tailX[i] = previousX;
		tailY[i] = previousY;
		previousX = previous2X;
		previousY = previous2Y;
	}

	switch (dir)
	{
	case LEFT:
		snakeX--;
		break;
	case RIGHT:
		snakeX++;
		break;
	case UP:
		snakeY--;
		break;
	case DOWN:
		snakeY++;
		break;
	default:
		break;
	}

	//if (snakeX > width || snakeX < 0 || snakeY > height || snakeY < 0)
		//gameOver = true;

	if (snakeX >= width)
		snakeX = 0;
	else
		if (snakeX < 0)
			snakeX = width - 1;

	if (snakeY >= height)
		snakeY = 0;
	else
		if (snakeY < 0)
			snakeY = height - 1;

	for (int i = 0; i < tailLength; i++)
	{
		if (tailX[i] == snakeX && tailY[i] == snakeY)
			gameOver = true;
	}

	if (gameOver)
		cout << "GAME OVER!!" << endl;

	if (snakeX == fruitX && snakeY == fruitY)
	{
		score += +10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		tailLength++;
	}
}

int main()
{
	GameSetup();
	while (!gameOver)
	{
		Draw();
		KeyboardInput();
		Movements();
		Sleep(80);
	}
    return 0;
}

