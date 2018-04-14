#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "mcts.h"
#include "jsoncpp\json.h"
using namespace std;

/*
void placeAt(int x, int y)
{
if (x >= 0 && y >= 0) {
Grid[x][y] = true;
}
}*/

/*
int main()
{
// ����JSON
string str;
getline(cin, str);
Json::Reader reader;
Json::Value input;
reader.parse(str, input);

// �����Լ��յ���������Լ���������������ָ�״̬
string data = input["data"].asString(); // �öԾ��У���ǰ��Bot����ʱ�洢����Ϣ
int turnID = input["responses"].size();
for (int i = 0; i < turnID; i++)
{
istringstream in(input["requests"][i].asString()),
out(input["responses"][i].asString());

// ������Щ��������𽥻ָ�״̬����ǰ�غ�
}

// �����Լ����غ�����
istringstream in(input["requests"][turnID].asString());

// �������ߴ�ΪmyAction

// �������JSON
Json::Value ret;
//ret["response"] = myAction;
//ret["data"] = myData; // ���Դ洢һЩǰ������Ϣ���������Ծ���ʹ��
Json::FastWriter writer;
cout << writer.write(ret) << endl;
return 0;
}
*/

//#define FLAG

int main()
{
	State state;
	state.print_state();
	while (!state.is_over())
	{
		int player = state.get_player_id();
		if (player == 1)//computer 1
		{
			MCTS mcts;
			Action action;
			action = mcts.run(state);
			state.apply_action(action);
			std::cout << "Computer1(o) chose action " << action.get_x() << " " << action.get_y() << endl;
			//cout << "Computer1 chose action " << action.get_ind() << endl;
		}
#ifndef FLAG
		if (player == 2)//computer 2
		{
			MCTS mcts;
			Action action;
			action = mcts.run(state);
			state.apply_action(action);
			std::cout << "Computer2(x) chose action " << action.get_x() << " " << action.get_y() << endl;
			//cout << "Computer2 chose action " << action.get_ind() << endl;
		}
#endif 

#ifdef FLAG
		else//human player
		{
			std::cout << "please input your action(x):";
			int a, b;
			cin >> a >> b;
			int m = (a - 1)*SIZE + b - 1;
			Action action(m, 2);
			state.apply_action(action);
		}
#endif 
		
		state.print_state();
	}
	int winner = state.has_a_winner();
	if (winner == 1)
		cout << "player 1 wins!\n";
	else if (winner == 2)
		cout << "player 2 wins!\n";
	else
		cout << "draw! nobody wins!\n";
}