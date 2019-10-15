#include<bits/stdc++.h>
using namespace std;
long long cuspow(long long a, long long b, long long n)
{
	long long i, temp;
	temp = a;
	for(i = 2; i <= b; i++)
	{
		a = (a * temp) % n;
	}
	return a;
}

bool isPrime(long long n)
{
	long long i;
	for(i=2; i * i <= n; i++)
	{
		if(n % i==0)
        {
            return 0;
        }
	}
	return 1;
}

int extended(int a,int b)
{
	  int r1,r2,r,q,s1=1,s2=0,s,t1=0,t2=1,t;
	if(a>b)
  	{
  		r1=a;
  		r2=b;
  	
  	}
  else 
  {
  	r1=b;
  	r2=a;
  }
  
  
  while(r2>0)	
  {
     q=r1/r2;
	 r=r1-q*r2;
	 s=s1-q*s2;
	 t=t1-q*t2;
	 
	 r1=r2;
	 r2=r;  	
  	
  	 s1=s2;
  	 s2=s;
  	
  	 t1=t2;
  	 t2=t;
  	
  }
  
	return t1;	
	
}

pair<long long , char> rsa(long long plaintext , long long e , long long d, long long n)
{
	long long ciphertext;
	char dplaintext;
	ciphertext = cuspow(plaintext, e, n);
	dplaintext = cuspow(ciphertext, d, n);
	pair<long long , char> rpairs = make_pair(ciphertext , dplaintext);
	return rpairs;
}

int main()
{
	long long int p , q , i, n, e, d, phi_of_n;
	char plaintext1[1000];
	char plaintext[1000];
	vector<char> ciphertext;
	do
	{
		cout << "\nEnter first prime number: ";
		cin >> p;
	}while(!isPrime(p));
	do
	{
		cout << "\nEnter second prime number: ";
		cin >> q;
	}while(!isPrime(q));

	n = p * q;
	cout<<"Value of n = "<<n<<endl;
	phi_of_n = (p - 1) * (q - 1);
	cout<<"Value of phi_of_n = "<<phi_of_n<<endl;
	for(i = 2; i < phi_of_n ; i++)
	{
		if(__gcd(i, phi_of_n) == 1)
		{
			e = i;
			break;
		}
	}
	cout<<"Value of e = "<<e<<endl;
	
	d=extended(e,phi_of_n);
	if(d<0)d+=phi_of_n;
	cout<<"Value of d is "<<d;
	cout<<"\nEnter Plaintext"<<endl;
 	scanf(" %[^\n]s",plaintext);


	cout << "\nEncrypted Text ";

    	for(i = 0; i < plaintext[i]!='\0'; i++)
	{
	
		
		pair <long long , char> rpairs = rsa(plaintext[i]-96, e, d, n);
		cout << rpairs.first;

		ciphertext.push_back(rpairs.second);
	}
    cout<<endl;

	cout << "\nDecrypted Text: ";
	for(i = 0; i < ciphertext.size(); i++)
	{
		ciphertext[i]=ciphertext[i]+96;
		cout <<(char)ciphertext[i];
	}
	cout << endl;
}
