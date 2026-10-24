class Solution {
private:
    int dateToDayOfYear(const std::string& date) {
        static const std::vector<int> daysInMonth = {
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };
        
        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(3, 2));
        
        int dayOfYear = day;
        for (int i = 0; i < month - 1; ++i) {
            dayOfYear += daysInMonth[i];
        }
        
        return dayOfYear;
    }

public:
    int countDaysTogether(std::string arriveAlice, std::string leaveAlice, 
                          std::string arriveBob, std::string leaveBob) {
        int startAlice = dateToDayOfYear(arriveAlice);
        int endAlice = dateToDayOfYear(leaveAlice);
        int startBob = dateToDayOfYear(arriveBob);
        int endBob = dateToDayOfYear(leaveBob);
        
        int overlapStart = std::max(startAlice, startBob);
        int overlapEnd = std::min(endAlice, endBob);
        
        return std::max(0, overlapEnd - overlapStart + 1);
    }
};