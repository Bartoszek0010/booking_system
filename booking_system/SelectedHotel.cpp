//
//  SelectedHotel.cpp
//  booking_system
//
//  Created by Bartosz Jastrzębski on 19/10/2018.
//  Copyright © 2018 Bartosz Jastrzębski. All rights reserved.
//

#include "SelectedHotel.hpp"
SelectedHotel::SelectedHotel(){}
void SelectedHotel::setHotelData(){
    hotel_name = getHotels(position);
    hotel_city = getHotelsCity(position);
    hotel_stars = getHotelsStars(position);
    hotel_price = getHotelsPrice(position);
    hotel_places = getHotelsPlaces(position);
}
