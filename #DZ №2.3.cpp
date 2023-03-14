#include <iostream>
 using namespace std;  
   
 template <typename x>  
 void kill_me_pls(int n) {  
     x* a = new x[n];  
     for (int i = 0; i < n; i++) {  
         cin >> a[i];  
     }  
     for (int i = 0; i < n; i++) {  
         cout << a[i] << " ";  
     }  
 }  
 int main() {  
     int n;  
     cin >> n;  
     kill_me_pls(n);  
     return 0;  
 } 
