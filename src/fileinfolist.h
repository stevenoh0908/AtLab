/****************************************************
*                   fileinfolist.h                  *
*****************************************************
* Doubly Linked List for Managing File Informations *
* - Element Policy: in assending order of filename  *
*****************************************************/

// Doubly Linked List for Managing Opened File Object
struct FileInfoNode {
    char* filename;
    char* dirname;
    size_t filesize;
    int fd;
    int dirfd;
    struct FileInfoNode* prev;
    struct FileInfoNode* next;
};

struct FileInfoList {
    struct FileInfoNode* head;
    struct FileInfoNode* tail;
    size_t count;
} fInfoList;

// Doubly Linked List Management

// Initialize FileInfoList
int initFileInfoList(struct FileInfoList* list);

// Insert into FileInfoList
int insertFileInfo(struct FileInfoList* list, char* filename);

// Remove from FileInfoList
int removeFileInfo(struct FileInfoList* list, char* filename);

// Find in FileInfoList
// If nothing found, return NULL
struct FileInfoList* getFileInfo(struct FileInfoList* list, char* filename);

// Destruct FileInfoList
int removeFileInfoList(struct FileInfoList* list);
