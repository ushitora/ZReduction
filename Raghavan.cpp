/*
A string of the form  x y y^R y z  Z-reduces to  x y z, where  y^R  denotes the revers of  y .

Input : a string w 
Output : the Z-irreducible form of w

Implementation of Raghavan's algorithm (1994) by Shintaro Barisada (2018)
*/
#include<iostream>
#include<string>
#include<list>
#include<stdio.h>
#include<time.h>

using namespace std;

struct pal {
	list<int>::iterator l;
	list<int>::iterator c;
	list<int>::iterator r;
	pal(list<int>::iterator it) {
		l = ++it;
		c = --it;
		r = it;
	}
};

int n;
string T;
list<int> X;
list<pal> Alive;

void preprocess() {
	list<int>::iterator itr;
	for (int i = 0; i < n;i++) {
		itr = X.end();
		itr = X.insert(itr, i);
	}
	auto it = X.begin();
	it++;
	while (T[*it] != '#') {
		Alive.emplace_back(it);
		it++;
	}
	return;
}

void update_A(int i) {
	list<int>::iterator X_l, X_r;
	list<pal>::iterator  A = Alive.begin();
	while (A != Alive.end()) {
		X_l = (*A).l;
		X_l--;
		X_r = (*A).r;
		X_r++;
		if (T[*X_l] == T[*X_r] && *(*A).l != 0 && *(*A).r != n - 1) {
			(*A).l = X_l;
			(*A).r = X_r;
			A++;
		}
		else {
			A = Alive.erase(A);
		}
	}
	return;
}

void deletion(int i) {
	list<pal>::iterator A = Alive.begin();
	list<pal>::iterator A_n = A;
	if (A != Alive.end()) A_n++;
	list<pal>::iterator A_b;
	list<int>::iterator X_b, X_e;
	list<int>::iterator X_l;

	while (A != Alive.end() && A_n != Alive.end()) {
		int d = 0;
		X_l = (*A_n).l;
		if (X_l != X.begin()) X_l--;
		while (*(*A).r >= *(*A_n).c && *(*A).c >= *X_l) {
			if (d == 0) {
				A_b = A;
				X_b = (*A).c;
				X_b++;
			}
			A++;
			A_n++;
			d++;
			if (A_n == Alive.end()) {
				break;
			}
			else {
				X_l = ((*A_n).l);
				if (X_l != X.begin()) X_l--;
			}
		}

		if (d == 0) {
			A++;
			A_n++;
		}
		else {
			if (d % 2 == 1) {
				X_e = (*A).r;
			}
			else {
				list<int>::iterator X_r = (*A).c;
				for (int j = 0;j<i;j++) X_r++;
				(*A_b).r = X_r;
				A_b++;
				X_e = (*A).r;
				for (int j = 0;j<i;j++) X_e--;
			}
			while (A_b != A_n) {
				A_b = Alive.erase(A_b);
			}
			if (A_n != Alive.end()) {
				list<int>::iterator X_l2 = (*A_n).l;
				if (*X_l2 <= *X_e) {
					int l = 0;
					while (*X_l2 != *X_e) { l++; X_l2++; }
					list<int>::iterator X_u = X_b;
					for (int j = 0;j <= l;j++) X_u--;
					(*A_n).l = X_u;
				}
			}
			A = A_b;
			X_e++;
			while (X_b != X.end() && *X_b < *X_e) {
				X_b = X.erase(X_b);
			}
			A_n = A;
			if (A != Alive.end()) A_n++;
			if (A == Alive.end()) {
				break;
			}
			else if (A_n == Alive.end()) {
				break;
			}
		}
	}
	return;
}

void raghavan() {
	preprocess();
	int i = 1;
	while (Alive.size()>0) {
		update_A(i);
		deletion(i);
		i++;
	}
	return;
}

int main(int argc, char* argv[]) {
	if (argc <= 1) return 0;
	T = argv[1];
	T = "$" + T + "#";
	n = T.size();
	raghavan();
	X.pop_front();
	X.pop_back();
	for (auto it=X.begin(); it!=X.end(); it++){printf("%c",T[*it]);} cout << endl;
	return 0;
}
