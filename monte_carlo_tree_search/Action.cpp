#include "Action.h"

Action::Action(int ind, int player)
{
	_ind = ind;
	_player = player;
}
Action::Action(const Action& action)
{
	_ind = action.get_ind();
	_player = action.get_player();
}
void Action::Set1(int _x, int _y)
{
	_ind = _x*SIZE + _y;
}
void Action::Set2(int ind, int player)
{
	_ind = ind;
	_player = player;
}
Action& Action::operator=(const Action& a)
{
	_ind = a.get_ind();
	_player = a.get_player();
	return *this;
}