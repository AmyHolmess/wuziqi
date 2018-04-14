#pragma once
#include "TreeNode.h"


class MCTS
{
public:
	MCTS();
	Action run(State& state);
private:
	double uct_k;
	int max_iter;
	int sim_depth;
};