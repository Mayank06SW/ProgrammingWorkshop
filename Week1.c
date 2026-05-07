#include <stdio.h>
#include <limits.h>

#define N 5
#define K 7
#define INF 100000

typedef struct {
    int node;
    int dist;
    int toll;
} State;

int dist[N+1][K+1];

int edgeList[7][4] = {
    {1,2,4,2},
    {1,3,2,4},
    {2,3,1,1},
    {2,4,5,3},
    {3,4,8,2},
    {4,5,2,1},
    {3,5,10,6}
};

State pq[1000];
int size = 0;

void swap(State *a, State *b)
{
    State t = *a;
    *a = *b;
    *b = t;
}

void push(State s)
{
    pq[size++] = s;

    for(int i=size-1;i>0;i--)
    {
        if(pq[i].dist < pq[(i-1)/2].dist)
        {
            swap(&pq[i], &pq[(i-1)/2]);
        }
    }
}

State pop()
{
    State top = pq[0];
    pq[0] = pq[--size];

    int i = 0;

    while(1)
    {
        int left = 2*i+1;
        int right = 2*i+2;
        int smallest = i;

        if(left<size && pq[left].dist < pq[smallest].dist)
            smallest = left;

        if(right<size && pq[right].dist < pq[smallest].dist)
            smallest = right;

        if(smallest==i) break;

        swap(&pq[i], &pq[smallest]);
        i = smallest;
    }

    return top;
}

int main()
{
    int S = 1, D = 5;

    for(int i=1;i<=N;i++)
        for(int j=0;j<=K;j++)
            dist[i][j] = INF;

    dist[S][0] = 0;

    push((State){S,0,0});

    while(size)
    {
        State cur = pop();

        int u = cur.node;
        int d = cur.dist;
        int t = cur.toll;

        if(d > dist[u][t]) continue;

        for(int i=0;i<7;i++)
        {
            int a=edgeList[i][0];
            int b=edgeList[i][1];
            int w=edgeList[i][2];
            int toll=edgeList[i][3];

            int v = -1;

            if(a==u) v=b;
            else if(b==u) v=a;
            else continue;

            int nd = d + w;
            int nt = t + toll;

            if(nt<=K && nd < dist[v][nt])
            {
                dist[v][nt] = nd;
                push((State){v,nd,nt});
            }
        }
    }

    int ans = INF;

    for(int i=0;i<=K;i++)
        if(dist[D][i] < ans)
            ans = dist[D][i];

    if(ans==INF)
        printf("-1\n");
    else
        printf("Minimum Distance = %d\n",ans);

    return 0;
}
