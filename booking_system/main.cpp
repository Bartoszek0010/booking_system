//
//  main.cpp
//  booking_system
//
//  Created by Bartosz Jastrzębski on 17/10/2018.
//  Copyright © 2018 Bartosz Jastrzębski. All rights reserved.
//

#include <iostream>

#include <fstream>
#include <string>
#include "AllHotels.hpp"
#include "SelectedHotel.hpp"
#include "Booking.hpp"
#include "History.hpp"
// stages
#define firstMenu 0
#define allHotelsMenu 1
#define findNameHotel 2
#define findCityHotel 3
#define findStarsHotel 4
#define findPriceHotel 5
#define reservations 6

using namespace std;
//// print MAINMENU
void printFirstMenu(){
    cout<<"Press number to choose option: "<<endl;
    cout<<"1. Show all hotels."<<endl;
    cout<<"2. Find a hotel."<<endl;
    cout<<"3. Show all hotels in city."<<endl;
    cout<<"4. Show all hotels with n-stars."<<endl;
    cout<<"5. Show all hotels with price lower than."<<endl;
    cout<<"6. Your reservations."<<endl;
}
////
void printAllHotelsMenu(AllHotels list){
    cout<<"Choose a hotel :"<<endl;
    for(int i=0; i<list.getAmount();i++){
        cout<<i + 1<<". "<<list.getHotels(i)<<endl;
    }
}
// function to input number of hotel or sth
char getInput(){
    char c;
    cin>>c;
    return c;
}
///////// finding hotel - set phrase
string findHotel(){
    string phrase;
    cout<<"Find a hotel: "<<endl;
    cin>>phrase;
    return phrase;
}
// finding hotel by name
string findingHotelName(AllHotels list, string phrase){
    string hotel;
    string positions = ""; // postition of searched hotels in vectors (class)
    for(int i=0; i<list.getAmount(); i++){
        hotel = list.getHotels(i);
        if(hotel.find(phrase) != string::npos){
            positions += char(i);
        }
    }
    return positions;
}
// finding hotel by city
string findingHotelCity(AllHotels list, string phrase){
    string hotel;
    string positions =""; // postition of searched hotels in vectors (class)
    for(int i=0;i<list.getAmount();i++){
        hotel = list.getHotelsCity(i);
        if(hotel.find(phrase) != string::npos){
            positions += char(i); // add position if city is correct
            
        }
    }
    return positions;
}

void printFoundHotels(string positions, AllHotels list, vector<int> &actualList){
    for(int i=0;i<positions.length();i++){ // return all hotels from positions
        cout<<i + 1<<". "<< list.getHotels(positions[i])<<endl;
        actualList.push_back(int(positions[i]));
    }
}
///////////finding hotels by stars
int findStars(){
    cout<<"Find Hotels with stars: "<<endl;
    int stars;
    cin>>stars;
    return stars;
}
void printFoundHotelsStars(AllHotels list, int stars, vector<int> &actualList){
    int numPrint = 1;
    for(int i=0; i<list.getAmount(); i++){
        if(list.getHotelsStars(i) == stars){
            cout<<numPrint<<". "<<list.getHotels(i)<<endl;
            actualList.push_back(i);
            numPrint ++;
        }
    }
}
//////// finding hotels with price lower than
int setPrice(){
    cout<<"Enter price treshold: "<<endl;
    int price;
    cin>>price;
    return price;
}

