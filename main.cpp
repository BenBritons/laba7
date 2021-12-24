#include "NodeStack.h"
#include "StackOnArray.h"
#include "StackOnList.h"
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include "BracketBalance.h"

using std::set;
using std::string;

int prior(char v){
    switch(v){
        case '(': return 1;
        case '+':
        case '-': return 6;
        case '*':
        case '/': return 7;
        default:
            return 0;
    }
}
bool is_op(char c){
    return c=='+' || c=='-' || c=='*' || c=='/' || c == '%' || c == '>' || c == '<' || c == '&' || c == '^' || c == '|';
}

bool is_number(char c){
    return c>='0' && c<='9';
}

double char_to_double(char s){
    return s - '0';
}

void Task2(){
    StackOnList<double> d_st;
    StackOnList<char> d_ch;
    double tmp1;
    double tmp2;
    int j;
    string exp;
    std::cin >> exp;
    for(int i = 0; i < exp.length(); ++i){
        if(is_number(exp[i])){
            j = i;
            tmp1 = 0;
            tmp2 = 0;
            tmp1 = tmp1 + char_to_double(exp[j])*pow(10, j - i);
            j++;
            while(is_number(exp[j])){
                tmp1 = tmp1*10;
                tmp1 = tmp1 + char_to_double(exp[j]);
                j++;
            }
            i = j;
            if(exp[j] == '.'){
                j++;
                while(is_number(exp[j])){
                    tmp2 = tmp2 + char_to_double(exp[j])*pow(10, -(j - i));
                    j++;
                }
                i = j;
            }
            d_st.Push(tmp1 + tmp2);
        }
        if(exp[i] == '('){
            d_ch.Push(exp[i]);
        }
        if(is_op(exp[i])){
            if(d_ch.IsEmpty()||(prior(exp[i]) >= prior(d_ch.TopValue()))){
                d_ch.Push(exp[i]);
            }else if(prior(exp[i]) < prior(d_ch.TopValue())){
                double t1;
                double t2;
                while(!d_ch.IsEmpty() || prior(exp[i]) < prior(d_ch.TopValue())){
                    if( d_ch.TopValue()  == '+'){
                        t1 = d_st.TopValue();
                        d_st.Pop();
                        t2 = d_st.TopValue();
                        d_st.Pop();
                        d_st.Push(t1 + t2);
                        d_ch.Pop();
                    }else if( d_ch.TopValue() == '-'){
                        t1 = d_st.TopValue();
                        d_st.Pop();
                        t2 = d_st.TopValue();
                        d_st.Pop();
                        d_st.Push(t2 - t1);
                        d_ch.Pop();
                    }else if( d_ch.TopValue()  == '*'){
                        t1 = d_st.TopValue();
                        d_st.Pop();
                        t2 = d_st.TopValue();
                        d_st.Pop();
                        d_st.Push(t1 * t2);
                        d_ch.Pop();
                    }else if( d_ch.TopValue()  == '/'){
                        t1 = d_st.TopValue();
                        d_st.Pop();
                        t2 = d_st.TopValue();
                        d_st.Pop();
                        d_st.Push(t2 / t1);
                        d_ch.Pop();
                    }
                }
                d_ch.Push(exp[i]);
            }
        }
        if(exp[i] == ')'){
            double t1;
            double t2;
            while(d_ch.TopValue() != '('){
                if(d_ch.TopValue() == '+'){
                    t1 = d_st.TopValue();
                    d_st.Pop();
                    t2 = d_st.TopValue();
                    d_st.Pop();
                    d_st.Push(t1 + t2);
                    d_ch.Pop();
                }
                if(d_ch.TopValue() == '-'){
                    t1 = d_st.TopValue();
                    d_st.Pop();
                    t2 = d_st.TopValue();
                    d_st.Pop();
                    d_st.Push(t2 - t1);
                    d_ch.Pop();
                }
                if(d_ch.TopValue() == '*'){
                    t1 = d_st.TopValue();
                    d_st.Pop();
                    t2 = d_st.TopValue();
                    d_st.Pop();
                    d_st.Push(t1 * t2);
                    d_ch.Pop();
                }
                if(d_ch.TopValue() == '/'){
                    t1 = d_st.TopValue();
                    d_st.Pop();
                    t2 = d_st.TopValue();
                    d_st.Pop();
                    d_st.Push(t2 / t1);
                    d_ch.Pop();
                }
            }
            d_ch.Pop();
        }
    }
    double t1;
    double t2;
    while(!d_ch.IsEmpty()){
        if( d_ch.TopValue()  == '+'){
            t1 = d_st.TopValue();
            d_st.Pop();
            t2 = d_st.TopValue();
            d_st.Pop();
            d_st.Push(t1 + t2);
            d_ch.Pop();
        }else if( d_ch.TopValue() == '-'){
            t1 = d_st.TopValue();
            d_st.Pop();
            t2 = d_st.TopValue();
            d_st.Pop();
            d_st.Push(t2 - t1);
            d_ch.Pop();
        }else if( d_ch.TopValue()  == '*'){
            t1 = d_st.TopValue();
            d_st.Pop();
            t2 = d_st.TopValue();
            d_st.Pop();
            d_st.Push(t1 * t2);
            d_ch.Pop();
        }else if( d_ch.TopValue()  == '/'){
            t1 = d_st.TopValue();
            d_st.Pop();
            t2 = d_st.TopValue();
            d_st.Pop();
            d_st.Push(t2 / t1);
            d_ch.Pop();
        }
    }

    std::cout << d_st.TopValue();

}


void Task1(){
    set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string form;
    StackOnList<string> st = StackOnList<string>();
    std::cin >> form;
    for( int i = 0; i < form.length(); ++i){
        if(form[i] == 'm'){
            if(form[i+1] == 'i'){
                st.Push("min");
                i = i + 2;
                continue;
            } else if(form[i+1] == 'a'){
                st.Push("max");
                i = i + 2;
                continue;
            }
        }
        if(numbers.find(form[i]) != numbers.end()){
            string a(1, form[i]);
            st.Push(a);
        }
        if(form[i] == ')'){
            int a1 = std::stoi(st.Top()->value);
            st.Pop();
            int a2 = std::stoi(st.Top()->value);
            st.Pop();
            if(st.Top()->value == "max"){
                st.Pop();
                st.Push(std::to_string(std::max(a1, a2)));
            }
            if(st.Top()->value == "min"){
                st.Pop();
                st.Push(std::to_string(std::min(a1, a2)));
            }


        }
    }
    std::cout << st.Top()->value;


}

int main() {
    Task2();
    return 0;
}

