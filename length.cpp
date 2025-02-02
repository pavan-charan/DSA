#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class lineSegment {
public:
    int start;
    int end;
    lineSegment(int start, int end) : start(start), end(end) {}
    bool operator<(const lineSegment &other) const {
        return start < other.start;
    }
};

class endPoint {
public:
    int coordinate;
    int lu;
    endPoint(int coordinate, int lu) : coordinate(coordinate), lu(lu) {}
    bool operator<(const endPoint &other) const {
        if (coordinate == other.coordinate) {
            return lu < other.lu;
        }
        return coordinate < other.coordinate;
    }
    static vector<endPoint> sortCoordinates(vector<endPoint> endPoints) {
        if (endPoints.size() <= 1) {
            return endPoints;
        }
        vector<endPoint> left(endPoints.begin(), endPoints.begin() + endPoints.size() / 2);
        
        vector<endPoint> right(endPoints.begin() + endPoints.size() / 2, endPoints.end());
        left = sortCoordinates(left);
        right = sortCoordinates(right);
        vector<endPoint> sorted;
        merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(sorted));
        return sorted;
    }
};

vector<endPoint> makeEndpoints(vector<lineSegment> lineSegments) {
    vector<endPoint> endPoints;
    for (const auto& seg : lineSegments) {
        endPoints.emplace_back(seg.start, 0);
        endPoints.emplace_back(seg.end, 1);
    }
    return endPoint::sortCoordinates(endPoints);
}

int maxSegment(vector<lineSegment> lineSegments) {
    vector<endPoint> endPoints = makeEndpoints(lineSegments);
    int maxLen = 0;
    int activSeg = 0;
    int start = 0;
    int end = 0;

    for (const auto& e : endPoints) {
        if (e.lu == 0) { // start
            activSeg++;
            if (activSeg == 1) {
                start = e.coordinate;
            }
        } else { // end
            activSeg--;
            if (activSeg == 0) {
                end = e.coordinate;
                maxLen = max(maxLen, end - start);
            }
        }
    }

    return maxLen;
}

vector<pair<int, int>> mergeIntervals(vector<lineSegment> lineSegments) {
    vector<endPoint> endPoints = makeEndpoints(lineSegments);
    vector<pair<int, int>> combined;
    int active = 0;
    int start = 0;

    for (const auto& e : endPoints) {
        if (e.lu == 0) { // start
            active++;
            if (active == 1) {
                start = e.coordinate;
            }
        } else { 
            active--;
            if (active == 0) {
                combined.emplace_back(start, e.coordinate);
            }
        }
    }
    for (const auto& seg : lineSegments) {
        combined.emplace_back(seg.start, seg.end);
    }

    return combined;
}

int maxTransLen(vector<lineSegment> first_color, vector<lineSegment> second_color) {
    vector<pair<int, int>> intervals1 = mergeIntervals(first_color);
    vector<pair<int, int>> intervals2 = mergeIntervals(second_color);

    int maxLen = 0;
    bool transition = false;

    for (const auto& int1 : intervals1) {
        for (const auto& int2 : intervals2) {
            if (int2.first < int1.second && int2.first >= int1.first && int2.second > int1.second) {
                maxLen = max(maxLen, int2.second - int1.first);
                transition = true;
            }
        }
    }

    return transition ? maxLen : -1;
}

int main() {
    vector<lineSegment> redSeg;
    vector<lineSegment> greenSeg;
    vector<lineSegment> blueSeg;
    int count;
    cin >> count;

    for (int i = 0; i < count; i++) {
        int start, end;
        string color;
        cin >> start >> end >> color;

        if (color == "r") {
            redSeg.emplace_back(start, end);
        } else if (color == "g") {
            greenSeg.emplace_back(start, end);
        } else if (color == "b") {
            blueSeg.emplace_back(start, end);
        }
    }

    cout << maxSegment(redSeg) << endl;
    cout << maxSegment(greenSeg) << endl;
    cout << maxSegment(blueSeg) << endl;

    int transLen;

    transLen = maxTransLen(redSeg, greenSeg);
    if (transLen != -1) {
        cout << transLen << endl;
    } else {
        cout << "nil" << endl;
    }

    transLen = maxTransLen(greenSeg, blueSeg);
    if (transLen != -1) {
        cout << transLen << endl;
    } else {
        cout << "nil" << endl;
    }

    transLen = maxTransLen(blueSeg, redSeg);
    if (transLen != -1) {
        cout << transLen << endl;
    } else {
        cout << "nil" << endl;
    }

    return 0;
}
