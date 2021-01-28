//
//  reverseArray.cpp
//  PracticeCode
//
//  Created by Julio Lujan on 3/30/20.
//  Copyright © 2020 Julio Lujan. All rights reserved.
// Reverses the order of a user-defined array of size n

#include <iostream>

using namespace std;


int main(){
    int n;
    int temp;
  
    cout<< "Enter an the size of the array you would like to reverse"<<endl;
    cin>>n;
    int array[n];
    cout<<"Enter the integers of the array"<<endl;
    for (int i = 0; i < n; ++i) {
          cin >> array[i];
      }
    cout << "The numbers in the array are: "<<endl;

        //  print array elements
        for (int i = 0; i < n; ++i) {
            cout << array[i] << "  ";
        }
    cout<<endl;

    //reversing the array:
    for (int i=0; i<n/2; i++){
        temp = array[i];
        array[i] = array[n-i-1];
        array[n-i-1] = temp;
}
    cout << "The reverse order of the numbers in the array are: "<<endl;

        //  print array elements
        for (int i = 0; i < n; ++i) {
            cout << array[i] << "  ";
        }
    cout<<endl;
}
