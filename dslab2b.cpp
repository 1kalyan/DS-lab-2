//wap to implement binary integer addition, multilication and division

#include<iostream>
#include<bitset>
using namespace std;

int main(){
    int a,b,c;
    cout<<"Enter two number: ";
    cin>>a>>b;
    //converting to binary from bitset
    bitset<8>binary_a(a);
    bitset<8>binary_b(b);
    cout<<"For sum"<<endl;
    cout<<"  "<<binary_a<<endl<<"+ "<<binary_b<<endl;
    cout<<"-----------"<<endl;
    //sum calculate
    bitset<9>result =a+b ;
    cout<<result<<endl<<endl;

    
    //multiplication
    cout<<"For multiplication"<<endl;
    bitset<9>mul = a*b;
    cout<<"  "<<binary_a<<endl<<"x "<<binary_b<<endl;
    cout<<"-----------"<<endl;
    cout<<mul<<endl<<endl;

    //division
    cout<<"For division"<<endl;
    bitset<9>div = a/b;
    cout<<binary_a<<endl<<"________"<<endl<<binary_b<<endl;
    cout<<"-----------"<<endl;
    cout<<"="<<div;
    return 0;

}