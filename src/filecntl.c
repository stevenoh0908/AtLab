/***************************************************
*                  filecntl.c                      *
****************************************************
* Controls file I/Os.                              *
***************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#ifndef _FILEPARSER_H_
    #define _FILEPARSER_H_
    #include "fileparser.h"
#endif

#ifndef _FILEINFOLIST_H_
    #define _FILEINFOLIST_H_
    #include "fileinfolist.h"
#endif

// retval 0: success
// retval <0: failure
int initFileController(void) {
    initFileInfoList(&fInfoList);
    return 0;
}

// retval 0: success
// retval <0: failure
int openfile(const char* filename, mode) {
    struct FileInfoNode* fileinfo;
    int flags;

    insertFileInfo(&fInfoList, filename);

    fileinfo = getFileInfo(&fInfoList, filename);
    if (fileinfo == NULL) return -1;

    // Open up file and directory
    flags = 0;
    if (mode | MODE_READ) flags = flags;
    if (mode | MODE_WRITE) flags = flags | O_CREAT | O_TRUNC;
    if (mode | MODE_APPEND) flags = flags | O_CREAT | O_APPEND;
    fileinfo->fd = open(filename, flags, S_IRUSR|S_IWUSR|S_IRGRP);
    if (fileinfo->fd < 0) return -1;

    fileinfo->dirfd = opendir(dirname);
    if (fileinfo->dirfd < 0) return -1;

    return 0;
}

// retval 0: success
// retval <0: failure
int closeFile(const char* filename) {
    struct FileInfoNode* fileinfo;
    int ret;

    fileinfo = getFileInfo(&fInfoList, filename);
    if (fileinfo == NULL) return -1;

    if (fileinfo->fd >= 0) close(fileinfo->fd);
    if (fileinfo->dirfd >= 0) close(fileinfo->dirfd);

    ret = removeFileInfo(&fInfoList, filename);
    return ret;
}
