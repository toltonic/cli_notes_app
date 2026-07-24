#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "notes.h"
#include <string.h>


int note_add(const char *filename,
             const char *title,
             const char *body){

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL){
	return 0;
    }

    Note *note = malloc(sizeof(Note));;
    if(note == NULL){
	return 0;
    }

    note->id = 1;
    strcpy(note->title, title);
    strcpy(note->body, body);

    printf("%s\n%s\n", title, body);

    fwrite(note, sizeof(Note), 1, fp);
    fclose(fp);

    free(note);

    return 1;
}
