#include <stdio.h>

void Bubble_Sort(int A[],int n) {
    for(int i=0;i<n;i++) {
        int flag=0;
        for(int j=0;j<n-i-1;j++) {
            if(A[j]>A[j+1]) {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
int main(void) {
    int A[]={5,2,9,7,1};
    int n=sizeof(A)/sizeof(A[0]);
    Bubble_Sort(A,n);
    for(int i=0;i<n;i++) {
        printf("%d ",A[i]);
    }

    return 0;
}
