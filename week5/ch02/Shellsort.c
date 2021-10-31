//希尔排序
void Shellsort(ElementType A[], int N) {
    int i, j, k;
    int gap;//分组的步长
    ElementType Tmp;

    for (int gap = N / 2; gap > 0; gap = gap / 2) {
        for (i = 0; i < gap; i++) {
            for (j = i+gap; j < N; j = j + gap) {
                if (A[j] < A[j - gap]) {
                    Tmp = A[j];
                    k = j - gap;
                    while (k >= 0 && Tmp < A[k]) {
                        A[k + gap] = A[k];
                        k = k - gap;
                    }
                    A[k+gap] = Tmp;
                }

            }
        }
    }
}
