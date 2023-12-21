/****************************************************
*                  fileinfolist.c                   *
*****************************************************
* Doubly Linked List for Managing File Informations *
* - Element Policy: in assending order of filename  *
****************************************************/

// Include Headers

#include <stdlib.h>
#include <string.h>

#ifndef _FILEINFOLIST_H_
    #define _FILEINFOLIST_H_
    #include "fileinfolist.h"
#endif
#ifndef _FILEPARSER_H_
    #define _FILEPARSER_H_
    #include "fileparser.h"
#endif

// Functions
int initFileInfoList(struct FileInfoList* list) {
    list->head = NULL;
    list->tail = NULL;
    count = 0;
    return 0;
}

// retval 0: success
// retval -1: error on parsing file information
// retval -2: error on dynamic memory allocation
int insertFileInfo(struct FileInfoList* list, char* filename) {
    int ret;
    struct FileInfoNode fileinfo;
    struct FileInfoNode* node, it, pit;

    ret = parseFileInfo(filename, &fileinfo);
    if (ret < 0) return -1;

    node = malloc(sizeof(struct FileInfoNode));
    if (node == NULL) return -1;

    node->filename = malloc(char*(strlen(fileinfo.filename)+1);
    if (node->filename == NULL) return -1;
    strcpy(node->filename, fileinfo.filename);

    node->dirname = malloc(char*(strlen(fileinfo.dirname)+1);
    if (node->dirname == NULL) return -1;
    strcpy(node->dirname, fileinfo.dirname);

    node->filesize = fileinfo.filesize;
    node->fd = -1;
    node->dirfd = -1;
    node->next = NULL;

    for (it = list->head; (it != NULL) && (strcmp(it->filename, node->filename) > 0); it = it->next, pit = it)

    if (pit == list->head) {
        list->head = node;
    }
    if (it == NULL) {
        list->tail = node;
    }

    if (pit != NULL) pit->next = node;
    node->prev = pit;
    node->next = it;
    if (it != NULL) it->prev = node;

    list->count++;

    return 0;
}

// retval 0: success
// retval -1: error
int removeFileInfo(struct FileInfoList* list, char* filename) {
    struct FileInfoList* node;

    node = getFileInfo(list, filename);
    if (node == NULL) return -1;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (node == list->head) list->head = node->next;
    if (node == list->tail) list->tail = node->prev;

    free(node);

    list->count--;
    return 0;
}

// retval NON-NULL: success
// retval NULL: failure
struct FileInfoList* getFileInfo(struct FileInfoList* list, char* filename) {
    struct FileInfoList* it;

    for (it = list.head; (it != NULL) && (strcmp(it->filename, filename) == 0); it = it->next);
    return it;
}

// retval 0: success
// retval -1: error
int removeFileInfoList(struct FileInfoList* list) {
    struct FileInfoList* it, next;
    for (it = list.head; it != NULL; it = next) {
        next = node->next;
        free(node->filename);
        free(it->dirname);
        free(node);
    }

    list->count = 0;
    list->head = NULL;
    list->tail = NULL;

    return 0;
}
