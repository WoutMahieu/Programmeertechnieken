/*
 * RFID.h
 *
 *  Created on: 12 okt. 2020
 *      Author: Lowie Lameire
 */

#ifndef RFID_H_
#define RFID_H_

#include "LPC17xx.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "UART.h"
#include "LinkedList.h"
#include "StatusLED.h"

#define SIZEOF_TAG_CHECKSUM 12
#define SIZEOF_TAG_ID 10

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Initialize hardware for the RFID reader
*/
void RFID_Init(void);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Sets a boolean that is checked in RFID_LockHandler.
* 0 = check if tag is valid and the lock accordingly
* 1 = add the tag that is shown to the list of valid tags
* 2 = delete the tag that is shown from the list of valid tags
*/
void RFID_SetMode(int);

/*
* Returns the value of the variable "boolRFID"
* 1 = tag is valid
* 0 = tag is invalid
* @return  boolean: 0 or 1
*/
int RFID_GetBool(void);

/*
* Returns the value of the variable "falseTries"
* @return  the number of times an invalid tag has been read
*/
int RFID_GetFalseTries(void);

/*
* Sets the value of the variable "falseTries", this function is used to reset the number of times an invalid tag was read
*/
void RFID_SetFalseTries(int);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Gets rid of the unneeded data that is received via UART (STX, ETX, CR, LF)
* @param rawData  raw data that is received via UART (ASCII format)
* @return  a string that only contains the TAGID and the accompanied CHECKSUM (ASCII format)
*/
const char* RFID_GetTagAndCheckSumData(const char * rawData);

/*
* Converts the string that contains the TAGID and its CHECKSUM form ASCII to HEX
* @param asciiData  string that contains the TAGID and CHECKSUM (ASCII format)
* @return  a string of HEX data that represents the TAGID and its CHECKSUM
*/
const char* RFID_ConvertASCIIHEX(const char * asciiData);

/*
* Converts the string that contains the TAGID and its CHECKSUM form ASCII to HEX
* @param hexData  a string of HEX data that represents the TAGID and its CHECKSUM
* @return  boolean: 0 if checksum wasn't correct, 1 if it was
*/
int RFID_CheckSum(const char * hexData);

/*
* Gets rid of the checksum, in this way the returned string represents the TAGID of the RFID tag that was read
* @param tagAndChecksum  string that contains the TAGID and CHECKSUM (ASCII format)
* @return  a string that only contains the TAGID (ASCII format)
*/
const char* RFID_GetTagID(const char * tagAndChecksum);

/*
* Receives the raw UART data and then calls the following function in this order
* RFID_GetTagAndCheckSumData
* RFID_ConvertASCIIHEX
* RFID_CheckSum
* RFID_GetTagID
* The end product is a clean TAGID that is saved in the variable "tagID" if the UART data was valid and the checksum was correct, if not tagID is set empty
*/
void RFID_DataHandler(void);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* This function gets called when an interrupt is caused by the RFID reader, it calls RFID_DataHandler to read and process the UART data
* On the basis of the value of the variable "mode" the tag is checked if valid, added the the list of valid tags or deleted from the list of valid tags
*/
void RFID_LockHandler(void);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* This function calls the function LinkedL_Push to add the parameter tagID to the list of valid tags
* @param tagID  string that contains the TAGID (ASCII format)
*/
void RFID_AddTagLL(const char * tagID);

/*
* This function calls the function LinkedL_Delete to delete the parameter tagID from the list of valid tags
* @param tagID  string that contains the TAGID (ASCII format)
*/
void RFID_DeleteTagLL(const char * tagID);

/*
* This function calls the function LinkedL_Contains to check if the parameter tagID is in the list of valid tags
* @param tagID  string that contains the TAGID (ASCII format)
* @return  boolean: 0 if the TADID wasn't in the list, 1 if it was
*/
int RFID_ContainsTagLL(const char * tagID);

/*
* This function calls the function LinkedL_PrintList, it prints each entry of the list to the console
* Used for debugging purposes
*/
void RFID_PrintLL(void);

/*
* Return the list of valid tags
* @return  pointer to the first element of the list with valid tags
*/
LinkedList_t* RFID_GetLL(void);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif /* RFID_H_ */
