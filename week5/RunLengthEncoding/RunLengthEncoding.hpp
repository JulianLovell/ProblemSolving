#include <iostream>
#include <string>

using namespace std;

class RunLengthEncoding
{
public:
    string decode(string text)
    {
        // Initialise new empty string
        string newString = {};

        // Initialise multiplyer
        int multi = 1;

        for (int i = 0; i < text.size(); ++i)
        {
            // Update multiplyer if element is number
            if (isdigit(text[i]) == true)
            {
                multi = stoi(text[i]);
            }
            else
            {
                // pushback text[i] 'multi' times, default is 1 if no new number found
                for (int j = 0; j < multi; ++j)
                {
                    newString.push_back(text[i]);
                }
            }

            // Reset multiplyer back to 1
            multi = 1;
        }
        return newString;
    }
};