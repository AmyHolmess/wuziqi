#pragma once
#ifndef SITUATION_H
#define SITUATION_H
#include"Action.h"
#include<vector>
using namespace std;

#define SIZE 15
class Piece
{
	friend bool operator==(const Piece&p1, const Piece&p2)
	{
		if (p1.x == p2.x&&p1.y == p2.y&&p1.c == p2.c)return true;
		else return false;
	}
	friend bool operator!=(const Piece&p1, const Piece&p2)
	{
		if (p1.x == p2.x&&p1.y == p2.y&&p1.c == p2.c)return false;
		else return true;
	}
public:
	int x; int y; int c;
	Piece(int sx = 0, int sy = 0, int sc = 0) { x = sx; y = sy; c = sc; }
	Piece(const Action& a) { x = a.get_x() - 1; y = a.get_y() - 1; c = 0; }
	void Set(int sx, int sy, int sc) { x = sx; y = sy; c = sc; }
	Piece& operator=(const Piece& p) { x = p.x; y = p.y; c = p.c; return *this; }
};

class Situation
{
public:
	Situation();
	~Situation();
	
	vector<Piece>* get_situation(const int* board);
	int judge(const int* board);

	bool add_situation(vector<Piece>* s);

	bool Sorty(const Piece& p1, const Piece& p2) { return p1.x < p2.x; }
	vector<Piece>& rotate(vector<Piece>& sit);
private:
	vector<vector<Piece>*>* totalSituation[100];
	vector<Piece>* currentSituation;
};
#endif // !SITUATION_H
