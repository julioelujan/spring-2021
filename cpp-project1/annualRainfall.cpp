//
//  annualRainfall.cpp
//  PracticeCode
//
//  Created by Julio Lujan on 1/29/21.
//  Copyright © 2021 Julio Lujan. All rights reserved.
// Given an array of amount of rain per month, calculates the total rainfall,
// the average rainfall, and the months with the max and min rainfall.

#include <iostream>
#include <string>

using namespace std;

int main(){
    double rainFall[12];
    string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October","November", "December"};
    double totalRain = 0.0;
    double avgRain = 0.0;
    int maxRain = 0;
    int minRain = 0;

    for (int i=0; i<12; i++){
        cout<<"Enter the rainfall for "<<month[i]<<": ";
        cin>>rainFall[i];
        while (rainFall[i] < 0){
            cout<<"invalid data (negative rainfall) -- retry";
            cin>>rainFall[i];
            cout<<"\n";
        }
    }
    
    //finding max and min rainfall values
    for(int i=0; i<12; i++){
        if (rainFall[i] < rainFall[minRain]){
            minRain = i;
        }
        if (rainFall[i] > rainFall[maxRain]){
            maxRain = i;
        }
        totalRain += rainFall[i];
    }
    avgRain = totalRain/12;
    cout<<"Total rainfall: "<<totalRain<<"\n";
    avgRain = totalRain/12;
    cout<<"Average rainfall: "<<avgRain<<"\n";
    
    cout<<"Least rainfall in: "<<month[minRain]<<"\n";
    cout<<"Most rainfall in: "<<month[maxRain]<<"\n";
    
}
