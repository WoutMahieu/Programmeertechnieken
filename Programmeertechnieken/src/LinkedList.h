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

typedef struct LinkedList{
	const char * value;
	struct LinkedList * nextPtr;
}LinkedList_t;

void LinkedL_printList(LinkedList_t* startPtr);

void LinkedL_push(LinkedList_t ** startPtrPtr, const char * value);

const char * LinkedL_delete(LinkedList_t ** startPtrPtr, const char * value);

int LinkedL_contains(LinkedList_t ** startPtrPtr, const char * value);

//char * pop(LinkedList * head);
//
//char * remove_by_index(LinkedList * head, int n);

#endif /* LINKEDLIST_H_ */