void printFoundHotelsPrice(AllHotels list, int price, vector<int> &actualList){
    int numPrint = 1;
    for(int i=0; i<list.getAmount(); i++){
        if(list.getHotelsPrice(i) <= price){
            cout<<numPrint<<". "<<list.getHotels(i)<<endl;
            actualList.push_back(i);
            numPrint ++;
        }
    }
}
/////////
void firstMenuAction(AllHotels list, int &actual_stage, vector<int> &actualList){
    printFirstMenu();
    char op = getInput();
    switch(op){
        case '1':
            actual_stage = allHotelsMenu;
            break;
        case '2':
            actual_stage = findNameHotel;
            actualList.clear();
            break;
        case '3':
            actual_stage = findCityHotel;
            actualList.clear();
            break;
        case '4':
            actual_stage = findStarsHotel;
            actualList.clear();
            break;
        case '5':
            actual_stage = findPriceHotel;
            actualList.clear();
            break;
        case '6':
            actual_stage = reservations;
            actualList.clear();
            break;
    }
}
void yourReservations(History history, int &actual_stage){
    cout<<"Your reservations: "<<endl;
    for(int i=0;i<history.getAmount();i++){
        cout<<i + 1<<". "<<endl;
        cout<<"Your booking at: "<<history.getDay(i)<<"."<<history.getMonth(i)<<"-"<<history.getYear(i)<<" for "<<history.getDays(i)<<" days in : "<<endl;
        cout<<history.getName(i)<<" in "<<history.getCity(i)<<" ("<<history.getStars(i)<<" stars). "<<"Full price is :";
        cout<<history.getPrice(i)<<"$ ."<<endl<<endl;
        
    }
    actual_stage = firstMenu;
}
// Printing info about booking
void getFullInfo(Booking book, SelectedHotel hotel){
    cout<<"Your booking at: "<<book.getDay()<<"-"<<book.getMonth()<<"-"<<book.getYear()<<" for "<<book.getDays()<<" days in : "<<endl;
    cout<<hotel.getHotelName()<<" in "<<hotel.getHotelCity()<<"( "<<hotel.getHotelStars()<<" stars). "<<"Full price is :";
    cout<<hotel.getHotelPrice() * book.getDays()<<"$ ."<<endl;
}
void bookingHotel(AllHotels &list, int &actual_stage, vector<int> &actualList, int pos, SelectedHotel &hotel, Booking &book, History &history){
    // set position to get data from AllHotels class at(pos)
    hotel.setPosition(pos);
    book.setPosition(pos);
    hotel.setHotelData();
    book.setBookingData();
    history.setPosition(pos);
    
    string input;
    int inputData;
    int day, month, year;
    cout<<"Give a number of days to book: "<<endl;
    cin>>input;
    inputData = stoi(input);
    book.setDays(inputData);
    cout<<"Give a day: "<<endl;
    cin>>input;
    day = stoi(input);
    cout<<"Give a month: "<<endl;
    cin>>input;
    month = stoi(input);
    cout<<"Give a year: "<<endl;
    cin>>input;
    year = stoi(input);
    
    book.setDate(day, month, year);
    getFullInfo(book, hotel);
    //save whole book in history
    history.setHistoryData(book.getDay(), book.getMonth(), book.getYear(), book.getPrice(), book.getDays());
    list.bookRoom(pos);
}
void chooseOrBook(AllHotels &list, int &actual_stage, vector<int> &actualList, SelectedHotel &hotel, Booking &book, History &history){
    cout<<"Choose a hotel or press 0 to back to Menu."<<endl;
    char op = getInput();
    int pos; // this is position from hotels vectors
    if(op == '0'){
        actual_stage = firstMenu;
        return;
    } else {
        pos = actualList.at(int(op) - 49); // -49 because it's char
        cout<<"INNFORMATION ABOUT HOTEL:"<<endl;
        cout<<"Name:  "<<list.getHotels(pos)<<endl;
        cout<<"City:  "<<list.getHotelsCity(pos)<<endl;
        cout<<"Stars:  "<<list.getHotelsStars(pos)<<endl;
        cout<<"Price per person:  "<<list.getHotelsPrice(pos)<<endl;
        cout<<"Free rooms:  "<<list.getHotelsPlaces(pos)<<endl<<endl;
        cout<<"To book this hotel press 1, to back to Menu press 0."<<endl;
        actualList.clear(); // delete postions from temporary list
    }
    op = getInput();
    if(op == '1'){
        bookingHotel(list, actual_stage, actualList, pos, hotel, book, history);
        
    } else if(op == '0'){
        actual_stage = firstMenu;
    }
    actual_stage = firstMenu;
}
void allHotelsMenuAction(AllHotels &list, int &actual_stage, vector<int> &actualList, SelectedHotel &hotel, Booking &book, History &history){
    cout<<hotel.getHotelCity()<<endl;
    printAllHotelsMenu(list);
    char op = getInput();
    int opInt = int(op) - 49; // -49 because it's char
    cout<<"INNFORMATION ABOUT HOTEL:"<<endl;
    cout<<"Name:  "<<list.getHotels(opInt)<<endl;
    cout<<"City:  "<<list.getHotelsCity(opInt)<<endl;
    cout<<"Stars:  "<<list.getHotelsStars(opInt)<<endl;
    cout<<"Price per person:  "<<list.getHotelsPrice(opInt)<<endl;
    cout<<"Free rooms:  "<<list.getHotelsPlaces(opInt)<<endl<<endl;
    cout<<"To book this hotel press 1, to back to Menu press 0."<<endl;
    op=getInput();
    if(op == '1'){
        bookingHotel(list, actual_stage, actualList, opInt, hotel, book, history);
        
    } else if(op == '0'){
        actual_stage = firstMenu;
    }
    actual_stage = firstMenu;
}
void findNameHotelMenu(AllHotels &list, int &actual_stage, vector<int> &actualList, SelectedHotel &hotel, Booking &book, History &history){
    printFoundHotels(findingHotelName(list, findHotel()), list, actualList);
    chooseOrBook(list, actual_stage, actualList, hotel, book, history);
}
void findCityHotelMenu(AllHotels &list, int &actual_stage, vector<int> &actualList, SelectedHotel &hotel, Booking &book, History &history){
    printFoundHotels(findingHotelCity(list, findHotel()), list, actualList);
    chooseOrBook(list, actual_stage, actualList, hotel, book, history);
    
}
void findStarsHotelMenu(AllHotels &list, int &actual_stage, vector<int> &actualList, SelectedHotel &hotel, Booking &book, History &history){
    printFoundHotelsStars(list, findStars(), actualList);
    chooseOrBook(list, actual_stage, actualList, hotel, book, history);
}
void findPriceHotelMenu(AllHotels &list, int &actual_stage, vector<int> &actualList, SelectedHotel &hotel, Booking &book, History &history){
    printFoundHotelsPrice(list, setPrice(), actualList);
    chooseOrBook(list, actual_stage, actualList, hotel, book, history);
}

int main(int argc, const char * argv[]) {
    int actual_stage = firstMenu;
    AllHotels list;
    SelectedHotel hotel;
    Booking book;
    History history;
    //SelectedHotel hotel;
    //Booking book;
    vector<int> actualList; // list of temporary positions of hotels in vector
    while(true){
        switch(actual_stage){
            case firstMenu:
                firstMenuAction(list, actual_stage, actualList);
                break;
            case allHotelsMenu:
                allHotelsMenuAction(list, actual_stage, actualList, hotel, book, history);
                break;
            case findNameHotel:
                findNameHotelMenu(list, actual_stage, actualList, hotel, book, history);
                break;
            case findCityHotel:
                findCityHotelMenu(list, actual_stage, actualList, hotel, book, history);
                break;
            case findStarsHotel:
                findStarsHotelMenu(list, actual_stage, actualList, hotel, book, history);
                break;
            case findPriceHotel:
                findPriceHotelMenu(list, actual_stage, actualList, hotel, book, history);
                break;
            case reservations:
                yourReservations(history,actual_stage);
                break;
        }
    }
    return 0;
}
