#include <iostream>

using namespace std;

struct info{
    double x, y;
};

struct edge{
    info first, second;
};

int main(){
    edge a, b;
    a.first.x = 1;
    a.first.y = 1;
    a.second.x = 4;
    a.second.y = 4;

    b.first.x = 1;
    b.first.y = 4;
    b.second.x = 4;
    b.second.y = 1;
    
    double delta_a, delta_b, bias_a, bias_b;
    delta_a = (a.second.y - a.first.y) / (a.second.x - a.first.y);
    delta_b = (b.second.y - b.first.y) / (b.second.x - b.first.y);

    bias_a = a.first.y - delta_a * a.first.x;
    bias_b = b.first.y - delta_b * b.first.x;
    
    // a.first.y = a.first.x * delta_a + bias_a;
    /*
     (a.first.y - a.second.y)x - (a.first.x - a.second.x)y = (a.first.y - a.second.y) * a.first.x - (a.first.x - a.second.x) * a.first.y;
    */
    //(a.first.y - a.second.y)x = (a.first.y - a.second.y) * a.first.x - (a.first.x - a.second.x) * a.first.y + (a.first.x - a.second.x)y;
    x = ((a.first.y - a.second.y) * a.first.x - (a.first.x - a.second.x) * a.first.y + (a.first.x - a.second.x)y / (a.first.y - a.second.y));
    (b.first.y - b.second.y)x - (b.first.x - b.second.x)y = (b.first.y - b.second.y) * b.first.x - (b.first.x - b.second.x) * b.first.y;
    
    (b.first.x - b.second.x)y = (b.first.y - b.second.y)((a.first.y - a.second.y) * a.first.x - (a.first.x - a.second.x) * a.first.y + (a.first.x - a.second.x)y / (a.first.y - a.second.y)); - (b.first.y - b.second.y) * b.first.x - (b.first.x - b.second.x) * b.first.y;
    
}
