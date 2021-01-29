//
//  foodCalculator_perWeek.cpp
//  PracticeCode
//
//  Created by Julio Lujan on 1/29/21.
//  Copyright © 2021 Julio Lujan. All rights reserved.
/*/ Given 3 monkeys living in a zoo 7 days a week: This program iterates across a two dimensional array in order to calculate the total weekly average food eaten by 3 different monkeys each day of the week.(Starting on Sunday)/*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    int eatenWeekly[3][7];  //3 monkeys(rows) and 7 days(columns)
    int max, min, total = 0, monkeyMin = 0, monkeyMax = 0, dayMin = 0, dayMax = 0;
    double avg;
    string dayofweek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    //gathering the data from the user about each monkey's eating amount for each day of the week
    for (int day = 0; day<7; day++){
        for (int monkey = 0; monkey<3; monkey++){
            cout<<"Enter the food eaten by monkey #"<<monkey+1<<" on "<<dayofweek[day]<<":";
            cin>>eatenWeekly[monkey][day];
            if (eatenWeekly[monkey][day] < 0){
                cout<<"invalid (negative) food quantity -- re-enter";
                cin>>eatenWeekly[monkey][day];
                            cout<<"\n";
            }
            total += eatenWeekly[monkey][day];
        }
    }
    //initializing the min and max variables
    min = eatenWeekly[0][0];
    max = eatenWeekly[0][0];
    
    //finding the max and min values
    for (int monkey = 0; monkey<3; monkey++){
        for (int day = 0; day<7; day++){
            if (eatenWeekly[monkey][day] < min){
                min = eatenWeekly[monkey][day];
                monkeyMin = monkey+1;
                dayMin = day;
            }
            if (eatenWeekly[monkey][day] > max){
                max = eatenWeekly[monkey][day];
                monkeyMax = monkey;
                dayMax = day;
            }
        }
    }
    //finding the average amount of food eaten by one monkey a week
    avg = (double)total/7.0;
    //output data
    cout<<"Average food consumed daily: "<<avg<<"\n";
    cout<<"The least daily food consumed was by Monkey #"<<monkeyMin<<" on "<<dayofweek[dayMin]<<".\n";
    cout<<"The most daily food consumed was by Monkey #"<<monkeyMax+1<<" on "<<dayofweek[dayMax]<<".\n";
}
