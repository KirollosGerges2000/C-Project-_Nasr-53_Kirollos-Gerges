#include "STD.h"
#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED

typedef struct{

uint32 ID;
uint32 student_year;
uint32 course_ID[3];
uint32 grades[3];


}student;
struct student *next;
student *head=NULL;
bool SDB_IsFull ();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeletEntry (uint32 ID);
bool SDB_ReadEntry (uint32 id);
void SDB_GetList (uint8 * count, uint32 * list);
bool SDB_IsIdExist (uint32 id);
#endif
