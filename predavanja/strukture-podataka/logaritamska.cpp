/*
Zadan je niz a od maksimalno 10^6 elemenata. Indeksi elementi tog niza
nalaze se u intervalu [1, N] gdje je N broj elemenata tog niza.

Nad tim nizom odraditi cemo M upita. Postoje dvije vrste upita koje mozemo
napraviti:

Update:
    U x y
'U' je oznaka pri inputu da radimo update. Updateamo element u nizu a na poziciji
x tako da ga postavimo na vrijednost y. Dakle update U x y radi a[x] = y;

Query:
    Q x
'Q' je oznaka pri inputu da radimo query nad nizom. Taj query treba vratiti sumu
elemenata iz intervala [1, x];

Input:
    N, M. N je broj elemenata koji ce biti u nizu. M je broj querya koji ce se
    izvrsiti nad nizom.

    Nakon toga slijedi N elemenata niza.

    Nakon toga slijedi M queryia formata:
        U x y
        Q x

    U radi update x-tog elementa na vrijednost y.
    Q vraca sumu elemenata u intervalu [1, x].

Output:
    Treba vratiti odgovarajucu sumu nakon svakog query 'Q' upita.
*/
#include <cstdio>
#include <cmath>

using namespace std;

const int MAX_N = 1000003;

int f[(1 << 21) + 3], a[MAX_N], N, M;

int query(int x) {
    int sum = 0;
    for(; x > 0; x -= x & -x) {
        sum += f[x];
    }
    return sum;
}

void update(int x, int v) {
    for(; x <= N; x += x & -x) {
        f[x] += v;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        update(i, a[i]);
    }
    for(int i = 0; i < M; i++) {
        char c;
        int x, y;
        scanf(" %c", &c);
        if(c == 'Q') {
            scanf("%d", &x);
            printf("%d\n", query(x));
        } else {
            scanf("%d%d", &x, &y);
            update(x, y - a[x]);
            a[x] = y;
        }
    }
    return 0;
}
