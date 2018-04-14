#pragma once
#define SIZE 15

class Action
{
	
public:
	Action() {};
	Action(int ind, int player);
	Action(const Action&);
	~Action() {};
	int get_x()const { return _ind / SIZE+1 ; }
	int get_y()const { return _ind % SIZE+1 ; }
	int get_ind()const { return _ind; }
	int get_player()const { return _player; }
	void Set1(int _x, int _y);
	void Set2(int ind, int player);
	Action& operator=(const Action& a);
private:
	int _ind;
	int _player;
};

