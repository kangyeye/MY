//堆排序

#define LeftChild(i) (2*(i)+1)

//交换
void Swap(int* a, int* b) {
    int Tmp;
    Tmp = *a;
    *a = *b;
    *b = Tmp;
}

void PercDown(ElementType A[],int i, int N) {
    int Child;
    ElementType Tmp;

    for (Tmp = A[i]; LeftChild(i) < N; i = Child) {
        Child = LeftChild(i);
        if (Child != N - 1 && A[Child + 1] > A[Child])
            Child++;
        if (Tmp < A[Child])
            A[i] = A[Child];
        else
            break;
    }
    A[i] = Tmp;
}

void Heapsort(ElementType A[], int N) {
    int i;

    for (i = N / 2; i >= 0; i--) {/*BuildHeap*/
        PercDown(A, i, N);
    }
    for (i = N - 1; i > 0; i--) {
        Swap(&A[0], &A[i]); /*DeleteMax*/
        PercDown(A, 0, i);
    }
}
