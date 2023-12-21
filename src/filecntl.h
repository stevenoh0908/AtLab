/**********************************************
*               filecntl.h                    *
***********************************************
* Header file for controlling file I/Os.      *
**********************************************/

#ifndef _FILEINFOLIST_H_
    #define _FILEINFOLIST_H_
    #include "fileinfolist.h"
#endif

// global variables
static FileInfoList fInfoList;

// mode flags
int MODE_READ = 1; // 3'b001
int MODE_WRITE = 2; // 3'b010
int MODE_APPEND = 4; // 3'b100

// Init FileController
int initFileController(void);

// Open File (open given file, and parse fileinfo and put it in global fInfoList)
int openfile(const char* filename, int mode);

// Close File (close given file, free element in fInfoList)
int closefile(const char* filename);


