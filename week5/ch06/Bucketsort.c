//桶式排序
#define MAX 100
void Bucketsort(ElementType A[], int N, int max_num)//N表示排序数组大小，max_num表示排序数组中最大的数
{
    int i;
    int j;
    int count[MAX] = {0};

    for (i = 0; i < N; i++) {
        ++count[A[i]];
    }
    for (j = 0; j <= max_num; j++) {
        while (count[j] > 0) {
            printf("%d ", j);
            count[j]--;
        }
    }
    printf("\n");
}
