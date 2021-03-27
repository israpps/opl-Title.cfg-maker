#ifndef EXEDIR_H_INCLUDED
#define EXEDIR_H_INCLUDED
#include "tinydir.h"
std::string EXE_DIR (std::string temporary)
{
    std::string path;
    path = temporary.substr(0,temporary.find_last_of('\\')+ 1 );



return path;
}


#endif // EXEDIR_H_INCLUDED
