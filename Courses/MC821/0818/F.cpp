
#include <iostream>
#include <vector>
#include <cmath>

class Point{
public:
  char c;
  int x, y;
  Point(char c, int x, int y){
    this->c = c;
    this->x = x;
    this->y = y;
  }
  Point(){
    this->c = ' ';
    this->x = 0;
    this->y = 0;
  }
};


using namespace std;

int sign (Point p1, Point p2, Point p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle (Point pt, Point v1, Point v2, Point v3)
{
    bool b1, b2, b3;

    b1 = sign(pt, v1, v2) < 0;
    b2 = sign(pt, v2, v3) < 0;
    b3 = sign(pt, v3, v1) < 0;

    return ((b1 == b2) && (b2 == b3));
}

bool isInline(Point p, Point p1, Point p2){
  return (p.y - p1.y) * (p2.x - p1.x) == (p.x - p1.x) * (p2.y - p1.y)
    && ((p.x >= p1.x && p2.x >= p.x) || (p.x <= p1.x && p2.x <= p.x));
}

int Area(Point p1, Point p2, Point p3){
  return abs(((p3.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p3.x - p1.x)));
}


int main(){
  ios::sync_with_stdio(false);
  int n;
  vector<Point> points;

  char c;
  int x, y;

  while(cin >> n && n != 0){
    points.clear();
    for(int i = 0; i < n; i++){
      cin >> c >> x >> y;
      points.push_back(Point(c, x, y));
    }

    double mA = 0;
    Point p1 = Point(), p2 = Point(), p3 = Point();
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        for(int k = j + 1; k < n; k++){
          bool flag = true;
          for(int l = 0; l < n; l++){
            if(l != i && l != j && l != k){
              if(PointInTriangle(points[l], points[i], points[j], points[k])
                || isInline(points[l], points[i], points[j])
                || isInline(points[l], points[i], points[k])
                || isInline(points[l], points[j], points[k])){
                flag = false;
              }
            }
          }
          if(flag){
              if(Area(points[i], points[j], points[k]) > mA){
                mA = Area(points[i], points[j], points[k]);
                p1 = points[i];
                p2 = points[j];
                p3 = points[k];
              }
          }
        }
      }
    }

    cout << p1.c << p2.c << p3.c << endl;
  }


  return 0;
}
