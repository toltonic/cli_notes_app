#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "notes.h"


int
main(){

    char *title = "title";
    char *body = "body";

    NoteList *list;

    list_init(list);

    note_create(tile, body);

    printf("%d\n)", sizeof(NoteList));

}

