#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    //Variable Declaration
    string Line, Tipe[3] = {"Information", "Error", "Warning"}, output_file;
    size_t initial=0;
    fstream log, output;

    //Membuat output file berupa txt sesuai jenis log
    for(int i=0; i<3; ++i)
    {
        output_file = Tipe[i] + ".txt";
        output.open(output_file, ios::out);
        output<< "Output log tipe "<< Tipe[i]<<endl<<endl;
        output.close();
    }

    log.open("event_log_windows_1000.txt", ios::in); //Membuka file log windows
    while (getline(log, Line)){
        for(int i=0; i<3; ++i){
            if(Line.find(Tipe[i])==initial)
            {
                output_file = Tipe[i] + ".txt";
                output.open(output_file, ios::app);//Menambah (append) baris baru ke dalam output file
                output<< Line<<endl;
                output.close();
                break;
            }
        }
    }
    log.close();
    return 0;
}
