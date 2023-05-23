//
//  MapCoordinate.hpp
//  #5
//
//  Created by Nico Savage on 5/22/23.
//

#ifndef MapCoordinate_hpp
#define MapCoordinate_hpp

#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
#include <stdio.h>

class MapCoordinate{
private:
    string name;
    double latitude, longitude;
    
public:
    MapCoordinate();
    MapCoordinate(string n, double lat, double longi);
    
    void setName(string n);
    void setLatitude(double lat);
    void setLongitude(double longi);
    string getName();
    double getLatitude();
    double getLongitude();
    
    string toString();
    
    friend ostream& operator<<(ostream& os, MapCoordinate& mc);
    friend istream& operator>>(istream& is, MapCoordinate& mc);
    
    
};

#endif /* MapCoordinate_hpp */
