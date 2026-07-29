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
note_print_all(NoteList *list){
    if (list->head == NULL){
        printf("list is empty\n");
        return;
    }

    printf("Listing notes...\n");

    Note *note = list->head;

    while(note != NULL){
        printf("title: %sbody: %s\n", note->title, note->body);

        note = note->next;
    }
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
    //FOR TESTING
    if (fp == NULL){
        printf("Could not load list\n");
        return 0;
    }

    while (true){

        Note *note = malloc(sizeof(Note));
        if(note == NULL){
            return 0;
        }

        int ret = fread(note, sizeof(Note), 1, fp);
        if(ret != 1){
            free(note);
            fclose(fp);
            return 0;
        }

        list_add(list, note);

    }

    fclose(fp);

    return 1;
}

int
list_add(NoteList *list,
        Note *note){

    if (note == NULL){
        return 0;
    }

    note->next = list->head;
    list->head = note;
    list->size++;

    return 1;
}

int
list_save(const char *filename,
        NoteList *list){

    int ret = 0;

    FILE *fp = fopen(filename, "w");
    if (fp == NULL){
        return 0;
    }

    Note *note = list->head;

    Note *note_old = note;

    while (note != NULL){

        ret = fwrite(note, sizeof(Note), 1, fp);
        if (ret != 1){
            printf("could not write note\n");
            fclose(fp);
            return 0;
        }

        note = note->next;
        free(note_old);
        note_old = note;

    }
    
    fclose(fp);

    list->head = NULL;
    list->size = 0;

    return 1;
}
/*
 * This is to free memory. If we load the list
 * but do not make any changes, it doesn't make sense
 * to go through the trouble of saving it.
 */
int
clear_mem(NoteList *list){

    if(list->head == NULL){
        return 1;
    }
    Note *old_note = list->head;
    Note *note = old_note;


    while (note != NULL){
        note = note->next;
        free(old_note);
        old_note = note;
    }

    list->size = 0;
    list->head = NULL;

    return 1;
}
