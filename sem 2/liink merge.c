#define SIZE 4
static unsigned int a[SIZE] = {5,8,4,7};
static size_t link[SIZE];               /* index to next element */

size_t MergeLists(size_t i, size_t j)
{
size_t head;
size_t *pprev = &head;                  /* ptr: head or link[] */
    while((i != -1) && (j != -1)){      /* while not end lists */
        if(a[i] <= a[j]){               /*   if i < j          */
            *pprev = i;                 /*      link to i      */
            pprev = &link[i];           /*      advance pprev  */
            i=*pprev;                   /*      advance i      */
        } else {                        /*   else              */
            *pprev = j;                 /*      link to j      */
            pprev = &link[j];           /*      advance pprev  */
            j=*pprev;                   /*      advance j      */
        }
    }
    if(i == -1)                         /* if end of i list    */
        *pprev=j;                       /*   link to rest of j */
    else                                /* else                */
        *pprev=i;                       /*   link to rest of i */
    return head;
}

size_t MergeSort(size_t low, size_t end)
{
size_t mid, i, j;
    if((end - low) == 0){               /* if size == 0           */
        return low;                     /*  (only on first call)  */
    }
    if((end - low) == 1){               /* if size == 1           */
        link[low] = -1;                 /*    initialize link[]   */
        return low;                     /*    return index        */
    }
    if((end - low) == 2){               /* if size == 2           */
        if(a[low] <= a[end-1]){         /*   if in order          */
            link[low]   = end-1;        /*    initialize link[]   */
            link[end-1] = -1;
            return low;                 /*    return index        */
        } else {                        /*   else                 */
            link[end-1] = low;          /*    initialize link[]   */
            link[low]   = -1;
            return end-1;               /*    return index        */
        }
    }
    mid = (low+end)/2;                  /* size > 2, recursively  */
    i = MergeSort(low, mid);            /*   split lists until    */
    j = MergeSort(mid, end);            /*   size <= 2            */
    return MergeLists(i, j);  
}