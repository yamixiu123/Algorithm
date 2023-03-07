#include<stdio.h>
#pragma warning(disable : 4996)
#define MAXSIZE 100
#define INF 0x3f3f3f
int G[MAXSIZE][MAXSIZE];
int color[MAXSIZE], p[MAXSIZE], d[MAXSIZE];
enum dye {
    white = 0, black,gray
};
void initiate(int* n) {
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        d[i] = INF;
        color[i] = white;
        for (int j = 0; j < *n; j++) {
            G[i][j] = INF;
        }
    }
    for (int i = 0; i < *n; i++) {
        int row, lik_num, column, weight;
        scanf("%d %d", &row, &lik_num);
        for (int j = 0; j < lik_num; j++) {
            scanf("%d %d", &column, &weight);
            G[row][column] = weight;
        }
    }
}

void dijkstra(int n, int s_vertex) {
    int mindex;
    color[s_vertex] = black;
    for (int i = 0; i < n; i++) {
        d[i] = G[s_vertex][i];
    }
    d[s_vertex] = 0;
    p[s_vertex] = -1;
    while (1) {
        int mincost = INF;
        for (int i= 0; i < n; i++) {
            if (color[i] != black && d[i] < mincost) {
                mincost = d[i];
                mindex = i;
            }
        }
        if (mincost == INF)break;
        
        color[mindex] = black;

        for (int i = 0; i < n; i++) {
            if (color[i] != black && G[mindex][i] != INF) {
                if (d[mindex]+G[mindex][i]<d[i])
                {
                    d[i] = d[mindex] + G[mindex][i];
                    p[i] = mindex;
                    color[i] = gray;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i ,d[i]);
    }
}

int main() {
    int n;
    initiate(&n);
    dijkstra(n, 0);
    return 0;
}
