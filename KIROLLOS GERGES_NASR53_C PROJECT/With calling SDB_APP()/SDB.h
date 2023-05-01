#include"STD.H"
#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED
typedef struct{

uint32 ID;
uint32 student_year;
uint32 course_ID[3];
uint32 grades[3];
struct students *next;

}students;

students *head=NULL;
bool SDB_isfull(void);
uint32 SDB_getusedsize(void);
void add_entry(void);
void deleted_entry();
void read_entry();
void get_list_ID(void);
bool SDB_is_ID_exist(uint32 Ident);
void SDB_APP ();
void SDB_action (uint8 choice);





#endif // SDB_H_INCLUDED
