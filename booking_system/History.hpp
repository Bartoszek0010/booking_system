//
//  History.hpp
//  booking_system
//
//  Created by Bartosz Jastrzębski on 24/10/2018.
//  Copyright © 2018 Bartosz Jastrzębski. All rights reserved.
//

#ifndef History_hpp
#define History_hpp

#include <stdio.h>
#include "AllHotels.hpp"
#include <string>
using namespace std;

class History : public AllHotels{
private:
    vector<int> days, day, month, year, price, stars;
    vector<string> name, city;
    int position;
    int amount = 0;
public:
    History();
    void setPosition(int pos){position = pos;}
    int getDays(int pos){return days.at(pos);}
    int getDay(int pos){return day.at(pos);}
    int getMonth(int pos){return month.at(pos);}
    int getYear(int pos){return year.at(pos);}
    int getPrice(int pos){return price.at(pos);}
    int getStars(int pos){return stars.at(pos);}
    string getName(int pos){return name.at(pos);}
    string getCity(int pos){return city.at(pos);}
    void setHistoryData(int day, int month, int year, int price, int days);
    int getAmount(){return amount;}
    
};
#endif /* History_hpp */
