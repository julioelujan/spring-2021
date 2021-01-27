// This This program calculates the annual change in population over a certain amount of time.
//Created by: julioelujan
//Github: spring-2021/cpp-populationCalculator
//****************************************************************************

#include<iostream>
using namespace std;

double popCalculator(double P, double B, double D, int A, int M);


int main(){
    double P;    //starting size of a population
    double B;    //annual birth rate
    double D;    //annual death rate
    int A;    //average annual number of people arrived
    int M;    //average annual number of people moved away
    int nYears; //number of years to display
    
    cout<<"This program calculates population change."<<endl;
    cout<<"Enter the starting population size: ";
    cin>>P;
    if (P<2){
        cout<<"Starting population must be 2 or more."<<endl;
        cout<<"Please re-enter: ";
        cin>>P;
    }
    
    cout<<"Enter the annual birth rate (as % of current population): ";
    cin>>B;
    if (B<0){
        cout<<"Birth rate percent cannot be negative."<<endl;
        cout<<"Please re-enter: ";
        cin>>B;
    }
    
    cout<<"Enter the annual death rate (as % of current population): ";
    cin>>D;
    if (D<0){
        cout<<"Death rate percent cannot be negative."<<endl;
        cout<<"Please re-enter: ";
        cin>>D;
    }
    
    cout<<"How many individuals move into the area each year? ";
    cin>>A;
    if (A<0){
        cout<<"Arrivals cannot be negative."<<endl;
        cout<<"Please re-enter: ";
        cin>>A;
    }
    
    cout<<"How many individuals leave the area each year? ";
    cin>>M;
    if (M<0){
        cout<<"Departures cannot be negative."<<endl;
        cout<<"Please re-enter: ";
        cin>>M;
    }
    
    cout<<"For how many years do you wish to view population changes? "<<endl;
    cin>>nYears;
    if (nYears<1){
        cout<<"Years must be one or more."<<endl;
        cout<<"Please re-enter: ";
        cin>>nYears;
    }
    cout<<endl;
    cout<<"Starting population: "<<P<<endl;

    for(int i=1;i <= nYears;i++){
        P = transientPop(P, B, D, A, M);
        cout<<endl;
        cout<<"Population at the end of year "<<i<<" is "<<(int)P<<" ";
    }
    cout<<endl;

}
         
double popCalculator(double P, double B, double D, int A, int M){
    double N = P + ((B*P)/100) - ((D*P)/100) + A - M;
    return N;
}
