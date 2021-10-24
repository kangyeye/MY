/* BinaryHeap.c
 * 二叉堆的结构属性：
 * 必须是一颗完成二叉树。这使得可以用数组来存取二叉堆，但数组大小需要预先估计好。
 * 二叉堆的堆序性：
 * 每个节点关键字的值必须不小于其父节点关键字的值。这使得根节点的关键字值总是最小。
 */
#include <stdio.h>
#include <stdlib.h>
#include "binheap.h"

#define MIN_PQ_SIZE    (10)
#define MIN_DATA    (-32767) /* 哨兵 */
#define MAX_DATA    (32768)

struct bin_heap
{
    int capacity;
    int size;
    element_type* elements;
};

int is_empty(prior_queue h)
{
    return h->size == 0;
}

int is_full(prior_queue h)
{
    return h->size == h->capacity;
}

prior_queue initialize(int max_elements)
{
    prior_queue h;

    if (max_elements < MIN_PQ_SIZE)
        printf("Priority queue size is to small!");


    h =(prior_queue) malloc(sizeof(struct bin_heap));
    if (NULL == h)
        printf("Out of space!");

    /* 使用h->elements[0]作为哨兵，因此多分配的一个单元 */
    h->elements = (element_type*)malloc((max_elements + 1)
        * sizeof(element_type));
    if (NULL == h->elements) {
        free(h);
        printf("Out of space!");
    }

    h->capacity = max_elements;
    h->size = 0;
    h->elements[0] = MIN_DATA;

    return h;
}

void make_empty(prior_queue h)
{
    h->size = 0;
}

void insert(element_type x, prior_queue h)
{
    int i;

    if (is_full(h))
        printf("Priority queue is full!");

    /*
    如果空穴的父节点的值比插入值大，则空穴往上移一层；
    否则将插入值填入空穴中。
    */
    for (i = ++h->size; h->elements[i / 2] > x; i /= 2) {
        h->elements[i] = h->elements[i / 2];
    }
    h->elements[i] = x;
}

/*
    删除二叉堆的最小单元
    二叉堆的最小单元就是根节点，删除根节点后需要从子树中寻找一个节点
    来做为根节点。方法是将根节点处的空穴下沉，并将最后那个节点移到合适的空穴上。
*/
element_type delete_min(prior_queue h)
{
    int i, child;

    element_type min_element, last_element;

    if (is_empty(h)) {
        printf("Priority queue is empty!");
        return h->elements[0];
    }

    min_element = h->elements[1];
    last_element = h->elements[h->size--];

    for (i = 1; i * 2 <= h->size; i = child) {
        child = i * 2;
        if (child != h->size && h->elements[child + 1]
            < h->elements[child])
            child++;

        if (last_element > h->elements[child]) {
            h->elements[i] = h->elements[child];
        }
        else {
            break;
        }
    }

    h->elements[i] = last_element;

    return min_element;
}

element_type find_min(prior_queue h)
{
    if (!is_empty(h))
        return h->elements[1];

    printf("Priority queue is empty!");
    return h->elements[0];
}

void destroy(prior_queue h)
{
    if (h == NULL)
        return;

    free(h->elements);
    free(h);
}

int get_parent(int pos)
{
    return (pos & 1) ? ((pos - 1) / 2) : (pos / 2);
}

/*
 * 降低指定位置关键字的值，根据新值重新调整二叉堆的
 * value 必须是正值！
 */
int decrease_key(int pos, int value, prior_queue h)
{
    int i;
    int parent;
    int new_element;

    if (h == NULL || pos > h->size) {
        printf("Input parameter error!");
        return -1;
    }

    i = pos; // + 1;
    new_element = h->elements[i] - value;

    for (parent = get_parent(i); parent > 0; parent = get_parent(i)) {
        if (new_element < h->elements[parent])
            h->elements[i] = h->elements[parent];
        else
            break;
        i /= 2;
    }
    h->elements[i] = new_element;

    return 0;
}

/*
 * 删除指定位置的节点：
 *        通过先将该位置关键字值降到最小，令其位置调整到根节点上，
 *        在调用delete_min()删除之。
 */
int delete_element(int pos, prior_queue h)
{
    if (decrease_key(pos, MAX_DATA, h))
        return -1;

    delete_min(h);

    return 0;
}


/************    Next we test binary heap    ***************/

#define get_array_size(array)    ( sizeof(array) / sizeof(array[0]) )

int main()
{
    int i;
    int min_element;

    prior_queue h;
    element_type elements[] ={ 3, 12, 11, 8, 9, 6, 5,
                               24, 1, 7, 13, 66, 28,
                               10, 20, 15, 16, 22, 2 };
    

    h = initialize(64);
    if (NULL == h) {
        printf("Out of Space");
        return 0;
    }

    for (i = 0; i < get_array_size(elements); i++) {
        insert(elements[i], h);
    }

    /* test for find_min() */
    min_element = find_min(h);
    printf("%d \n", min_element);

    /* test for delete_element() */
    delete_element(9, h);

    /* test for delete_min() */
    min_element = delete_min(h);
    printf("%d \n", min_element);

    /* test for find_min() */
    min_element = find_min(h);
    printf("%d \n", min_element);

    destroy(h);
    return 0;
}
