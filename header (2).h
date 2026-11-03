#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct student
{
int rollno;
char name[20];
float percentage;
struct student *next;
}sll;

void addrecord(sll **);
void printnode(sll *);
void deleteall(sll **);
void saverecord(sll *);
void deleterecord(sll **);
int countnode(sll *);
void reverselinks(sll **);
void sortrecord(sll *);
void modifyrecord(sll **);
