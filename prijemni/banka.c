#include <stdio.h>

int main(void)
{
    int N, T, sol = 0, cnt = 0, f = 0, t = 0;
    int i;
    scanf("%d%d", &N, &T);
    for(i = 0; i < N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(t <= b)
        {
            if(t <= T)
            sol++;
            t += a;
        }
    }
    printf("%d\n", sol);
    return 0;
}

