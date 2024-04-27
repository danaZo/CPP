/**
 * Adaptive Array 
 * 
 * Instructions:
 * The array changing it's size so every call to non negative index will pass.
 * Call to index with no value will return NULL
 * 
 * Implementation By: Dana Zorohov 207817529
 * struct AdptArry: used to implement an array data structure which is able to store
 * and manage any data type elements.
 * function CreateAdptArray: create new instance of AdptArray
 * function DeleteAdptArray: delete a given AdptArray instance
 * function SetAdptArrayAt: sets given element at given index at the adptarray
 * function GetAdptArrayAt: receives index and returnes copy of the element at this index in the array
 * function GetAdptArraySize: returns size of the array
 * function PrintDB: prints all the elements in the array
 */


#include <stdlib.h>
#include "AdptArray.h"
#include "book.h"
#include <stdio.h>

/* implementation of struct AdptArray_:
*   param size: holds the current number of elements in the AdptArray
*   param elementsArr: pointer to array with elements stored in the AdptArray
*   param copyfu: function pointer that points to function which copy elements
*   param delfu: function pointer that points to function which delete elements
*   param printfu: function pointer that points to function which print elements
*/
typedef struct AdptArray_{
    int size; 
    PElement *elementsArr;
    COPY_FUNC copyfu;
    DEL_FUNC delfu;
    PRINT_FUNC printfu;
}AdptArray;


/* implementation of function CreateAdptArray:
*   create new instance of AdptArray with functions:
*   COPY_FUNC, DEL_FUNC, PRINT_FUNC
*   param ADTarr: allocating new instance of AdptArray using malloc
*   return: new AdptArray
*/
PAdptArray CreateAdptArray(COPY_FUNC copyfu, DEL_FUNC delfu,PRINT_FUNC printfu)
{
    PAdptArray ADTarr = (PAdptArray)malloc(sizeof(AdptArray));
    if (ADTarr == NULL)
    {
        perror("allocation failed at CreateAdptArray");
        return NULL;
    }
    
    ADTarr->size = 0;
    ADTarr->elementsArr = NULL;
    ADTarr->copyfu = copyfu;
    ADTarr->delfu = delfu;
    ADTarr->printfu = printfu;

    return ADTarr;
}


/* implementation of function DeleteAdptArray:
*   delete a given AdptArray instance
*   if the given param is already null there's nothing to do
*   else, we iterate over all it's elements and delete them  
*   then free the array
*/
void DeleteAdptArray(PAdptArray ADTarr)
{
    if (ADTarr == NULL)
    {
        return;
    }
    
    for (int i = 0; i < ADTarr->size ; i++)
    {
        if (ADTarr->elementsArr[i] != NULL)
        {
            ADTarr->delfu(ADTarr->elementsArr[i]);
        }
    }
    free(ADTarr->elementsArr);
    free(ADTarr);
}

/* implementation of function SetAdptArrayAt:
*   receives index and element
*   saves copy of the element at the place of the index
*   frees the old element if exists  
*   if the index is negative then the function fails
*   if index is bigger than the size of the array or equal to it,
*   then we need to icrease the array. 
*   to achieve that, i am using realloc, 
*   and initializing the new space to NULL
*   if the element is null, i update the element at index to null
*   else, using the copyfu i create copy of elem
*   and replace the element at index to the copy of elem
*   the function returns SUCCESS if we secceded setting the element
*/
Result SetAdptArrayAt(PAdptArray ADTarr, int index, PElement elem) {

    if (index < 0) return FAIL;

    if (index >= ADTarr->size) {
        int new_size = index + 1;
        PElement *new_elements = (PElement*)realloc(ADTarr->elementsArr, new_size * sizeof(PElement));
        if (new_elements == NULL) return FAIL;
        
        for (int i = ADTarr->size; i < new_size; i++) {
        new_elements[i] = NULL;
        }
        
        ADTarr->elementsArr = new_elements;
        ADTarr->size = new_size;
    }
    

    PElement copied = ADTarr->copyfu(elem);
    if (copied == NULL) return FAIL;
    
    if (ADTarr->elementsArr[index] != NULL) {
        ADTarr->delfu(ADTarr->elementsArr[index]);
    }
    ADTarr->elementsArr[index] = copied;

    return SUCCESS;

}

/* implementation of function GetAdptArrayAt:
*   receives index and returnes copy of the element at this index in the array
*   if index is negative or bigger than the size of the array or element at index is null - nothing to return
*   else return the element at index
*/
PElement GetAdptArrayAt(PAdptArray ADTarr, int index)
{
    if (index < 0)
    {
        perror("index is negative, try again with positive index at GetAdptArrayAt");
        return FAIL;
    }

    if (index >= ADTarr->size)
    {
        perror("index is equal/bigger than the array size - out of bounds, try again with in-bounds index at GetAdptArrayAt");
        return FAIL;
    }
    
    if (ADTarr->elementsArr[index] == NULL)
    {
        return NULL;
    }
    
    return ADTarr->copyfu(ADTarr->elementsArr[index]);
}

/* implementation of function GetAdptArraySize:
*   returns size of the array
*/
int GetAdptArraySize(PAdptArray ADTarr)
{
    return ADTarr->size;
}

/* implementation of function PrintDB:
*   prints all the elements in the array
*/
void PrintDB(PAdptArray ADTarr)
{
     if (ADTarr == NULL) {
        printf("Array is NULL\n");
        return;
    }


    for (int i = 0; i < ADTarr->size; i++) {
        if (i >= ADTarr->size) {
            printf("Invalid index %d\n", i);
            return;
        }
        if (ADTarr->elementsArr[i] == NULL)
        {
            continue;
        }
        else
        {
            ADTarr->printfu(ADTarr->elementsArr[i]);
        }
    }
}
