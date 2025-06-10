#pragma once

#include "card.h"
#include <vector>


class Stack {
	int size;
	short watch;
	vector<card> ary;
public:
	Stack() {
		size = 0;
		vector<card> ary(size);
		watch = size - 1;
	}
	Stack(vector<card> a,int s,int e) {
		ary=vector<card>(a.begin()+s,a.begin()+e);
		size = ary.size();
		watch = size - 1;
	}
	void push_cards(const vector<card>& a) {
		ary.insert(ary.end(),a.begin(),a.end());
		size +=  int(a.size());
		watch += int(a.size());
	}
	void push_card(card a) {
		ary.push_back(a);
		++size;
		++watch;
	}
	card pop_card() {
		card temp = ary.back();
		ary.pop_back();
		--size, ++watch;
		return temp;
	}

	void print() {
		for (int i = watch; i < ary.size(); i++)
			cout << ary[i];	
	}

	int get_watch() {
		return watch;
	}

	vector<card> pop_cards(int a) {
		vector<card> temp(ary.end() - a, ary.end());
		ary.erase(ary.end() - a, ary.end());
		ary.shrink_to_fit();
		size -= a;
		watch -= a;
		return temp;
	}

};