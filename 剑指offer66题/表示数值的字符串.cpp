class Solution {
public:
    bool isNumeric(char* string)
    {
        //头可以是加号减号或数字；尾部可以是数字或点号；中间至多只能有一个.和一个E。E后面可以有负号
        int n = strlen(string);
        cout<<n<<endl;
        if (n<1) return false;
        if(string[0]!='+' && string[0]!='-' && (string[0] < '0' || string[0] > '9'))
            return false;
        if(n==1) return true;
        if(string[n-1]!='.' && (string[n-1] < '0' || string[n-1] > '9'))
            return false;
        int numd = 0;
        int nume = 0;
        for(int i = 1; i<n-1; i++)
        {
            if((nume||numd) && string[i] == '.')
                return false;
            else if(!nume && !numd && string[i] == '.')
                numd++;
            else if(nume && (string[i] == 'E' || string[i] == 'e'))
                return false;
            else if(string[i] == 'E' || string[i] == 'e')
                nume++;
            else if((string[i]=='-' || string[i]=='+'))
            {
                if((string[i-1] == 'e' || string[i-1] == 'E'))
                    ;
                else
                    return false;
            }
            else if(string[i]< '0' || string[i] > '9')
                return false;
        }
        return true;

    }

};
