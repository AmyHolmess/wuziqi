#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include "Action.h"
#include "State.h"

#define EPSILON 0.000001

class TreeNode
{
public:
	TreeNode(State& state, TreeNode* parent = NULL)//构造函数，初始化变量
		:_state(state), _action(),_parent(parent),_value(0),_visits(0), _player_id(state.get_player_id()){}
	~TreeNode(){}//析构函数

	const State& get_state() const { return _state; }//返回当前棋盘状态
	const Action& get_action() const;//返回得到当前结点的动作
	TreeNode* get_parent() { return _parent; }//返回当前结点的父结点
	TreeNode* get_child(int i) { return _children[i]; }//返回当前结点的第i个子结点
	int children_num()const { return _children.size(); }//返回当前结点子结点个数
	double get_value()const { return _value; }//返回当前结点权值
	int get_visited_num()const { return _visits; }//返回当前结点被访问次数
	int get_player()const { return _player_id; }//返回当前棋盘出手的玩家

	TreeNode* add_child_with_action(Action& new_action);//延伸部分，增加一个子结点
	TreeNode* get_most_visited_child();//返回被访问次数最多的子结点

	TreeNode* select(double uct_k = sqrt(2));//蒙特卡洛树搜索选择部分
	TreeNode* expand();//蒙特卡洛树搜索延伸部分
	void update(double reward);//向上更新权值

	bool is_terminal()const;//判断当前结点游戏是否结束
	bool is_fully_expanded()const;//判断当前结点所有子结点是否都expand并simulate
	
private:
	//state of this node
	State _state;//该结点状态
	//action that led to current state
	Action _action;//得到当前结点的动作
	//all possible actions in current state
	vector<Action>_actions;//当前状态所有可能的动作
	//parent of this node
	TreeNode* _parent;//当前结点的父结点
	//all current children
	vector<TreeNode*> _children;//当前结点所有子结点
	//value of this node
	double _value;//当前结点权值
	//num of being visited
	int _visits;//当前结点被访问次数
	//current player, 1 for player1, 2 for player2
	int _player_id;//当前玩家
};

