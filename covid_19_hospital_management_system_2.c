#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<process.h>

#include<stdlib.h>

#include<dos.h>

struct contact

{

    long ph;

    char name[20],add[20],email[30],result[15];

    int age;

} list;

char query[20],name[20];

FILE *fp, *ft;

int i,n,ch,l,found;

time_t t;

int main()

{

main:

    time(&t);

    system("cls");

    printf("\n\t **** Welcome to COVID-19 Hospital Management System ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Member\n\t\t[2] List all Member\n\t\t[3] Search for a Member\n\t\t[4] Edit a Member\n\t\t[5] Delete a Member\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");

    scanf("%d",&ch);

    switch(ch)

    {

    case 0:

        printf("\n\n\t\tDo You Really Want To Exit?");

        break;

    case 1:

        system("cls");

        fp=fopen("contact.dll","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the name input\nName:");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)

                break;

            printf("Age: ");

            scanf("%d",&list.age);

            fflush(stdin);

            printf("Phone:");

            scanf("%ld",&list.ph);

            fflush(stdin);

            printf("address:");

            scanf("%[^\n]",&list.add);

            fflush(stdin);

            printf("email address:");

            gets(list.email);

            fflush(stdin);

            printf("COVID-19 Test Result:");

            scanf("%[^\n]",&list.result);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);

        break;

    case 2:

        system("cls");

        printf("\n\t\t================================\n\t\t\tLIST OF MEMBER\n\t\t================================\n\nName\t\tAge\t\tPhone No\t    Address\t\tE-mail\t\tCOVID-19 Test Result ad.\n====================================================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("contact.dll","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nAge\t: %d\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\nCOVID-19 Test Result: %s\n",list.name,

                           list.age,list.ph,list.add,list.email,list.result);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }

        break;

    case 3:

        system("cls");

        do

        {

            found=0;

            printf("\n\n\t..::MEMBER SEARCH\n\t===========================\n\t..::Name of Member to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("contact.dll","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                   printf("\n\t\tMedical Report By UIU APP FORUM\t\t\t\t\nDate: %s\n\n",ctime(&t));

                   printf("..::Name\t: %s\n..::Age\t\t: %d\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\nCOVID-19 Test Result\t: %s\n",list.name,list.age,list.ph,list.add,list.email,list.result);

                   printf("\nWe advice you to take care of yourself during this pandemic at least for your close ones. ThankYou!\n\n :)");
                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        break;

    case 4:

        system("cls");

        fp=fopen("contact.dll","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("..::Edit Member\n===============================\n\n\t..::Enter the name of member to edit:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Editing '%s'\n\n",name);

        printf("..::Name(Use identical):");

        scanf("%[^\n]",&list.name);

        printf("..::Age:");

        scanf("%d",&list.age);

        fflush(stdin);

        printf("..::Phone:");

        scanf("%ld",&list.ph);

        fflush(stdin);

        printf("..::address:");

        scanf("%[^\n]",&list.add);

        fflush(stdin);

        printf("..::email address:");

        gets(list.email);

        fflush(stdin);

        printf("..::COVID-19 Test Result:");

        scanf("%[^\n]",&list.result);

        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.dll");

        rename("temp.dat","contact.dll");

        break;

    case 5:

        system("cls");

        fflush(stdin);

        printf("\n\n\t..::DELETE A MEMBER\n\t==========================\n\t..::Enter the name of member to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("contact.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.dll");

        rename("temp.dat","contact.dll");

        break;

    default:

        printf("Invalid choice");

        break;

    }

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    scanf("%d",&ch);

    switch (ch)

    {

    case 1:

        goto main;

    case 0:

        break;

    default:

        printf("Invalid choice");

        break;

    }

    return 0;

}

