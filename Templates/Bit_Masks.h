#ifndef CP_TRAINING_BIT_MASKS_H
#define CP_TRAINING_BIT_MASKS_H
#define ll long long
#include <bitset>

std::bitset<2323> s;

int parity(int n)
{
    // 1 => odd    0 => even
   return (n & 1)? 1 : 0;
}

int get(int n,int i)
{
    return (1<<i) & n;
}

int set(int n,int i)
{
  return (1<<i) | n;
}

int reset(int n,int i)
{
    return (~(1<<i)) & n;
}

int flip(int n,int i)
{
    return (1<<i) ^ n;
}


/*
 * Careful:
 *
 *  1<<60 ?? can't bec 1 is int (32 bits)   [1ULL<<60]
 *  1<<k-1 => 1<<(k-1) can't [(1<<k)-1]
 *
 */


int countOnes(int n)
{
    int cnt=0;

    while(n)
    {
        n = ((n-1) & n);
        cnt++;
    }

    return cnt;
}

int OffLastOne(int n)
{
    return (n-1) & n;
}


int OnLastZero(int n)
{
    return (n+1) | n;
}


int OnLastZeroes(int n)
 {
    return (n-1) | n;
 }


int OffLastOnes(int n)
{
    return (n+1) & n;
}


bool powerOfTwo(int n)
{
    if(countOnes(n)==1)
        return 1;
    else
        return 0;
}


#endif //CP_TRAINING_BIT_MASKS_H
