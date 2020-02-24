/*
Author: Liam
Date: Feb 5, 2020
0 ms
8.2MB

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"

 

Constraints:

    The given address is a valid IPv4 address.

*/

class Solution {
public:
    string defangIPaddr(string address) {
        int length = address.length();
        for (int i = 0; i<length; i++) {
            if (address[i] == '.'){
                address.replace(i,1,"[.]");
                i= i+2;
                length = length + 2;
            }
        }
        return address;
    }
};