#include <stdio.h>

int Binary_Search(int A[],int n) {
    int low=0;
    int high=n-1;

    while(low<=high) {
        int mid=low+(high-low)/2;

        if((mid == 0 || A[mid] > A[mid - 1]) && (mid == n-1 || A[mid] > A[mid + 1]))
            return A[mid];
        else if(A[mid]<A[mid-1])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int main(void) {
    int A[]={4,5,8,9,10,11,7,3,2,1};
    int n=sizeof(A)/sizeof(A[0]);

    int max=Binary_Search(A,n);
    printf("Max element is %d",max);

    return 0;
}
