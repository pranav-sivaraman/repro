int main() {
  int N = 100;
  int *a = new int[N];
  int *b = new int[N];
  int *c = new int[N];

#pragma omp target teams distribute parallel for simd
  for (int i = 0; i < N; i++) {
    c[i] = a[i] + b[i];
  }

  return 0;
}
