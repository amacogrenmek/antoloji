class Solution {

private:

    int digitCounts[10] = { 4, 4, 4, 3,3,3,2,2,2,2 };

    bool isValidDate(vector<int>& A)
    {
        int leftTuple = (10 * A[0]) + A[1];
        int rightTuple = (10 * A[2]) + A[3];

        return (leftTuple < 24) && (rightTuple < 60);
    }

    bool isValidCombination(vector<int>& A)
    {

        for (auto i = A.begin(); i != A.end(); ++i)
        {
            if (digitCounts[*i] > 0)
            {
                digitCounts[*i]--;
            }
            else
            {
                return false;
            }            
        }
        
        return true;
    }

    string permute(vector<int> A)
    {
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());

        if (isValidDate(A))
        {
            return getTimeString(A);
        }

        while (prev_permutation(A.begin(), A.end()))
        {

            if (isValidDate(A))
            {
                return getTimeString(A);
            }
        }

        return "";

    }

public:
    Solution()
    {

    }

    static void print(vector<int>& A)
    {
        for (auto i = A.begin(); i != A.end(); ++i)
        {
            cout << *i << " ";
        }

    }

    string getTimeString(vector<int>& A)
    {
        std::stringstream s;
        s << A[0] << A[1] << ":" << A[2] << A[3];
        return s.str();
    }

    string largestTimeFromDigits(vector<int>& A) {        
        
        string largestTime="";

        if (isValidCombination(A))
        {
            largestTime = permute(A);
        }        

        return largestTime;

    }

};