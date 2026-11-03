#include"header.h"
int main()
{
        sll *headptr=0;
        char ch;
        while(1)
        {
                printf("*******student record menu ***********\n");
                printf("a/A:add new record\n");
                printf("d/D:delete a record\n");
                printf("s/S:show the list\n");
                printf("m/M:modify a record\n");
                printf("v/V:save record\n");
                printf("e/E:exit\n");
                printf("t/T:sort the list\n");
                printf("l/L:delete all the records\n");
                printf("r/R:reverse the list\n");
                printf("***************************************\n");
                scanf(" %c",&ch);
                switch(ch)
                {
                        case 'a':addrecord(&headptr);break;
                        case 's':printnode(headptr);break;
                        case 'l':deleteall(&headptr);break;
                        case 'v':saverecord(headptr);break;
                        case 'd':deleterecord(&headptr);break;
                        case 'r':reverselinks(&headptr);break;
                        case 't':sortrecord(headptr);break;
                        case 'm':modifyrecord(&headptr);break;
                        case 'e':exit(0);
                }
        }
}

void modifyrecord(sll **p)
{
        if(*p==0)
        {
                printf("no records available\n");
                return ;
        }
        sll *ptr=*p;
        char ch;
        printf("r/R:search by rollno\n");
        printf("n/N:search by name\n");
        printf("p/P:search by percentage\n");
        printf("enter option to search:");
        scanf(" %c",&ch);

        if(ch=='r' || ch=='R')
        {
                int n,f=0;
                printf("enter rollno to search:");
                scanf("%d",&n);
                char nn[20];
                float per;
                while(ptr)
                {
                        if(n==ptr->rollno)
                        {
                                f=1;
                                printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                                printf("enter new name and new percentage:");
                                scanf(" %s %f",nn,&per);
                                ptr->rollno=ptr->rollno;
                                strcpy(ptr->name,nn);
                                ptr->percentage=per;
                                break;
                        }
                        ptr=ptr->next;
                }
                if(f==0)
                        printf("rollno not found\n");
        }
        else if(ch=='n' || ch=='N')
        {
                char s[20];
                int f=0,c=0;
                sll *p1=ptr;
                printf("enetr name to search:");
                scanf(" %s",s);
                int d_r;
                while(p1)
                {
                        if(strcmp(s,p1->name)==0)
                        {
                                f=1;
                                d_r=p1->rollno;
                                c++;
                                printf("%d %s %f\n",p1->rollno,p1->name,p1->percentage);
                        }
                        p1=p1->next;
                }
                int n1;
                ptr=*p;
                if(c==1)
                        goto l;
                if(c>1)
                {
                        printf("enetr rollno to modify:");
                        scanf("%d",&n1);
l:
                        if(c==1)
                                n1=d_r;
                        while(ptr)
                        {
                                if(n1==ptr->rollno)
                                {
                                        char s2[20];
                                        float percent;
                                        printf("enter name and percentage to modify:");
                                        scanf(" %s%f",s2,&percent);
                                        ptr->rollno=ptr->rollno;
                                        strcpy(ptr->name,s2);
                                        ptr->percentage=percent;
                                }
                                ptr=ptr->next;
                        }
                }
                if(f==0)
                        printf("name not found\n");
        }
        else if(ch=='p' || ch=='P')
        {
                int f=0,c,d1_r;
                float f1;
                printf("enter percentge:");
                scanf("%f",&f1);
                while(ptr)
                {
                        if(f1==ptr->percentage)
                        {
                                f=1;c++;
                                d1_r=ptr->rollno;
                                printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                        }
                        ptr=ptr->next;
                }
                ptr=*p;
                int n3;
                if(c==1)
                        goto l1;
                if(c>1)
                {
                        printf("enter rollno to search:");
                        scanf("%d",&n3);
l1:
                        if(c==1)
                                n3=d1_r;
                        while(ptr)
                        {
                                if(n3==ptr->rollno)
                                {
                                        char s3[20];
                                        float p3;
                                        printf("enter name and percentage to modify:");
                                        scanf(" %s%f",s3,&p3);
                                        ptr->rollno=ptr->rollno;
                                        strcpy(ptr->name,s3);
                                        ptr->percentage=p3;
                                }
                                ptr=ptr->next;
                        }
                }
                if(f==0)
                        printf("percentage not found\n");
        }
}

void sortrecord(sll *ptr)
{
        if(ptr==0)
        {
                printf("no records available\n");
                return ;
        }
        sll *p1,*p2,t;
        p1=ptr;
        int i,j,c=countnode(ptr);
        char ch;
        printf("n/N:sort with name\n");
        printf("p/P:sort with percentage\n");
        printf("enter option to sort:");
        scanf(" %c",&ch);
        if(ch=='n' || ch=='N')
        {
                for(i=0;i<c-1;i++)
                {
                        p2=p1->next;
                        for(j=0;j<c-1-i;j++)
                        {
                                if(strcmp(p1->name,p2->name)>0)
                                {
                                        t.rollno=p1->rollno;
                                        strcpy(t.name,p1->name);
                                        t.percentage=p1->percentage;

                                        p1->rollno=p2->rollno;
                                        strcpy(p1->name,p2->name);
                                        p1->percentage=p2->percentage;

                                        p2->rollno=t.rollno;
                                        strcpy(p2->name,t.name);
                                        p2->percentage=t.percentage;
                                }
                                p2=p2->next;
                        }
                        p1=p1->next;
                }
        }
        else if(ch=='p' || ch=='P')
        {
                for(i=0;i<c-1;i++)
                {
                        p2=p1->next;
                        for(j=0;j<c-1-i;j++)
                        {
                                if(p1->percentage > p2->percentage)
                                {
                                        t.rollno=p1->rollno;
                                        strcpy(t.name,p1->name);
                                        t.percentage=p1->percentage;

                                        p1->rollno=p2->rollno;
                                        strcpy(p1->name,p2->name);
                                        p1->percentage=p2->percentage;

                                        p2->rollno=t.rollno;
                                        strcpy(p2->name,t.name);
                                        p2->percentage=t.percentage;
                                }
                                p2=p2->next;
                        }
                        p1=p1->next;
                }
        }
}


