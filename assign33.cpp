#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ll no_points;
    cin >> no_points;

    map<ll, set<pair<ll, ll>>> unsum;
    map<ll, set<pair<ll, ll>>> undiff;
    map<ll, set<pair<ll, ll>>> ocsum;
    map<ll, set<pair<ll, ll>>> ocdiff;

    for (int i = 0; i < no_points; i++) {
        ll x, y;
        cin >> x >> y;
        pair<ll, ll> key = make_pair(x, y);
        unsum[x + y].insert(key);
        undiff[x - y].insert(key);
    }

    ll kids;
    cin >> kids;
    ll count = 0;

    for (int i = 0; i < kids; i++) {
        ll x, y;
        cin >> x >> y;
        pair<ll, ll> key = make_pair(x, y);
        ocsum[x + y].insert(key);
        ocdiff[x - y].insert(key);
        
        unsum[x + y].erase(key);
        undiff[x - y].erase(key);
    }
    ll rank=1;
    while (!ocsum.empty() && count < kids) {
        ll maximumdist = -1;
        pair<ll, ll> selOc, selUc;

        for (const auto &os : ocsum) {
            for (const auto &oc : os.second) {
                for (const auto &us : unsum) {
                    for (const auto &uc : us.second) {
                        ll dist = abs(oc.first - uc.first) + abs(oc.second - uc.second);
                        if (dist > maximumdist) {
                            maximumdist = dist;
                            selOc = oc;
                            selUc = uc;
                        }
                    }
                }
            }
        }

        if (maximumdist != -1) {
           
            ocsum[selOc.first + selOc.second].erase(selOc);
            if (ocsum[selOc.first + selOc.second].empty()) {
                ocsum.erase(selOc.first + selOc.second);
            }

            ocdiff[selOc.first - selOc.second].erase(selOc);
            if (ocdiff[selOc.first - selOc.second].empty()) {
                ocdiff.erase(selOc.first - selOc.second);
            }

            unsum[selUc.first + selUc.second].erase(selUc);
            if (unsum[selUc.first + selUc.second].empty()) {
                unsum.erase(selUc.first + selUc.second);
            }

            undiff[selUc.first - selUc.second].erase(selUc);
            if (undiff[selUc.first - selUc.second].empty()) {
                undiff.erase(selUc.first - selUc.second);
            }

            cout << selOc.first << " " << selOc.second <<" rank "<<rank<<" with distance " <<maximumdist << endl;
            rank++;
            count++;
        }
    }

    return 0;
}