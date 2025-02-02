// #include <bits/stdc++.h>
// using namespace std;

// void MaxDist(vector<pair<int, int>>& Z, int n) {
//     vector<int> V(n), V1(n);

//     for (int i = 0; i < n; i++) {
//         V[i] = Z[i].first + Z[i].second;
//         V1[i] = Z[i].first - Z[i].second;
//     }
//     sort(V.begin(), V.end());
//     sort(V1.begin(), V1.end());

//     int maximum = max(V.back() - V.front(), V1.back() - V1.front());

//     cout <<maximum << endl;
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<pair<int, int>> Z(n);
//     for (int i = 0; i < n; i++) {
//         cin >> Z[i].first >> Z[i].second;
//     }
// 	int m;
// 	cin >> m;
// 	vector<pair<int, int>> Y(m);
// 	for (int i = 0; i < m; i++) {
// 		cin >> Y[i].first >> Y[i].second;
// 	}

//     MaxDist(Z, n);

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// int manhattanDistance(pair<int, int> a, pair<int, int> b) {
//     return abs(a.first - b.first) + abs(a.second - b.second);
// }
// void rankKids(vector<pair<int, int>>& kids, vector<pair<int, int>>& points) {
//     int k = kids.size();
//     vector<int> minDistances(k, INT_MAX);
//     for (int i = 0; i < k; i++) {
//         for (const auto& point : points) {
//             if (find(kids.begin(), kids.end(), point) == kids.end()) {
//                 int dist = manhattanDistance(kids[i], point);
//                 minDistances[i] = min(minDistances[i], dist);
//             }
//         }
//     }

//     vector<pair<int, int>> rankedKids;
//     for (int i = 0; i < k; i++) {
//         rankedKids.push_back({minDistances[i], i});
//     }
//     sort(rankedKids.rbegin(), rankedKids.rend());
//     cout << "Rankings (Kid Index: Manhattan Distance):" << endl;
//     for (int i = 0; i < k; i++) {
//         cout << "Rank " << i + 1 << ": Kid " << rankedKids[i].second 
//              << " (Distance: " << rankedKids[i].first << ")" << endl;
//     }
// }

// int main() {
//     int k, p;
//     cout << "Enter the number of kids: ";
//     cin >> k;
//     cout << "Enter the number of points: ";
//     cin >> p;

//     vector<pair<int, int>> points(p);
//     cout << "Enter the points (x y):" << endl;
//     for (int i = 0; i < p; i++) {
//         cin >> points[i].first >> points[i].second;
//     }
//     srand(time(0));
//     vector<pair<int, int>> kids(k);
//     set<int> usedIndices;
//     for (int i = 0; i < k; i++) {
//         int index;
//         do {
//             index = rand() % p;
//         } while (usedIndices.count(index));
//         usedIndices.insert(index);
//         kids[i] = points[index];
//     }
//     rankKids(kids, points);

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

// Function to calculate Manhattan Distance
int manhattanDistance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// Function to rank kids based on their distance from the nearest unoccupied point
void rankKids(vector<pair<int, int>>& kids, vector<pair<int, int>>& points) {
    int k = kids.size();
    vector<int> minDistances(k, INT_MAX);

    // Calculate minimum distance to any unoccupied point for each kid
    for (int i = 0; i < k; i++) {
        for (const auto& point : points) {
            if (find(kids.begin(), kids.end(), point) == kids.end()) {
                int dist = manhattanDistance(kids[i], point);
                minDistances[i] = min(minDistances[i], dist);
            }
        }
    }

    // Create a vector of pairs (distance, kid_index) and sort it
    vector<pair<int, int>> rankedKids;
    for (int i = 0; i < k; i++) {
        rankedKids.push_back({minDistances[i], i});
    }

    // Sort kids by distance (descending order)
    sort(rankedKids.rbegin(), rankedKids.rend());

    // Output the ranks
    cout << "Rankings (Kid Index: Manhattan Distance):" << endl;
    for (int i = 0; i < k; i++) {
        cout << "Rank " << i + 1 << ": Kid " << rankedKids[i].second 
             << " (Distance: " << rankedKids[i].first << ")" << endl;
    }
}

// Function to compare two vectors and store points that are not common in both vectors
void CompareVectors(const vector<pair<int, int>>& Z, const vector<pair<int, int>>& Y, vector<pair<int, int>>& result) {
    unordered_set<pair<int, int>, hash<pair<int, int>>> ySet(Y.begin(), Y.end());

    for (const auto& z : Z) {
        if (ySet.find(z) == ySet.end()) {
            result.push_back(z);
        }
    }

    unordered_set<pair<int, int>, hash<pair<int, int>>> zSet(Z.begin(), Z.end());

    for (const auto& y : Y) {
        if (zSet.find(y) == zSet.end()) {
            result.push_back(y);
        }
    }
}

// Function to find the maximum distance between points in Z
void MaxDist(vector<pair<int, int>>& Z, int n) {
    vector<int> V(n), V1(n);

    for (int i = 0; i < n; i++) {
        V[i] = Z[i].first + Z[i].second;
        V1[i] = Z[i].first - Z[i].second;
    }
    sort(V.begin(), V.end());
    sort(V1.begin(), V1.end());

    int maximum = max(V.back() - V.front(), V1.back() - V1.front());

    cout << "Maximum Distance: " << maximum << endl;
}

int main() {
    int n;
    cout << "Enter the number of points on the playground (Z): ";
    cin >> n;

    vector<pair<int, int>> Z(n);
    cout << "Enter the coordinates of the points on the playground (x y):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> Z[i].first >> Z[i].second;
    }

    int k;
    cout << "Enter the number of kids: ";
    cin >> k;

    vector<pair<int, int>> Y(k);
    cout << "Enter the coordinates occupied by the kids (x y):" << endl;
    for (int i = 0; i < k; i++) {
        cin >> Y[i].first >> Y[i].second;
    }

    vector<pair<int, int>> differentPoints;
    CompareVectors(Z, Y, differentPoints);

    cout << "Points that are not occupied by any kid:" << endl;
    for (const auto& point : differentPoints) {
        cout << "(" << point.first << ", " << point.second << ")" << endl;
    }

    MaxDist(Z, n);
    rankKids(Y, Z);

    return 0;
}
