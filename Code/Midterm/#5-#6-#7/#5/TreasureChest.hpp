//
//  TreasureChest.hpp
//  #5
//
//  Created by Nico Savage on 5/22/23.
//

#ifndef TreasureChest_hpp
#define TreasureChest_hpp
#include "MapCoordinate.hpp"
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

class TreasureChest : public MapCoordinate {
private:
    string treasureName, originalHider;
    
public:
    TreasureChest();
    TreasureChest(string name, double lat, double longi, string treasureName, string hider);
    
    void setTreasureName(string name);
    void setOriginalHider(string hider);
    
    string getTreasureName();
    string getOriginalHider();
    
    friend ostream& operator<<(ostream& os, TreasureChest& tc);

    string toString();
    
};



#endif /* TreasureChest_hpp */
