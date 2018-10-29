

#include "AllHotels.hpp"
#include <fstream>
using namespace std;
AllHotels::AllHotels(){}
string AllHotels::getHotels(int pos){
    return hotels_names.at(pos);
}
string AllHotels::getHotelsCity(int pos){
    return hotels_city.at(pos);
}
int AllHotels::getHotelsStars(int pos){
    return hotels_stars.at(pos);
}
int AllHotels::getHotelsPrice(int pos){
    return hotels_price.at(pos);
}
int AllHotels::getHotelsPlaces(int pos){
    return hotels_places.at(pos);
}
int AllHotels::getAmount(){
    return hotels_amount;
}

