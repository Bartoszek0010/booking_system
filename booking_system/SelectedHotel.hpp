//
//  SelectedHotel.hpp
//  booking_system
//
//  Created by Bartosz Jastrzębski on 19/10/2018.
//  Copyright © 2018 Bartosz Jastrzębski. All rights reserved.
//

#ifndef SelectedHotel_hpp
#define SelectedHotel_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "AllHotels.hpp"
using namespace std;

class SelectedHotel : public AllHotels {
protected:
    string hotel_name;
    string hotel_city;
    int hotel_stars;
    int hotel_price;
    int hotel_places;
    int position;
public:
    SelectedHotel();
    string getHotelName(){ return hotel_name; }
    string getHotelCity(){ return hotel_city; }
    int getHotelStars(){ return hotel_stars; }
    int getHotelPrice(){ return hotel_price; }
    int getHotelPlaces(){ return hotel_places; }
    void setHotelData();
    void setPosition(int pos){ position = pos; }
};
#endif /* SelectedHotel_hpp */
