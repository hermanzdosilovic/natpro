/*
 * Zadatak LEKSPUT
 * Dana je matrica dimenzija RxS (1<=R,S<=40) :) 
 * 
 * Covjeculjak stoji u gornjem lijevom  matrice i pokusava doci do 
 * donjeg desnog kuta matrice. Sa nekog polja, covjeculjak se moze 
 * pomaknuti za jedno polje udesno ili za jedno polje prema dolje.
 *
 * Dodatno, covjeculjak ne smije stati na polje sa znakom '#'.
 *
 * Prevaljen put kodiramo nizom znakova 'R' (right) ili 'D' (down)
 * pri nam cemu i-ti znak kodne rijeci daje do znanja gdje se 
 * covjeculjak u i-tom koraku pomaknuo. 
 * 
 * Ispisite K-ti leksikografski put od gornjeg lijevog do donjeg desnog
 * kuta matrice. Ukoliko takav put ne postoji ispisite "NEMOGUCE". 
 * (1<=K<=10^18)
 */

#include <cstdio>

typedef long long llint;

using namespace std;

char grid[21][21];

int R, S;

llint K;
llint dp[21][21]; // dp[i][j] = na koliko nacina je moguce doci iz donjeg desnog kuta do polja (i,j)

inline bool check(int r, int s) {
    return r >= 0 && r < R && s >= 0 && s < S && grid[r][s] != '#';
} 

int main(void) {

    scanf("%d%d%lld", &R, &S, &K);
    for (int i = 0; i < R; ++i) scanf("%s", grid[i]);

    dp[R - 1][S - 1] = 1LL;
    for (int i = R - 1; i >= 0; --i) {
        for (int j = S - 1; j >= 0; --j) {
            if (grid[i][j] == '#' || i == R - 1 && j == S - 1) continue;
            dp[i][j] = 0LL;
            if (check(i, j + 1)) dp[i][j] += dp[i][j + 1];
            if (check(i + 1, j)) dp[i][j] += dp[i + 1][j];
        }
    }

    if (K > dp[0][0]) {
        printf("NEMOGUCE\n");
        return 0;
    } 

    /*
     *
     * Mislim da sam ovo stvarno lose objasnio na predavanju pa idem probati
     * ovako: 
     * 
     * Analizirajmo prvi korak rekonstrukcije. Predstavimo sve moguce putove 
     * sljedecim dijagramom: 
     *
     *        D                   R
     * [.............|.........................]
     * 
     * Dakle, dio svih putova zapocinje znakom 'D' (lijevo od znaka '|'), a dio 
     * svih putova zapocinje znakom 'R' (desno od znaka '|'). Svaka tockica 
     * oznacava jedan od mogucih putova. Na "slici" vidimo da postoji 13 putova
     * koji zapocinju znakom 'D' i 25 putova koji zapocinju znakom 'R'. 
     *
     * Moguca su dva scenarija: 
     *
     * 1) K <= broj putova koji pocinju znakom 'D'
     *
     *        D                   R
     * [.............|.........................]
     *           |
     *           K = 10 tockica 
     *
     * Vidimo da K-ti leksikografski put pocinje znakom D ==> ispisujemo znak 
     * D i trazimo K-ti put na cijelom tom interavalu... sljedeci korak bi
     * mogao biti: 
     *
     *        D      
     *    D      R
     * [.....|........]
     *            |
     *            K = 10 tockica
     *
     * Nastavljamo istim postupkom...
     *
     * 2) K > broj putova koji pocinju znakom 'D'
     *
     *        D                   R
     * [.............|.........................]
     *                   |
     *                   K = 17 tockica
     *
     * Vidimo da K-ti leksikografski put pocinje znakom R ==> ispisujemo znak R
     * i trazimo [K - (broj putova koji pocinju s D)]-ti put na intervalu pod
     * pod slovom R.
     *
     * Primijetimo da na tom intervalu vise ne trazimo K-ti leksikografski put
     * jer se donja granica intervala vise ne nalazi na nuli. Pomicanje donje
     * granice (do znaka '|') efektivno smanjuje K za (broj putova koji pocinju
     * s D). 
     *
     * Sljedeci korak bi mogao biti:
     *
     *                            R
     *                       D             R
     *               [................|.........]
     *                   |
     *                   K = 17 - 13 = 4 tockice 
     *
     * Nastavljamo istim postupkom...
     * Nadam se da je sad malo jasnije :) 
     */
   
    int r = 0, s = 0;
    while (r != R - 1 || s != S - 1) {
        if (check(r + 1, s) && K <= dp[r + 1][s]){ 
            printf("D"); ++r;
        } else {
            printf("R");  
            if (check(r + 1, s)) K -= dp[r + 1][s];
            ++s;
        }
    }

    printf("\n");

    return 0;

}
