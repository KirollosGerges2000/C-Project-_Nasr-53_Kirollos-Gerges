#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"SDB.h"
#include "STD.h"
void SDB_action (uint8 choice); //initialization on prototype
 uint32 counter=0;
uint32 x,y,z,ID;
bool SDB_isfull(void) //if bool is full or not
{
if(counter>=10)  // maximum student is 10 students
    {

    return true;
}
else
    return false;
}

uint32 SDB_getusedsize(void) //get how many students in your database have added

{
return printf("The Number of entries: %d\n",counter);
}

void add_entry(void)  //user chooses to add entry this function asks him for required data
{
students *node=NULL;
node=(students*)malloc(sizeof(students));

if(counter==10)
{
printf(" The list is completed \n");
    return;
}

printf("Enter the student ID: \n");
fflush(stdin);
scanf("%d",&node->ID);
printf("Enter the student year:\n");
fflush(stdin);
scanf("%d",&node->student_year);
printf("Enter the student course(1) ID:\n");
fflush(stdin);
scanf("%d",&node->course_ID[0]);
printf("Enter the student course(1) grade: \n");
fflush(stdin);
scanf("%d",&node->grades[0]);
printf("Enter the student course(2) ID: \n");
fflush(stdin);
scanf("%d",&node->course_ID[1]);
printf("Enter the student course(2) grade: \n");
fflush(stdin);
scanf("%d",&node->grades[1]);
printf("Enter the student course(3) ID:\n");
fflush(stdin);
scanf("%d",&node->course_ID[2]);
printf("Enter the student course(3) grade:\n");
fflush(stdin);
scanf("%d",&node->grades[2]);

node->next=head;
uint32 head=node;
counter++;
printf(" The new entry is successfully added \n");
printf("\n");
}

void deleted_entry() //to delete data
{
	int deleted_ID;
	printf("Enter the ID to delete the its data: \n");
	fflush(stdin);
	scanf("%d",&deleted_ID);
students * delete_node=NULL;
students * current_ptr=NULL;
students * previos_ptr=NULL;


if (head==NULL){
	printf("the list is empty ");
	return;
}
current_ptr=head;
if (current_ptr->ID==deleted_ID){
	delete_node=head;
	head=current_ptr->next;
	free(delete_node);
	printf("The required data is deleted successfully \n");
	counter--;
	return;
}

current_ptr=current_ptr->next;
previos_ptr=head;
while (current_ptr!=NULL){
	if (current_ptr->ID==deleted_ID){
		delete_node=current_ptr;
		previos_ptr->next=current_ptr->next;
		free(delete_node);
		printf(" The required data is deleted successfully \n");
		counter--;
		return;
	}
	previos_ptr=current_ptr;
	current_ptr=current_ptr->next;
}


}

void read_entry()  //print the data of the user by searching on his data by the given id

{
    uint32 read_ID;
    printf("Enter the required ID: ");
    fflush(stdin);
    scanf("%d",&read_ID);
    students *temp=head;

while(temp!=NULL){
printf("student id is %d \n",temp->ID);
printf("student year is %d \n",temp->student_year);
printf("course 1 id is %d \n",temp->course_ID[0]);
printf("course 2 id is %d \n",temp->course_ID[1]);
printf("course 3 id is %d \n",temp->course_ID[2]);
printf("course 1 grade is %d \n",temp-> grades[0]);
printf("course 2 grade is %d \n",temp-> grades[1]);
printf("course 3 grade is %d \n",temp-> grades[2]);

temp=temp->next;

}
}



void get_list_ID(void)  //Get list function
{
students* temp = head;
printf("Student IDs List:\t");

while(temp!=NULL){
printf("%d",temp->ID);
temp=temp->next;
}
}

bool SDB_is_ID_exist(uint32 Ident)  //checking for ID is exist or not
{

students* temp=head;

while(temp!=NULL){
   if(temp->ID==Ident)
    {
     return 1;
    }
temp=temp->next;
}
return 0;
}
void SDB_APP ()   //The function that will be call in the main
{

    while (1)
        {
        printf("\n______________________________________________________");
printf("\nC Project for Gp Nasr53\n");
printf("Author:Eng/Kirollos Gerges Asaad\n");
printf("\n");
printf("Simple Database For Students\n");
printf("\n");
printf(" a)Enter '1' to add new student data\n");
printf("  b)Enter '2' to get used size in data base\n");
printf("   c)Enter '3' to read student data\n");
printf("     d)Enter '4' to Get List of IDs\n");
printf("       e) Enter '5' to check about these ID Exists or not\n");
printf("         f)Enter '6' to delete student data\n");
printf("           g)Enter '7' to check is database is full or not\n");
printf("            h)Enter '0' to  Exit the program\n");
printf("\n");
printf("\n");

        }

    return 0;
}

void SDB_action (uint8 choice)  //the process that controlled the choice of user
{
x=SDB_isfull();
if(x==1)
    printf("DATABASE IS FULL\n");

fflush(stdin);
printf("Choice: ");
scanf("%d",&choice);

switch (choice)
{case 0:
    printf("Thank you for using my program\n");
            return 0;
            break;
	case 1:
	add_entry();
	break;
	case 2:
    SDB_getusedsize();
	break;
	case 3:
	read_entry();  //badl 2lread delw2ti
	break;
	case 4:
    get_list_ID();
    break;
    case 5:
        printf("Please enter student ID to check: ");
        fflush(stdin);
        scanf("%d",&ID);
        z=SDB_is_ID_exist(ID);
        if(z==1)
            printf("the ID %d is Exist\n",ID);
        else if(z==0)
            printf("the ID %d is Not Exist\n",ID);
    break;
    	case 6:
deleted_entry();
break;
        case 7:
            SDB_isfull();
            break;
             default:
	printf("Invalid choice!!!!!!\nplease choose from 0 to 7\n");
	break;
return choice;
}
}








