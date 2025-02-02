#include<bits/stdc++.h>
using namespace std;
bool istriangle(int num){
    double n=(-1+sqrt(1+8*num))/2;
    return n==static_cast<int>(n);
}

int main(){
    int level=1;
    int n;
    int num;
    int count=0;
    int i;
    cin>>n;
    if(istriangle(n)){
        cin>>num;
        for(i=1;i<num;i++){
            count++;
            if(count==level){
                level++;
                count=0;
            }
        }
        int z=num;
        int temp=level;
        cout<<"The level of "<<num<<" is "<<level<<endl;
        int h=(-1+sqrt(1+8*n))/2;
        cout<<h;
        int k;
        int lvl;
        for(lvl=1;lvl<=h;lvl++,z+=level){
            for(count=1,k=z;count<=lvl;count++,k++){
                if(k<=n){
                if(count<h && lvl <h)
                cout<<k<<", ";
                else cout<<k;
                 z=k;
                
                }
            }
        }
    }
    else{
        cout<<n<<" is not triangular number.";
    }
    return 0;
}