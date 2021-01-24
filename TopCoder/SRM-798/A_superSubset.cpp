#include<bits/stdc++.h>
using namespace std;

class  SyllableCountEstimator{
public:
	int estimate(string w){
        int ans =0;
        int n =w.size();
     	for(int i =0;i<n;i++)
        	if(w[i] == 'a' ||w[i] == 'o' ||w[i] == 'i' ||w[i] == 'e' ||w[i] == 'u') ans++;
        if(n>=2)
		for(int i =0;i<n-1;i++)   {
            if(w[i] == 'a' && w[i+1] == 'u') ans --;
            if(w[i] == 'o' && w[i+1] == 'a') ans --;
            if(w[i] == 'o' && w[i+1] == 'o') ans --; 
        }
        
		if(w[n-1] =='e') ans--;
		if(n>=3) {
            for(int i =0;i<n-2;i++) 
            	if(w[i] == 'i' && w[i+1] == 'o' &&w[i+2] =='u' ) ans --;
                
        	 if(w[n-3] != 'a' && w[n-3] != 'o' &&w[n-3] != 'i' &&w[n-3] != 'e' &&w[n-3] != 'u'){
                 if(w[n-2]=='l' && w[n-1] == 'e')
                     ans++;
             }
         }
		if(ans<1) ans=1;
        return ans;
    }
};