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
    printf("creating note\n");

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
    printf("initializing list\n");
}

int
load_list(const char *filename,
          NoteList *list){
    FILE *fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not load list\n");
        return 0;
    }

    //ret = fread(

    return 1;
}

int
list_add(NoteList *list,
	 Note *note){

    if (note == NULL){
	return 0;
    }
    printf("adding note to list\n");

    note->next = list->head;
    list->head = note;
    
    return 1;
}

int
list_save(const char *filename,
          NoteList *list){
    printf("saving list to file\n");
    
    FILE *fp = fopen(filename, "w");
    int ret = 0;
    if (fp == NULL){
	return 0;
    }

    Note *note = list->head;

    while (note != NULL){
	ret = fwrite(note, sizeof(Note), 1, fp);
	if (ret != sizeof(note)){
	    printf("could not write note\n");
	}
	note = note->next;
    }

    fclose(fp);
    return 1;
}
