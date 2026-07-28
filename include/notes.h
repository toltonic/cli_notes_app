#ifndef notes
#define notes

#define MAX_TITLE_LENGTH 50
#define MAX_BODY_LENGTH 256
#define DATA_FILE "data/notes.dat"

typedef struct Note
{
    int id;
    char title[MAX_TITLE_LENGTH];
    char body[MAX_BODY_LENGTH];
    struct Note *next;
} Note;

typedef struct NoteList
{
    int size;
    Note *head;
} NoteList;

/* ============================
 * Note stuff
 * ============================
 */
Note
*note_create(const char *title,
            const char *body);

void
note_print_all(NoteList *list);
/* ============================
 * Linked list stuff
 * ============================
 * */
void
list_init(NoteList *list);

int
load_list(const char *filename,
          NoteList *note);

int
list_add(NoteList *list,
	 Note *note);

int
list_save(const char *filename,
          NoteList *list);

#endif
