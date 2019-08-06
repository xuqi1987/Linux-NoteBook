//
// Created by root on 19-8-5.
//

#include <iostream>
#include <vector>
#include "csv/csv.h"

using namespace std;

int main(){
    io::CSVReader<6> in("../../data/test.csv");
    in.read_header(io::ignore_extra_column, "LogRecType","secMark","lat", "long","heading","speed");
    string type;
    unsigned  int secMark;
    double lat;
    double lon;
    double heading;
    double speed;

    while(in.read_row(type,secMark, lat,lon,heading,speed)){
        // do stuff with the data
        cout << "Type:" << type << "\t";
        cout << "secMark:" << secMark << "\t";
        cout << "lat:" << lat << "\t";
        cout << "lon:" << lon << "\t";
        cout << "speed:" << speed << "\t";
        cout << "heading:" << heading << endl;
    }
}
