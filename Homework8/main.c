#include <stdio.h>
#include "AVLTree.h"
#include "treeTest.h"

#define MAX_STRING_SIZE 100

void commandChooses(void) {
    printf("0 - exit\n");
    printf("1 - add value by token to dictionary. If token exists, change to new\n");
    printf("2 - get value by token\n");
    printf("3 - check for containing token in dictionary\n");
    printf("4 - delete token and corresponding value from dictionary\n");
}

int main() {
    if (!AVLTreeBalanceTest() || !fullTest()) {
        printf("Tests Failed");
        return 1;
    }

    commandChooses();
    Dictionary *dictionary = createDictionary();
    if (dictionary == NULL) {
        printf("Not enough memory");
        return 1;
    }

    int option = 1;
    while (option != 0) {
        printf("Choose option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                printf("Input token: ");
                char token[MAX_STRING_SIZE] = {0};
                scanf("%s", token);
                printf("Input value with length less than 100: ");
                char value[MAX_STRING_SIZE] = {0};
                scanf("%s", value);
                int errorCode = addValue(dictionary, token, value);
                if (errorCode) {
                    printf("Not enough memory");
                    deleteTree(&dictionary);

                    return 1;
                }

                printf("Value successfully added \n");

                break;
            }
            case 2: {
                printf("Input token to get value of it: ");
                char token[MAX_STRING_SIZE] = {0};
                scanf("%s", token);
                char *answer = getValue(dictionary, token);
                if (answer == NULL) {
                    printf("No value with this token in the dictionary \n");
                    break;
                }

                printf("Value of token %s is '%s' \n", token, answer);

                break;
            }
            case 3: {
                printf("Input token to check for its containing in the dictionary: ");
                char token[MAX_STRING_SIZE] = {0};
                scanf("%s", token);
                printf("The token %s %s in the dictionary \n", token,
                        isContain(dictionary, token)
                        ? "is contained"
                        : "isn't contained");

                break;
            }
            case 4: {
                printf("Input token to delete its and value from the dictionary: ");
                char token[MAX_STRING_SIZE] = {0};
                scanf("%s", token);
                deleteValue(dictionary, token);
                printf("Deletion completed\n");

                break;
            }
            case 0: {
                break;
            }

            default: {
                printf("There is not option with this number, please, repeat input: \n");
                commandChooses();

                break;
            }
        }
    }

    deleteTree(&dictionary);

    return 0;
}
