#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int VertexCount = 6;
int AdjacencyMatrix[VertexCount][VertexCount] =
{
	{0,1,0,1,0,0},
	{1,0,1,1,0,0},
	{0,1,0,0,0,0},
	{1,1,0,0,1,0},
	{0,0,0,1,0,1},
	{0,0,0,0,1,0}
};

bool Visited[VertexCount] = {};
int Distance[VertexCount] = {};
int Parent[VertexCount] = {};

void PrintPath(int Start, int Current)
{
	if (Distance[Start] != Distance[Current])
	{
		PrintPath(Start, Parent[Current]);
	}

	cout << Current << " ";
}

void PrintShortestPath(int Start, int Dest)
{
	if (Visited[Dest] == false)
	{
		cout << "Error" << endl;
	}

	cout << "경로 : ";
	PrintPath(Start, Dest);
}

void BFS(int Start)
{
	queue<int> VertexQueue;
	VertexQueue.push(Start);

	Visited[Start] = true;
	Parent[Start] = Start;
	Distance[Start] = 0;

	while (!VertexQueue.empty())
	{
		int Current = VertexQueue.front();

		cout << "방문 : " << Current << endl;

		VertexQueue.pop();

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

			VertexQueue.push(Next);
			Visited[Next] = true;
			Parent[Next] = Current;
			Distance[Next] = Distance[Current] + 1;
		}
	}
}

void main()
{
	BFS(0);

	PrintShortestPath(0, 5);
}