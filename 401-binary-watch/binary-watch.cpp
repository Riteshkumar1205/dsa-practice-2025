class Solution {
public:
  vector<string> result;

  void backtrack(int turnedOn, int index, int hour, int minute){
    // If LEDs used exceed limits, stop
    if(hour > 11 || minute > 59) return;

    //if no LEDs left to turn on, record valid time
    if(turnedOn == 0) {
        string time = to_string(hour) + ":";
        if(minute < 10) time += "0";
        time += to_string(minute);
        result.push_back(time);
        return;
    }
    if(index == 10) return;

    if(index < 4){
        backtrack(turnedOn - 1, index + 1, hour + (1 << index),minute);
    }else {
        backtrack(turnedOn - 1,index + 1, hour, minute + (1 << (index - 4)));
    }
    backtrack(turnedOn, index + 1, hour, minute);
  }


    vector<string> readBinaryWatch(int turnedOn) {
       backtrack(turnedOn, 0, 0,0);
       return result; 
    }
};