#include<stdio.h>


int reverse_num(int x);
int del_dupnum(int x);

int main() {
    int N, M, n1;
    int gap, maximum, num_mid, mid_max = 0;
    int  i = 0, j = 0, k = 0;

    scanf("%d", &N);
    while (N >=0) {
        n1 = N;
        N = reverse_num(N);
        M = del_dupnum(N);
        printf(" %d", M);

        if (n1 > M) {
            gap = n1 - M;
            num_mid = n1;
        }
        else {
            gap = M - n1;
            num_mid = n1;
        }
        if (gap > mid_max) {
            mid_max = gap;
            maximum = n1;
        }
        scanf("%d", &N);
    }
    printf("\n");
    printf("%d %d", maximum, mid_max);

    return 0;
}

int del_dupnum(int x) {
    int i = 0, j = 0, k = 0;
    int b = 0, cnt = 0, a1, sum = 0, c;
    int arr[10], cntx = 0, tmp = 1, tttp = 0;
    a1 = x;

    while (x > 0) {
        x /= 10;
        cnt++;
    }
    x = a1;
    for (k = 0; k < cnt; k++) {
        tmp = 1; tttp = 0;
        for (i = k; i < cnt - 1; i++) {
            tmp *= 10;
        }
        c = x / tmp;
        for (i = 0; i < cntx; i++) {
            if (c == arr[i])
                tttp = 1;
        }
        if (tttp == 0) {
            sum *= 10;
            arr[cntx++] = c;
            sum += c;
        }
        x = x % tmp;
    }
    sum = 0;
    for (i = 0; i < cntx; i++) {
        sum *= 10;
        sum += arr[i];
    }

    return sum;
}

int reverse_num(int x) {
    int tmp = 0;
    for (;x > 0;x /= 10) {
        tmp *= 10;
        tmp += x % 10;
    }
    return tmp;
}