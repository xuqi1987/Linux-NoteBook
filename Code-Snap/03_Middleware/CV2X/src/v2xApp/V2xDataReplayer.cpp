//
// Created by root on 19-8-5.
//

#include "V2xDataReplayer.h"
#include "csv/csv.h"
#include <string>
#include "V2xSetting.h"

using namespace std;
namespace v2x
{

void V2xDataReplayer::run()
{
    string path = SET["Debug.ReplayerPath"].as<string>();
    io::CSVReader<6> in(path);
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
V2xDataReplayer::V2xDataReplayer()
    : V2xThread()
{

}
V2xDataReplayer::~V2xDataReplayer()
{

}
void V2xDataReplayer::loadData()
{
    if (SET["Debug.ReplaySwith"].as<bool>())
    {

    }

}

}