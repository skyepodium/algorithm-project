#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <math.h>
using namespace std;


class CTheater
{
    
    
private:
    string m_strName;
    int m_nTripTime;
    int m_pnShowTime[10];
    static int m_nTheater;
   
    
public:
    CTheater();
    ~CTheater();
    
    void SetName(string strName);
    string GetName();
    void SetTripTime(int TripTime);
    int GetTripTime();
    void SetShowTime(int* pnShowTime, int nSize);
    void GetShowTime(int* pnShowTime, int nSize);
    void PrintShowTime();
    static void ShowNumberOfTheater();
    static void AnotherStaticFunction();
    
    CTheater(string strName, int nTripTime, int* pnShowTime, int nSize);
    void ShowMe();
};

int CTheater::m_nTheater = 0;

int main() {
    CTheater myTheater;
    
    const int nSize = 10;
    int pnShowTime[nSize] = {1100, 1300, 1600, 1830};
    CTheater::ShowNumberOfTheater();
    
    myTheater.SetName("강남CGV");
    myTheater.SetTripTime(10);
    myTheater.SetShowTime(pnShowTime, nSize);
    
    myTheater.PrintShowTime();
    
    CTheater yourTheater("이수 메가박스", 10, pnShowTime, nSize);
    yourTheater.ShowMe();
    CTheater::ShowNumberOfTheater();
    
    myTheater = CTheater("코엑스 메가박스", 15, pnShowTime, nSize);//재 초기화
    myTheater.ShowMe();
    return 0;
}

void CTheater::SetName(string strName){
    m_strName = strName;
}

string CTheater::GetName(){
    
    return string(m_strName);
}

void CTheater::SetTripTime(int TripTime){
    m_nTripTime = TripTime;
}

int CTheater::GetTripTime(){
    
    return int(m_nTripTime);
}

void CTheater::SetShowTime(int* pnShowTime, int nSize){
    
    for(int nIndex = 0; nIndex < nSize; nIndex++){
        m_pnShowTime[nIndex] = pnShowTime[nIndex];
    }
}

void CTheater::GetShowTime(int* pnShowTime, int nSize){
    
    for(int nIndex = 0; nIndex < nSize; nIndex++){
        pnShowTime[nIndex] = m_pnShowTime[nIndex];
    }
}

void CTheater::PrintShowTime()
{
    for(int nIndex = 0; nIndex < 10; nIndex++){
        if(m_pnShowTime[nIndex] != 0){
            cout<<m_pnShowTime[nIndex] << endl;
        }
    }
}

CTheater::CTheater()
{
    m_nTheater = m_nTheater + 1;
}

CTheater::~CTheater()
{
    
}

CTheater::CTheater(string strName, int nTripTime, int* pnShowTime, int nSize)
{
    m_nTheater = m_nTheater + 1;
    
    m_strName = strName;
    m_nTripTime = nTripTime;
    SetShowTime(pnShowTime, nSize);
    
}

void CTheater::ShowMe()
{
    cout<< m_strName <<endl;
    cout<< "Trip Time is" << m_nTripTime << endl;
    PrintShowTime();
}

void CTheater::ShowNumberOfTheater(){
    int myLocalVar = 3;
    myLocalVar = m_nTheater + 1;
    cout<< myLocalVar <<endl;
    cout<<"The number of Theater is "<<m_nTheater<<endl;
    AnotherStaticFunction();
}

void CTheater::AnotherStaticFunction(){
    
    cout<<" Just for Fun!" <<endl;
    
}
