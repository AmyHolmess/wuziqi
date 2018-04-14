#include"Situation.h"

Situation::Situation()
{

}
Situation::~Situation()
{

}
vector<Piece>* Situation::get_situation(const int* board) {
	Piece hold;
	vector<Piece>* s = new vector<Piece>;
	for(int k=0;k<SIZE*SIZE;++k)
		if (board[k] != 0)
		{
			hold.Set(k / SIZE, k%SIZE, board[k]);
			s->push_back(hold);
		}
	return s;
}
int Situation::judge(const int* board)
{
	currentSituation = get_situation(board);
	vector<Piece>* hold;
	int si = currentSituation->size();
	for (int i = 0; i < totalSituation[si]->size(); ++i)
	{
		hold = (*totalSituation[si]).at(i);
		for (int j = 0; j < hold->size(); ++j)
			if (currentSituation->at(j) != hold->at(i))
				break;
	}
}
vector<Piece>& Situation::rotate(vector<Piece>& sit);
bool Situation::add_situation(vector<Piece>* s)
{
	int size = s->size();
	totalSituation[size]->push_back(s);
	return true;
}