#include <iostream>


bool leap_year(int year){
    bool ly;
    if(year % 400 == 0){
        ly = true;
    }
    else if(year % 100 == 0){
        ly = false;
    }
    else if(year % 4 == 0){
        ly = true;
    }
    else{
        ly = false;
    }
    return ly;
}



void next_date(int d1, int m1, int y1, int& d2, int& m2, int& y2){
    int days_in_month;

    if(m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12){
        days_in_month = 31;
    }
    else if(m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11){
        days_in_month = 30;
    }
    else{
        if(leap_year(y1)){
            days_in_month = 29;
        }
        else{
            days_in_month = 28;
        }
    }

    if(d1 < days_in_month){
        d2 = d1 + 1;
        m2 = m1;
        y2 = y1;
    }
    else{
        d2 = 1;
        if(m1 < 12){
            m2 = m1 + 1;
            y2 = y1;
        }
        else{
            m2 = 1;
            y2 = y1 + 1;
        }
    }
}

int main(){
    int d1, m1, y1;
    int d2, m2, y2;

    std::cout << "Enter day month year: " << std::endl;
    std::cin >> d1 >> m1 >> y1;

    next_date(d1, m1, y1, d2, m2, y2);

    std::cout << "Next date is: "
              << d2 << "/" << m2 << "/" << y2 << std::endl;

    return 0;
}