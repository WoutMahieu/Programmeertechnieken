/*
 * LinkedList_t.c
 *
 *  Created on: 26 okt. 2020
 *      Author: Lowie Lameire
 */

#include "LinkedList.h"

void LinkedL_PrintList(LinkedList_t* startPtr)
{
	LinkedList_t* walkingPtr = startPtr;

	if (walkingPtr == NULL)
		printf("List is empty.\n\n");
	else
	{
		printf("The list is:\n");

		while (walkingPtr != NULL)
		{
			printf("%s --> ", walkingPtr->value);
			walkingPtr = walkingPtr->nextPtr;
		}

		printf("NULL\n");
	}
}

void LinkedL_Push(LinkedList_t ** startPtrPtr, const char * value){

	//if value is already in the list, it doesn't have to be pushed
	if(LinkedL_Contains(startPtrPtr, value) == 0){

		//making new element and linking value to it
		LinkedList_t* newElementPtr = malloc(sizeof(LinkedList_t));
		newElementPtr->value = malloc(strlen(value) + 1);
		strcpy(newElementPtr->value, value);

		//newElementPtr becomes te first pointer in the list
		newElementPtr->nextPtr = *startPtrPtr;
		*startPtrPtr = newElementPtr;
		//printf("Value has been pushed to the list\n");

		//Flash LED
		StatusLED_Flash();
	}else{
		//printf("Value was already in the list\n");
	}
	//LinkedL_PrintList(*startPtrPtr);
}

void LinkedL_Delete(LinkedList_t ** startPtrPtr, const char * toDelete){
	LinkedList_t* walkingPtr = *startPtrPtr;
	LinkedList_t* prevWalkingPtr = NULL;
	LinkedList_t* temp = NULL;
	int found = 0;

	//return if only 1 element in list
	if(walkingPtr->nextPtr == NULL){
		return;
	}

	//check if value is already in the linked list
	while(walkingPtr != NULL && found == 0){
		if(strcmp((walkingPtr->value), toDelete) != 0){
			prevWalkingPtr = walkingPtr;
			walkingPtr = walkingPtr->nextPtr;
		}
		else if(strcmp((walkingPtr->value), toDelete) == 0){
			if(prevWalkingPtr == NULL){
				temp = walkingPtr;
				*startPtrPtr = walkingPtr->nextPtr;
				found = 1;
			}
			else{
				temp = walkingPtr;
				prevWalkingPtr->nextPtr = walkingPtr->nextPtr;
				found = 1;
			}

			free(temp);

			//Flash LED
			StatusLED_Flash();
		}
	}
}

int LinkedL_Contains(LinkedList_t ** startPtrPtr, const char * value){
	LinkedList_t* walkingPtr = *startPtrPtr;
	int found = 0;

	//printf("List of comparisons\n");
	//check if value is in the linked list
 	while(walkingPtr != NULL && found == 0){
		//printf("%s <==> %s\n", value, walkingPtr->value);
		if(strcmp((walkingPtr->value), value) == 0){
			//for debugging purposes
			//printf("Value found in the list %s\n", walkingPtr->value);
			found = 1;
			return found;
		}
		walkingPtr = walkingPtr->nextPtr;
	}
	return found;
}
