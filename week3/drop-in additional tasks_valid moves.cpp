#include <iostream>
#include <cmath>

int main(){
    int x1, y1, x2, y2;

    std::cout << "start point   ";
    std::cin >> x1 >> y1;
    std::cout << "end point   ";
    std::cin >> x2 >> y2;
    if( x1<1 || x2<1 || y1<1 || y2<1 ||
        x1>8 || x2>8 || y1>8 || y2>8){
        std::cout << "error: out of boundsss";
        return 0;
    }
    int dx = x1 - x2;
    int dy = y1 - y2;
    int sqrlen = dx * dx + dy * dy;
    if(sqrlen==5){
        std::cout<< "valid move";
    }
    else{
        std::cout<< "not valid move";
    }
    return 0;
}