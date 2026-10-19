/*
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
        std::cout << "error";
        return 0;
    }
    int sqrlen= std::pow((x1 - x2), 2) + std::pow((y1 - y2), 2);
    if(sqrlen==5){
        std::cout<< "valid move";
    }
    else{
        std::cout<< "not valid move";
    }
    return 0;
}
*/



#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>




int main() {
    // Generate and display a random starting position
    // Initialise the move counter
    // Seed the random number generator
std::srand(std::time(NULL));//按照时间产生种子

// Generate random coordinates from 2 to 7
int x1 = std::rand() % 6 + 2;
int y1 = std::rand() % 6 + 2;
int x2, y2, x0, y0;
x0=x1;
y0=y1;
int i=5;
    // While the knight has not reached a corner square:
        // Read destination coordinates from the user
        // If the move is valid:
            // Update position, increment move counter, display new position
        // Otherwise:
            // Display invalid move message
    while(x1*y1!=1 && x1*y1!=64 && !(x1==1 && y1==8) && !(x1==8 && y1==1)){
        
        if (i>=2){
            std::cout << i << " steps remain" << std::endl;
        }
        else if (i==1){
            std::cout << "only one step remain!" << std::endl;
        }
        else{
            std::cout << "no step remain, please try again!" << std::endl;
            x1=x0;
            y1=y0;
            i=5;
        }


        if (i==5){
            std::cout << "start point (" << x1 << ", " << y1 << ")" << std::endl;
        }
        else{
            std::cout << "Reach point (" << x1 << ", " << y1 << ")" << std::endl;
        }



        std::cout << "Please enter your next move (x y):" << std::endl;//玩家输入下一步坐标
        std::cin >> x2 >> y2;
        if( x2<1 || y2<1 || x2>8 || y2>8){
            std::cout << "Error: out of bounds! Please try again." << std::endl;
            continue;
        }


        int dx = x1 - x2;
        int dy = y1 - y2;
        int sqrlen = dx * dx + dy * dy;
        // int sqrlen= std::pow((x1 - x2), 2) + std::pow((y1 - y2), 2);     AI说不好，浮点数可能不正确。
        if(sqrlen==5){
            std::cout<< "valid move, nice"<< std::endl << std::endl;
            i--;
            x1=x2;
            y1=y2;
        }
        else{
            std::cout<< "Error: not valid move! Please try again." << std::endl;
            continue;
        }        

    }
std::cout << "Reach the corner (" << x1 << ", " << y1 << "), escape!" << std::endl;
return 0;

}








