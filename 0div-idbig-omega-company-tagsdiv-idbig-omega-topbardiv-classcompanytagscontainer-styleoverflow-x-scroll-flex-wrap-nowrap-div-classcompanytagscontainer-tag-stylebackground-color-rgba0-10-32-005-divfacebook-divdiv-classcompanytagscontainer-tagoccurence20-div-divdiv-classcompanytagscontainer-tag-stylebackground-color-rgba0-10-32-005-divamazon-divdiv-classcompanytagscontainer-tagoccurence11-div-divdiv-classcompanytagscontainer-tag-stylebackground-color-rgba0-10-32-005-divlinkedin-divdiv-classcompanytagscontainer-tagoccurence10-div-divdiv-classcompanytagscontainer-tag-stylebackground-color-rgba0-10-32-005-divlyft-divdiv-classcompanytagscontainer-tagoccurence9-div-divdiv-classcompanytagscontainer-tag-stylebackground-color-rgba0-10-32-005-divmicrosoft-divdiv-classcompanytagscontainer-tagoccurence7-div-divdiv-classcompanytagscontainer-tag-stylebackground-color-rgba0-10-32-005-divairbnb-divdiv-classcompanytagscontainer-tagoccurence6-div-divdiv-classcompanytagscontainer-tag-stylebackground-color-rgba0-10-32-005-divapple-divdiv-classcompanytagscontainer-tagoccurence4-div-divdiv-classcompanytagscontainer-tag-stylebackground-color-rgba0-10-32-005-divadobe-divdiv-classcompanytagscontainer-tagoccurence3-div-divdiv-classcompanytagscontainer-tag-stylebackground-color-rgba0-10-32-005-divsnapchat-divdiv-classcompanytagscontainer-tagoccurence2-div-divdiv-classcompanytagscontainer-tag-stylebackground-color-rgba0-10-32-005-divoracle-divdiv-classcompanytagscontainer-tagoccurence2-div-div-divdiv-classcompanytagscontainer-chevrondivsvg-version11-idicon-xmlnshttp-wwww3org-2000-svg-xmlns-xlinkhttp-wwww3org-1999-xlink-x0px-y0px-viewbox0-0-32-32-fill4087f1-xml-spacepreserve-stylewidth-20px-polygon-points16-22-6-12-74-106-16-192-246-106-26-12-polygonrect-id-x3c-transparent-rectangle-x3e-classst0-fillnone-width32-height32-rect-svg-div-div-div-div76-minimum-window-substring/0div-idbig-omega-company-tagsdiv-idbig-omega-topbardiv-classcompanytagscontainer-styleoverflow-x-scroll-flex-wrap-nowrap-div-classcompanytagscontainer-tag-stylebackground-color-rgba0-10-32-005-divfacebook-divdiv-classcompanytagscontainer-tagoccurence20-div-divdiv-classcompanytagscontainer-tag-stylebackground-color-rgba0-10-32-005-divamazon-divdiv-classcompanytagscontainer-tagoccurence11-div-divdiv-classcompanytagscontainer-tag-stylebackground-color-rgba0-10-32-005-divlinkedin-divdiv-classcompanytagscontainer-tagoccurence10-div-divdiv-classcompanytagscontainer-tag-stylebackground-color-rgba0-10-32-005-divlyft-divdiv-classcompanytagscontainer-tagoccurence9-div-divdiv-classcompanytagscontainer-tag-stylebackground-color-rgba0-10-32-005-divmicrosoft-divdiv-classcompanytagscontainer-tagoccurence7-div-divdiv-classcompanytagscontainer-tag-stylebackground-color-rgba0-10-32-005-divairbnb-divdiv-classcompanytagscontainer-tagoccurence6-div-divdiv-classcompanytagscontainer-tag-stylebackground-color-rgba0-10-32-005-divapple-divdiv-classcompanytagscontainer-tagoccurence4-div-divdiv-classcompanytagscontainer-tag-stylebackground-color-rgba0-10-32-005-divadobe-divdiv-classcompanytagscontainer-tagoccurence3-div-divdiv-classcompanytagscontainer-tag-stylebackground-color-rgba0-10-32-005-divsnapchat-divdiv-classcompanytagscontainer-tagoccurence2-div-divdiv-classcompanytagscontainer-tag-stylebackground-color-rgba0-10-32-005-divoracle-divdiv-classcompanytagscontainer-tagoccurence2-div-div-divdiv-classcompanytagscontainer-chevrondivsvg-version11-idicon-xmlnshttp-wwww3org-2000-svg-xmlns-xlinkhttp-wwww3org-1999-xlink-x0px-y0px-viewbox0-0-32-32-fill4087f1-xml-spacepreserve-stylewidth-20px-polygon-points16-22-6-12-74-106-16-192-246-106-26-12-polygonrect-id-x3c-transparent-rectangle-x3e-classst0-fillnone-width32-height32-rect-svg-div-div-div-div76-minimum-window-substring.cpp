class Solution
{
    public:
        string minWindow(string s, string t)
        {
            int l = 0, r = 0, cnt = 0, minLen = s.length() + 1, ind = -1;
            map<int, int> hash;
            for (int i = 0; i < t.length(); i++)
            {
                hash[t[i] - 'a']++;
            }

            while (r < s.length())
            {
                if (hash[s[r] - 'a'] > 0)
                    cnt++;

                hash[s[r] - 'a']--;

                while (cnt == t.length())
                {
                    if ((r - l + 1) < minLen)
                    {
                        minLen = r - l + 1;
                        ind = l;
                    }
                    hash[s[l] - 'a']++;
                    if (hash[s[l] - 'a'] > 0)
                        cnt--;

                    l++;
                }

                r++;
            }

            return (ind == -1) ? "" : s.substr(ind, minLen);
        }
};