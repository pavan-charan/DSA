#include<stdio.h>
#include<stdbool.h>
void swap(int *x, int *y) {
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void bubblesort(int arr[], int n){
    bool swapped;
    int i,j;
    for(i=0;i<n;i++){
        swapped=false;
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j+1],&arr[j]);
                swapped=true;
            }
        }
        if(swapped==false)
        break;
    }
}
void printarray(int arr[],int n){
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
int main(){
    int n;
    printf( "Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
    scanf( "%d", &arr[i]);
    bubblesort(arr,n);
    printf("Sorted array: ");
    printarray(arr,n);
    return 0;
}