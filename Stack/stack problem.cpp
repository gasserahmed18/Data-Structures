#include <iostream>
#include <bits/stdc++.h>
#include <list>
using namespace std;
#define N 8 // Maximum number of persons in the party

//////////////////stack problem
bool matr[N][N] = {{0, 1, 1, 1},
                    {1, 0, 1, 0},
                    {0, 0, 0, 0},
                    {1, 0, 1, 0}};

bool ifoneknowother(int a, int b)
{
    return matr[a][b];
}
// Returns -1 if celebrity isnot found and id (value from 0 to n-1) if it is found

int findCelebrity(int n)
{
    stack<int> s;

    int c; // refer to celebrity

    // Push people to stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // Extract top
    int x = s.top();
    s.pop();
    int y = s.top();
    s.pop();

    // Find all potential celebrities
    while (s.size() > 1)
    {
        if (ifoneknowother(x, y))
        {
            x = s.top();
            s.pop();
        }
        else
        {
            y = s.top();
            s.pop();
        }
    }
    ///////if c is the wanted one
    c = s.top();
    s.pop();

    if (ifoneknowother(c, x))
        c = x;
    if (ifoneknowother(c, y))
        c = y;

// find if C is already a celebrity or not
    for (int i = 0; i < n; i++)
    {
// If any person doesn't know c or c doesn't know any person, return -1
        if ( (i != c) &&(ifoneknowother(c, i) ||!ifoneknowother(i, c)) )
            return -1;
    }
    return c;
}

int main()
{
    cout << "enter the number of visitors in the party" << endl;
    int num;
    cin >> num;
    int idofperson = findCelebrity(num);
    if (idofperson == -1)
        cout << "No celebrity" ;
    else
        cout << "Celebrity ID is " << idofperson;
    return 0;
}
