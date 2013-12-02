//Nathan Mueller, 10/29/13, Harden
//This program draws a rocketship out of asterisks. The different parts of the ship
//are drawn with different functions, giving the user control over the height and width
//of each stage and the number of stages in the rocket.

#include <iostream>
using namespace std;

void getDimensions(int &width, int &height, int &stages);	
void drawRocket(int rocketWidth, int rocketHeight, int rocketStages);

void drawCone(int coneWidth);
void drawConeLine(int spaces, int coneWidth);
void drawSpaces(int sideSpaces);
void drawTop(int coneWidth);

void drawBox(int numX, int numY);
void drawHorizontalLine(int numX);
void drawVerticalLine(int numX, int numY);
void drawBoxSpaces(int numX);

int main()
{
	int width;
	int height;
	int stages;

	getDimensions(width, height, stages);
	drawRocket(width, height, stages);

}


void getDimensions(int &width, int &height, int &stages) //User enters numbers to define the rocket
{
	cout << "How high should each stage be? ";
	cin >> height;
	cout << "How wide should each stage be? ";
	cin >> width;
	cout << "How many stages would you like? ";
	cin >> stages;
}


void drawRocket(int rocketWidth, int rocketHeight, int rocketStages)  //Draws the parts of the rocket
{
	int drawCount = 1;
	drawCone(rocketWidth);    

    while (drawCount <= rocketStages)	//The number of stages drawn depends on the user's entry
	{
		drawBox(rocketWidth, rocketHeight);
		drawCount++;
	}

    drawCone(rocketWidth);
}


void drawCone(int coneWidth)	//Defines how to create the cone
{
	drawTop(coneWidth);		//Draws the top of the cone

	int lineCount = 0;
	while (lineCount <= coneWidth - 3)		//Defines how to draw each successive part of the cone
	{
		drawConeLine(lineCount, coneWidth);
		lineCount+=2;
	}

}


void drawTop(int coneWidth)		//Draws a single dot spaced equally on top of the cone
{
	int sideSpaces = ((coneWidth - 1 ) / 2) - 1;
	drawSpaces(sideSpaces);
	cout << "*" << endl;
}



void drawConeLine(int spaces, int coneWidth)	//Defines how to draw each line of the cone
{
	int sideSpaces = ((coneWidth - 3 - spaces) / 2) - 1;
	drawSpaces(sideSpaces);
	cout << "*";
	drawSpaces(spaces);
	cout << "*" << endl;
}


void drawSpaces(int sideSpaces)		//This function just draws a specified number of spaces
{
	int count = 0;
	while (count <= sideSpaces)
	{
		cout << " ";
		count++;
	}
}


void drawBox(int numX, int numY)	//Defines how to draw a stage of the rocket
{	
	drawHorizontalLine(numX);
	drawVerticalLine(numX, numY);
	drawHorizontalLine(numX);
}


void drawHorizontalLine(int numX)	//Draws a horizontal line of specified length
{
	int widthCount = 1;
	while (widthCount <= numX)
	{
		cout << "*";
		widthCount++;
	}
	cout << endl;
}


void drawVerticalLine(int numX, int numY)	//Draws the two vertical lines that form the sides of the stages
{
	int heightCount = 3;

	while (heightCount <= numY)
	{
		cout << "*";

		drawBoxSpaces(numX);

		cout << "*" << endl;
		heightCount++;
	}
}


void drawBoxSpaces(int numX)	//Another space drawing function modifed for use with drawing the boxes 
{
	int widthCount = 1;
	while (widthCount + 2 <= numX)
	{
		cout << " ";
		widthCount++;
	}
}