int countnode(sll *ptr)
{
        if(ptr==0)
        {
                printf("no record found\n");
                return 0 ;
        }
        int c=0;
        while(ptr)
        {
                c++;
                ptr=ptr->next;
        }
        return c;
}


void reverselinks(sll **ptr)
{

        if(*ptr==0)
        {
                printf("no record found\n");
                return ;
        }

        int i,c=countnode(*ptr);
        sll **a,*t=*ptr;
        if(c>1)
        {
                a=malloc(sizeof(sll *)*c);
                for(i=0;i<c;i++)
                {
                        a[i]=t;
                        t=t->next;
                }
                for(i=c-1;i>0;i--)
                        a[i]->next=a[i-1];

                a[0]->next=0;
                *ptr=a[c-1];
        }
}

void deleterecord(sll **ptr)
{
        if(*ptr==0)
        {
                printf("no records available\n");
                return ;
        }
        char ch;
        printf("r/R:rollno delete\n");
        printf("n/N:name delete\n");
        printf("enter option to delete:");
        scanf(" %c",&ch);
        int n;
        char name[20];
        if(ch=='r' || ch=='R')
        {
                printf("enter roll number to delete:");
                scanf("%d",&n);

                sll *del,*prev;
                del=*ptr;
                while(del)
                {
                        if(n==del->rollno)
                        {
                                if(del==*ptr)
                                        *ptr=del->next;
                                else
                                        prev->next=del->next;

                                free(del);
                                return ;
                        }
                        prev=del;
                        del=del->next;
                }
                printf("roll number not found\n");
        }
        else if(ch=='n' || ch=='N')
        {
                printf("enter name to delete:");
                scanf("%s",name);
                sll *del,*prev;
                del=*ptr;
                int found=0;
                int c=0;
                while(del)
                {
                        if(strcmp(name,del->name)==0)
                        {
                                printf("%d %s %f\n",del->rollno,del->name,del->percentage);
                                c++;
                        }
                        del=del->next;
                }
                if(c==0)
                        printf("name not found\n");
                else
                {
                        int roll;
                        if(c>1)
                        {
                                printf("enter rollno:");
                                scanf("%d",&roll);
                        }
                        else
                        {
                                del=*ptr;
                                while(del)
                                {
                                        if(strcmp(name,del->name)==0)
                                        {
                                                roll=del->rollno;
                                                break;
                                        }
                                        del=del->next;
                                }
                        }
                        del=*ptr;
                        sll *prev=NULL;
                        while(del)
                        {
                                if((strcmp(name,del->name)==0)&& (roll== del->rollno))
                                {
                                        if(del==*ptr)
                                        {
                                                *ptr=del->next;
                                        }
                                        else
                                        {
                                                prev->next=del->next;
                                        }
                                        free(del);
                                        break;
                                }
                                prev=del;
                                del=del->next;
                        }

                }
        }
}
void printnode(sll *ptr)
{
        if(ptr==0)
        {
                printf("no records available\n");
                return ;
        }
        while(ptr)
        {
                printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                ptr=ptr->next;
        }
}

void saverecord(sll *ptr)
{
        if(ptr==0)
        {
                printf("no records available\n");
                return ;
        }
        FILE *fp;
        fp=fopen("student.txt","w");
        while(ptr)
        {
                fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
                ptr=ptr->next;
        }
        printf("data saved successfully\n");
        fclose(fp);
}

void addrecord(sll **ptr)
{
        sll *new,*temp;
        int roll=1;
        int found;
        new=malloc(sizeof(sll));
        while(1)
        {
                found=0;
                temp=*ptr;
                while(temp)
                {
                        if(temp->rollno == roll)
                        {
                                found=1;
                                break;
                        }
                        temp=temp->next;
                }
                if(found==0)
                        break;

                roll++;
        }
        new->rollno=roll;
        printf("enter name and percentage:");
        scanf("%s%f",new->name,&new->percentage);


        if(*ptr==NULL)
        {
                *ptr=new;
        }
        else
        {
                temp=*ptr;
                while((temp->next!=NULL) && (new->rollno > temp->next->rollno))
                {
                        temp=temp->next;
                }
                new->next=temp->next;
                temp->next=new;
        }
}

void deleteall(sll **ptr)
{
        if(*ptr==0)
        {
                printf("no records available\n");
                return ;
        }
        int c=1;
        sll *del;
        del=*ptr;
        while(del)
        {
                *ptr=del->next;
                printf("node deleted:%d\n",c++);
                sleep(1);
                free(del);
                del=*ptr;
        }
        printf("all nodes deleted\n");
}