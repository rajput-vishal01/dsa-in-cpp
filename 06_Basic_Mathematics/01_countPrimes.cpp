//204. Count Primes

// M1
class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int countPrimes(int n)
    {
        int c = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime(i))
                ++c;
        }
        return c;
    }
};

//T.C : O(n^2)

// M2
class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int countPrimes(int n)
    {
        int c = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrime(i))
                ++c;
        }
        return c;
    }
};

//T.C : O(n√n)

// M3 Sieve of Eratosthenes Algorithm
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        int ans = 0;

        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                ++ans;

                int j = 2 * i;
                while (j < n)
                {
                    prime[j] = false;
                    j += i;
                }
            }
        }
        return ans;
    }
};

//T.c : O(n log (log n))