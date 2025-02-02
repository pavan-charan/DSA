#include<bits/stdc++.h>
using namespace std;
int manhatten(int x1,int y1,int x2, int y2)
{
    int val1 = (x1+y1)-(x2+y2);
    int val2 = (x1-y1)-(x2-y2);
    int val3 = (x2+y2)-(x1+y1);
    int val4 = (x2-y2)-(x1-y1);
    return max(max(val1,val2), max(val3, val4));
}

int main()
{
    int no_points;
    cin>>no_points;
    vector<pair<int, int>> points(no_points);
    for(int i=0;i<no_points;i++)
    {
        cin>>points[i].first;
        cin>>points[i].second;
    }
    int no_kids;
    cin>>no_kids;
    vector<pair<int, int>> kids(no_kids);
    for(int i=0;i<no_kids;i++)
    {
        cin>>kids[i].first;
        cin>>kids[i].second;
    }
    vector<pair<int, int>> dup(kids);
    
    int no_free = no_points - no_kids;
    vector<pair<int, int>> free_points;
    sort(points.begin(), points.end());
    sort(dup.begin(), dup.end());
     set_difference(
        points.begin(), points.end(),
        dup.begin(), dup.end(),
        back_inserter(free_points)
    );
   
 vector<int> values;
   
    for(pair<int, int> kid : kids)
    {
        int x = kid.first;
        int y = kid.second;
        vector<int> distances;
        for(vector<pair<int, int>>::iterator it = free_points.begin(); it!=free_points.end(); it++)
        {
            int x1 = (*(it)).first;
            int y1 = (*(it)).second;
            distances.push_back(manhatten(x,y,x1,y1));
        }
    auto max_iter = max_element(distances.begin(), distances.end());
    int max_index = distance(distances.begin(), max_iter);
    values.push_back(distances[max_index]);
    free_points.erase(free_points.begin() + max_index);
    }
    
    for(int i=0;i<no_kids;i++)
    {
        cout<<kids[i].first<<" "<<kids[i].second<<" rank "<<i+1<<" with distance "<<values[i]<<"\n";
    }
    
    
}