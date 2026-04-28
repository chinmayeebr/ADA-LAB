#include <stdio.h>

#define LEFT -1
#define RIGHT 1

int getMobile(int a[], int dir[], int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        if ((dir[a[i]] == LEFT && i > 0 && a[i] > a[i - 1]) ||
            (dir[a[i]] == RIGHT && i < n - 1 && a[i] > a[i + 1])) {
            if (a[i] > mobile)
                mobile = a[i];
        }
    }
    return mobile;
}

int getPos(int a[], int n, int mobile) {
    for (int i = 0; i < n; i++)
        if (a[i] == mobile)
            return i;
    return -1;
}

void printPerm(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void johnsonTrotter(int n) {
    int a[n], dir[n + 1];

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    for (int i = 1; i <= n; i++)
        dir[i] = LEFT;

    printPerm(a, n);

    while (1) {
        int mobile = getMobile(a, dir, n);
        if (mobile == 0)
            break;

        int pos = getPos(a, n, mobile);

        if (dir[mobile] == LEFT) {
            int t = a[pos];
            a[pos] = a[pos - 1];
            a[pos - 1] = t;
        } else {
            int t = a[pos];
            a[pos] = a[pos + 1];
            a[pos + 1] = t;
        }

        for (int i = 0; i < n; i++)
            if (a[i] > mobile)
                dir[a[i]] *= -1;

        printPerm(a, n);
    }
}

int main() {
    int n;
    printf("Enter n :");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
