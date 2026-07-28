#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "notes.h"


int
main(){

    char *title = "wefds";
    char *itle = "iyurhnt";
    char *body = "dienadlsfeh";
    char *ody = "asdfdsf";

    NoteList list;

    list_init(&list);

    Note *note = note_create(title, body);

    list_add(&list, note);

    Note *ote = note_create(itle, ody);

    list_add(&list, ote);

    list_save(DATA_FILE, &list);

    return 0;
}

