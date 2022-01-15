#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using ll = long long;

typedef pair<int, int> ii;

ll area(int x1, int y1, int x2, int y2)
{
	return (1ll * abs(y2 - y1) * abs(x2 - x1));
}
pair<ii, ii> overlap(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	int ix1 = max(min(x1, x2), min(x3, x4));
	int iy1 = max(min(y1, y2), min(y3, y4));
	int ix2 = min(max(x1, x2), max(x3, x4));
	int iy2 = min(max(y1, y2), max(y3, y4));
	if(ix1 >= ix2 || iy1 >= iy2)
		return {{0, 0}, {0, 0}};
	return {{ix1, iy1}, {ix2, iy2}};
}
int main()
{
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

	pair<ii, ii> wb1 = overlap(x1, y1, x2, y2, x3, y3, x4, y4);
	pair<ii, ii> wb2 = overlap(x1, y1, x2, y2, x5, y5, x6, y6);
	pair<ii, ii> wb12 = overlap(wb1.f.f, wb1.f.s, wb1.s.f, wb1.s.s, wb2.f.f, wb2.f.s, wb2.s.f, wb2.s.s);

	ll wa = area(x1, y1, x2, y2);
	ll wb1a = area(wb1.f.f, wb1.f.s, wb1.s.f, wb1.s.s);
	ll wb2a = area(wb2.f.f, wb2.f.s, wb2.s.f, wb2.s.s);
	ll wb12a = area(wb12.f.f, wb12.f.s, wb12.s.f, wb12.s.s);

	cout << (wa > wb1a + wb2a - wb12a ? "YES" : "NO") << endl;

	return 0;
}

