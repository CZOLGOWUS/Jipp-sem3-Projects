#include <iostream>

int main()
{
    float _height;
    float _mass;
    float BMI;

    std::cout << "what is your height in [cm]: ";
    std::cin >> _height;
    std::cout << std::endl;
    _height /= 100;

    std::cout << "what is your weight in [kg]: ";
    std::cin >> _mass;
    std::cout << std::endl;


    BMI = _mass/(_height*_height);
    std::cout<<"Your BMI is: " << BMI << std::endl;


    std::cout 
    <<"Zakresy wartości BMI:\n"
    <<"mniej niż 16 -   wygłodzenie\n"
    <<"16 - 16.99 -     wychudzenie\n"
    <<"17 - 18.49 -     niedowaga\n"
    <<"18.5 - 24.99 -   wartość prawidłowa\n"
    <<"25 - 29.99 -     nadwaga\n"
    <<"30 - 34.99 -     I stopień otyłości\n"
    <<"35 - 39.99 -     II stopień otyłości\n"
    <<"powyżej 40 -     otyłość skrajna\n\n";


    if( BMI - 16 < 0 )         { std::cout << "wygłodzenie\n" ; return  0;}   
    else if(BMI - 16 < 0.99  ) { std::cout << "wychudzenie\n" ; return  0;} 
    else if(BMI - 16 < 2.49  ) { std::cout << "niedowaga\n" ; return  0;} 
    else if(BMI - 16 < 8.99  ) { std::cout << "wartość prawidłowa\n" ; return  0;} 
    else if(BMI - 16 < 13.99 ) { std::cout << "nadwaga\n" ; return  0;} 
    else if(BMI - 16 < 18.99 ) { std::cout << "I stopień otyłości\n" ; return  0;} 
    else if(BMI - 16 < 23.99 ) { std::cout << "II stopień otyłości\n" ; return  0;} 
    else if(BMI - 16 < 24    ) { std::cout << "otyłość skrajna\n\n" ; return  0;} 


    return 0;
}