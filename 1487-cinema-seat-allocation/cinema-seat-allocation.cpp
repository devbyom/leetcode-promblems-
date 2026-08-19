class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedMap;
        for (const auto& seat : reservedSeats) {
            reservedMap[seat[0]] |= (1 << (seat[1] - 1));
        }

        // Each row can have at most 2 groups.
        // Initially, all n rows can have 2 groups.
        int totalGroups = 2 * n;

        // Subtract for rows that have reservations
        for (const auto& [row, mask] : reservedMap) {
            bool left = (mask & 0b0111100000) == 0; // seats 2, 3, 4, 5
            bool right = (mask & 0b0000011110) == 0; // seats 6, 7, 8, 9
            bool middle = (mask & 0b0001111000) == 0; // seats 4, 5, 6, 7

            if (left && right) {
                // Both left and right blocks are free, we can seat 2 groups.
                continue;
            } else if (left || right || middle) {
                // We can seat at least 1 group. Since we started with 2, we lose 1.
                totalGroups -= 1;
            } else {
                // We cannot seat any group in this row. Since we started with 2, we lose 2.
                totalGroups -= 2;
            }
        }

        return totalGroups;
    }
};