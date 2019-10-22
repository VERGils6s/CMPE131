#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
typedef struct InComeSystem
{
 char name[8];
 char InComeWay[12];
 int HowMuch;
 struct InComeSystem* next;
}ICSystem,*ICSystem_;
typedef struct OutComeSystem
{
 char name[8];
 char OutComeWay[12];
 int HowMuch;
 struct OutComeSystem* next;
}OCSystem,*OCSystem_;
int i=0;  
ICSystem* InputNew()
{   
 ICSystem *pNewNode=NULL; 
 pNewNode=new ICSystem;
 pNewNode->next=NULL; 
 

 printf("please enter income information[name,job,balance]:\n");
 printf("=========================================");
 printf("\n name:");   scanf("%s",&pNewNode->name);          fflush(stdin);
 printf("job:");     scanf("%s",&pNewNode->InComeWay);  fflush(stdin);
 printf("balance :");     scanf("%d",&pNewNode->HowMuch);     fflush(stdin);
 printf("======================================\n"); 
 return pNewNode;
}

struct InComeSystem *creat()
{
 ICSystem *pHead=NULL;
 ICSystem *pTail=NULL; 
 ICSystem *pNewNode=NULL; 
 char comfirm;
 
 while(1)
 {
  pNewNode=new ICSystem;
  pNewNode->next=NULL; 
  
  pNewNode=InputNew();
  
  
  if (pHead==NULL)
  {  
   pHead=pTail=pNewNode;
  }
  else
  {   
   pTail->next=pNewNode;
   pTail=pNewNode; 
  }
  
  fflush(stdin);
  printf("more data?(Y/N):");
  scanf("%c",&comfirm); 
  if (comfirm=='N'||comfirm=='n')  break;  
 }
 
 
 return pHead; 
}

void OutputList(ICSystem *head)
{
 if (head==NULL) 
 {
  printf("empty data!");
  return;
 }
 
    
    printf("         income information              \n");
    printf("======================================\n");
    printf("name \t\t job\t\t balance \t\t\n");
    ICSystem *pCur=head;
    while(pCur!=NULL)
    {    
     printf("%s\t\t%s\t\t%d\t\t\n",pCur->name,pCur->InComeWay,pCur->HowMuch);
     pCur=pCur->next;
    }
    
}

ICSystem* InsertByHead(ICSystem *head,ICSystem *pNew)
{
 ICSystem *pNewHead=NULL; 
 pNew->next=head;       
 pNewHead=pNew;
 return pNewHead;  
}

ICSystem*  DeleteNode(ICSystem *head,char name[10],char way[10],int howmuch)
{
 ICSystem *pCur=head;
 ICSystem *pPre=head;
 
 ICSystem *pNewHead=head;
 while(pCur!=NULL)
 {
  if((strcmp(pCur->name,name)==0) && (strcmp(pCur->InComeWay,way)==0) && 
   ((pCur->HowMuch==howmuch)?1:0)) 
   break;  
  else
   i=0;  
  pPre=pCur;   
  pCur=pCur->next;
 }
 
 if(pCur==NULL) 
 {
  printf("didn't find node");
  return head;
  i=0;  
 }
 else 
 {
  if(pCur==head) 
  { 
   pNewHead=pCur->next;
   delete pCur;
   i=1;  
  }
  else
  {
   pPre->next=pCur->next; 
  
   delete pCur; 
   i=1; 
  }
 }
 return pNewHead; 
}  

OCSystem* InputNew_()
{   
 OCSystem *pNewNode=NULL; 
 pNewNode=new OCSystem;
 pNewNode->next=NULL; 
 
 
 printf("please enter cost information[name, way,balance]:\n");
 printf("=========================================");
 printf("\n name:");   scanf("%s",&pNewNode->name);          fflush(stdin);
 printf(" way :");     scanf("%s",&pNewNode->OutComeWay);  fflush(stdin);
 printf("balance :");     scanf("%d",&pNewNode->HowMuch);     fflush(stdin);
 printf("======================================\n"); 
 return pNewNode;
}

struct OutComeSystem *creat_()
{
 OCSystem *pHead=NULL;
 OCSystem *pTail=NULL; 
 OCSystem *pNewNode=NULL; 
 char comfirm;
 
 while(1)
 {
  pNewNode=new OCSystem;
  pNewNode->next=NULL; 
  
  pNewNode=InputNew_();
  
  
  if (pHead==NULL)
  {  
   pHead=pTail=pNewNode;
  }
  else
  {  
   pTail->next=pNewNode;
   pTail=pNewNode; 
  }
  
  fflush(stdin);
  printf("more data?(Y/N):");
  scanf("%c",&comfirm); 
  if (comfirm=='N'||comfirm=='n')  break;  
 }
 
 
 return pHead; 
}

void OutputList_(OCSystem *head)
{
 if (head==NULL) 
 {
  printf("empty data!");
  return;
 }
 
   
    printf("          cost information              \n");
    printf("======================================\n");
    printf("name\t\t way\t\t balance \t\t\n");
    OCSystem *pCur=head;
    while(pCur!=NULL)
    {    
     printf("%s\t\t%s\t\t%d\t\t\n",pCur->name,pCur->OutComeWay,pCur->HowMuch);
     pCur=pCur->next;
    }
    
}

