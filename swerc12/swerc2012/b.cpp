// B. Bits Equalizer

#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int c;
	cin >> c;
	for(int t = 1; t <= c; t++){
		string st1, st2;
		cin >> st1 >> st2;
		
		int i0, i1, u0, z1;
		i0 = i1 = u0 = z1 = 0;
		
		for(int i = 0; i < st1.size(); i++){
			if(st1[i] == '?'){
				if(st2[i] == '0')
					i0++;
				else
					i1++;
			}
			else if(st1[i] == '0' && st2[i] == '1')
				z1++;
			else if(st1[i] == '1' && st2[i] == '0')
				u0++;
		}
		int count = 0;
		if(z1 < u0){
			count = z1;
			u0 -= z1;
			z1 = 0;
		}
		else if(u0 < z1){
			count = u0;
			z1 -= u0;
			u0 = 0;
		}
		else{
			count = z1;
			z1 = u0 = 0;
		}
		
		if(z1 > 0){
			count += z1;
			z1 = 0;
		}
		if(u0 <= i1){
			count += u0;
			i1 -= u0;
			i0 += u0;
			u0 = 0;
		}
		count += i0 + i1;
		if(u0 > 0 || z1 > 0)
			cout << "Case " << t << ": " <<  -1 << endl;
		else
			cout << "Case " << t << ": " << count << endl;
	}
	
	return 0;
}
