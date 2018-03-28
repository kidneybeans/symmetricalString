//
//  main.cpp
//  1
//
//  Created by kidneybeans on 17/11/1.
//  Copyright ? 2017 kidneybeans. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int prStr(chara[], intn);
int prStr2(chara[], intn);

int main(intargc, constchar* argv[]) {
    // insert code here...
    chara[24] = "abacdlkjkljlhihadbcecbx";
    prStr2(a, 24);
    return0;
}

int prStr(chara[], intn)
{
    if(a ==NULL) return0;
    
    inti = 0, ti = 0, j = n-1, tj = n-1;
    boolflag = false;
    intmaxLen = 0, matchLen = 0;
    while(i < n)
    {
        matchLen = 0;
        
        if(flag) {
            j = n-1, tj = j;
        }
        
        while(a[i] != a[j] && j >=i)// cong hou wang qian zhao
        {
            j--;
        }
        if(j<=i)
        {
            i++;
            flag = true;
            continue;
        }
        
        ti = i, tj = j;
        while(a[ti] == a[tj] && ti < tj)
        {
            ti++;
            tj--;
            matchLen++;
        }
        
        if(matchLen && matchLen == (j-i)/2)
        {
            for(intk = i; k <= j; k++) {
                cout<< a[k] << " ";
            }
            cout<< endl;
            if(matchLen > maxLen)
                maxLen = matchLen;
            
        }
        elseif(j >i)
        {
            j--;
            flag = false;
            continue;
        }// ji xu sou suo
        
        i++;
        flag = true;
        
    }
    
    returnmaxLen;
}


int prStr2(chara[], intn)
{
    if(a ==NULL) return0;
    
    inti = 1, ti = 0, ti2 = 0;
    intmaxLen = 0, matchLen = 0;
    
    vector <int> maxLenID, matchLenID;
    
    while(i < n)
    {
        matchLen = 0;
    
        ti = i-1, ti2 = i+1;
        while(a[ti] == a[ti2] && ti >=0 && ti2 <n)
        {
            ti--;
            ti2++;
            matchLen++;
        }
        
        if(matchLen)
        {
            if(matchLen > maxLen)
                maxLen = matchLen;
            
            matchLenID.push_back(ti+1);
            matchLenID.push_back(ti2-1);
        }
        
        i++;
    }
    
    for(inti = 0; i < matchLenID.size(); i+=2)
    {
        for(intj = i+2; j < matchLenID.size(); j+=2)
        {
            if(matchLenID[i] > matchLenID[j] && matchLenID[i+1]< matchLenID[j+1]) // include
            {
               maxLenID.push_back(matchLenID[j]);
                maxLenID.push_back(matchLenID[j+1]);
            }
            elseif(matchLenID[i+1] == matchLenID[j])// overlap
            {
                if((matchLenID[i+1]-matchLenID[i])>(matchLenID[j+1]-matchLenID[j]))
                {
                    maxLenID.push_back(matchLenID[i]);
                    maxLenID.push_back(matchLenID[i+1]);
                }
                else{
                    maxLenID.push_back(matchLenID[j]);
                    maxLenID.push_back(matchLenID[j+1]);
                }
                i = j+2;
            }
        }
        maxLenID.push_back(matchLenID[i]);
        maxLenID.push_back(matchLenID[i+1]);
        
    }
    
    for(inti = 0; i < maxLenID.size(); i+=2) {
        for(intj = maxLenID[i]; j <= maxLenID[i+1]; j++)
            cout << a[j] << " ";
        cout << endl;
    }
    cout << endl;
    
    
    returnmaxLen;
}
