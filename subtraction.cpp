#include <bits/stdc++.h>
using namespace std;
#define NMAX 1001
char a[NMAX], b[NMAX], ans[NMAX];
bool chk[2];
string m,n;
int charlen(char x[]){
	int temp;
	for (int i = NMAX - 1; i>=0;i--){
		if (x[i] != '0'){
		temp = i;
		break;
		}
	}
	if (temp == 32767) return 0;
	else return temp+1;
}
bool neg(char x[]){
	if ((x[charlen(x) - 1]) == '-') return true;
	else return false;
}
bool gtr(char x[], char y[]){
	if (neg(x)&&!neg(y)) return 0;
	if (!neg(x)&&neg(y)) return 1;

	for (int i = NMAX - 1; i>=0;i--){
		if ((x[i] == '0')&&(y[i]!='0')){
			return 0;
			break;
		}

		if ((x[i]!=y[i])&&((x[i] - '0') > (y[i] - '0'))) {
			return true;
			break;
		}
		if (i == 0&&x[i]==y[i]) return 1;
	}
	return false;
}
void nhap(){
	cin>>m>>n;
	memset(a, '0', NMAX);
	memset(b, '0', NMAX);
	memset(ans, '0', NMAX);
	for (int i = m.length(); i>0; i--){
		a[m.length() - i] = m[i-1];
	}
	for (int i = n.length(); i>0; i--){
		b[n.length() - i] = n[i-1];
	}
}
void add(char x[], char y[], char z[]){
	int i = charlen(x), j = charlen(y), sodu = 0, k = 0, d;
	while (j>0 || i>0 || sodu!=0){
		d = x[k]+y[k]-'0'-'0'+sodu;
		sodu = 0;
		while (d>=10){
			d%=10;
			sodu++;
		}
		z[k] = d+'0';
		i--;j--;k++;
	}
}
void sub(char x[], char y[], char z[]){
	bool temp1 = 0;
	if (!gtr(x,y)){
		temp1 = 1;
		char *temp = x;
		x = y;
		y = temp;
	}
	int i = charlen(x), j = charlen(y), sodu = 0, k = 0, d;
	while (j>0 || i>0 || sodu!=0){
		if (x[k] >= y[k]){
		d = x[k]-y[k];
		}
		else {
			d = x[k]-y[k]+10;
			x[k+1] = x[k+1] -1 ;
		}
		z[k] = d+'0';
		i--;j--;k++;
	}
	if (temp1) z[charlen(z)] = '-';
}
void subtract(){
	if (neg(a)){
		if (neg(b)){
			a[charlen(a) - 1] = '0';
			b[charlen(b) - 1] = '0';
			add(b,a,ans);
			ans[charlen(ans)] = '-';
		}
		else {
			a[charlen(a) - 1] = '0';
			sub(b,a,ans);
		}
	}
	else {
		if (neg(b)){
			b[charlen(b) - 1] = '0';
			sub(a,b,ans);
			}
		else add(a,b,ans);
	}
}
void xuat(){
	for (int i = charlen(ans) - 1; i>=0 ;i--){
		cout<<ans[i];
	}
}
int main(){
	nhap();
	subtract();
	xuat();
}