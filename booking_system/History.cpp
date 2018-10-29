//
//  History.cpp
//  booking_system
//
//  Created by Bartosz Jastrzębski on 24/10/2018.
//  Copyright © 2018 Bartosz Jastrzębski. All rights reserved.
//

#include "History.hpp"

History::History(){
    
}
void History::setHistoryData(int day, int month, int year, int price, int days){
    this->days.push_back(days);
    this->day.push_back(day);
    this->month.push_back(month);
    this->year.push_back(year);
    this->price.push_back(price);
    name.push_back(getHotels(position));
    city.push_back(getHotelsCity(position));
    stars.push_back(getHotelsStars(position));
    amount ++;
}
