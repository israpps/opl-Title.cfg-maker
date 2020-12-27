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
#include "LANG.h"
#include "exedir.h"
#include "tinydir.h"
#include "COLOR_MACROS.H"

//namespaces
using namespace std;

//globals
vector <string> ELFLIST;

//func
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
            && (
                filename.substr(filename.length()-4)== ".ELF"
                ||
                filename.substr(filename.length()-4)== ".elf"

               )
           )
        {

            ELFLIST.push_back(filename);


        }
    }

    tinydir_close(&dir);
    if (ELFLIST.size()>0)
    {
        COLOR_0e;
        cout << LANG_1;
        COLOR_0f;
        cout << " "<< ELFLIST.size()  << " ";
        COLOR_0e;
        cout << LANG_2 <<endl<<endl;
        COLOR_0f;
        for (int z = 0; z<ELFLIST.size(); z++)
        {

            cout << LANG_3<<  "["<< ELFLIST[z] << "]" << endl;
            string cfg_folder = ELFLIST[z].substr(0,ELFLIST[z].length() - 4);

                     if (mkdir(cfg_folder.c_str()) != 0)
                        {
                        COLOR_0c;
                        if (errno == EEXIST ) {cout << LANG_4 << "[" << ELFLIST[z] << "]" <<endl;}
                        COLOR_0f;

                    } else {

                        string target = cfg_folder + "\\" + ELFLIST[z];

                        if ( 0 ==! MoveFile(ELFLIST[z].c_str(), target.c_str() ) );
                        {
                            COLOR_0a;
                            cout << ELFLIST[z] << LANG_5<<endl;
                            COLOR_0f;
                        ofstream title_cfg_stream(cfg_folder + "\\title.cfg");

                        if ( title_cfg_stream.is_open() )
                            {
                            title_cfg_stream << "title=" << cfg_folder <<endl;
                            title_cfg_stream << "boot=" << cfg_folder << ELFLIST[z].substr( ELFLIST[z].find_last_of(".") ) << endl;

                            COLOR_0a;
                            cout << LANG_6<<endl;
                            COLOR_0f;


                            } else {

                            COLOR_0c;
                            cout << LANG_7;
                            COLOR_0f;
                            }//*/
                        }

            }//*/

        }//*/
//*/
    }
    else
    {
        COLOR_0e;
        cout << LANG_8<< endl;
        COLOR_0f;
        //cin.get();
    }

    cin.ignore();
    return 0;
}


void Presentacion()
{
    COLOR_0f;
    cout << "========================================================================================="<<endl;
    cout << "title.cfg maker V " << VERSION_ << LANG_9<<endl;
    cout << LANG_10;
    COLOR_0e;
    cout << " El_isra "<<endl;
    COLOR_0f;
    cout << "www.psx-place.com/members/el_isra.59064/"<<endl;
    cout << "github.com/israpps/opl-Title.cfg-maker/tree/1.0.0-%40C++"<<endl;
    cout << LANG_11<<endl;
    COLOR_0e;
    cout << LANG_12 <<endl;
    COLOR_0f;
    cout << "========================================================================================="<<endl;
    cout <<endl<<endl;

}




