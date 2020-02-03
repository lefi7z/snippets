#include "binary_search.h"

/* ------- iterative version ------- */

/* do a binary search for `elm`. 
 * return pointer to elm or NULL if not found.*/
void* binary_search(int elm, int arr[], size_t len)
{
    if (arr == NULL || len == 0)
        return NULL;

    size_t mid, lo = 0, hi = len;
    int i = 0;

    while (lo < hi)
    {
        mid = (lo + hi) / 2;  // round down, especially 1 / 2 = 0

        if (elm == arr[mid])
            return &arr[mid];

        if (hi - lo == 1)
            break;
        
        else if (elm < arr[mid]) 
            hi = mid;
        else if (elm > arr[mid]) 
            lo = mid;
    }
    return NULL;
}

/* ------- recursive version ------- */

/* do a binary search for `elm`. 
 * return pointer to elm or NULL if not found.*/
void* binary_search_r(int elm, int arr[], size_t len)
{
    if (arr == NULL || len == 0)
        return NULL;

    size_t mid = len / 2;  // round down, especially: 1 / 2 = 0

    if (elm == arr[mid])
        return &arr[mid];
    
    else if (len == 1)
        return NULL;

    else if (elm < arr[mid]) 
        return binary_search_r(elm, &arr[0], mid);

    else if (elm > arr[mid]) 
        return binary_search_r(elm, &arr[mid], len-mid);
        
    return NULL;
}
