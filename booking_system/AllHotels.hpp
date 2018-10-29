//
//  AllHotels.hpp
//  booking_system
//
//  Created by Bartosz Jastrzębski on 17/10/2018.
//  Copyright © 2018 Bartosz Jastrzębski. All rights reserved.
//

#ifndef AllHotels_hpp
#define AllHotels_hpp

#include <stdio.h>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

class AllHotels{
private:
    vector<string> hotels_names{"Royal Ambert","Palace","Hilton","Gromada","Italio"};
    vector<string> hotels_city{"London","Berlin","New York","Warsaw","Rome"};
    vector<int> hotels_price{100,150,234,70,122};
    vector<int> hotels_stars{4,5,5,3,4};
    vector<int> hotels_places{300,345,555,100,23};
    int hotels_amount = 5;
public:
    AllHotels();
    string getHotels(int pos);
    string getHotelsCity(int pos);
    int getHotelsStars(int pos);
    int getHotelsPrice(int pos);
    int getHotelsPlaces(int pos);
    int getAmount();
    void bookRoom(int pos){ hotels_places.at(pos) = hotels_places.at(pos) - 1; }
};
#endif /* AllHotels_hpp */
