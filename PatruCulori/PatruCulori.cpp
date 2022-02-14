
#include<fstream>
#include<iostream>
using namespace std;

ifstream fin("program.in");
ofstream fout("program.out");

bool isColouringViable(int numberOfRooms, int roomIndex, int colorNumber, int adjacencyMatrix[191][101], int coloredRooms[101])
{
	for (int i = 1; i <= numberOfRooms; i++)
		if (adjacencyMatrix[roomIndex][i] == 1 && coloredRooms[i] == colorNumber)
			return false;
	return true;
}

void colorTheRooms(int roomIndex, int numberOfRooms, int numberOfColors, int adjacencyMatrix[191][101], int coloredRooms[101])
{
	if (roomIndex > numberOfRooms)
	{
		for (int i = 1; i <= numberOfRooms; i++)
		{
			cout << coloredRooms[i] << ' ';
		}
		cout << endl;
	}
	else
		for (int colorNumber = 1; colorNumber <= numberOfColors; colorNumber++)
		{
			if (isColouringViable(numberOfRooms, roomIndex, colorNumber, adjacencyMatrix, coloredRooms)) {
				coloredRooms[roomIndex] = colorNumber;

				colorTheRooms(roomIndex + 1, numberOfRooms, numberOfColors, adjacencyMatrix, coloredRooms);

				coloredRooms[roomIndex] = 0;
			}
		}
}


int main()
{
	int coloredRooms[101];
	int n, k;
	fin >> n >> k;
	int adjacencyMatrix[101][101];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			fin >> adjacencyMatrix[i][j];
	for (int i = 1; i <= 100; i++)
	{
		coloredRooms[i] = 0;
	}
	colorTheRooms(1, n, k, adjacencyMatrix, coloredRooms);
}

