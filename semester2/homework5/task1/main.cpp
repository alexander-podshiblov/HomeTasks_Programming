#include <stdio.h>
#include "Test.h"
#include "table.h"

int main()
{
    Test test;
    QTest::qExec(&test);
    printf("\n\n\n");

    Table *t = new Table;
    char choice = '-';
    char s[200];

    HashFunc *f1 = new Func1;
    HashFunc *f2 = new Func2;




    while(choice != '0')
    {
        printf("0 - Exit\n");
        printf("1 - Add string\n");
        printf("2 - Del string\n");
        printf("3 - Search string\n");
        printf("4 - Show stats\n");
        printf("5 - Select hash-function\n");
        choice = getc(stdin);
        getc(stdin);
        printf("\n");


        if (choice == '1')
        {
            printf("Enter the string: ");
            fgets(s, 200, stdin);
            t->add(s);
            printf("\n\n");
        }
        else if (choice == '2')
        {
            printf("Enter the string: ");
            fgets(s, 200, stdin);
            t->del(s);
            printf("\n\n");
        }
        else if (choice == '3')
        {
            printf("Enter the string: ");
            fgets(s, 200, stdin);
            if(t->exist(s))
                printf("Yes");
            else
                printf("No");

            printf("\n\n");
        }
        else if (choice == '4')
        {
            printf("Numer of cells: %i\n", t->cells());
            t->stats();
            printf("Load factor is %lf\n", t->loadFactor);
            printf("Number of conflicts is %i\n", t->conflicts);
            printf("Maximum length of conflict is %i\n\n", t->lconf);
        }
        else if (choice == '5')
        {
            printf("Enter the number of func (1/2): ");
            char c = '-';
            c = getc(stdin);
            getc(stdin);
            if (c == '1')
                t->changeFunc(f1);
            else if (c == '2')
                t->changeFunc(f2);

        }
    }









    delete t;
    return 0;
}
