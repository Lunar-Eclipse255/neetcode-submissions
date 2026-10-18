/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start, end;
        for (const auto& i : intervals) {
            start.push_back(i.start);
            end.push_back(i.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int count = 0;
        int rooms = 0;
        int start_t = 0;
        int end_t = 0;
        while (start_t < intervals.size()) {
            if (start[start_t]<end[end_t]) {
                start_t++;
                count++;
            }
            else {
                end_t++;
                count--;
            }
            rooms = max(rooms, count);
        }
        return rooms;
    }
};