OCSystem* InsertByHead_(OCSystem *head,OCSystem *pNew)
{
 OCSystem *pNewHead=NULL; 
 pNew->next=head;       
 pNewHead=pNew;
 return pNewHead;  
}
OCSystem*  DeleteNode_(OCSystem *head,char name[10],char way[10],int howmuch)
{
 OCSystem *pCur=head;
 OCSystem *pPre=head;
 
 OCSystem *pNewHead=head;
 while(pCur!=NULL)
 {
  if((strcmp(pCur->name,name)==0) && (strcmp(pCur->OutComeWay,way)==0) && 
   ((pCur->HowMuch==howmuch)?1:0)) 
   break;  
  else
   i=0; 
  pPre=pCur;   
  pCur=pCur->next;
 }
 
 if(pCur==NULL) 
 {
  printf("didn't find node");
  return head;
  i=0;  
 }
 else 
 {
  if(pCur==head) 
  { 
   pNewHead=pCur->next;
   delete pCur;
   i=1;  
  }
  else
  {
   pPre->next=pCur->next; 
   
   delete pCur;
   i=1;  
  }
 }
 return pNewHead; 
}  

void menu(void)
{
    system("cls");
 printf("\n\t\t\t                   Dollar Dream \n");
 printf("\t\t\t|-----------------------------------------------|\n");
 printf("\t\t\t|\t                 \t                |\n");
 printf("\t\t\t|\t [1] Build income list \t                |\n");
 printf("\t\t\t|\t [3] Add income information\t        |\n");
 printf("\t\t\t|\t [5] Delate income information\t        |\n");
 printf("\t\t\t|\t [7] Display income information \t|\n");
 printf("\t\t\t|\t [0] Exit \t\t                |\n");
 printf("\t\t\t|\t                 \t                |\n");
 printf("\t\t\t|-----------------------------------------------|\n");
 printf("\t\t\t|-----------------------------------------------|\n");
 printf("\t\t\t|\t                 \t                |\n");
 printf("\t\t\t|\t [2] Build cost list \t                |\n");
 printf("\t\t\t|\t [4] Add cost information \t        |\n");
 printf("\t\t\t|\t [6] Delate cost information \t  \      |\n");
 printf("\t\t\t|\t [8] Display cost information \t        |\n");
 printf("\t\t\t|\t [0] Exit \t\t                |\n");
 printf("\t\t\t|\t                 \t                |\n");
 printf("\t\t\t|-----------------------------------------------|\n");
 printf("\t\t\t       Plese select functions(0-8):");
}
void main()
{
 int choose;
 ICSystem *phead=NULL;
 OCSystem *phead_=NULL;
 ICSystem *pNew=NULL;
 OCSystem *pNew_=NULL;
    static char name[10];
 static char name_[10];
 static  char icway[10];
 static  char icway_[10];
 static  int  money;
 static  int  money_;
 while(1)
 {
  menu();
  fflush(stdin);
  scanf("%d[0-9]",&choose);
  system("cls");
  switch(choose)
  {
  case 1: 
  
   phead=creat();   
   break; 
  case 2:
  
   phead_=creat_();   
   break; 
  case 3:
  
   pNew=InputNew();
   phead=InsertByHead(phead,pNew);
   OutputList(phead);
   printf("\n enter to continue");
   fflush(stdin);
   getch(); 
   break;
  case 4:
   
   pNew_=InputNew_();
   phead_=InsertByHead_(phead_,pNew_);
   OutputList_(phead_);
   printf("\n enter to continue");
   fflush(stdin);
   getch(); 
   break;
  case 5:
   printf("please enter name:");scanf("%s",name);
   printf("please enter way:");scanf("%s",icway);
   printf("please enter balance:");scanf("%d",&money);
   phead=DeleteNode(phead,name,icway,money);
   if(i==1)
   {
    printf("delate success\n");
    OutputList(phead);
   }
   else 
   {
    system("cls");
    printf("不存在该节点信息\n");
   }
   printf("\n按回车键回到主菜单。");
   fflush(stdin);
   getch();
   break;
  case 6:
   printf("please enter name");    scanf("%s",name_);
   printf("please enter way:");scanf("%s",icway_);
   printf("please enter balance:");scanf("%d",&money_);
   phead_=DeleteNode_(phead_,name_,icway_,money_);
   if(i==1)
   {
    printf("delate success\n");
    OutputList_(phead_);
   }
   else 
   {
    system("cls");
    printf(" didn't find node \n");
   }
   printf("\n enter to continue");
   fflush(stdin);
   getch();
   break;
  case 7:
   
   OutputList(phead);
   printf("\n enter to continue");
   fflush(stdin);
   getch();     
   break;
  case 8:

   OutputList_(phead_);
   printf("\n enter to continue");
   fflush(stdin);
   getch();     
   break;
  case 0:

   exit(1);
   break;
  default:
   printf("you enter wrong char, enter to continue。");
   getch(); 
   menu();
   fflush(stdin);
  }
 }
}

