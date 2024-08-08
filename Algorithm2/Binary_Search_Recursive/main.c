#include <stdio.h>

int Binary_Search(int A[],int low,int high,int x) {
   if(low>high)
       return -1;
    int mid=low+(high-low)/2;
    if(x==A[mid])
        return mid;
    else if(x<A[mid])
        return Binary_Search(A,low,mid-1,x);
    else
        return Binary_Search(A,mid+1,high,x);
}
int main(void)
{
    int A[]={3,5,6,8,9};
    int n=sizeof(A)/sizeof(A[0]);

    int x;
    printf("Enter number to search:\n");
    scanf("%d",&x);

    int index=Binary_Search(A,0,n,x);
    if(index!=-1) {
        printf("Index of %d is %d",x,index);
    }
    else {
        printf("Number isnot found");
    }
    return 0;
}
