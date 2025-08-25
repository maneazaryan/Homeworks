//Copy only the class BrowserHistory and paste into this page
//https://leetcode.com/problems/design-browser-history/
class BrowserHistory {
    std::vector<std::string> v;
    int n;
public:
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        n=0;
    }
    
    void visit(string url) {
        if(n!= v.size()-1)
        {
            for(int i=v.size()-1; i>n+1;i--)
            {
                v.pop_back();
            }
            n++;
            v[n]=url;
        }
        else
        {
            v.push_back(url);
            n++;
        }
    }
    
    string back(int steps) {
        if(steps>0 && n-steps>=0 ){
            int a = n;
            n=a-steps;
            return v[a-steps];
        }else{
            return v[0];
        }
    }
    
    string forward(int steps) {
        if(steps>0 && n+steps<v.size())
        {
            int a = n;
            n=n+steps;
            return v[steps+a];
        }else{
            return v[v.size()-1];
        }
    }
};
