/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution
{
public:
    struct trie
    {
        int isword = 0;
        int child_cnt = 0;
        trie *next[26] = {0};
    };
    int numMatchingSubseq(string s, vector<string> &words)
    {
        trie *root = new trie();
        for (int i = 0; i < words.size(); i += 1)
        {
            trie *ptr = root;
            for (int j = 0; j < words[i].size(); j += 1)
            {
                int charnum = words[i][j] - 'a';
                if (ptr->next[charnum] == nullptr)
                {
                    ptr->next[charnum] = new trie();
                    ptr->child_cnt += 1;
                }
                ptr = ptr->next[charnum];
            }
            ptr->isword += 1;
        }
        int ans = root->isword;
        root->isword = 0;
        // cout << ans << endl;
        queue<trie *> q;
        q.push(root);
        for (int i = 0; i < s.size(); i += 1)
        {
            int l = q.size();
            // cout << "i: " << i << endl;
            while (l--)
            {
                trie *tmp = q.front();
                // cout << ans << " " << tmp->child_cnt << " " << tmp->isword << endl;
                q.pop();
                if (tmp->next[s[i] - 'a'])
                {
                    // cout << s[i] << " " << tmp->next[s[i] - 'a']->child_cnt << endl;
                    ans += tmp->next[s[i] - 'a']->isword;
                    tmp->next[s[i] - 'a']->isword = 0;
                    if (tmp->next[s[i] - 'a']->child_cnt > 0)
                    {
                        q.push(tmp->next[s[i] - 'a']);
                    }
                    tmp->next[s[i] - 'a'] = nullptr;
                    tmp->child_cnt -= 1;
                }
                if (tmp->child_cnt > 0)
                {
                    q.push(tmp);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
