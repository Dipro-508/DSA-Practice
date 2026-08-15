#include <stdio.h>
#include <string.h>
#define MAX 100

char text[MAX] = "";

char undoStack[MAX][MAX];
char redoStack[MAX][MAX];

int undoTop = -1;
int redoTop = -1;

void saveUndo()
{
    if(undoTop < MAX - 1)
    {
        strcpy(undoStack[++undoTop], text);
    }
}

void clearRedo()
{
    redoTop = -1;
}

void typeText(char input[])
{
    saveUndo();

    strcat(text, input);

    clearRedo();
}

void undo()
{
    if(undoTop == -1)
    {
        printf("Nothing to undo.\n");
        return;
    }

    strcpy(redoStack[++redoTop], text);

    strcpy(text, undoStack[undoTop--]);
}

void redo()
{
    if(redoTop == -1)
    {
        printf("Nothing to redo.\n");
        return;
    }

    saveUndo();

    strcpy(text, redoStack[redoTop--]);
}

void display()
{
    printf("Current Text: %s\n", text);
}

int main()
{
    int choice;
    char input[MAX];

    while(1)
    {
        printf("\n--- TEXT EDITOR ---\n");
        printf("1. Type Text\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        if(choice == 1)
        {
            printf("Enter text: ");
            fgets(input, MAX, stdin);

            input[strcspn(input, "\n")] = '\0';

            typeText(input);
        }
        else if(choice == 2)
        {
            undo();
        }
        else if(choice == 3)
        {
            redo();
        }
        else if(choice == 4)
        {
            display();
        }
        else if(choice == 5)
        {
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}