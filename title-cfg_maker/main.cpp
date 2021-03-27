#include "main.h"

//func
int main ( int argc, char* argv[] )
{
    COLOR_0f;
    Presentacion();


    tinydir_dir dir;
    string current_path = EXE_DIR(argv[0]);

    tinydir_open_sorted(&dir,current_path.c_str() );

    for (size_t i = 0; i < dir.n_files; i++)
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

                        if (MoveFile(ELFLIST[z].c_str(), target.c_str() ) ==! 0 );
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
    cout << LANG_13 <<endl;
    cin.ignore();
    return 0;
}







