/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> rooms;
        for(Interval i : intervals) {
            rooms[i.start] += 1;
            rooms[i.end] -= 1;
        }
        int maxRoom = 0;
        int currentRoom = 0;
        for(auto i : rooms) {
            currentRoom += i.second;
            maxRoom = max(maxRoom, currentRoom);
        }
        return maxRoom;
    }
};