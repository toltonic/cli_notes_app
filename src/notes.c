#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

// user defined library
#include "notes.h"

/* 
 * ==========================
 * note funcs
 * ==========================
 */
// add a note
Note
*note_create(const char *title,
            const char *body){

    Note *note = malloc(sizeof(Note));
    if (note == NULL){
        return note;
    }

    strcpy(note->title, title);
    strcpy(note->body, body);

    return note;
}


/*
Note
note_find(const char *filename,
               int id){
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL){
        printf("Could not open file %s\n", filename);
        return;
    }
}
*/

// print a note from an id
void
note_print_from_id(const char *filename,
                   int id){
    FILE *fp;
    Note *pnote;
    size_t ret;
    char buffer[2000] = {0};

    fp = fopen(filename, "rb");
    if (fp == NULL){
        printf("Could not open file %s\n", filename);
        return;
    }

    Note note = {0};
    pnote = &note;

    ret = fread(pnote, sizeof(Note), 1, fp);
    if (ret != 1){
        printf("Failed to read\n");
        return;
    }

    fclose(fp);

    printf("%d\n%s\n%s\n", note.id, note.title, note.body);
}
/* 
 * =====================
 * list funcs
 * =====================
 */
void
list_init(NoteList *list){
    list->size = 0;
    list->head = NULL;
}

int
load_list(const char *filename,
          NoteList *list){
    FILE *fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not load list");
        return 0;
    }

    ret = fread(

    return 1;
}

int
list_add(NoteList *list, Note *note){

    note->next = list->head;
    list->head = note;
    
    return 1;
}

int
list_save(const char *filename,
          Note note){
    
    

    return 1;
}
