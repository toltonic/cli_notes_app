#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

// user defined library
#include "notes.h"

// add a note
int note_add(const char *filename,
             const char *title,
             const char *body){

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL){
        printf("Could not open file %s\n", filename);
        return 0;
    }

    Note note = {0};
    Note *pnote = &note;

    note.id = 1;
    strcpy(note.title, title);
    strcpy(note.body, body);

    fwrite(pnote, sizeof(Note), 1, fp);
    fclose(fp);


    return 1;
}
/*
Note note_find(const char *filename,
               int id){
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL){
        printf("Could not open file %s\n", filename);
        return;
    }
}
*/

// print a note from an id
void note_print_from_id(const char *filename,
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
