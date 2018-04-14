#include"Score.h"
Score::Score() {
	//偏移量数组初始化
	dir[0].set(-1, -1);//左上
	dir[1].set(0, -1);//上
	dir[2].set(1, -1);//右上
	dir[3].set(1, 0);//右
	dir[4].set(1, 1);//右下
	dir[5].set(0, 1);//下
	dir[6].set(-1, 1);//左下
	dir[7].set(-1, 0);//左

}
/*Score::Score(State& state)
{
	//偏移量数组初始化
	dir[0].Set1(-1, -1);//左上
	dir[1].Set1(0, -1);//上
	dir[2].Set1(1, -1);//右上
	dir[3].Set1(1, 0);//右
	dir[4].Set1(1, 1);//右下
	dir[5].Set1(0, 1);//下
	dir[6].Set1(-1, 1);//左下
	dir[7].Set1(-1, 0);//左

	/*for (int x = 0; x < SIZE; ++x)
		for (int y = 0; y < SIZE; ++y)
			board[x][y] = state.board[x*SIZE + y];*/

	/*current_action = state.current_action;
	player_id = state.get_player_id();
}*/
/*int Score::get_score(const int* board,const Action& currentAction,int player) {
	int sum = 0;
	int x = 0, y1 = 0, y2 = 0, y = 0;
	int n = -1;

	Action p = current_action = currentAction;
	player_id = current_action.get_player();
	/*for (int x = 0; x < SIZE; ++x)
		for (int y = 0; y < SIZE; ++y)
			board[x][y] = s_board[x*SIZE + y];*/

	/*for (int i = 0; i < 4; ++i)
	{
		x = continuous(p, dir[i]).get_x() + continuous(p, dir[i + 4]).get_x() + 1;
		y1 = continuous(p, dir[i]).get_y();
		y2 = continuous(p, dir[i + 4]).get_y();

		switch (y1 + y2) {
		case 0:
			if (!y1*y2)y = 0;
			else y = 1;
			break;
		case -1:y = 2; break;
		case -2:y = 3; break;
		case 1:
			if (!y1*y2)y = 4;
			else y = 5;
			break;
		case 2:
			if (!y1*y2)y = 6;
			else y = 7;
			break;
		default:y = 8;
			break;
		}

		if (board[p.get_x()][p.get_y()] == player_id)
			if (player != player_id)
				sum += gradeOffensive[x - 1][y];
			else
				sum += gradeDefensive[x - 1][y];
		else
			if (player != player_id)
				sum -= gradeDefensive[x - 1][y];
			else
				sum -= gradeOffensive[x - 1][y];
	}
	return sum;
}
*/
int Score::get_score(const int* board, const Action& currentAction, int player) {
	int sum = 0;
	int x = 0, y1 = 0, y2 = 0, y = 0;
	int n = -1;

	Position p(currentAction);
	player_id = currentAction.get_player();
	/*for (int x = 0; x < SIZE; ++x)
	for (int y = 0; y < SIZE; ++y)
	board[x][y] = s_board[x*SIZE + y];*/

	for (int i = 0; i < 4; ++i)
	{
		x = continuous(board,p, dir[i]).x + continuous(board,p, dir[i + 4]).x + 1;
		y1 = continuous(board, p, dir[i]).y;
		y2 = continuous(board, p, dir[i + 4]).y;

		switch (y1 + y2) {
		case 0:
			if (!y1*y2)y = 0;
			else y = 1;
			break;
		case -1:y = 2; break;
		case -2:y = 3; break;
		case 1:
			if (!y1*y2)y = 4;
			else y = 5;
			break;
		case 2:
			if (!y1*y2)y = 6;
			else y = 7;
			break;
		default:y = 8;
			break;
		}

		if (board[p.x*SIZE+p.y] == player_id)
			if (player != player_id)
				sum += gradeOffensive[x - 1][y];
			else
				sum += gradeDefensive[x - 1][y];
		else
			if (player != player_id)
				sum += gradeDefensive[x - 1][y];
			else
				sum += gradeOffensive[x - 1][y];
	}
	return sum;
}

/*Action Score::continuous(Action p, Action dir) {
	Action counter(0, 0);
	int x = 0, y = 0;
	for (int i = 1; i < 5; i++) {
		if (board[p.get_x() + dir.get_x()*i][p.get_y() + dir.get_y()*i] == board[p.get_x()][p.get_y()])
			++x;
		else
			if (board[p.get_x() + dir.get_x()*i][p.get_y() + dir.get_y()*i] == 0) {
				for (int j = i + 1; j < 5; j++)
					if (board[p.get_x() + dir.get_x()*j][p.get_y() + dir.get_y()*j] == board[p.get_x()][p.get_y()])
						++y;
					else {
						counter.Set1(x, y);
						return counter;
					}
			}
			else y = -1;
	}
	counter.Set1(x, y);
	return counter;
}*/


Position Score::continuous(const int* board,Position p, Position direction) {
	//判断p位置dir方向的连子情况
	//counter的x表示直接连续的连子情况，y表示间隔一个后的连子情况，最大范围为5，若被堵，则为-1
	Position counter(0, 0);
	for (int i = 1; i < 5; i++) {
		if (board[(p.x + direction.x*i)*SIZE + (p.y + direction.y*i)] == board[(p.x)*SIZE + p.y])
			++counter.x;
		else
			if (board[(p.x + direction.x*i)*SIZE+(p.y + direction.y*i)] == 0) {
				for (int j = i + 1; j < 5; j++)
					if (board[(p.x + direction.x*j)*SIZE + p.y + direction.y*j] == board[(p.x)*SIZE + p.y])
						++counter.y;
					else
						return counter;
			}
			else counter.y = -1;
	}
	return counter;
}