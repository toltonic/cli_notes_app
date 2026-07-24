#include <stdio.h>
#include <stdlib.h>
#include "notes.h"

int main(int argc, char argv[]){

    char *lit = "this shit";
    char *This = "this is the body";


    note_add(DATA_FILE, lit, This);

    return 0;
}
