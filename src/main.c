#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "notes.h"

void
print_help();

int
main(int argc, char *argv[]){

    char *body[MAX_BODY_LENGTH];
    char *title[MAX_TITLE_LENGTH];
    char *str_list = "list";
    char *str_help = "help";
    char *str_count = "count";
    char *str_add = "add";
    char *str_view = "view";
    char *str_delete = "delete";

    /* 
     * The list is going to be initialized and loaded from the save at the start of the program
     */
    
    NoteList *list;

    list_init(list);

    /*
     * strcmp returns 0 if the strings are equal
     */

    if(argc == 2){

        if (strcmp(argv[1], str_help) == 0){
            print_help();
        }
        if (strcmp(argv[1], str_add) == 0){
            printf("adding note\n");
            /* take in title,
             * take in body,
             */

            Note note = note_create(title, body);

            list_add(list,note)
        }
        if (strcmp(argv[1], str_count) == 0){
            printf("The amount of notes that you have is: \n");
        }
        if (strcmp(argv[1], str_list) == 0){
            printf("Listing notes...\n");
        }
    }
    
    if (argc == 3){
        if (strcmp(argv[1], str_view) == 0){
        }

        if (strcmp(argv[1], str_delete) == 0){

        }
    }

    return 0;
}

void
print_help(){
    printf("USAGE: notes <option>\n Options:\n    add 'add a note'\n    count 'shows number of notes saved'\n    list 'list the notes'\n    view <id> 'print note from id'\n    delete <id> 'delete note from id'\n");
}
