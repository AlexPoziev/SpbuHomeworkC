#include "sortedList.h"
#include <stdio.h>

int main() {
    List* list = createList();
    insert(list, 2);
    insert(list, 1);
    insert(list, 10);
    insert(list, 3);
    printList(list);

    return 0;
}
