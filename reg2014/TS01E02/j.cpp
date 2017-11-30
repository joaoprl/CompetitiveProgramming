#include <iostream>
#include <vector>

#define MAXR 510
#define MAXC 510
#define MAXN 10

using namespace std;

const int INF = 1e9;
const int INF2 = INF + 1;

class Qr{
public:
	int v, x, y;

	Qr(int v, int x, int y) : v(v), x(x), y(y) { }

	bool operator<(const Qr &ot)const{
		return v < ot.v;
	}
};

class LQTree{
private:
	LQTree *q1, *q2, *q3, *q4;
	int x1, x2, y1, y2, midX, midY;
	Qr val;
	LQTree(int _x1, int _x2, int _y1, int _y2) : val(INF, _x1, _y1) {
		x1 = _x1;
		x2 = _x2;
		y1 = _y1;
		y2 = _y2;

		midX = (x1 + x2) / 2;
		midY = (y1 + y2) / 2;

		q1 = q2 = q3 = q4 = NULL;

		if(x1 != x2){
			q1 = new LQTree(x1, midX, y1, midY);
			q2 = new LQTree(midX + 1, x2, y1, midY);
		}
		if(y1 != y2){
			if(!q1)
				q1 = new LQTree(x1, midX, y1, midY);
			q3 = new LQTree(x1, midX, midY + 1, y2);
		}
		if(x1 != x2 && y1 != y2)
			q4 = new LQTree(midX + 1, x2, midY + 1, y2);

		if(q1) val = min(val, q1->val);
		if(q2) val = min(val, q2->val);
		if(q3) val = min(val, q3->val);
		if(q4) val = min(val, q4->val);
	}

public:
	LQTree(int x, int y) : LQTree(1, x, 1, y){ }
	~LQTree(){
		if(q1) delete q1;
		if(q2) delete q2;
		if(q3) delete q3;
		if(q4) delete q4;
	}

	void update(int xa, int xb, int ya, int yb, int v){
		// cout << "up: " << x1 << " " << x2 << " " << y1 << " " << y2 << " " << v << endl;
		if(val.v == INF2)
			return;

		if(q1 && xa <= midX && ya <= midY)
			q1->update(xa, min(midX, xb), ya, min(midY, yb), v);
		if(q2 && xb > midX && ya <= midY)
			q2->update(max(xa, midX + 1), xb, ya, min(midY, yb), v);
		if(q3 && xa <= midX && yb > midY)
			q3->update(xa, min(midX, xb), max(ya, midY + 1), yb, v);
		if(q4 && xb > midX && yb > midY)
			q4->update(max(xa, midX + 1), xb, max(ya, midY + 1), yb, v);

		if(xa == x1 && xb == x2 && ya == y1 && yb == y2)
			val = min(val, Qr(v, xa, ya));
		else{
			val = Qr(INF2, -1, -1);
			if(q1) val = min(val, q1->query(x1, midX, y1, midY));
			if(q2) val = min(val, q2->query(midX + 1, x2, y1, midY));
			if(q3) val = min(val, q3->query(x1, midX, midY + 1, y2));
			if(q4) val = min(val, q4->query(midX + 1, x2, midY + 1, y2));
		}
	}

	Qr query(int xa, int xb, int ya, int yb){
		if(val.v == INF2)
			return val;

		if(xa == x1 && xb == x2 && ya == y1 && yb == y2){
			// cout << "qr: " << x1 << " " << x2 << " " << y1 << " " << y2 << " " << val.v << endl;
			return val;
		}

		Qr q(INF2, -1, -1);
		if(q1 && xa <= midX && ya <= midY)
			q = min(q, q1->query(xa, min(midX, xb), ya, min(midY, yb)));
		if(q2 && xb > midX && ya <= midY)
			q = min(q, q2->query(max(xa, midX + 1), xb, ya, min(midY, yb)));
		if(q3 && xa <= midX && yb > midY)
			q = min(q, q3->query(xa, min(midX, xb), max(ya, midY + 1), yb));
		if(q4 && xb > midX && yb > midY)
			q = min(q, q4->query(max(xa, midX + 1), xb, max(ya, midY + 1), yb));

		// cout << "qr: " << x1 << " " << x2 << " " << y1 << " " << y2 << " " << q.v << endl;
		return q;
	}

	void set(int x, int y){
		// cout << "st: " << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
		if(x1 == x && x2 == x && y1 == y && y2 == y)
			val = Qr(INF2, -1, -1);

		if(q1 && x <= midX && y <= midY)
			q1->set(x, y);
		if(q2 && x > midX && y <= midY)
			q2->set(x, y);
		if(q3 && x <= midX && y > midY)
			q3->set(x, y);
		if(q4 && x > midX && y > midY)
			q4->set(x, y);

		val = Qr(INF2, -1, -1);
		if(q1) val = min(val, q1->query(x1, midX, y1, midY));
		if(q2) val = min(val, q2->query(midX + 1, x2, y1, midY));
		if(q3) val = min(val, q3->query(x1, midX, midY + 1, y2));
		if(q4) val = min(val, q4->query(midX + 1, x2, midY + 1, y2));
	}
};

int main(){
	ios::sync_with_stdio(false);

	int r, c, n, ox, oy, nx, ny, x, y, v;
	int V[MAXR][MAXC], R[MAXR][MAXC], C[MAXR][MAXC];

	while(cin >> r >> c >> n){
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				cin >> V[i][j];

		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				cin >> R[i][j];

		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				cin >> C[i][j];

		cin >> ox >> oy;
		for(int i = 0; i < n - 1; i++){
			cin >> nx >> ny;

			LQTree tr(r, c);
			tr.update(ox, ox, oy, oy, 0);

			Qr q = tr.query(nx, nx, ny, ny);
			while(q.v == INF){
				q = tr.query(1, r, 1, c);

				if(q.v == INF2)
					break;

				v = q.v;
				x = q.x;
				y = q.y;
				// cout << x << " " << y << " " << v << endl;

				// cout << "update: " << max(1, x - R[x][y]) << " " << min(r, x + R[x][y]) << " " << max(1, y - C[x][y]) << " " << min(c, y + C[x][y]) << " " << v + V[x][y] << endl;
				tr.update(max(1, x - R[x][y]), min(r, x + R[x][y]), max(1, y - C[x][y]), min(c, y + C[x][y]), v + V[x][y]);
				tr.set(x, y);
				q = tr.query(nx, nx, ny, ny);
			}

			q = tr.query(nx, nx, ny, ny);
			if(q.v == INF || q.v == INF2)
				cout << -1;
			else
				cout << q.v;
			if(i != n - 2)
				cout << " ";

			ox = nx;
			oy = ny;
		}
		cout << endl;
	}

	return 0;
}
