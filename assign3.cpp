#include <bits/stdc++.h>
using namespace std;
int manhattanDistance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
void rankKids(vector<pair<int, int>>& kids, vector<pair<int, int>>& points) {
    int k = kids.size();
    vector<int> minDistances(k, INT_MAX);
    for (int i = 0; i < k; i++) {
        for (const auto& point : points) {
            if (find(kids.begin(), kids.end(), point) == kids.end()) {
                int dist = manhattanDistance(kids[i], point);
                minDistances[i] = min(minDistances[i], dist);
            }
        }
    }
    vector<pair<int, int>> rankedKids;
    for (int i = 0; i < k; i++) {
        rankedKids.push_back({minDistances[i], i});
    }
    sort(rankedKids.rbegin(), rankedKids.rend());
    cout << "Rankings (Kid Index: Manhattan Distance):" << endl;
    for (int i = 0; i < k; i++) {
        cout << "Rank " << i + 1 << ": Kid " << rankedKids[i].second 
             << " (Distance: " << rankedKids[i].first << ")" << endl;
    }
}

int main() {
    int p, k;
    cout << "Enter the number of points: ";
    cin >> p;

    vector<pair<int, int>> points(p);
    cout << "Enter the points on the ground (x y):" << endl;
    for (int i = 0; i < p; i++) {
        cin >> points[i].first >> points[i].second;
    }
    cout << "Enter the number of kids: ";
    cin >> k;

    vector<pair<int, int>> kids(k);
    cout << "Enter the points occupied by kids (x y):" << endl;
    for (int i = 0; i < k; i++) {
        cin >> kids[i].first >> kids[i].second;
    }
    
    rankKids(kids, points);

    return 0;
}
