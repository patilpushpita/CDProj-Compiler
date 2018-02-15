#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int size=0, sizeC=0;
void Display();
void DisplayC();
void insert();
int Search(char lab[]);
void insertC();
int SearchC(char labC[]);
struct SymbTab
{
 char label[30],symbol[30];
 struct SymbTab *next;
}; struct SymbTab *first,*firstC, *last, *lastC;
void insert(char l[], char s[])
{
  int n;
  n=Search(l);
  if(n==0)
   {
    struct SymbTab *p;
    p=malloc(sizeof(struct SymbTab));
    strcpy(p->label,l);
    strcpy(p->symbol,s);
    p->next=NULL;
    if(size==0)
     {
      first=p;
      last=p;
     }
    else
     {
      last->next=p;
      last=p;
     }
    size++;
   }
}
void insertC(char l[], char s[])
{
  int n;
  n=SearchC(l);
  if(n==0)
   {
    struct SymbTab *p;
    p=malloc(sizeof(struct SymbTab));
    strcpy(p->label,l);
    strcpy(p->symbol,s);
    p->next=NULL;
    if(sizeC==0)
     {
      firstC=p;
      lastC=p;
     }
    else
     {
      lastC->next=p;
      lastC=p;
     }
    sizeC++;
   }
}
int Search(char lab[])
{
 int i, flag=0;
 struct SymbTab *p;
 p=first;
  for(i=0;i<size;i++)
   {
    if(strcmp(p->label,lab)==0)
     flag=1;
    p=p->next;
   }
 return flag;
}
int SearchC(char lab[])
{
 int i, flag=0;
 struct SymbTab *p;
 p=firstC;
  for(i=0;i<sizeC;i++)
   {
    if(strcmp(p->label,lab)==0)
     flag=1;
    p=p->next;
   }
 return flag;
}
void Display()
{
  int i;
  struct SymbTab *p;
  p=first;
  printf("\n\tLABEL\t\t\tSYMBOL\n");
  for(i=0;i<size;i++)
   {
    printf("\t%s\t\t\t%s\n",p->label,p->symbol);
    p=p->next;
   }
}
void DisplayC()
{
  int i;
  struct SymbTab *p;
  p=firstC;
  printf("\n\tCONSTANT\t\tSYMBOL\n");
  for(i=0;i<sizeC;i++)
   {
    printf("\t%s\t\t%s\n",p->label,p->symbol);
    p=p->next;
   }
}
