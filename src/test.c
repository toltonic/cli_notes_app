#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "notes.h"


int
main(){

    char *title = "wefds";
    char *itle = "iyurhnt";
    char *tle = "3rd";
    char *body = "dienadlsfeh";
    char *ody = "asdfdsf";
    char *dy = "this is the third body";

    NoteList list;

    list_init(&list);

    Note *note = note_create(title, body);

    list_add(&list, note);

    Note *ote = note_create(itle, ody);

    list_add(&list, ote);

    note_print_all(&list);

    list_save(DATA_FILE, &list);

    note_print_all(&list);

    load_list(DATA_FILE, &list);

    note_print_all(&list);

    Note *te = note_create(tle, dy);

    list_add(&list, te);

    list_save(DATA_FILE, &list);

    load_list(DATA_FILE, &list);

    note_print_all(&list);

    list_save(DATA_FILE, &list);
    return 0;
}

