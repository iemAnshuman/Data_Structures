#include<iostream>
using namespace std;
int main() {

    int n;
    cin>>n;

    int  X=0 ;

    char A[n][3];

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>A[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        if(A[i][1] == '+'){
            ++X ;
        }
        if(A[i][1] == '-'){
            --X ;
        }
    }
    
    cout<<X;


    return 0;
}