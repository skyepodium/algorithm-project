#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <math.h>
using namespace std;

class CMoney {

    public:
        CMoney();
        ~CMoney();
        int GetDollar() const;
        int GetCent() const;
        CMoney(int nDollar, int nCent);
    
    private:
        int m_nDollar;
        int m_nCent;

};

//CMoney Add(CMoney aMoney, CMoney bMoney);
const CMoney operator +(const CMoney &aMoney, const CMoney &bMoney);


void ShowMoney(CMoney aMoney);

int main(){
    CMoney aMoney(3, 60), bMoney(9, 45), addedMoney;
    addedMoney = aMoney + bMoney;
//    addedMoney = Add(aMoney, bMoney);
    ShowMoney(aMoney);
    cout << " + ";
    ShowMoney(bMoney);
    cout << " + ";
    cout << " = ";
    ShowMoney(addedMoney);
    cout<<endl;
}

//CMoney Add(CMoney aMoney, CMoney bMoney){
const CMoney operator +(const CMoney &aMoney, const CMoney &bMoney){

    int nCent = aMoney.GetCent() + bMoney.GetCent();
    int nCarry = nCent / 100;
    nCent = nCent % 100;
    int nDollar = aMoney.GetDollar() + bMoney.GetDollar() + nCarry;
    
    return CMoney(nDollar, nCent);
}

int CMoney::GetDollar() const{
    
    return m_nDollar;
}


int CMoney::GetCent() const{
    
    return m_nCent;
}

CMoney::CMoney(){
    
}

CMoney::~CMoney(){
    
}

CMoney::CMoney(int nDollar, int nCent){
    m_nDollar = nDollar;
    m_nCent = nCent;
}


void ShowMoney(CMoney aMoney){
    cout << "$" << aMoney.GetDollar()<<"."<<aMoney.GetCent();
}

