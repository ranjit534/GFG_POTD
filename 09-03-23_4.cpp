class Solution
{ // Question - Find anagrams in linked list
public:
    vector<Node *> findAnagrams(struct Node *head, string s)
    {

        vector<int> v(26, 0);

        for (int i = 0; i < s.length(); i++)
            v[s[i] - 'a']++;

        vector<Node *> res;
        int k = s.length();
        Node *curr = head, *start = head;

        vector<int> a(26, 0);
        vector<int> b(26, 0);

        while (curr != NULL)
        {

            a[curr->data - 'a']++;
            k--;
            if (k == 0) // check if we get a sublist of size same as string
            {
                if (v == a) // check if characters in v is same as a
                {
                    res.push_back(start);
                    Node *temp = curr->next;
                    curr->next = NULL; // to make end of a anagram
                    curr = temp;
                    start = temp; // to avoid overlap

                    a = b;
                    k = s.length();
                }
                else
                {
                    a[start->data - 'a']--;
                    k++;
                    start = start->next;
                    curr = curr->next;
                }
            }
            else
                curr = curr->next;
        }
        return res;
    }
};