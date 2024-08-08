#include <stdio.h>

void Merge(int l[], int nl, int r[], int nr, int A[]) {
    int i = 0, j = 0, k = 0;

    while(i < nl && j < nr) {
        if(l[i] < r[j]) {
            A[k++] = l[i++];
        } else {
            A[k++] = r[j++];
        }
    }

    while(i < nl) {
        A[k++] = l[i++];
    }

    while(j < nr) {
        A[k++] = r[j++];
    }
}

void Merge_Sort(int A[], int n) {
    if(n < 2)
        return;

    int mid = n / 2;
    int l[mid];
    int r[n - mid];

    for(int i = 0; i < mid; i++) {
        l[i] = A[i];
    }
    for(int i = mid; i < n; i++) {
        r[i - mid] = A[i];
    }

    Merge_Sort(l, mid);
    Merge_Sort(r, n - mid);
    Merge(l, mid, r, n - mid, A);
}

int main(void) {

    int n1,n2;
    printf("Enter size of two arrays:");
    scanf("%d %d",&n1,&n2);

    int A1[n1],A2[n2];
    int n=n1+n2;
    int A[n];

    printf("Input Elements of first array:");
    for(int i=0;i<n1;i++) {
        scanf("%d",&A1[i]);
    }

    printf("Input Elements of second array:");
    for(int j=0;j<n2;j++) {
        scanf("%d",&A2[j]);
    }

    Merge(A1,n1,A2,n2,A);
    Merge_Sort(A,n);
    printf("Merged Array in ascending order:\n");
    for(int i=0;i<n;i++) {
        printf("%d ",A[i]);
    }
    return 0;
}
