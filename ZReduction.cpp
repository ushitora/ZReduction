/*
A string of the form  x y y^R y z  Z-reduces to  x y z, where  y^R  denotes the revers of  y .

Input : a string w 
Output : the Z-irreducible form of w

(C) 2019, Shintaro Narisada, Hendrian Diptarama, Ryo Yoshinaka, Ayumi Shinohara
*/
#include<chrono>
#include<iostream>
#include<string>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

string T = "";
int t = 1;
vector<char> w;
vector<int> Pals;
stack<int> st;

void deletion(int j, int i) {
	for(int k = 0; k < i - j + 1; k++) {
		w.pop_back();
		Pals.pop_back();
	}
	return;
}

bool slowExtend(int c) {
	int r = w.size() - 2 - c;
	while(w[c + r + 1] == w[c - r]) {
		r++;
		if (Pals[c - r] >= r) {
			deletion(c - r + 1, c + r);
			return true;
		}
		Pals[c + r] = Pals[c - r];
		t++; w.push_back(T[t]); Pals.push_back(-1);
	}
	Pals[c] = r;
	return false;
}

bool fastExtend(int c) {
	while(!st.empty()) {
		int r = st.top() - c;
		if (Pals[c - r] >= Pals[c + r]) { st.pop(); }
		else {
			Pals[c] = r + Pals[c - r];
			return false;
		}
	}
	return true;
}

bool stabilize(int c) {
	int b = w.size() - 1;
	bool unstable = true;
	while (unstable) {
		unstable = false;
		if (slowExtend(c)) return true;
		for (int d = c + Pals[c]; d >= b; d--){
			if (d + Pals[d] >= c + Pals[c]) {
				if (fastExtend(d))	{
					if(stabilize(d)){
						if (c == w.size() - 1)  return true;
						if (d == w.size() - 1)  Pals[d] = Pals[2 * c - d];
						t++; w.push_back(T[t]); Pals.push_back(-1);
						unstable = true;
						break;
					}
				}
			}
			st.push(d);
		}
	}
	return false;
}

int main(int argc, char* argv[]) {
	if (argc <= 1) return 0;
	T = argv[1];
	T = "$" + T + "#";
	t = 0;
	w.push_back(T[t]);  Pals.push_back(0);
	while(t<T.size()) {
		t++; w.push_back(T[t]); Pals.push_back(-1);
		stabilize(w.size() - 2);
		while(!st.empty()) st.pop();
	}
	for (int i = 1; i<w.size()-2; i++) { printf("%c", w[i]); } cout << endl;
	return 0;
}
