class DinnerPlates {
public:
  DinnerPlates(int capacity) {
      cap=capacity;
  }
 
  void push(int val) {  
    int index = aval.empty() ? stacks.size() : *begin(aval);
    if (index == stacks.size()) stacks.emplace_back();
    stack<int>& s = stacks[index];
    s.push(val);
    if (s.size() == cap)
      aval.erase(index);
    else if (s.size() == 1) // only insert for the first element
      aval.insert(index);
  }
 
  int pop() { 
      return popAtStack(stacks.size() - 1);
       }
 
  int popAtStack(int index) {
    if (index < 0 || index >= stacks.size() || stacks[index].empty()) 
    return -1;
    stack<int>& s = stacks[index];
    int val = s.top(); 
    s.pop();
    if (s.size() == cap - 1) aval.insert(index);    
    
    // Amortized O(1)
    auto it = prev(end(aval));
    while (stacks.size() && stacks.back().empty()) {
      stacks.pop_back();
      aval.erase(it--);
    }
    return val;
  }
private:
  int cap;
  set<int> aval;
  vector<stack<int>> stacks;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */