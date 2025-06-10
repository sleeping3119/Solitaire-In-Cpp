#pragma once
#include "card.h"
#include <vector>

class Stack {
	int size;
	short watch;
	vector<card> ary;
public:
	bool empty() {
		return (size == 0);
	}
	Stack() {
		size = 0;
		vector<card> ary(size);
		watch = size - 1;
	}
	Stack(vector<card> a, int s, int e) {
		ary = vector<card>(a.begin() + s, a.begin() + e);
		size = int(ary.size());
		watch = size - 1;
	}
	void push_cards(const vector<card>& a) {
		ary.insert(ary.end(), a.begin(), a.end());
		size += int(a.size());
		//watch += int(a.size());
	}
	void push(card a) {
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
		for (int i = watch; i < ary.size(); i++){
			//printf("%d) ", i + 1-watch);
			cout << ary[i];
	     }
	}
	char get_char(int a) {
		return this->ary[a].getCh();
	}

	int get_watch() {
		return watch;
	}

	vector<card> pop(short a) {
		vector<card> temp(ary.end() - a, ary.end());
		ary.erase(ary.end() - a, ary.end());
		ary.shrink_to_fit();
		size -= a;
		watch -= a;
		return temp;
	}
	int get_size() {
		return size;
	}
	int get_nmbr(int index) {
		return this->ary[index].getNmbr();
	}
	int get_clr(int index) {
		return this->ary[index].getClr();
	}
};