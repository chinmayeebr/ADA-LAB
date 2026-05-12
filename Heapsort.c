#include <stdio.h>
#include <time.h>

#define MAX 100

void heapify(int a[], int n, int i){
    int l=2*i+1,r=2*i+2,largest=i,t;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i){
        t=a[i]; a[i]=a[largest]; a[largest]=t;
        heapify(a,n,largest);
    }
}

void heapsort(int a[], int n){
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>0;i--){
        int t=a[0]; a[0]=a[i]; a[i]=t;
        heapify(a,i,0);
    }
}

int main(){
    int n,a[MAX];

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    clock_t start=clock();
    heapsort(a,n);
    clock_t end=clock();

    printf("Sorted array:\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);

    double time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds",time);

    return 0;
}

