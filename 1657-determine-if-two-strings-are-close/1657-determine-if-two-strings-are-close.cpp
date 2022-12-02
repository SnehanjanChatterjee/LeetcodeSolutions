class Solution {
private:
    // Two observations:
    //   1. With operation 1 we can sort the word.
    //   2. With operation 2 we can assign freely assign the the
    //      letter frequencies of all the letters in the word.
    // With that we frequency count the letters and then assign
    // the frequencies in descending order amount to the present
    // letters.
    array<int, 26> signature(const string& word) {
        array<int, 26> freq = {};
        for (char ch : word) ++freq[ch - 'a'];
        array<int, 26> ans = freq;
        sort(begin(freq), end(freq), greater<>());
        for (int i = 0, j = 0; i < size(ans); ++i)
            if (ans[i]) ans[i] = freq[j++];
        return ans;
    }
public:
    // https://leetcode.com/problems/determine-if-two-strings-are-close/discuss/2868028/C%2B%2B-oror-sort-frequency-count-w-some-variants-oror-fast-(27ms-100)
    bool closeStrings(const string& word1, const string& word2) {
        if (size(word1) != size(word2)) return false;

        return signature(word1) == signature(word2);
    }
};