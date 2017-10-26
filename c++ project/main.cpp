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
    //const CMoney operator +(const CMoney& bMoney);
    friend const CMoney operator +(const CMoney &aMoney, const CMoney &bMoney);
    friend  ostream& operator <<(ostream& outStream, const CMoney& aMoney);
    
private:
    int m_nDollar;
    int m_nCent;
    
};


//CMoney Add(CMoney aMoney, CMoney bMoney);
//const CMoney operator +(const CMoney &aMoney, const CMoney &bMoney);


void ShowMoney(CMoney aMoney);

int main(){
    CMoney aMoney(3, 60), bMoney(9, 45), addedMoney;
    addedMoney = aMoney + bMoney;
    //addedMoney = Add(aMoney, bMoney);
    //ShowMoney(aMoney);
    cout << aMoney << " + " << bMoney << " = " << addedMoney << endl;
    /*
    cout << " + ";
    ShowMoney(bMoney);
    cout << " + ";
    cout << " = ";
    ShowMoney(addedMoney);
    cout<<endl;
     */
}

//CMoney Add(CMoney aMoney, CMoney bMoney){

const CMoney operator +(const CMoney &aMoney, const CMoney &bMoney){
    
    int nCent = aMoney.m_nCent + bMoney.m_nCent;
    int nCarry = nCent / 100;
    nCent = nCent % 100;
    int nDollar = aMoney.m_nDollar + bMoney.m_nDollar + nCarry;
    
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
//멤버 함수 쓰는 이유 변수를 직접 엑세스 해서 속도 높이기 위함
/*
const CMoney CMoney::operator +(const CMoney &bMoney)
{
    int nCent = m_nCent + bMoney.m_nCent;
    int nCarry = nCent / 100;
    nCent = nCent % 100;
    int nDollar = m_nDollar + bMoney.m_nDollar + nCarry;
    
    return CMoney(nDollar, nCent);
}
*/

//cout이라는 포트의 주소를 받는 것,
 ostream& operator <<(ostream& outStream, const CMoney& aMoney)
{
    
   outStream << "$" << aMoney.m_nDollar <<"."<<aMoney.m_nCent;

    return outStream;
}

