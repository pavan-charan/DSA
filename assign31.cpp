#include <bits/stdc++.h>
using namespace std;

// Function to calculate Manhattan Distance
int manhattanDistance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// Function to rank kids based on their maximum distance from the farthest unoccupied point
void rankKids(vector<pair<int, int>>& kids, vector<pair<int, int>>& points) {
    int k = kids.size();
    vector<int> distances(k, -1); // Vector to store maximum distances for each kid
    vector<bool> usedPoints(points.size(), false); // Vector to track used points
    
    // For each kid
    for (int i = 0; i < k; i++) {
        int maxDist = -1;
        int maxDistIndex = -1;
        
        // For each point, if not used, calculate the distance
        for (int j = 0; j < points.size(); j++) {
            if (!usedPoints[j]) {
                int dist = manhattanDistance(kids[i], points[j]);
                if (dist > maxDist) {
                    maxDist = dist;
                    maxDistIndex = j;
                }
            }
        }
        
        // Store the maximum distance for the current kid
        distances[i] = maxDist;
        
        // Mark the farthest point as used
        if (maxDistIndex != -1) {
            usedPoints[maxDistIndex] = true;
        }
    }

    // Output the rankings based on the maximum distance
    cout << "Rankings (Kid Index: Manhattan Distance):" << endl;
    vector<pair<int, int>> rankedKids;
    for (int i = 0; i < k; i++) {
        rankedKids.push_back({distances[i], i});
    }

    // Sort the kids by distance in descending order
    sort(rankedKids.rbegin(), rankedKids.rend());

    // Output the ranked kids in the original order
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
