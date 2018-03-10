class Solution {
public:

    bool isNumeric(char* string)
    {
        initDFA();
        STATUS current = START;
        while (*string && current != END)
        {
            current = dfa[*string][current];
            ++string;
        }
        switch (current)
        {
            case INTEGER:
            case FLOAT:
            case SCIENCE:
                return true;
        }
        return false;
    }

private:
    enum STATUS {END = 0, START, SIGNED1, INTEGER, POINT, FLOAT, EXPONENT, SIGNED2, SCIENCE};
    STATUS dfa[256][9] = {END};

    void initDFA() {
        char d = '0';

        dfa['+'][START] = SIGNED1;
        dfa['-'][START] = SIGNED1;
        dfa['.'][START] = POINT;

        for (d = '0'; d <= '9'; ++d)
        {
            dfa[d][START] = INTEGER;
        }

        for (d = '0'; d <= '9'; ++d)
        {
            dfa[d][SIGNED1] = INTEGER;
        }
        dfa['.'][SIGNED1] = POINT;

        for (d = '0'; d <= '9'; ++d)
        {
            dfa[d][INTEGER] = INTEGER;
        }
        dfa['.'][INTEGER] = FLOAT;
        dfa['E'][INTEGER] = EXPONENT;
        dfa['e'][INTEGER] = EXPONENT;

        for (d = '0'; d <= '9'; ++d)
        {
            dfa[d][POINT] = FLOAT;
        }

        for (d = '0'; d <= '9'; ++d)
        {
            dfa[d][FLOAT] = FLOAT;
        }
        dfa['E'][FLOAT] = EXPONENT;
        dfa['e'][FLOAT] = EXPONENT;

        for (d = '0'; d <= '9'; ++d)
        {
            dfa[d][EXPONENT] = SCIENCE;
        }
        dfa['+'][EXPONENT] = SIGNED2;
        dfa['-'][EXPONENT] = SIGNED2;

        for (d = '0'; d <= '9'; ++d)
        {
            dfa[d][SIGNED2] = SCIENCE;
        }
        for (d = '0'; d <= '9'; ++d)
        {
            dfa[d][SCIENCE] = SCIENCE;
        }
    }

};