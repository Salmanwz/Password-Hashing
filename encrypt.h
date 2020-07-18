#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>

using namespace std;

int x=11, y=23, n=253, t=220, i, flag;
long int temp[50], j;
//n = x * y;  
//t = (x - 1) * (y - 1);

//function to encrypt the message
void encrypt(char m[])
{
   long int pt, ct, key = 13, k, len;
   i = 0;
   len = strlen(m);

   while(i != len)
   {
      pt = m[i];
      pt = pt - 96;
      k = 1;
      for(j = 0; j < key; j++)
      {
         k = k * pt;
         k = k % n;
      }
      temp[i] = k;
      ct= k + 96;
      m[i] = ct;
      i++;
   }
   m[i] = '\0';
}

//function to decrypt the message
void decrypt(char m[])
{
   long int pt, ct, key = 17, k;
   i = 0;
   while(m[i] != '\0')
   {
      ct = temp[i];
      k = 1;
      for(j = 0; j < key; j++)
      {
         k = k * ct;
         k = k % n;
      }
      pt = k + 96;
      m[i] = pt;
      i++;
   }
   m[i] = '\0';
}