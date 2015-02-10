N cvorova

int w[MAX][MAX];

for (int k = 0; k < N; k++) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
    }
  }
}
