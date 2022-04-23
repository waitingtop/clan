class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        int index = 0;
        while(index < len && s[index] == ' ') ++index;
        if(index == len) return 0;
        int flag = 1;
        if(s[index] == '-')
        {
            flag = -1;
            ++index;
        }
        else if(s[index] == '+')
        {
            ++index;
        }
        int res = 0;
        while(index < len && (s[index] >= '0' && s[index] <= '9'))
        {
            int tmp = s[index] - '0';
            if((res > INT_MAX / 10) || ((res == INT_MAX / 10) && tmp > 7))
                return flag == 1 ? INT_MAX : INT_MIN;
            res = res * 10 + tmp;
            ++index;
        }
        return res * flag;
    }
};