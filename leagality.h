#pragma once
#include "Header.h"
#include <vector>
#include "card.h"
void printh(const vector<card>&, vector<Stack>);
bool Sel_basic(us pn, us cn, vector<Stack> ary) {
	if (pn <= 0 || pn >= 8 || ary[pn].get_size() == 0 || ary[pn].empty())
	{
		cout << "Illegal pile no please enter both number agian: ";
		return false;
	}
	else if (cn <= 0 || cn > ary[pn].get_size() - ary[pn].get_watch())
	{
		cout << "Illeagal card no please select pile and card agian: ";
		return false;
	}
	return true;
}
bool Destination_basic(us _pn, us _cn, us pn, vector<Stack> ary) {

	if (pn < 0 || pn > 8 || (ary[pn].get_size() == 0 && ary[pn].get_nmbr(_cn) != 13))
	{
		cout << "Illegal pile no please select pile and card agian: ";
		return false;
	}
	--_pn, --pn;
	us cn = ary[pn].get_size() - 1;
	_cn += ary[_pn].get_watch() - 1;
	if (ary[_pn].get_clr(_cn) == ary[pn].get_clr(cn) ||
		ary[pn].get_nmbr(cn) - ary[_pn].get_nmbr(_cn) != 1
		)
	{
		cout << "Illegal card paste please select pile and card agian\n";
		return false;
	}
	return true;
}
void trasnferCard(vector<Stack>& piles, us _pn, us pn, us _cn) {
	int a = piles[_pn].get_size() - piles[_pn].get_watch() - _cn + 1;
	pn--; _pn--;
	piles[pn].push_cards(piles[_pn].pop(a));
}
bool sel(us& _pn, us& _cn, vector<Stack> piles) {
	cout << "Please enter 'pile no' and 'card no' to select card or enter 0 to go back : ";
	do {
		cin >> _pn;
		if (_pn == 0) return false;
		cin >> _cn;
	} while (!Sel_basic(_pn, _cn, piles));
	return true;
}
us ask(vector<Stack>& collection, us _pn, us _cn, vector<Stack>& ary) {
	char y{};
	cout << "Do you want to add this card to winner slot or not [y/n]: "; cin >> y;
	if (y == 'y')
	{
		--_pn;
		_cn += ary[_pn].get_watch() - 1;
		int a = ary[_pn].get_size() - _cn;

		for (int i = 0; i < 4; i++)
		{
			short cn = collection[i].get_size() - 1;
			if (collection[i].empty() && ary[_pn].get_nmbr(_cn) == 1)
			{
				collection[i].push(ary[_pn].pop(a).front());
				return 2;
			}
			else if (!collection[i].empty() &&
				ary[_pn].get_clr(_cn) == collection[i].get_clr(cn) &&
				collection[i].get_nmbr(cn) - ary[_pn].get_nmbr(_cn) == -1)
			{
				collection[i].push_cards(ary[_pn].pop(a));
				return 2;
			}
		}
		cout << "There is no matching slot";
		return 0;
	}
	return 1;
}
int mode() {
	char ch;
	cout << "please Select mode to play:\nEasy = e\nMedium = m\nHard = h\v "; cin >> ch; switch (ch) {
	case 'h':
	case 'H': system("cls"); return 3; break;
	case 'M':
	case 'm': system("cls"); return 2; break;
	case 'E':
	case 'e':
	default: system("cls"); return 1;
	}

}

bool takeHelp(vector<card>& help, vector<Stack>& ary) {
	if (help.front().getNmbr() != 0) {
		printh(help, ary);
		return true;
	}
	char ch;
	cout << "Do want to take helping card? [y/n]: "; cin >> ch;
	if (ch == 'y')
	{
		help = ary[7].pop(short(help.size()));
		printh(help, ary);
		return true;
	}
	return false;
}
bool inputHelp(vector<card>& help, vector<Stack>& ary) {
	char ch{};
	cout << "Do you want to use helping card [y/n]: "; cin >> ch;
	if (ch != 'y') return false;
	int cardNo{}, pn = -1, cn;
	do {
		cout << "please select the card: "; cin >> cardNo;
	} while (cardNo < 0 || cardNo >= help.size());
	--cardNo;
	do {
		cout << "Please select the destination pile or enter 0 to go back: "; cin >> pn;
		if (pn == 0) return false;
		pn--;
		cn = ary[pn].get_size() - 1;
	} while (pn < 0 || pn >= 8 || (ary[pn].get_size() == 0 && ary[pn].get_char(cn) != 'K') ||
		help[cardNo].getClr() == ary[pn].get_clr(cn) ||
		ary[pn].get_nmbr(cn) - help[cardNo].getNmbr() != 1
		);
	vector<card> temp = { help[cardNo] };
	ary[pn].push_cards(temp);
	help.erase(help.begin() + cardNo);
	return true;
}
void printh(const vector<card>& help, vector<Stack> ary) {
	int a, b;
	getCurrentCursorPosition(a, b);
	gotoRowCol(0, 35);
	cout << "Helping card: (remaining card= " << ary[7].get_size() << " )";
	for (int i = 0; i < help.size(); i++)
	{
		gotoRowCol(i + 1, 35);
		cout << i + 1 << ") " << help[i];
	}
	gotoRowCol(a, b);
}

