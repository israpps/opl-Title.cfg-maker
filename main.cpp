#define ISRA_TESTER
#include "version.h"
// #include <>
#include <iostream>
#include <string>
//#include <vector>

// #include ""
#include "LANG.h"
#include "exedir.h"
#include "tinydir.h"
#include "COLOR_MACROS.H"
#include "Class/ELF_Handler/ELF_handler.h"
//namespaces
using namespace std;
///using namespace ELF_handler;

ELF_handler ELF_handle;

void Presentacion();
int main ( int argc, char* argv[] )
{
    COLOR_0f;
    Presentacion();


    tinydir_dir dir;
    int i;
    string current_path = EXE_DIR(argv[0]);

    tinydir_open_sorted(&dir,current_path.c_str() );

    for (i = 0; i < dir.n_files; i++)
    {
        tinydir_file file;
        tinydir_readfile_n(&dir, &file, i);

        string filename = file.name ;

        if (
            !file.is_dir
            &&
                (
                filename.substr(filename.length()-4)== ".ELF"
                ||
                filename.substr(filename.length()-4)== ".elf"
                )
           )
        {
            ELF_handle.insert_ELF(filename);
        }
    }

    tinydir_close(&dir);
    ELF_handle.get_vector_length();
    if (ELF_handle.VECT_lnght>0)
    {

        ELF_handle.manifest();
    for (int z = 0; z<ELF_handle.VECT_lnght; z++)
        {
        ELF_handle.main_handler(z);
        }
//*/
    }
    else
    {
    ELF_handle.no_ELF();
    }

    cin.ignore();
    return 0;
}


void Presentacion()
{
    COLOR_0f;
    cout << "==========================================================="<<endl;
    cout << "title.cfg maker V " << AutoVersion::FULLVERSION_STRING << LANG_9<<endl;
    cout << LANG_10;
    COLOR_0e;
    cout << " El_isra "<<endl;
    COLOR_0f;
    cout <<endl;
    cout << "www.psx-place.com/members/el_isra.59064/"<<endl;
    cout << "github.com/israpps/opl-Title.cfg-maker/tree/1.0.0-%40C++"<<endl;
    cout <<endl;
    cout << LANG_11<<endl;
    COLOR_0e;
    cout << LANG_12 <<endl;
    COLOR_0f;
    cout << "==========================================================="<<endl;
    cout <<endl<<endl;

}




