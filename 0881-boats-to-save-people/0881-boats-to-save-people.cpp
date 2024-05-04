class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int boatCnt = 0;
        int i = 0, j = people.size() - 1;
        
        while (i <= j) {
            // If sum of lightest & heaviest person are under limit then both can go together
            if (people[i] + people[j] <= limit) i++, j--;
            // Else let heaviest person go alone
            else j--;
            
            boatCnt++;
        }
        
        return boatCnt;
    }
};