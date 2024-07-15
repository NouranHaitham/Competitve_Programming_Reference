#ifndef CP_TRAINING_NUMBER_THEORY_H
#define CP_TRAINING_NUMBER_THEORY_H

#include <bits/stdc++.h>
#define ll long long
using namespace std;


vector<bool> sieve(ll n)
{
    vector<bool> isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;

    for(ll i=2;i*i<=n;i++)
    {
        if(isPrime[i]){

            for (ll j=i+i;j<=n;j+=i)
            {
                 isPrime[j]=false;
            }

        }
    }

    return isPrime;
}


vector<ll> generateDivisors(ll n)
{
    vector<ll> div;
    ll i;

    for(i=1; i*i<n;i++)
    {
        if(n%i==0)
        {
            div.push_back(i);
            div.push_back(n/i);
        }

    }

    if(i*i==n)
        div.push_back(i);

    return div; // not sorted

}



vector<ll> generatePrimeFactors(ll n)
{
    vector<ll> primDiv;

    if(n==0 || n==1) return primDiv;

    // Prime  or  Product of Primes

    for(ll i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            primDiv.push_back(i);
            n/=i;
        }

    }

    if(n>1)
        primDiv.push_back(n);


    return primDiv;
}

ll fact(ll n)
{
    if(n==0 || n==1) return 1;

    ll res=1;
    for(ll i=2;i<=n;i++)
        res*=i;

    return res;

}


ll gcd(ll a,ll b)  // a must be bigger number
{
    if(b==0)
        return a;

   return gcd(b,a%b);
}


/*
 *
 *  LCM => a*b/gcd
 *
 *  nPr => n!/(n-r)!
 *    order imp
 *
 *  nCr => n!/ ((n-r)! * r!)
 *   order not imp
 *
 */


ll fastPower(ll b, ll p, ll mod)
{

    ll res=1;
    while(p>0)
    {
       if(p%2!=0)
           res = (res *  b) %mod;

       b=(b * b) %mod;
       p/=2;

    }

    return res;

}






#endif //CP_TRAINING_NUMBER_THEORY_H
