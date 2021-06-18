#include <iostream>
#include "parser.h"

using namespace std;
const int MAX_CHAR_SIZR=1000;
char char_buffer[MAX_CHAR_SIZR];
bool hide_file_input=0;


void in_parser(istream &is,bool is_file=0){
    bool end_of_sentence=1;
    string sentence_stream;
    while((cout<<(is_file&&hide_file_input?"":(end_of_sentence?"sql> ":"...> "))),is.getline(char_buffer,MAX_CHAR_SIZR)){
        if(is_file&&!hide_file_input)cout<<char_buffer<<endl;
        sentence_stream+=char_buffer;
        sentence_stream+=' ';
        if(regex_match(sentence_stream,exit_sentence))break;
        if(regex_match(sentence_stream,end_sentence_token)){
            try{
                parser(sentence_stream);
            }
            catch (SQLError &e){
                cout<<"\033[31m"<<"SQLError "<<e.what()<<"\033[0m"<<endl;

            }
            end_of_sentence=1;
            sentence_stream="";
        }else end_of_sentence=0;
    }
}

int main(int argc,char **argv) {
    cout<<"\033[43m\033[35m"<<"Welcome to use tiny sql engine authored by BryanHe!"<<"\033[0m"<<endl<<endl;
    init_parser();
    if(argc>=2){
        int begin=1;
        if(strcmp(argv[begin],"-h")==0)hide_file_input=1,begin++;
        for(int i=begin;i<argc;i++){
            ifstream ifs(argv[i]);
            if(!ifs.is_open())cout<<"\033[31m"<<"FILE IS NOT OPEN :"<<"\033[0m"<<argv[1];
            else {
                cout<<"\033[36m"<<"Output of sql file : "<<argv[i]<<"\033[0m"<<endl<<endl;
                in_parser(ifs,1);
                cout<<endl<<"\033[36m"<<"End of sql file : "<<argv[i]<<"\033[0m"<<endl<<endl;
            }
        }
    }
    in_parser(cin);
    save_tables();
    cout<<endl<<"\033[43m\033[35m"<<"See you next time!"<<"\033[0m";
    return 0;
}
