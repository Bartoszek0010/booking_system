//
//  Booking.cpp
//  booking_system
//
//  Created by Bartosz Jastrzębski on 19/10/2018.
//  Copyright © 2018 Bartosz Jastrzębski. All rights reserved.
//

#include "Booking.hpp"
Booking::Booking(){}
void Booking::setDate(int day, int month, int year){
    date[0] = day;
    date[1] = month;
    date[2] = year;
}
void Booking::setBookingData(){
    price = getHotelsPrice(position);
    stars = getHotelsStars(position);
    name = getHotels(position);
    city = getHotelsCity(position);
}

