#include <iostream>
#include <string>
using namespace std;

string complexNumberMultiplay(string a,string b){
    int len_a=a.size(),len_b=b.size();
    int a_=0,b_=0,c_=0,d_=0;
    int f_a=1,f_b=1,f_c=1,f_d=1;
    int pos=0;
    if(a[pos]=='-'){pos++;f_a=-1;}
    for(;pos<len_a;pos++){
        if(a[pos]=='+'){pos++;break;}
        a_ = a_*10 + a[pos]-'0';
    }
    if(a[pos]=='-'){pos++;f_b=-1;}
    for(;pos<len_a;pos++){
        if(a[pos]=='i'){break;}
        b_ = b_*10 + a[pos]-'0';
    }
    pos=0;
    if(b[pos]=='-'){pos++;f_c=-1;}
    for(;pos<len_b;pos++){
        if(b[pos]=='+'){pos++;break;}
        c_ = c_*10 + b[pos]-'0';
    }
    if(b[pos]=='-'){pos++;f_d=-1;}
    for(;pos<len_b;pos++){
        if(b[pos]=='i'){break;}
        d_ = d_*10 + b[pos]-'0';
    }
    a_*=f_a;b_*=f_b;c_*=f_c;d_*=f_d;
    cout << a_ << " " << b_ << " " << c_ << " " << d_ << endl;
    /*
    (a*c)-(b*d) + (a*d)+(b*c) i
    */
    return to_string((a_*c_)-(b_*d_))+"+"+to_string((a_*d_)+(b_*c_))+"i";
}

int main(){
    cout << complexNumberMultiplay("20+22i","-18+-10i") << endl;
    return 0;
}