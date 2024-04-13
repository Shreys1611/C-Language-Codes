/*#include<stdio.h>
#include<stdlib.h>
#define LIST_SIZE 30
void main()
{
    int *element=NULL;
    int ch,i,j,n;
    int insdata,deldata,moddata,found;
    int top=-1;
    element=(int*)malloc(sizeof(int)* LIST_SIZE);
    while(1)
    {
        fflush(stdin);
        printf("\nBasic Operations in a List: \n\n");
        printf("1.Create New List \n2.Modify List \n3.View List \n");
        printf("4.Insert First \n5.Insert Last \n6.Insert Middle \n");
        printf("7.Delete First \n8.Delete Last \n9.Delete Middle \n\n");
        printf("Enter the Choice 1 to 10: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            top=-1;
            printf("\nEnter the Number of Elements: ");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                printf("\n Enter The Element [%d]: ",(i+1));
                scanf("%d",&element[++top]);
            }
            break;
            case 2:
            if(top==-1)
            {
                printf("\n Linear List is Empty.");
                break;
            }
            printf("\n Enter the Element for Modification: ");
            scanf("%d",&moddata);
            found=0;
            for(i=0;i<=top;i++)
            {
                if(element[i]==moddata)
                {
                    found=1;
                    printf("\n Enter The New Element: ");
                    scanf("%d",&element[i]);
                    break;
                }
            }
            if(found==0)
            {
                printf("\n Element %d not found.",moddata);
                break;
            }
            case 3:
            if(top==-1)
            {
                printf("\n \n List is Empty.");
            }
            else if(top==LIST_SIZE -1)
            {
                printf("\n List is Full:");
                for(i=0;i<=top;i++){
                    printf("\n Element[%d]is-->%d",(i+1),element[i]);
                }
                break;
            }
            case 4:
            if(top==LIST_SIZE-1)
            {
                printf("\n List is Full.");
                break;
            }
            top++;
            for(i=top;i>0;i--)
            {
                element[i]=element[i-1];
                printf("\n Enter the Element: ");
                scanf("%d",&element[0]);
            }
            break;
            case 5:
            if(top==LIST_SIZE-1)
            {
                printf("\n List is Full.");
                break;
            }
            printf("\n Enter the Element: ");
            scanf("%d",&element[++top]);
            break;
            case 6:
            if(top==LIST_SIZE-1)
            {
                printf("\n List is Full.");
            }
            else if(top==-1)
            {
                printf("\n List is Empty.");
            }
            else
            {
                found=0;
                printf("\n Enter the Element after which the insertion is to be made: ");
                scanf("%d",&insdata);
                for(i=0;i<=top;i++){
                    if(element[i]==insdata)
                    {
                        found=1;
                        top++;
                        for(j=top;j>i;j--)
                        {
                            element[j]=element[j-1];
                            printf("\n Enter the Element: ");
                            scanf("%d",&element[i+1]);
                        }
                        break;
                    }
                    if(found==0)
                    {
                        printf("\n Element %d Not Found",insdata);
                    }
                }
            }
            break;
            case 7:
            if(top==-1)
            {
                printf("\n Linear List is Empty.");
                break;
            }
            printf("\n Deleted Data-->Element :%d",element[0]);
            top--;
            for(i=0;i<=top;i++)
            {
                element[i]=element[i+1];
            }
            break;
            case 8:
            if(top==-1)
            {
                printf("\n Linear List is Empty.");
            }
            else
            {
                printf("\n Deleted Data-->Element :%d",element[top--]);
                break;
            }
            case 9:
            if(top==-1)
            {
                printf("\n Linear List is Empty.");
                break;
            }
            printf("\n Enter the Element for Deletion: ");
            scanf("%d",&deldata);
            found=0;
            for(i=0;i<=top;i++)
            {
                if(element[i]==deldata)
                {
                    found=1;
                    printf("\n Deleted data-->Element: %d",element[i]);
                    top--;
                    for(j=i;j<=top;j++)
                    {
                        element[j]=element[j+1];
                    }
                    break;
                }
                if(found==0)
                {
                    printf("\n Element %d Not Found.",deldata);
                    break;
                }
            }
            default: 
            free(element);
            printf("\n End Of The Program.");
            exit(0);
        }
    }
}*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct
{
    int list[MAX];
    int element;     
    int pos;           
    int length;     
}l;
enum boolean
{
    true, false
};
typedef enum boolean boolean;        

int menu(void);           
void create(void);       
void insert(int, int);    
void delet(int);       
void find(int);        
void display(void);       
boolean islistfull(void);  
boolean islistempty(void);        

void main()
{
    int ch;
    int element;
    int pos;
    l.length = 0;
    while(1)
    {
        ch = menu();
        switch (ch)
        {
             case 1:   l.length = 0;
             create();
             break;
             case 2:
             if (islistfull() != true)
             {
                  printf("Enter New element: ");
                  scanf("%d", &element);
                  printf("Enter the Position : ");
                  scanf("%d", &pos);
                  insert(element, pos);
             }
             else
             {
                  printf("List is Full. Cannot insert the element");
                  printf("\nPress any key to continue.\n");
             }
             break;
             case 3:
             if (islistempty() != true)
             {
                  printf("Enter the position of element to be deleted: ");
                  scanf("%d", &pos);
                  delet(pos);
             }
             else
             {
                  printf("List is Empty.");
                  printf("\nPress any key to continue.\n");
             }
             break;
             case 4:
             printf("No of elements in the list is %d", l.length);
             printf("\nPress any key to continue.\n");
             break;
             case 5:
             printf("Enter the element to be searched: ");
             scanf("%d", &element);
             find(element);
             break;
             case 6:
             display();
             break;
             case 7:
             printf("End Of Program.");
             exit(0);
             break;
             default:  printf("Invalid Choice");
             printf("\nPress any key to continue.\n");
        }
    }
}        
int menu()
{
    int ch;
    printf("1. Create List\n2. Insert Element\n3. Delete Element\n4. Count Element\n5. Find Element\n6. Display List\n7. Exit\n\nEnter your choice: ");
    scanf("%d", &ch);
    printf("\n\n");
    return ch;
}      
void create(void)
{
    int element;
    int flag=1;
    while(flag==1)
    {
        printf("Enter element : ");
        scanf("%d", &element);
        l.list[l.length] = element;
        l.length++;
        printf("To insert another element press '1' : ");
        scanf("%d", &flag);
    }
}     
void display(void)
{
    int i;
    for (i=0; i<l.length; i++)
        printf("Element %d : %d \n", i+1, l.list[i]);
    printf("Press any key to continue.\n");
}  
void insert(int element, int pos)
{
    int i;
    if (pos == 0)
    {
        printf("\nCannot insert an element at 0th position\n");
        return;
    }

    if (pos-1 > l.length)
    {
        printf("\nOnly %d elements exit. Cannot insert at %d position", l.length, pos);
        printf("\nPress any key to continue.\n");
    }
    else
    {
        for (i=l.length; i>=pos-1; i--)
        {
            l.list[i+1] = l.list[i];
        }
        l.list[pos-1] = element;
        l.length++;
    }
}     
void delet(int pos)
{
    int i;
    if(pos == 0)
    {
        printf("\nCannot delete at an element 0th position");
        return;
    }
    if (pos > l.length)
    {
        printf("\n\n Only %d elements exit. Cannot delete", l.length, pos);
        printf("\nPress any key to continue.\n");
        return;
    }
    for (i=pos-1; i<l.length; i++)
    {
        l.list[i] = l.list[i+1];
    }
    l.length--;
}      

void find(int element)
{
    int i;
    int flag = 1;

    for (i=0; i<l.length; i++)
    {
        if(l.list[i] == element)
        {
            printf ("%d exists at %d position",element, i+1);
            flag = 0;
            printf("\nPress any key to continue.\n");
            break;
        }
    }
    if(flag == 1)
    {
        printf("Element not found.\nPress any key to continue.\n");
    }
}  
boolean islistfull(void)
{
    if (l.length == MAX)
        return true;
    else
        return false;
}   
boolean islistempty(void)
{
    if (l.length == 0)
        return true;
    else
        return false;
}