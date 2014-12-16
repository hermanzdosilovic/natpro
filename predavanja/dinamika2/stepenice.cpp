/*
 * Zadatak STEPENICE 
 * Mirko se igrom slucaja nasao ispred stepenista od (1<=N<=10^5) stepenica.
 * Mirko odjednom može preskočiti najviše (1<=K<=N) stepenica.
 *
 * Ispisite na koliko razlicitih nacina Mirko moze doskociti na vrh stepenista.
 * Rjesenje ispisite po modulu 10^9 + 7
 */

#include <cstdio>

using namespace std;

const int mod = 1e9 + 7;

int N, K;
int dp[100002]; // dp[i] = dp[i - 1] + dp[i - 2] + ... + dp[i - K]
int cum_dp[1000002]; // cum_dp[i] = dp[0] + dp[1] + ... + dp[i]

// Iz gornjih tablica: 
// dp[i] = dp[i - 1] + dp[i - 2] + ... dp[i - K] = cum_dp[i - 1] - cum_dp[i - K - 1]
// O(N) 

int main(void) {

    scanf("%d%d", &N, &K);
    
    // nizovi su 1-indeksirani 
    dp[0] = 1; 
    cum_dp[0] = 1;

    for (int i = 1; i <= N; ++i) {
        dp[i] = cum_dp[i - 1];
        if (i - K - 1>= 0) dp[i] -= cum_dp[i - K - 1];
        dp[i] += mod; dp[i] %= mod;
        cum_dp[i] = cum_dp[i - 1] + dp[i];
        cum_dp[i] %= mod;
    }

    printf("%d\n", dp[N]);

    return 0;

}
