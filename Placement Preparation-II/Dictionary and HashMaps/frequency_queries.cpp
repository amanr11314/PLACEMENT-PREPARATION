/**
 * Link: https://www.hackerrank.com/challenges/frequency-queries/
*/
vector<int> freqQuery(vector<vector<int>> queries)
{

    vector<int> ans;
    unordered_map<int, int> mp;
    unordered_map<int, int> fc;
    for (auto v : queries)
    {
        int type = v[0];
        int val = v[1];
        if (type == 1)
        {
            //prev freq
            int cf = mp[val];
            //insert into map
            mp[val]++;
            //if contributes to prev freq, decrement
            if (cf)
                fc[cf]--;
            //curr freq of ele
            cf = mp[val];
            //update for curr freq
            fc[cf]++;
        }
        if (type == 2)
        {
            int cf = mp[val];
            if (cf)
            {
                mp[val]--;
                //also remove from curr freq
                fc[cf]--;
                //add to new lower freq
                cf = mp[val];
                if (cf)
                    fc[cf]++;
            }
        }
        if (type == 3)
        {
            if (fc[val])
                ans.push_back(1);
            else
                ans.push_back(0);
        }
    }
    return ans;
}