#pragma once

#include "Action.h"
#include"Score.h"
#include <vector>
#include <iostream>
using std::vector;

/*
actions in 15x15 board
0    1  ...  13 14
15  16  ...  28 29
30  31  ...  43 44
.   .       .   .
.   .       .   .

210 211 ... 223 224
*/

#define SIZE 15
#define GRID 225

/*class State
{
public:
	State();
	State(int p);
	State& operator = (const State& other);
	State(const State& other);

	//get all possible actions
	void get_actions(vector<Action>&actions);
	//more possible actions in current state(adjcent)
	void get_adjcent_actions(vector<Action>&adjcent_actions);
	//return false if no possible action found
	bool get_random_action(Action& action);
	State& apply_action(Action& new_action);

	//player who just made the action
	int get_player_id() { return player_id; }

	//player taking turn to play
	void take_turn();

	void print_state();

	bool is_over()const;
	//return 1 if player wins, 0 if player loses, 0.5 if draw
	double get_reward(int player)const;
	//return player's id if player wins, -1 if no winner
	int has_a_winner()const;
private:
	//1 for player1, 2 for player2
	int player_id;
	//all occupied actions
	vector<int>occupied;
	//available actions, 0 for unavailable, 1 for available
	int available[GRID];
	//15x15 board
	int board[GRID];
};*/

class Score;
class State
{
public:
	State();
	State(int p);
	State& operator = (const State& other);
	State(const State& other);

	//获取棋盘上所有可以落子的位置
	void get_actions(vector<Action>&actions);
	//获取棋盘上所有棋子的周围八个方向可落子位置的集合
	void get_adjcent_actions(vector<Action>&adjcent_actions);
	//从当前可落子位置的集合中随机选取一个落子位置
	bool get_random_action(Action& action);
	//落子，并转换玩家
	State& apply_action(Action& new_action);

	//获得当前状态即将执行落子的玩家
	int get_player_id() { return player_id; }
	//玩家转换
	void take_turn();

	//打印棋盘
	void print_state();

	//判断游戏是否结束（平局或某一玩家获胜）
	bool is_over()const;
	//返回当前局面分数，胜利为1，失败为0，平局为0.5
	double get_reward(int player)const;
	//返回获胜玩家id，若无玩家获胜则为-1
	int has_a_winner()const;

private:
	//1是一号玩家，2是2号玩家
	int player_id;
	//已落子的位置集合
	vector<int>occupied;
	//记录当前棋盘落子状态，0为不可落子（已落子），1为可落子（该位置为空）
	int available[GRID];
	//15*15的棋盘，int值为玩家该点落子的玩家id，0为空（未落子）
	int board[GRID];
	Action current_action;
};

