vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n = s.size();
		    vector<string> ans;
		    
		    for(int i=0; i<(1<<n); i++){
		        
		        string temp = "";
		        
		        for(int j=0; j<n; j++){
		            if(i & (1<<j)) temp += s[j];
		        }
		        
		        if(temp.size()) ans.push_back(temp);
		        
		    }
        sort(ans.begin(), ans.end());
		    return ans;
}

 
