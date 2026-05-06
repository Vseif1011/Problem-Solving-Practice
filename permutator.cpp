#include <vector>
#include <iostream> 
#include <algorithm>
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<long long> A(n);
    vector<long long> B(n);
 
    for(int i = 0; i < n; i++) cin >> A[i];
    
    for(int i = 0; i < n; i++) cin >> B[i];
 
    vector<long long> C(n);
 
    for(int i = 0; i < n; i++) {
        long long w = 1LL * (i + 1) * (n - i);
        C[i] = A[i] * w;
    }
 
    sort(C.begin(), C.end());
    
     sort(B.begin(), B.end(), greater<long long>());
 
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += C[i] * B[i];
    }
 
    cout << sum;
}


// Wrong implementation 

// #include <vector>
// #include <iostream> 
// #include <algorithm>
// #include <utility>
// using namespace std;

// int main() {
//     int n; cin>>n;
//     vector<int>A(n);
//     vector<int>B(n);

//     for(int i=0;i<n;i++) {
//         int c; cin>>c; A[i]=c;
//     }
//     for(int i=0;i<n;i++) {
//         int c; cin>>c; B[i]=c;
//     }

//     sort(A.begin(),A.end());

//     vector<bool>booked(n,false);
//     for(int i=0;i<n;i++) {
//         int currentMIN = INT_MAX;
//         for (int j=0;j<n;j++) {
//             if(A[i]*B[j]<currentMIN && !booked[j]) {
//                 currentMIN=A[i]*B[j];
//                 swap(B[j],B[i]);
//                 booked[j] = true;
//             }
//         }
//     }
// }
