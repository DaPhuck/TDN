#include <bits/stdc++.h>
using namespace std;

int m;
ifstream inp("CHONCAM.INP");
ofstream out("CHONCAM.OUT");

int main() {
	inp >> m;
	vector<pair<int, int>> ns(5, {0, 0});

	while (m--) {
		int a, b;
		inp >> a >> b;
		ns[a - 1].first++;
		if (b != a) ns[b - 1].first++;

		for (int i = 1; i < 6; i++) {
			ns[i - 1].second = max(ns[i - 1].second, ns[i - 1].first);
			if (a != i && b != i) ns[i - 1].first = 0;
		}
	}

	for (int i = 1; i < 6; i++) ns[i - 1].first = i;

	sort(ns.begin(), ns.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	});

	out << ns[0].second << " " << ns[0].first << endl;
}
