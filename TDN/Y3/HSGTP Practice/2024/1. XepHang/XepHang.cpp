#include <bits/stdc++.h>
using namespace std;

#define prob first
#define pnl second

ifstream inp("XEPHANG.INP");
ofstream out("XEPHANG.OUT");
int n, m, rk = 1;

int main() {
	inp >> n >> m;
	vector<pair<int, int>> ns(n, {0, 0});
	multiset<pair<int, int>> b;

	while (m--) {
		int team, pnlt;
		inp >> team >> pnlt;

		team--;
		if (team != 0) {
			auto i = b.find({ ns[team].prob, -ns[team].pnl });
			if (i != b.end()) b.erase(i);
			b.insert({ ns[team].prob + 1, -ns[team].pnl - pnlt });
		}
		ns[team].prob++; ns[team].pnl += pnlt;

		if (team != 0 && ((ns[0].prob + 1 == ns[team].prob && ns[0].pnl <= ns[team].pnl - pnlt) || (ns[0].prob == ns[team].prob && ns[0].pnl > ns[team].pnl))) {
			rk++;
		} else if (team == 0) {
			while (b.size() && (ns[0].prob > b.begin()->prob || (ns[0].prob == b.begin()->prob && ns[0].pnl <= -b.begin()->pnl))) b.erase(b.begin());
			rk = b.size() + 1;
		}

		out << rk << endl;
	}
}
