//deque -> push front,pop front ,push back and pop back 
//addtext, deletetext, cursorleft and cursorright 

class TextEditor {
public:
    deque<char>left,right;
    TextEditor() { //constructor

        
    }
    
    void addText(string text) {
        for(auto i:text){
            left.push_back(i);
        }
        
    }
    
    int deleteText(int k) {
        int ans=0;
        while(k!=0 && left.size()!=0){
            left.pop_back();
            k--;
            ans++;
        }
        return ans;
    }
    
    string cursorLeft(int k) {
        while(k!=0 && left.size()!=0){
            right.push_front(left.back());
            left.pop_back();
            k--;
        }

        int n=left.size();
        string ans="";
        for(int i=n-1;i>=max(0,n-10);i--){
            ans+=left[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;


        
    }
    
    string cursorRight(int k) {
        while(k!=0 && right.size()!=0){
            left.push_back(right.front());
            right.pop_front();
            k--;
        }

        int n=left.size();
        string ans="";
        for(int i=n-1;i>=max(0,n-10);i--){
            ans+=left[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */