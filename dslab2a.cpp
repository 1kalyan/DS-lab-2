#include<iostream>
using namespace std;

void gcd(int a,int b){
    int c,d;
    while(d>0){
    c = a/b;
    d = a-b*c;
    cout<<a<<"="<<b<<"x"<<c<<"+"<<d<<endl;
    a = b;
    b =d;
    }
    cout<<"GCD = "<<a;    
}
/*ax + by = gcd(a,b)
gcd(a,b)=gcd(b,a%b)
gcd(b,a%b)=bx1 +(a%b)y1
a%b = a-(a/b)*b
from this equation

ax+by = bx1 +(a%b)y1
ax + by = bx1 + (a-(a/b)*b)y1
ax + by = ay1+b(x1-(a/b)*y)
therefore x = y1 , y = x1-(a/b)*y1 
*/

struct extended{
    int x,y,gcd;

};
extended Euclid(int a,int b){
    if(b==0){
        extended ans;
        ans.x =1;
        ans.gcd =a;
        ans.y =0;
        return ans;
    }
    extended smallans = Euclid(b,a%b);
    extended ans;
    ans.gcd = smallans.gcd;
    ans.x = smallans.y;
    ans.y=smallans.x - (a/b)*smallans.y;
    return ans;
}

int main(){
    int a,b;
    cout<<"Enter two number a and b where a>b: ";
    cin>>a>>b;
    gcd(a,b);
    extended ans = Euclid(a,b);
    cout<<endl<<"x = "<<ans.x<<endl<<"y ="<<ans.y;
    return 0;

}
