#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "notes.h"

void
print_help();

int
main(int argc, char *argv[]){

    char body[MAX_BODY_LENGTH];
    char title[MAX_TITLE_LENGTH];
    char *str_list = "list";
    char *str_help = "help";
    char *str_count = "count";
    char *str_add = "add";
    char *str_view = "view";
    char *str_delete = "delete";
    int id;


    if(argc == 1 || argc > 3){
        print_help();
    }

    /* 
     * The list is going to be initialized and loaded from the save if args are correct
     */

    if(argc == 2){
        NoteList list;

        list_init(&list);

        load_list(DATA_FILE, &list);

        if (strcmp(argv[1], str_help) == 0){
            print_help();

        }else if (strcmp(argv[1], str_add) == 0){

            Note *note;

            /* take in title,
             * take in body,
             */

            printf("Please enter title (no more than 50 characters):\n");
            fgets(title, sizeof(title), stdin);

            printf("Please enter body (no more than 256 characters):\n");
            fgets(body, sizeof(body), stdin);

            note = note_create(title, body);

            list_add(&list, note);

            list_save(DATA_FILE, &list);

        }else if (strcmp(argv[1], str_count) == 0){
            printf("The amount of notes that you have is: %d\n", list.size);
            clear_mem(&list);

        }else if (strcmp(argv[1], str_list) == 0){
            note_print_all(&list);
            clear_mem(&list);

        }else {
            print_help();
            clear_mem(&list);

        }


    }

    if (argc == 3){

        NoteList list;

        list_init(&list);

        load_list(DATA_FILE, &list);

        id = atoi(argv[2]);

        if (strcmp(argv[1], str_view) == 0){

            Note *note = note_find(&list, id);
            if(note == NULL){
                printf("There is no note with that id\n");
                 
            }else{
                printf("id: %d\ntitle: %sbody: %s\n", note->id, note->title, note->body);

            }
            
            clear_mem(&list);

        }else if (strcmp(argv[1], str_delete) == 0){

            int ret = note_remove(&list, id);
            if(ret == 1){
                list_save(DATA_FILE, &list);
                printf("Note id: %d was removed\n", id);

            }else{
                printf("There is no note with that id\n");
                clear_mem(&list);
            }

        }else{
            print_help();
            clear_mem(&list);
        }
    }



    return 0;
}

void
print_help(){
    printf("USAGE: notes <option>\n Options:\n    add 'add a note'\n    count 'shows number of notes saved'\n    list 'list the notes'\n    view <id> 'print note from id'\n    delete <id> 'delete note from id'\n");
}
