/************************************************
*               fileparser.c                    *
*************************************************
* Parse info of a given file, saves into Node.  *
************************************************/

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#ifndef _FILEINFOLIST_H_
    #include "fileinfolist.h"
#endif

// retval NULL: failed
// retval Non-null: directory name of the given filename
char* getDirname(char* filename) {
    return dirname(filename);
}

// retval -1: failed
// retval >= 0: filesize of the given filename
off_t getFilesize(char* filename) {
    struct stat fileinfo;
    int ret;

    ret = stat(filename, &fileinfo);
    if (ret < 0) return -1;
    return fileinfo.st_size;
}

// retval NULL: failed
// retval Non-NULL: pointer of FileInfoNode, which only filename, dirname, filesize is valid.
// Note: this function is not thread-safe.
struct FileInfoNode* getFileInfo(char* filename) {
    static struct FileInfoNode* node;

    char* dirname = getDirname(filename);
    if (dirname == NULL) return NULL;
    if (node->dirname != NULL) free(node->dirname);
    node->dirname = malloc(sizeof(char)*(strlen(dirname)+1));
    if (node->dirname == NULL) return NULL;
    strcpy(node->dirname, dirname);

    if (node->filename != NULL) free(node->filename);
    node->filename = malloc(sizeof(char)*(strlen(filename)+1));
    if (node->filename == NULL) return NULL;
    strcpy(node->filename, filename);

    size_t filesize = (size_t) getFilesize(filename);
    if (filesize < 0) return NULL;
    node->filesize = filesize;

    node->prev = NULL;
    node->next = NULL;
    node->fd = -1;
    node->dirfd = -1;

    return node;
}
