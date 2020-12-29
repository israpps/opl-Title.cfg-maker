#include "ELF_handler.h"
using namespace std;


/***********************************************************/
 ELF_handler::ELF_handler()
{
    VECT_lnght = 0;
    //ctor
}
/***********************************************************/
 ELF_handler::~ELF_handler()
{
    //dtor
}

/***********************************************************/
void ELF_handler::manifest()
{
    COLOR_0e;
cout << LANG_1;
    COLOR_0f;
cout << " " << ELF_handler::ELFLIST.size()  << " ";
    COLOR_0e;
cout << LANG_2 <<endl<<endl;
    COLOR_0f;

}
/***********************************************************/
void ELF_handler::no_ELF()
{
    COLOR_0e;
    cout << LANG_8<< endl;
    COLOR_0f;
    //cin.get();
}
/***********************************************************/
void ELF_handler::main_handler(int z)
{
        cout << LANG_3<<  "["<< ELF_handler::ELFLIST[z] << "]" << endl;
        string cfg_folder = ELF_handler::ELFLIST[z].substr(0,ELF_handler::ELFLIST[z].length() - 4);

            if (mkdir(cfg_folder.c_str()) != 0)
            {
                COLOR_0c;
                if (errno == EEXIST ) {cout << LANG_4 << "[" << ELF_handler::ELFLIST[z] << "]" <<endl;}
                COLOR_0f;
            } else {
                string target = cfg_folder + "\\" + ELF_handler::ELFLIST[z];
                    if ( 0 ==!  MoveFile(ELF_handler::ELFLIST[z].c_str(), target.c_str()));
                    {
                        COLOR_0a;
                        cout << ELF_handler::ELFLIST[z] << LANG_5<<endl;
                        COLOR_0f;
                        ofstream title_cfg_stream(cfg_folder + "\\title.cfg");

                        if ( title_cfg_stream.is_open() )
                            {
                            title_cfg_stream << "title=" << cfg_folder <<endl;
                            title_cfg_stream << "boot=" << cfg_folder << ELF_handler::ELFLIST[z].substr( ELF_handler::ELFLIST[z].find_last_of(".") ) << endl;

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



}
/***********************************************************/
void ELF_handler::insert_ELF(string input)
{
ELF_handler::ELFLIST.push_back(input);
}
/***********************************************************/
void ELF_handler::get_vector_length()
{
ELF_handler::VECT_lnght = ELF_handler::ELFLIST.size();
}
/***********************************************************/

