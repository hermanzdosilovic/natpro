// Ivan Krpelnik
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define N 1000000

char str[N];
int bucketA[N], nBucketA[N], H, L;
int *bucket, *nBucket, *tmp;

struct Suffix {

    bool operator<(const Suffix &suff) const {
        if(H == 0)
            return str[idx] < str[suff.idx];
        else if(bucket[idx] == bucket[suff.idx])
            return bucket[idx+H] < bucket[suff.idx+H];
        else
            return bucket[idx] < bucket[suff.idx];
    }

    bool operator ==(const Suffix &suff) const {
        return !(*this < suff) && !(suff < *this);
    }

    int idx;
} pos[N];

bool updateBuckets() {
    int start = 0, id = 0;
    bool c = 0;
    for(int i = 0; i < L; ++i) {
        if(i != 0 && !(pos[i] == pos[i-1])) {
            start = i;
            id++;
        }
        c |= i != start;
        nBucket[pos[i].idx] = id;
    }
    tmp = bucket;
    bucket = nBucket;
    nBucket = tmp;
    return c;
}

void suffixSort() {
    for(int i = 0; i < L; ++i)
        pos[i].idx = i;
    H = 0;
    std::sort(pos, pos + L);
    bool c = updateBuckets();
    for(H = 1; c; H *= 2) {
        std::sort(pos, pos + L);
        c = updateBuckets();
    }
}

int rank[N];
int height[N];

void getHeight(int n){
  for (int i=0; i<n; ++i) rank[pos[i].idx] = i;
  height[0] = 0;
  for (int i=0, h=0; i<n; ++i){
    if (rank[i] > 0){
      int j = pos[rank[i]-1].idx;
      while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
      printf("%d\n", h);
      height[rank[i]] = h;
      if (h > 0) h--;
    }
  }
}

int main()
{
    scanf("%s", str);
    L = strlen(str)+1;
    bucket = bucketA;
    nBucket = nBucketA;
    suffixSort();
    for(int i = 0; i < L; ++i)
        printf("%s\n", str + pos[i].idx);
    getHeight(L);
    for(int i = 0; i < L; ++i)
        printf("%d\n", height[i]);
    return 0;
}
