class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        
        int total_candies = 1; 
        
        int up = 0;    // Length of current increasing sequence
        int down = 0;  // Length of current decreasing sequence
        int peak = 0;  // Height of the most recent peak
        
        for (int i = 1; i < ratings.size(); i++) {
            
            if (ratings[i] > ratings[i - 1]) {
                // Going Up
                up++;
                down = 0;       // Reset valley
                peak = up;      // New peak established
                total_candies += (1 + up);
                
            } else if (ratings[i] == ratings[i - 1]) {
                // Flat Ground
                up = 0;
                down = 0;
                peak = 0;
                total_candies += 1;
                
            } else {
                // Going Down
                up = 0; // Reset mountain
                down++;
                total_candies += down;
                
                // If the valley is deeper than the peak is tall, 
                // elevate the peak by 1
                if (down > peak) {
                    total_candies += 1;
                }
            }
        }
        
        return total_candies;
    }
};