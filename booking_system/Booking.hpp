//
//  Booking.hpp
//  booking_system
//
//  Created by Bartosz Jastrzębski on 19/10/2018.
//  Copyright © 2018 Bartosz Jastrzębski. All rights reserved.
//

#ifndef Booking_hpp
#define Booking_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "AllHotels.hpp"
using namespace std;
class Booking : public AllHotels{
protected:
    int days, price, stars;
    int date[3];
    string name, city;
    int position;
public:
    Booking();
    void setDays(int days){ this->days = days; price *= this->days; }
    void setDate(int day,int month, int year);
    int getDay(){return date[0];}
    int getMonth(){return date[1];}
    int getYear(){return date[2];}
    int getDays(){return days;}
    void setBookingData();
    int getPrice(){return price; }
    void setPosition(int pos){position = pos;}
};
#endif /* Booking_hpp */
