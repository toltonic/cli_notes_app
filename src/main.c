#include <stdio.h>
#include <stdlib.h>
#include "notes.h"

int main(int argc, char *argv[]){

    char *lit = "Whatever";
    char *hy = "hello";

    char *This = "this is the body";
    char *hl = "asdfkeloa;lkndf";


    note_add(DATA_FILE, lit, This);

    note_print_from_id(DATA_FILE, 1);

    note_add(DATA_FILE, hy, hl);

    note_print_from_id(DATA_FILE, 1);

    return 0;
}
