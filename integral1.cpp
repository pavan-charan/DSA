#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }

    bool operator<(const Point &other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
vector<Point> getpoints(Point p1, Point p2) {
    vector<Point> points;

    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;

    int steps = gcd(abs(dx), abs(dy));
    int xStep = dx / steps;
    int yStep = dy / steps;

    for (int i = 0; i <= steps; i++) {
        int x = p1.x + i * xStep;
        int y = p1.y + i * yStep;
        points.push_back(Point(x, y));
    }

    return points;
}
set<Point> doshare(vector<Point>& plot1, vector<Point>& plot2) {
    int n1 = plot1.size();
    int n2 = plot2.size();
    
    set<Point> sharedpoints;

    for (int i = 0; i < n1; i++) {
        Point p1 = plot1[i];
        Point p2 = plot1[(i + 1) % n1];
        
        for (int j = 0; j < n2; j++) {
            Point p3 = plot2[j];
            Point p4 = plot2[(j + 1) % n2];
            vector<Point> points1 = getpoints(p1, p2);
            vector<Point> points2 = getpoints(p3, p4);
            for (const auto& pt1 : points1) {
                for (const auto& pt2 : points2) {
                    if (pt1 == pt2) {
                        sharedpoints.insert(pt1);
                    }
                }
            }
        }
    }

    return sharedpoints;
}

int main() {
    int n;
    cout << "Enter the number of properties: ";
    cin >> n;

    vector<vector<Point>> plots(n);

    for (int i = 0; i < n; i++) {
        int cor;
        cout << "Enter the number of corners for plot " << i + 1 << ": ";
        cin >> cor;
        
        for (int j = 0; j < cor; j++) {
            int x, y;
            cin >> x >> y;
            plots[i].push_back(Point(x, y));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<Point> sharedPoints = doshare(plots[i], plots[j]);
            if (!sharedPoints.empty()) {
                cout << "Plot " << i + 1 << " and Plot " << j + 1 << " share a boundary with integral points:";
                for (const auto& point : sharedPoints) {
                    cout << "(" << point.x << ", " << point.y << ")" << endl;
                }
            }
        }
    }

    return 0;
}
