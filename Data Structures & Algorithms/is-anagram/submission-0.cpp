class Solution {
public:
    
    bool isAnagram(std::string s, std::string t) {
        // Get lengths of both strings
        int n1 = s.length();
        int n2 = t.length();

        // If length of both strings is not same, then they cannot be anagram
        if (n1 != n2) {
            return false;
        }

        // Sort both the strings
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        // Compare sorted strings
        for (int i = 0; i < n1; ++i) {
            if (s[i] != t[i]) {
                return false;
            }
        }

        return true;
    }
};
