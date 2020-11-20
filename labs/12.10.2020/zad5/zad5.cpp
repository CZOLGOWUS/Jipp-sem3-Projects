#include <iostream>     
#include <iomanip> 



int main () 
{

    int mac1[2][3];
    int mac2[3][2];

    std::cout << "podaj pierwszą kolumne macierzy 2x3\n";
    std::cin >> mac1[0][0] >> mac1[1][0];
    std::cout << "podaj drugą kolumne macierzy 2x3\n";
    std::cin >> mac1[0][1] >> mac1[1][1];
    std::cout << "podaj trzecią kolumne macierzy 2x3\n";
    std::cin >> mac1[0][2] >> mac1[1][2];


    std::cout << "podaj pierwszą kolumne macierzy 3x2\n";
    std::cin >> mac2[0][0] >> mac2[1][0] >> mac2[2][0];
    std::cout << "podaj drugą kolumne macierzy 3x2\n";
    std::cin >> mac2[0][1] >> mac2[1][1] >> mac2[2][1];

    int macWynik[4] = {
        mac2[0][0]*mac1[0][0] + mac2[1][0]*mac1[0][1] + mac2[2][0]*mac1[0][2], mac2[0][0]*mac1[1][0] + mac2[1][0]*mac1[1][1] + mac2[2][0]*mac1[1][2],
        mac2[0][1]*mac1[0][0] + mac2[1][1]*mac1[0][1] + mac2[2][1]*mac1[0][2], mac2[0][1]*mac1[1][0] + mac2[1][1]*mac1[1][1] + mac2[2][1]*mac1[1][2]
    };


    std::cout << "|" << std::setw(3) << macWynik[0] << std::setw(3) << "" << macWynik[1] << "|\n"; 
    std::cout << "|" << std::setw(3) << macWynik[2] << std::setw(3) << "" << macWynik[3] << "|\n"; 


    return 0;
}