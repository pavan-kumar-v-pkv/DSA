// Each lemonade at a booth sells for $5. Consumers are lining up to place 
// individual orders, following the billing order. Every consumer will purchase 
// a single lemonade and may pay with a $5, $10, or $20 bill. Each customer must
// receive the appropriate change so that the net transaction is $5. Initially,
// here is no change available.
// Determine if it is possible to provide the correct change to every customer.
// Return true if the correct change can be given to every customer, and false 
// otherwise.
// Given an integer array bills, where bills[i] is the bill the ith customer
// pays, return true if the correct change can be given to every customer, and
// false otherwise.
#include<bits/stdc++.h>
using namespace std;

// time: O(N) where N is the length of the bills array
// space: O(1) since we are using a constant amount of extra space
bool lemonadeChange(vector<int>& bills){
    int five = 0, ten = 0; // counter for $5 and $10 bills
    // iterate through each bill in the bills array
    for(int i=0;i<bills.size();i++){
        if(bills[i]==5){
            five++; // increment $5 bill count
        }
        else if(bills[i] == 10){
            if(five){
                five--; // give $5 change
                ten++; // increment $10 bill count
            }
            else{
                return false; // cannot give change
            }
        }
        else{
            // customer pays with $20 bill
            if(ten & five){
                ten--; //give $10 change
                five--; // give $5 change
            }
            else if(five >= 3){
                five -= 3; // give three $5 bills as change
            }
            else{
                return false; // cannot give change
            }

        }
         
    }
    return true; // if we reach here, it means we can give change to all customers
}