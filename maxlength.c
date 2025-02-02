#include<stdio.h>
struct coordinates{
    int e,s;
    char c;
}
int main(){
    int n;
    scanf("%d",&n);
    struct coordinates C[n];
    for(int i=0;i<n;i++){
        scanf("%d%d%c",&C[i]->s,&C[i]->e,C[i]->c);
    }

    return 0;
}