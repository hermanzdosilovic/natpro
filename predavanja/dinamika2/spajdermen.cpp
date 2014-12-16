/*
 * Zadatak SPAJDERMEN
 *
 * Spajdermen se nalazi u podnozju zgrade koja ima (1<=N<=100) katova, 
 * a na svakom katu s vanjske strane zgrade vidi se (1<=M<=10^5) pravilno
 * rasporedjenih prozora. 
 *
 * Spajdermen s podnozja zgrade skace na bilo koji prozor prvog kata, a sa
 * svakog prozora moze skociti na onaj direktno iznad njega ili na bilo koji
 * od dva njemu (onom iznad trenutne lokacije) susjedna prozora. Ukoliko se 
 * Spajdermen nalazi na prozoru posljednjeg kata, lagano se penje na krov zgrade
 * gdje njegov put zavrsava.
 *
 * Ispisite na koliko nacina Spajdermen moze doci od podnozja do vrha nebodera.
 * Rjesenje ispisite po modulu 10^9 + 7
 */

#include <algorithm>
#include <cstdio>

#define MAXM 100000

using namespace std;

const int mod = 1e9 + 7;

int N, M; 
int dp[3][MAXM + 1];
int ds[] = {-1, +0, +1};

int main(void) {

    scanf("%d%d", &N, &M);

    int prev = 0, curr = 1;
    for (int i = 0; i < M; ++i) dp[prev][i] = 1; // s podnozja na i-ti prozor prvog kata mogu skociti na 1 nacin

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            dp[curr][j] = 0;
            for (int k = 0; k < 3; ++k) { 
                if (j + ds[k] >= 0 && j + ds[k] < M){ 
                    dp[curr][j] += dp[prev][j + ds[k]];
                    dp[curr][j] %= mod;
                }
            }
        }
        swap(curr, prev);
    }

    int sol = 0; 
    for (int i = 0; i < M; ++i) {
        sol += dp[prev][i]; // na krov mogu doci sa svih prozora zadnjeg kata
        sol %= mod;
    }
    printf("%d\n", sol);

    return 0;

}
