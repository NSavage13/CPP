//
//  MapCoordinate.cpp
//  #5
//
//  Created by Nico Savage on 5/22/23.
//

#include "MapCoordinate.hpp"
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

MapCoordinate::MapCoordinate()
{
    name = "Example";
    latitude = 0;
    longitude = 0;
}
MapCoordinate::MapCoordinate(string n, double lat, double longi):
name(n), latitude(lat), longitude(longi){}

void MapCoordinate::setName(string n)
{
    name = n;
}
void MapCoordinate::setLatitude(double lat)
{
    latitude = lat;
}
void MapCoordinate::setLongitude(double longi)
{
    longitude = longi;
}
string MapCoordinate::getName()
{
    return name;
}
double MapCoordinate::getLatitude()
{
    return latitude;
}
double MapCoordinate::getLongitude()
{
    return longitude;
}
ostream& operator<<(ostream& os, MapCoordinate& mc){
    os << mc.toString() << endl;
    return os;
}
istream& operator>>(istream& is, MapCoordinate& mc){
    is >> mc.name >> mc.latitude >> mc.longitude;
    return is;
}
string MapCoordinate::toString()
{
    stringstream ss;
    ss << "Name: " << name << "\nLatitude: " << latitude << "\nLongitude: " << longitude << endl;
    return ss.str();
}

