#pragma once
#ifndef SITUATION_H
#define SITUATION_H
#include"Action.h"
#include<vector>
#include <algorithm> 
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
	int x; int y; int c;//x，y为棋子在棋盘上的横纵坐标，c为棋子颜色
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
	
	//获得当前棋盘对应的局面
	vector<Piece>* get_situation(const int* board);
	//判断当前局面是否在totalSituation中有匹配
	int judge(const int* board);
	
	//将局面s添加到总局面中
	bool add_situation(vector<Piece>* s);

	bool SortPiece(const Piece& p1, const Piece& p2);//sort函数排序判断
	//将局面sit旋转90度
	vector<Piece>& rotate(vector<Piece>& sit);
private:
	//局面为棋盘上所有落子位置的记录向量，按i的升序排列，局面的size是棋盘上的落子数
	vector<vector<Piece>*>* totalSituation[100];//所有的局面，totalSituation[i]为指向棋子数为i的局面的总和的向量指针
	vector<Piece>* currentSituation;//当前局面
};
#endif // !SITUATION_H
