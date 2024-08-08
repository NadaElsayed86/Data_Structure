#include <stdio.h>

int Quick(int A[],int ibegin,int jend) {
    int i=ibegin,j=jend;
    int p=i;

    while(1) {
        while(A[p]<=A[j] && p!=j) {
            j--;
        }
        if(p==j) break;
        else if(A[p]>A[j]) {
            int temp=A[p];
            A[p]=A[j];
            A[j]=temp;
            p=j;
        }

        while(A[p]>=A[i] && p!=i) {
            i++;
        }
        if(p==i) break;
        else if(A[p]<A[i]) {
            int temp=A[p];
            A[p]=A[i];
            A[i]=temp;
            p=i;
        }

    }
    return p;
}

void Quick_Sort(int A[],int l,int r) {
    if(l<r) {
        int piv=Quick(A,l,r);
        Quick_Sort(A,l,piv-1);
        Quick_Sort(A,piv+1,r);
    }

}
int main(void)
{
    int A[]={5,2,9,7,8,6};
    int n=sizeof(A)/sizeof(A[0]);
   Quick_Sort(A,0,n-1);
    for(int i=0;i<n;i++) {
        printf("%d ",A[i]);
    }
    return 0;
}
