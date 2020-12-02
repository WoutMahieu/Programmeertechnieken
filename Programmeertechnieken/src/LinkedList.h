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

typedef struct LinkedList{
	const char * value;
	struct LinkedList * nextPtr;
}LinkedList_t;

void LinkedL_PrintList(LinkedList_t* startPtr);

void LinkedL_Push(LinkedList_t ** startPtrPtr, const char * value);

void LinkedL_Delete(LinkedList_t ** startPtrPtr, const char * value);

int LinkedL_Contains(LinkedList_t ** startPtrPtr, const char * value);

//char * pop(LinkedList * head);
//
//char * remove_by_index(LinkedList * head, int n);

#endif /* LINKEDLIST_H_ */
