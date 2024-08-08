#include <stdio.h>

int Binary_Search(int A[],int n,int x) {
    int low=0;
    int high=n-1;

    while(low<=high) {
        int mid=low+(high-low)/2;
        if(x==A[mid])
            return mid;
        else if(x<A[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
int main(void)
{
    int A[]={3,5,6,8,9};
    int n=sizeof(A)/sizeof(A[0]);

    int x;
    printf("Enter number to search:\n");
    scanf("%d",&x);

    int index=Binary_Search(A,n,x);
    if(index!=-1) {
        printf("Index of %d is %d",x,index);
    }
    else {
        printf("Number isnot found");
    }
    return 0;
}
