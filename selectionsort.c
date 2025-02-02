#include<stdio.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void selectionsort(int  arr[],int n){
    int i,j,min;
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[min])
                min=j;
        swap(&arr[i],&arr[min]);
    }
}
void printarray(int  arr[],int n) {
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
int main(){
    int n;
    printf("Enter no.of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    selectionsort(arr,n);
    printf("Sorted array: ");
    printarray(arr,n);
    return 0;
}