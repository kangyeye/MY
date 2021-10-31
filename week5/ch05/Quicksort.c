//快速排序

//交换
void Swap(int* a, int* b) {
    int Tmp;
    Tmp = *a;
    *a = *b;
    *b = Tmp;
}

/* Return median of Left, Center, and Right */
/* Order these and hide the pivot */
ElementType Median3(ElementType A[], int Left, int Right) {/*实现三数中值分割方法的程序*/
    int Center = (Left + Right) / 2;

    if (A[Left] > A[Center])
        Swap(&A[Left] , &A[Center]);
    if (A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if (A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);

    /* Invariant: A[Left] <= A[Center] <= A[Right]*/

    Swap(&A[Center], &A[Right - 1]);/*Hide pivot*/
    return A[Right - 1];/*Return pivot*/
}

#define Cutoff (3)
void Qsort(ElementType A[], int Left, int Right) {/* 快速排序的主例程 */
    int i, j;
    ElementType Pivot;

    if (Left + Cutoff <= Right) {
        Pivot = Median3(A, Left, Right);
        i = Left;
        j = Right - 1;
        while (1) {
            while (A[++i] < Pivot) {}
            while (A[--j] > Pivot) {}
            if (i < j) {
                Swap(&A[i], &A[j]);
            }
            else {
                break;
            }
        }
        Swap(&A[i], &A[Right - 1]);

        Qsort(A, Left, i - 1);
        Qsort(A, i + 1, Right);
    }
    /* Do an insertion sort on the subarray*/
    /* 对于小数组，快速排序不如插入排序 */
    else
        InsertionSort(A + Left, Right - Left + 1);
}

void Quicksort(ElementType A[], int N) {/* 快速排序的驱动程序 */
    Qsort(A, 0, N - 1);
}
