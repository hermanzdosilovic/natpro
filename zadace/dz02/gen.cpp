#include <cstdio>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int N, b[200003];

int main() {
    srand(time(0));
    int N = 10000000;
    printf("%d\n", N);
    int i = 0;
    while(i < N) {
        int k = rand()%10000000 + 10000000;
        k *= rand()%2 ? -1 : 1;
        if(1) {
            printf("%d\n", k);
            i++;
        }
    }
    printf("\n");
    return 0;
}
