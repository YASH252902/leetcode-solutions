#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Helper function to convert "MM-DD" into the nth day of the year (1 to 365)
    int dateToDayOfYear(const string& date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int dayOfYear = 0;
        for (int i = 0; i < month - 1; ++i) {
            dayOfYear += daysInMonth[i];
        }
        dayOfYear += day;
        
        return dayOfYear;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aStart = dateToDayOfYear(arriveAlice);
        int aEnd = dateToDayOfYear(leaveAlice);
        int bStart = dateToDayOfYear(arriveBob);
        int bEnd = dateToDayOfYear(leaveBob);
        
        // Find the overlapping interval
        int startOverlap = max(aStart, bStart);
        int endOverlap = min(aEnd, bEnd);
        
        // If there is no overlap, the difference will be negative, so we return 0
        return max(0, endOverlap - startOverlap + 1);
    }
};