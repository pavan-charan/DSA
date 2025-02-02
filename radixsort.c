#include<stdio.h>
int getmax(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++)
    if(arr[i]>max)
    max=arr[i];
    return max;
}
void countsort(int arr[],int n,int exp){
    int output[n];
    int i,count[10]={0};
    for(i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
    arr[i]=output[i];
}
void radixsort(int arr[],int n) {
    int m=getmax(arr,n);
    for(int exp=1;m/exp>0;exp*=10)
    countsort(arr,n,exp); 
}
void print(int arr[],int n){
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter array: ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    radixsort(arr,n);
    printf("Sorted array: ");
    print(arr,n);
    return 0;
    }