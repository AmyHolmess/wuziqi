#ifndef SCORE_H
#define SCORE_H
#include "Action.h"

#define SIZE 15
struct Position {
	int x; int y;
	Position(int sx = 0, int sy = 0) { x = sx; y = sy; }
	Position(const Action& a) { x = a.get_x() - 1; y = a.get_y() - 1; }
	void set(int sx, int sy) { x = sx; y = sy; }
	Position& operator=(const Position& p) { x = p.x; y = p.y; return *this; }
};
class Score
{
public:
	Score();
	~Score() {};
	
	//��õ�ǰ���ӵľ�������
	int get_score(const int* board,const Action& a, int player);
	//�������λp�ڷ���dir�ϵ��������
	Position continuous(const int* board,Position p, Position dir);
private:
	//��ʾ8�������ƫ��ֵ����
	Position dir[8];
	//��ǰ���
	int player_id;
	//���̵�ǰ����λ��
	Position current_action;
	//���ڹ�������µ���������
	/*int gradeOffensive[5][9] =
	{ { 2,2,2,1,2,1,3,4,4 },
	{ 3,3,2,1,3,4,4,4,4 },
	{ 3,4,2,2,4,4,4,4,4 },
	{ 5,4,4,2,5,4,5,4,5 },
	{ 6,6,6,6,6,6,6,6,6 }
	};*/
	double gradeOffensive[5][9] =
	{ {20,20,20,10,20,10,36,50,50},
	{36,36,20,10,36,50,50,50,50},
	{36,50,20,20,50,50,50,50,50},
	{80,50,50,20,80,50,80,50,80},
	{100,100,100,100,100,100,100,100,100} };
	//���ڷ�������µ���������
	/*int gradeDefensive[5][9] =
	{ { 1,1,1,1,1,1,2,3,3 },
	{ 2,2,1,1,2,3,3,3,3 },
	{ 2,3,1,1,3,3,3,3,3 },
	{ 4,3,3,1,4,3,4,4,4 },
	{ 6,6,6,6,6,6,6,6,6 } };*/
	double gradeDefensive[5][9] =
	{ {10,10,10,10,10,10,7,4,4},
	{7,7,10,1,7,4,4,4,4},
	{7,4,10,10,4,4,4,4,4},
	{2,4,4,10,2,4,2,2,2},
	{0,0,0,0,0,0,0,0,0} };
};

#endif
