/*
 * ZADATAK Podnizovi
 * Zadan je niz od (1<=N<=10^5) brojeva pri cemu je svaki od tih brojeva <= 10^5
 * Potrebno je ispisati broj strogo rastucih podnizova zadanog niza. Strogo 
 * rastuci podniz duljine k niza {a_1, a_2, ..., a_n} je svaka uredjena k-torka * (a_x1, a_x2, ..., a_xk) gdje vrijedi a_x1 < a_x2 < ... < a_xk i 
 * x1 < x2 < ... < xk. 
 *
 * Rjesenje ispisati po modulu 10^9 + 7
 */

#include <cstdio>

using namespace std;

const int mod = 1e9 + 7;

int N; 
int a[100005], loga[100005], dp[100005]; // dp[i] = broj rastucih podnizova koji zavrsavaju s elementom a[i] -- rjesenje je tada suma(dp[i])

inline void set(int i, int val) {
    for ( ; i <= 100000; i += i & -i) {
        loga[i] += val;
        loga[i] %= mod;
    }
}

inline int sum(int i) {
    int ret = 0;
    for ( ; i > 0; i -= i & -i) {
        ret += loga[i];
        ret %= mod;
    }
    return ret;
}

int main(void) {

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", &a[i]);

    /*
     * dp[i] = suma svih dp[j] pri cemu j < i && a[j] < a[i]
     * Ovu relaciju mozemo optimzirati koristeci logaritamsku strukturu na nacin
     * da po obradi stanja dp[i], vrijednost dp[i] spremimo u logaritamsku pod 
     * indeksom a[i]. Obrada stanja svodi se na sumu prvih (a[i] - 1) elemenata
     * u logaritamskj.
     */

    int sol = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] - 1 > 0) dp[i] += sum(a[i] - 1);
        ++dp[i]; dp[i] %= mod;
        set(a[i], dp[i]);
        sol += dp[i]; sol %= mod;
    }

    printf("%d\n", sol);

    return 0;

}
