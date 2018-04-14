#include"Situation.h"

Situation::Situation()
{

}
Situation::~Situation()
{
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < totalSituation[i]->size(); ++j)
			delete[]totalSituation[i]->at(j);
		delete[] totalSituation[i];
	}
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
		for (int k = 0; k < 3; ++k) {
			for (int j = 0; j < hold->size(); ++j)
				if (currentSituation->at(j) != hold->at(i)) {
					*currentSituation = rotate(*currentSituation);
					break;
				}
			return 1;
		}
	}
	add_situation(currentSituation);
	return 0;
}
vector<Piece>& Situation::rotate(vector<Piece>& sit)
{
	vector<Piece> s(sit.size());
	Piece hold1, hold2;
	for (int i = 0; i < sit.size(); i++) {
		hold2 = sit.at(i);
		hold1.Set(hold2.y, SIZE - 1 - hold2.x, hold2.c);
		s.push_back(hold1);
	}
	sort(s.begin(), s.end(), Sortx);
	return s;
}
bool Situation::add_situation(vector<Piece>* s)
{
	int size = s->size();
	totalSituation[size]->push_back(s);
	return true;
}