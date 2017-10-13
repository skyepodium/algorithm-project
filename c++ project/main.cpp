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
    
public:
    void SetName(string strName);
    string GetName();
    void SetTripTime(int TripTime);
    int GetTripTime();
    void SetShowTime(int* pnShowTime, int nSize);
    void GetShowTime(int* pnShowTime, int nSize);
    void PrintShowTime();
};

int main() {
    CTheater myTheater;

    const int nSize = 10;
    int pnShowTime[nSize] = {1100, 1300, 1600, 1830};
    
    
    myTheater.SetName("강남CGV");
    myTheater.SetTripTime(10);
    myTheater.SetShowTime(pnShowTime, nSize);
    
    myTheater.PrintShowTime();
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
