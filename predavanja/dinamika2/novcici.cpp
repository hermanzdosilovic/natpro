/*
 * Zadatak NOVCICI
 * Na raspolaganju imate beskonacno mnogo kovanica koje poprimaju (1<=N<=100)
 * razlicitih vrijednosti. Zelite isplatiti sumu (1<=S<=10000) u sto je moguce
 * manjem broju kovanica. 
 *
 * Ispisite rjesenje u obliku "c1_c2_c3_..._cn", gdje ci oznacava vrijednost 
 * i-te isplacene kovanice i vrijedi c1>=c2>=...>=cn (znak '_' predstavlja razmak).
 * 
 * Ukoliko postoji vise rjesenja, ispisite bilo koje. Ukoliko rjesenje ne 
 * postoji, ispisite "NEMOGUCE". 
 */

#include <algorithm>
#include <cstdio>

using namespace std;

int N, S;
int kovanica[101];
int dp[10001]; // dp[i] = minimalan broj potreban za isplatiti sumu i 
int prev[10001]; // prev[i] = vrijednost novcica s kojim smo dosli u stanje dp[i] ==> u dp[i] smo dosli iz stanja dp[i - prev[i]] 

int main(void) {

    scanf("%d %d", &N, &S); // broj kovanica i suma koju treba isplatiti 
    for (int i = 0; i < N; ++i) scanf("%d", &kovanica[i]);
    
    sort(kovanica, kovanica + N);

    dp[0] = 0; 
    for (int i = 1; i <= S; ++i) {
        dp[i] = S + 1; // INF 
        for (int j = 0; j < N; ++j) {
            if (i - kovanica[j] < 0) break;
            if (1 + dp[i - kovanica[j]] <= dp[i]) {
                dp[i] = 1 + dp[i - kovanica[j]];
                prev[i] = kovanica[j];
            }
        }
    }
    
    if (dp[S] == S + 1) {
        printf("NEMOGUCE\n");
        return 0;
    }

    while (prev[S] != 0) {
        printf("%d ", prev[S]);
        S -= prev[S];
    }

    printf("\n");

    return 0;

}
