#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"SDB.h"
#include "STD.h"
extern int count=0;
 bool SDB_IsFull ()//if bool is full or not
{
if(count>=10)  // maximum student is 10 students
    {
    return true;
}
else

    return false;
}

 uint8 SDB_GetUsedSize()//get used size
{
return printf("The Number of entries: %d\n",count);
}

  bool SDB_AddEntry()//user chooses to add entry this function asks him for required data
{
student *node=NULL;
node=(student*)malloc(sizeof(student));

if(count==10)
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
head=node;
count++;
printf(" The new entry is successfully added \n");
printf("\n");
}

  Void SDB_DeletEntry () //deleting student data
{
	int deleted_ID;
	printf("Enter the id that you want to delete its data\n");
	fflush(stdin);
	scanf("%d",&deleted_ID);
student * delete_node=NULL;
student * current_ptr=NULL;
student * previos_ptr=NULL;


if (head==NULL){
	printf("the list is empty ");
	return;
}
current_ptr=head;
if (current_ptr->ID==deleted_ID){
	delete_node=head;
	head=current_ptr->next;
	free(delete_node);
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
		printf("The entry deleted successfully \n");
		counter--;
		return;
	}
	previos_ptr=current_ptr;
	current_ptr=current_ptr->next;
}

}

bool SDB_ReadEntry ()

{
    int read_ID;
    printf("enter the Student ID: ");
    fflush(stdin);
    scanf("%d",&read_ID);
    students *temp=head;
    while(temp!=NULL)
    {
      if(temp->ID == read_ID)
      {
          printf("student id is %d \n",temp->ID);
printf("student year is %d \n",temp->student_year);
printf("course 1 id is %d \n",temp->course_ID[0]);
printf("course 2 id is %d \n",temp->course_ID[1]);
printf("course 3 id is %d \n",temp->course_ID[2]);
printf("course 1 grade is %d \n",temp-> grades[0]);
printf("course 2 grade is %d \n",temp-> grades[1]);
printf("course 3 grade is %d \n",temp-> grades[2]);
return 1;
      }

      else
        {
    printf("no data to find\n");
    return 0;
}
temp=temp->next;
    }
}



  void SDB_GetList (uint8 * count, uint32 * list) //Get list function
{
student* temp = head;
printf("Student IDs List:\n");
while(temp!=NULL){
        list=ID;
printf("%d\n",temp->list);
temp=temp->next;
}
}

bool SDB_IsIdExist (uint32 id)  //checking for ID is exist or not
{

student* temp=head;

while(temp!=NULL){
   if(temp->id==Ident)
    {

     return 1;
    }
    else
    {

     return 0;
    }
temp=temp->next;
}
return 0;
}













void main(){
uint32 your_choice;
uint32 x,y,z,Z,ID;
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


x=SDB_IsFull ();
if(x==1)
    printf("DATABASE IS FULL\n");

fflush(stdin);
printf("Choice: ");
scanf("%d",&your_choice);

switch (your_choice)
{case 0:
    printf("Thank for using Database student program ,Goodbye");
            return 0;
            break;
	case 1:
	SDB_AddEntry();

	break;
	case 2:
    SDB_GetUsedSize();
	break;
	case 3:
	SDB_ReadEntry();//badl 2lread delw2ti
	break;
	case 4:
    SDB_GetList ());
    break;
    case 5:
        printf("Please enter student ID to check: ");
        fflush(stdin);
        scanf("%d",&ID);
        z=SDB_IsIdExist ();
        if(z==1)
            printf("the ID %d is Exist\n",ID);
        else if(z==0)
            printf("the ID %d is Not Exist\n",ID);
    break;
    	case 6:
SDB_DeletEntry ();
break;
        case 7:
           Z=  SDB_IsFull();
if(Z==true)
{
    printf("The database is full\n");
}
else if(Z==false)
{
    printf("The database is not full\n");
}
            break;
             default:
	printf("Invalid choice!!!!!!\nplease choose from 0 to 7\n");
	break;

}
    }

}
