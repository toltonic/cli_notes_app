#ifndef notes
#define notes

#define MAX_TITLE_LENGTH 50
#define MAX_BODY_LENGTH 256
#define DATA_FILE "data/notes.dat"

typedef struct Note{
    int id;
    char title[MAX_TITLE_LENGTH];
    char body[MAX_BODY_LENGTH];
} Note;

int note_add(const char *filename,
             const char *title,
             const char *body);

#endif
