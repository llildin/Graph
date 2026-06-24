#include <iostream>
#include <vector>

using namespace std;

/*
const int VertexCount = 6;
int AdjacencyMatrix[VertexCount][VertexCount] =
{
	{0,1,0,1,0,0},
	{1,0,1,1,0,0},
	{0,1,0,0,0,0},
	{1,1,0,0,0,0},
	{0,0,0,0,0,1},
	{0,0,0,0,1,0}
};

bool Visited[VertexCount] = {};

void DFS(int Current)
{
	cout << "¹æ¹® : " << Current << endl;
	Visited[Current] = true;

	for (int Next = 0; Next < VertexCount; Next++)
	{
		if (AdjacencyMatrix[Current][Next] == 0)
		{
			continue;
		}
		if (Visited[Next] == true)
		{
			continue;
		}
		DFS(Next);
	}
}

void SearchAll()
{
	for (int Current = 0; Current < VertexCount; Current++)
	{
		if (Visited[Current] == true)
		{
			continue;
		}
		DFS(Current);
	}
}
*/

const int VertexCount = 50;
int AdjacencyMatrix[VertexCount][VertexCount] = { 0, };

const int DirectionY[4] = { -1, 1,  0, 0 };
const int DirectionX[4] = { 0, 0, -1, 1 };

bool Visited[VertexCount][VertexCount] = {};

int K = 0;
int N, M;

int Result = 0;

void DFS(int x, int y)
{
	Visited[x][y] = true;

	for (int dir = 0; dir < 4; ++dir)
	{
		int NextY = y + DirectionY[dir];
		int NextX = x + DirectionX[dir];

		if (NextY < 0 || NextY >= M ||
			NextX < 0 || NextX >= N)
		{
			continue;
		}

		if (AdjacencyMatrix[NextX][NextY] == 0)
			continue;
		if (Visited[NextX][NextY] == true)
			continue;

		DFS(NextX, NextY);
	}
}

void SearchAll()
{
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (Visited[x][y] == true)
			{
				continue;
			}
			if (AdjacencyMatrix[x][y] == 0)
			{
				continue;
			}
			DFS(x, y);
			Result++;
		}
	}
}

int main()
{	
	int X = 0;
	int Y = 0;
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> X >> Y;
		AdjacencyMatrix[X][Y] = 1;
	}
	
	SearchAll();

	cout << Result << endl;
}
