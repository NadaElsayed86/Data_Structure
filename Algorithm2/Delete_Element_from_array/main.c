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

int main(void) {
    int n,pos;
    printf("Enter size of array:\n");
    scanf("%d",&n);
    int A[n];
    printf("Input array elements:");

    for(int i=0;i<n;i++) {
        scanf("%d",&A[i]);
    }

    printf("Input position to delete:");
    scanf("%d",&pos);

    int index=Binary_Search(A,n,A[pos]);

    printf("Array elements:\n");
    for(int i=0;i<n;i++) {
        if(i==index)
            continue;
        printf("%d ",A[i]);

    }

    return 0;
}
