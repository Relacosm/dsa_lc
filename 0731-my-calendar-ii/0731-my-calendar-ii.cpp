#include <vector>
using namespace std;

class MyCalendarTwo {
public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        // Check if the new booking overlaps with any double booking.
        for (auto& [os, oe] : overlaps) {
            if (start < oe && end > os) {
                return false; // Triple booking detected
            }
        }

        // Check overlaps with existing bookings to add double bookings.
        for (auto& [bs, be] : bookings) {
            if (start < be && end > bs) {
                // Add the overlapping interval to overlaps.
                overlaps.push_back({max(start, bs), min(end, be)});
            }
        }

        // Add the new booking to bookings.
        bookings.push_back({start, end});
        return true; // Booking is successful
    }

private:
    vector<pair<int, int>> bookings;  // List to keep all bookings
    vector<pair<int, int>> overlaps;  // List to keep all double bookings
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start, end);
 */
