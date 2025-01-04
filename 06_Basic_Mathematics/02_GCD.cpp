//using EUCLID's Algorithm
//formula : gcd(a,b) = gcd(a-b,b) OR gcd(a%b,b) till either a or b is 0.If onebecomes zero the 
//other number is the answer

//we don't use % formula as that takes more computation. 


//gfg question
int gcd(int A, int B)
{
    if (A == 0)
        return B;
    if (B == 0)
        return A;

    while (A > 0 && B > 0)
    {
        if (A > B)
            A = A - B;
        else
            B = B - A;
    }
    return A == 0 ? B : A;
}

//for LCM :
//  LCM * HCF = a*b 
//--lcm(a,b)*gcd(a,b) =a*b
//--lcm = a*b/gcd(a,b)