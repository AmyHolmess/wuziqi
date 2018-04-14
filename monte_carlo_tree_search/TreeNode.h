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
	TreeNode(State& state, TreeNode* parent = NULL)//���캯������ʼ������
		:_state(state), _action(),_parent(parent),_value(0),_visits(0), _player_id(state.get_player_id()){}
	~TreeNode(){}//��������

	const State& get_state() const { return _state; }//���ص�ǰ����״̬
	const Action& get_action() const;//���صõ���ǰ���Ķ���
	TreeNode* get_parent() { return _parent; }//���ص�ǰ���ĸ����
	TreeNode* get_child(int i) { return _children[i]; }//���ص�ǰ���ĵ�i���ӽ��
	int children_num()const { return _children.size(); }//���ص�ǰ����ӽ�����
	double get_value()const { return _value; }//���ص�ǰ���Ȩֵ
	int get_visited_num()const { return _visits; }//���ص�ǰ��㱻���ʴ���
	int get_player()const { return _player_id; }//���ص�ǰ���̳��ֵ����

	TreeNode* add_child_with_action(Action& new_action);//���첿�֣�����һ���ӽ��
	TreeNode* get_most_visited_child();//���ر����ʴ��������ӽ��

	TreeNode* select(double uct_k = sqrt(2));//���ؿ���������ѡ�񲿷�
	TreeNode* expand();//���ؿ������������첿��
	void update(double reward);//���ϸ���Ȩֵ

	bool is_terminal()const;//�жϵ�ǰ�����Ϸ�Ƿ����
	bool is_fully_expanded()const;//�жϵ�ǰ��������ӽ���Ƿ�expand��simulate
	
private:
	//state of this node
	State _state;//�ý��״̬
	//action that led to current state
	Action _action;//�õ���ǰ���Ķ���
	//all possible actions in current state
	vector<Action>_actions;//��ǰ״̬���п��ܵĶ���
	//parent of this node
	TreeNode* _parent;//��ǰ���ĸ����
	//all current children
	vector<TreeNode*> _children;//��ǰ��������ӽ��
	//value of this node
	double _value;//��ǰ���Ȩֵ
	//num of being visited
	int _visits;//��ǰ��㱻���ʴ���
	//current player, 1 for player1, 2 for player2
	int _player_id;//��ǰ���
};

