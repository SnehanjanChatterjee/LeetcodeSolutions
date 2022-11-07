class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        int found = str.find_first_of("6");
        if(found != string::npos) str[found] = '9';
        return stoi(str);
    }
};