#include <iostream>
#include <string>
#include "date.h"

Date *formed = NULL;

void menu();
void select(int);
int main(){
        int usrCommand = 0;
        std::cout << "Press 1 to use default date" <<std::endl;
        std::cout << "Press 2 to set specific date" <<std::endl;
        std::cout << "Enter Selection: ";
        std::cin >> usrCommand;
        if (usrCommand == 1){
                Date usr;
                formed = &usr;
        }
        else if(usrCommand == 2){
                int n1 =0;
                int n2 =0;
                int n3 =0;
                std::cout << "Enter Year: ";//prompt n3
                std::cin >> n3;
                while (n3 < 0){//validate n3
                        std::cout << "Invalid Year!\nEnter Year: ";
                        std::cin >> n3;
                }
                std::cout << "Enter Month: ";//prompt n2
                std::cin >> n2;
                while (n2 > 12 || n2 < 1){//validate n2
                        std::cout << "Invalid Month!\nEnter Month: ";
                        std::cin >> n2;
                }
                std::cout << "Enter Day: ";//prompt n1
                std::cin >> n1;
                int fx = (28 + (n2+(n2/8))%2)+(2%n2+(2/n2));
                if (n3%4 != 0 && n2 == 2)//If n2 is feb and not in leap n3, 1 n1 is subtracted(default 29)
                        fx -= 1;
                 while (n1 > fx || n1 < 1){//validate n1
                        std::cout << "Invalid Day!\nEnter Day: ";
                        std::cin >> n1;
                }
                Date usr(n1,n2,n3);
                formed  = &usr;
        }
        formed->PrintDate();
        while (1 < 2){
                menu();
                std::cout << "Enter Selection: ";
                std::cin >> usrCommand;
                if (usrCommand == 11)
                        return 0;
                else
                        select(usrCommand);
        }
        return 0;
}
void menu(){
        std::cout << "1.Add days" <<std::endl;
        std::cout << "2.Remove days" <<std::endl;
        std::cout << "3.Print Date" <<std::endl;
        std::cout << "4.Is leap year" <<std::endl;
        std::cout << "5.Set Month" <<std::endl;
        std::cout << "6.Set Day" <<std::endl;
        std::cout << "7.Set Year" <<std::endl;
        std::cout << "8.Get Month" <<std::endl;
        std::cout << "9.Get Day" <<std::endl;
        std::cout << "10.Get Year" <<std::endl;
        std::cout << "11. Quit" <<std::endl;
}
void select(int selec){
        static int buffer = 0;
        if (selec == 1){
                std::cout << "Enter number of days to add" <<std::endl;
                std::cout << "Enter Days: ";
                std::cin >> buffer;
                *formed = formed->AddDays(buffer);
        }
        if (selec == 2){
                std::cout << "Enter number of days to remove" <<std::endl;
                std::cout << "Enter Days: ";
                std::cin >> buffer;
                *formed = formed->RemoveDays(buffer);
        }
        if (selec == 3){
                formed->PrintDate();
        }
        if (selec == 4){
                buffer = formed->IsLeapYear();
                std::cout << buffer << std::endl;
        }
        if (selec == 5){
                formed->SetMonth();
        }
        if (selec == 6){
                formed->SetDay();
        }
        if (selec == 7){
                formed->SetYear();
        }
        if (selec == 8){
                buffer = formed->GetMonth();
                std::cout << buffer << std::endl;
        }
        if (selec == 9){
                buffer = formed->GetDay();
                std::cout << buffer << std::endl;
        }
        if (selec == 10){
                buffer = formed->GetYear();
                std::cout << buffer << std::endl;
        }
}
