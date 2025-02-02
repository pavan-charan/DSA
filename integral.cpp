#include<bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};
bool hi(Point p1, Point p2) {
    return p1.x == p2.x && p1.y == p2.y;
}
bool doLinesOverlap(Point p1, Point p2, Point p3, Point p4) {
    if (hi(p1, p3) || hi(p1, p4) || 
        hi(p2, p3) || hi(p2, p4)) {
        return true;
    }
    return false;
}
bool doPlotsShareBoundary(vector<Point>& plot1, vector<Point>& plot2) {
    int n1 = plot1.size();
    int n2 = plot2.size();
    
    for (int i = 0; i < n1; i++) {
        Point p1 = plot1[i];
        Point p2 = plot1[(i + 1) % n1];
        
        for (int j = 0; j < n2; j++) {
            Point p3 = plot2[j];
            Point p4 = plot2[(j + 1) % n2];
            
            if (doLinesOverlap(p1, p2, p3, p4)) { 
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int n;
    cout << "Enter the number of properties: ";
    cin >> n;

    vector<vector<Point>> plots(n);

    for (int i = 0; i < n; i++) {
        int corners;
        cin >> corners;
        
        for (int j = 0; j < corners; j++) {
            int x, y;
            cin >> x >> y;
            plots[i].push_back(Point(x, y));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (doPlotsShareBoundary(plots[i], plots[j])) {
                cout << "Plot X and Plot Y share a boundary." << endl;
            }
        }
    }
    return 0;
}
