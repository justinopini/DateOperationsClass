#include <iostream>
#include <iomanip>
#include <string>
#include "date.h"

Date::Date(){
   //Default date 1/1/1900
   Day = 1;
   Month = 1 ;
   Year = 1900;
}
Date::Date(int INTDay, int INTMonth, int INTYear){
    //Sets Date to user specified
    Day = INTDay;
    Month = INTMonth;
    Year = INTYear;
}
Date Date::AddDays(int Number) const{
    Date copy(Day, Month, Year);
    int fx = 0;//function to calculate number of days in month  (line 21) attributed to https://cmcenroe.me/2014/12/05/days-in-month-formula.html
    copy.Day += Number;
    fx = (28 + (copy.Month+(copy.Month/8))%2)+(2%copy.Month+(2/copy.Month));
    if (copy.Year%4 != 0 && copy.Month == 2)//If month is feb and not in leap year, 1 day is subtracted(default 29)
        fx -= 1;
    while (copy.Day > fx){// while the days are greater than the number in that month
        copy.Day -= fx;
        if (copy.Month == 12) {//If December Month set to January and one year added
            copy.Year++;
            copy.Month = 1;
        }
        else
            copy.Month++;
        fx = (28 + (copy.Month+(copy.Month/8))%2)+(2%copy.Month+(2/copy.Month));
        if (copy.Year%4 != 0 && copy.Month == 2)//If month is feb and not in leap year, 1 day is subtracted(default 29)
            fx -= 1;
    }
    return copy;
}
Date Date::RemoveDays(int Number) const{
    Date copy(Day, Month, Year);
    int fx = 0;//function to calculate number of days in month  (line 21) attributed to https://cmcenroe.me/2014/12/05/days-in-month-formula.html
    copy.Day -= Number;
    fx = (28 + (copy.Month+(copy.Month/8))%2)+(2%copy.Month+(2/copy.Month));
    if (copy.Year%4 != 0 && copy.Month == 2)//If month is feb and not in leap year, 1 day is subtracted(default 29)
        fx -= 1;
    while (copy.Day < 1){// while the days are less than 0
        copy.Day += fx;
        if (copy.Month == 1) {//If Januar Month set to December and one year added
            copy.Year--;
            copy.Month = 12;
        }
        else
            copy.Month--;
        fx = (28 + (copy.Month+(copy.Month/8))%2)+(2%copy.Month+(2/copy.Month));
        if (copy.Year%4 != 0 && copy.Month == 2)//If month is feb and not in leap year, 1 day is subtracted(default 29)
            fx -= 1;
    }
    return copy;
}
void Date::PrintDate() const{
    std::string Months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int pos = 0;
    pos = Month-1;
    std::cout<< "The date set is " << std::setfill('0')  << Months[pos] << " " << std::setw(2)<<Day << ", " << Year << std::endl;
}
bool Date::IsLeapYear() const {
 if (Year%4 == 0)
     return 1;
 else
     return 0;
}
void Date::SetMonth(){
    int temp = 0;
    std::cout << "Enter month: ";//prompt month
    std::cin >> temp;
    while (temp > 12 || temp < 1){//validate month
        std::cout << "Invalid Month!\nEnter month: ";
        std::cin >> temp;
    }
    Month = temp;
}
void Date::SetDay(){
    int temp = 0;
    int fx = 0;//function to calculate number of days in month  (line 21) attributed to https://cmcenroe.me/2014/12/05/days-in-month-formula.html
    std::cout << "Enter day: ";//prompt day
    std::cin >> temp;
    fx = (28 + (Month+(Month/8))%2)+(2%Month+(2/Month));
    if (Year%4 != 0 && Month == 2)//If month is feb and not in leap year, 1 day is subtracted(default 29)
        fx -= 1;
    while (temp > fx || temp < 1){//validate day
        std::cout << "Invalid Day!\nEnter day: ";
        std::cin >> temp;
    }
    Day = temp;
}
void Date::SetYear(){
    int temp = 0;
    std::cout << "Enter year: ";//prompt year
    std::cin >> temp;
    while (temp < 0){//validate year
        std::cout << "Invalid Year!\nEnter year: ";
        std::cin >> temp;
    }
    Year = temp;
}
int Date::GetMonth() const {
    return Month;
}
int Date::GetDay() const {
    return Day;
}
int Date::GetYear() const {
    return Year;
}
