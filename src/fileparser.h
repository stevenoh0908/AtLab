/************************************************
*               fileparser.h                    *
*************************************************
* Parse info of a given file, saves into Node.  *
************************************************/

#ifndef _FILEINFOLIST_H_
    #include "fileinfolist.h"
#endif

// get directory name
char* getDirname(char* filename);

// get filesize
off_t getFilesize(char* filename);

// get fileinfo (in FileInfoNode)
struct FileInfoNode* getFileInfo(char* filename);
