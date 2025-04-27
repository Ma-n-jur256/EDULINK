#include<stdio.h>
#include<string.h>

typedef struct
{
    char Name[35];
    char Student_ID[25];
    int Semester;
}st;

typedef struct
{
    char Subject[20];
    char Title[50];
    char Author[40];
    char Condition[15];
    char Availability[15];
    char Book_Owner_ID[25];
    int Semester;
}book;

void Reg_Student();
void Log_In(char Student_ID[25]);
void Book_Menu();
void Book_Searching();
void Book_List_Option();


void Reg_Student()
{
    st S;
    printf("Enter Name: ");
    scanf("%s", &S.Name);
    printf("Enter ID: ");
    scanf("%s", &S.Student_ID);
    printf("Enter Semester: ");
    scanf("%d", &S.Semester);

    FILE *file = fopen("Students_Information.txt", "a");
    if(file == NULL)
    {
        printf("ERROR 404! Failed to save your information. Please try again. :( ");
    }
    else
    {
        fprintf(file, "%s %s %d\n", S.Name, S.Student_ID, S.Semester);
        fclose(file);
        printf("  **Your Information Stored Carefully.**\n");
        printf(">>>>> Congo! Registration Completed. <<<<<\n");
    }
}
void Log_In(char Student_ID[25])
{
    FILE *file = fopen("Students_Information.txt", "r");
    st S;
    int f = 0;

    if(file == NULL)
    {
        printf("     Some Error Occurred. :( \n \t --->>>> Please Try Again...  :)  \n");
        return;
    }

    while (fscanf(file,"%s %s %d", S.Name, S.Student_ID, &S.Semester) != EOF)
        {
            if(strcmp(S.Student_ID, Student_ID) == 0)
                {
                    f = 1;
                }
        }
    fclose(file);

    if(f == 1)
    {
        printf("    -->> Log In Successful.\n\n");
        Book_Menu(Student_ID);
    }
    else
    {
        printf("    --->>> Log In FAILED! \n       --->> Please confirm your registration.\n");
    }
}

void Book_Menu(char Student_ID[25])
{
  book B;
  int b;
  printf("       ##Book Menu -> \n");
  printf("1) Add a book to the list.\n");
  printf("2) Search a book from the list.\n");
  printf("3) Exit.\n");
  printf("\n  -->> Select an option: ");
  scanf("%d", &b);
  switch (b)
  {
  case 1:
      Book_List_Option(Student_ID);
    break;
  case 2:
    break;
  case 3:
      printf("Successfully Exited.\n");
      return;
  default:
      printf("ERROR 404! Please choose correctly.\n");
  }

}

void Book_List_Option(char Student_ID[25])
{
    book B;
    printf("Subject: ");
    scanf("%s", &B.Subject);
    printf("\nEnter the Title of the BOOK: ");
    scanf("%s", &B.Title);
    printf("Enter the Author: ");
    scanf("%s", &B.Author);
    printf("Condition (New/Used): ");
    scanf("%s", &B.Condition);
    printf("Availability (Yes/No): ");
    scanf("%s", &B.Availability);
    printf("Semester: ");
    scanf("%d", &B.Semester);
    strcpy(B.Book_Owner_ID, Student_ID);

    FILE *file = fopen("Books_Information.txt", "a");

    if(file == NULL)
    {
        printf("ERROR 404! Failed to save Book's information. Please try again. :( ");
    }
    else
    {
        fprintf(file, "%s %s %s %s %s %s %d\n", B.Subject, B.Title, B.Author, B.Condition, B.Availability, B.Book_Owner_ID, B.Semester);
        fclose(file);
        printf("  **Book has been successfully added to the list.**\n");
    }
}

int main()
{
     char Student_ID[25];
     int c;
     printf("*_* *_* << EDULINK... >>  :) :) \n");
     printf("---------- A Unique BOOK Sharing System ----------\n");
     printf("1) Register. \n");
     printf("2) Login. \n");
     printf("3) Exit. \n");
     printf("\n  -->> Select an option: ");
     scanf("%d", &c);
     switch (c)
     {
     case 1:
        Reg_Student();
        break;
     case 2:
        printf("Enter your student id: ");
        scanf("%s", &Student_ID);
        Log_In(Student_ID);
        break;
     case 3:
        printf("Successfully Exited. \n");
        return 0;
     default:
        printf("ERROR 404! Please choose correctly.\n");
     }

    return 0;
}
