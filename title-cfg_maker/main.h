#ifndef _H_MAIN_H_
#define _H_MAIN_H_




#define ISRA_TESTER
#include "Version.inf"
// #include <>
#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include <windows.h>
#include <winbase.h>
#include <fstream>
#include <errno.h>
// #include ""
#include "version.h"
#include "LANG.h"
#include "exedir.h"
#include "tinydir.h"
#include "COLOR_MACROS.H"

//namespaces
using namespace std;

//globals
vector <string> ELFLIST;

//FUNC
void Presentacion(void)
{
    COLOR_0f;
    cout << "========================================================================================="<<endl;
    cout << "title.cfg maker V " << AutoVersion::FULLVERSION_STRING << LANG_9<<endl;
    cout << "build:" << AutoVersion::YEAR <<"-"<< AutoVersion::MONTH <<"-"<< AutoVersion::DATE<<endl;
    cout << LANG_10;
    cout << " El_isra "<<endl;
    cout << "www.psx-place.com/members/el_isra.59064/"<<endl;
    cout << "github.com/israpps/opl-Title.cfg-maker/tree/1.0.0-%40C++"<<endl;
    cout << LANG_11<<endl;
    COLOR_0c;
    cout << LANG_12 <<endl;
    COLOR_0f;
    cout << "========================================================================================="<<endl;
    cout <<endl<<endl;

}



#endif // _H_MAIN_H_
