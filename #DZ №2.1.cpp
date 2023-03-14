#include <iostream>  
 using namespace std;  
 int main() {  
     int n;  
     cin >> n;  
     int m = n;  
     int* a = new int[n];  
     int* b = new int[m];  
     for (int i = 0; i < n; i++) {  
         cin >> a[i];  
     }  
     int minimal = 1000000;  
     int indi = 0;  
     for (int i = 0; i < m; i++) {  
         int k = 0;  
         for (int j = 0; j < n; j++) {  
             if (a[j] <= a[0]) {  
                 k = a[j];  
                 indi = j;  
             }  
         }  
         b[i] = k;  
         for (int j = indi; j < n-1; j++) {  
             a[j] = a[j + 1];  
         }  
         n--;  
     }  
     for (int j = 0; j < m; j++) {  
         cout << b[j] << "\t";  
     }  
 } 
