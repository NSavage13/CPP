//
//  TreasureChest.cpp
//  #5
//
//  Created by Nico Savage on 5/22/23.
//

#include "TreasureChest.hpp"

TreasureChest::TreasureChest() : MapCoordinate(), treasureName(""), originalHider(""){}
TreasureChest::TreasureChest(string name, double lat, double longi, string treasureName, string hider) : MapCoordinate(name, lat, longi), treasureName(treasureName), originalHider(hider){}

void TreasureChest::setTreasureName(string name){this->treasureName = name;}
void TreasureChest::setOriginalHider(string name){this->originalHider = name;}
string TreasureChest::getTreasureName(){return this->treasureName;}
string TreasureChest::getOriginalHider(){return this->originalHider;}

ostream& operator<<(ostream& os, TreasureChest& tc){
    os << tc.toString();
    return os;
}

string TreasureChest::toString(){
    return MapCoordinate::toString() + "Treasure: " + treasureName + "\nHider: " + originalHider + "\n";
}

