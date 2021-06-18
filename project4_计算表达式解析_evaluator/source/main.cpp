#include <iostream>
#include <fstream>
#include "EFunc.h"
#include "EEnv.h"
#include "parser.h"

using namespace std;

int main(int argc,char **argv) {
    EEnv global(NULL);
    init_global(global);
    init_parser();
    string sentence;
    bool interpreter= false;
    if(argc>=2&&string(argv[1])=="-i")interpreter= true,cout<<"\033[34m"<<"interpreter_mode: open\n"<<"\033[0m";
    if(argc==2&&!interpreter||argc==3){
        ifstream ifs(argv[argc-1]);
        if(!ifs.is_open())cout<<"\033[31m"<<"FILE IS NOT OPEN :"<<"\033[0m"<<argv[1];
        else{
            while(getline(ifs,sentence)){
                cout<<"--> "<<sentence<<endl;
                try {
                    if(senctence_with_end(sentence,global,interpreter))break;
                    cout<<endl;
                }catch (EError &e){
                    cout<<"\033[31m"<<"Error : "<<e.what()<<"\033[0m"<<endl;
                }
            }
        }
    }
    while(1){
        cout<<"--> ";
        if(!getline(cin,sentence))break;
        try {
            if(senctence_with_end(sentence,global,interpreter))break;
            cout<<endl;
        }catch (EError &e){
            cout<<"\033[31m"<<"Error : "<<e.what()<<"\033[0m"<<endl;
        }
    }
    return 0;
}
