#include<bits/stdc++.h>
using namespace std;
#define NMAX 1001
string m,n;
char a[NMAX], b[NMAX], c[NMAX], temp[NMAX];

void nhap(){
	cin>>m>>n;
	memset(a, '0', NMAX);
	memset(b, '0', NMAX);
	memset(c, '0', NMAX);
	memset(temp, '0', NMAX);
	for (int i = m.length(); i>0; i--){
		a[m.length() - i] = m[i-1];
	}
	for (int i = n.length(); i>0; i--){
		b[n.length() - i] = n[i-1];
	}
}
void xuly(){
	int cnt = n.length(),sodu = 0, d, i = 0, j = 0,dem,k = 0,sodu1;
	int cnt1 = m.length();
	while (cnt1>0||sodu!=0){
		d = (a[i]-'0')*(b[0]-'0')+sodu;
		sodu = d/10;
		while (d>=10){
			d%=10;
		}
		c[i] = d+'0';
		cnt1--;i++;
	}
	for (int i = 1; i< cnt; i++){
	cnt1 = m.length();j = 0;dem++;
	while (cnt1>0||sodu!=0){
		d = (a[j]-'0')*(b[i]-'0')+sodu;
		sodu = d/10;
		while (d>=10){
			d%=10;
		}
		temp[j+dem] = d+'0';
		cnt1--;j++;
		}
		while (j>0 || sodu1!=0){
		d = c[k]+temp[k]-'0'-'0'+sodu1;
		sodu1 = 0;
		while (d>=10){
			d%=10;
			sodu1++;
		}
		c[k] = d+'0';
		cnt++;
		j--;k++;
	}
	}
}
void xuat(){
	cout<<m<<" "<<n<<endl;
	for (int i = 0; i<= 10; i++) cout<<a[i];
	cout<<endl;
	for (int i = 0; i<= 10; i++) cout<<b[i];
	cout<<endl;
	for (int i = 0; i<= 10; i++) cout<<c[i];
	cout<<endl;
	for (int i = 0; i<= 10; i++) cout<<temp[i];
}
int main(){
	freopen("multiplication.inp", "r", stdin);
	nhap();
	xuly();
	xuat();
}