/*
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

#include <iostream>
#include <vector>
using namespace std;

vector<Interval> merge(vector<Interval> &A)
{

    vector<Interval> result;
    Interval top = A[0];
    result.push_back(top);
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        Interval curr = A[i];
        if (top.end >= curr.start)
        {
            Interval temp;
            result.pop_back();
            if (curr.end >= top.end)
                temp = Interval(top.start, curr.end);
            else
                temp = Interval(top.start, top.end);
            result.push_back(temp);
            top = temp;
        }
        if (top.end < curr.start)
        {
            result.push_back(curr);
            top = curr;
        }
    }
    return result;
}
