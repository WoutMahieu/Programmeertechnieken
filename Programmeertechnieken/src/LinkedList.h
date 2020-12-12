/*
 * LinkedList.h
 *
 *  Created on: 26 okt. 2020
 *      Author: Lowie Lameire
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StatusLED.h"

/**
* A node of the linked list
* Each node holds a character array (= string) and holds a pointer to the next node in the list
*/
typedef struct LinkedList{
	const char * value;
	struct LinkedList * nextPtr;
}LinkedList_t;

/**
* Prints the entire linked list, element by element
*
* @param *startPtr  points to the first element in the linked list
*/
void LinkedL_PrintList(LinkedList_t* startPtr);

/**
* Push an item to the linked list
*
* @param **startPtrPtr  pointer to the pointer that point to the first element in the linked list
* @param *value  array of characters (= string)
*/
void LinkedL_Push(LinkedList_t ** startPtrPtr, const char * value);

/**
* Delete a specific string from the linked list
*
* @param **startPtrPtr  pointer to the pointer that point to the first element in the linked list
* @param *value  array of characters (= string)
*
* @return  the deleted array of characters (= string)
*/
void LinkedL_Delete(LinkedList_t ** startPtrPtr, const char * value);

/**
* Checks if a specific string is in the linked list
*
* @param **startPtrPtr  pointer to the pointer that point to the first element in the linked list
* @param *value  array of characters (= string)
*
* @return  a boolean (1 = linked list did contain the given string (char array), 0 = linked list didn't contain the given string (char array)
*/
int LinkedL_Contains(LinkedList_t ** startPtrPtr, const char * value);

#endif /* LINKEDLIST_H_ */
