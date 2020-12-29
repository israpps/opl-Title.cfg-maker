#ifndef ELF_HANDLER

#define ELF_HANDLER

///<INCLUDES>
#include <vector>
#include <string>
#include <iostream>
#include <dirent.h>
#include <windows.h>
#include <winbase.h>
#include <fstream>
#include <errno.h>
///"INCLIDES"


///#DEFINES
#include "../../COLOR_MACROS.H"
#include "LANG.h"

///namespaces
using namespace std;

class ELF_handler
{
    public:

        ELF_handler();
        virtual  ~ELF_handler();
        /*********************/

        void manifest();
        void no_ELF();
        void main_handler(int z);
        void insert_ELF(string input);
        void get_vector_length();

        int VECT_lnght;

    private:
        vector <string> ELFLIST;
    protected:

};
#endif // ELF_HANDLER
