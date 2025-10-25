class Spreadsheet {
public:
    vector<vector<int>>shit;
    Spreadsheet(int rows) {
        shit.assign(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0]-'A';
        int row = stoi(cell.substr(1))-1;
        shit[row][col]=value;
    }
    
    void resetCell(string cell) {
        int col = cell[0]-'A';
        int row = stoi(cell.substr(1))-1;
        shit[row][col]=0;
    }
    
    int getValue(string formula) {
        string X = "";
        string Y = "";
        bool isafterplus = false;
        for(int i = 1;i<formula.size();i++){
            if(formula[i]=='+'){
                isafterplus=true;
                continue;
            }
            if(isafterplus){
                Y+=formula[i];
            }
            else{
                X+=formula[i];
            }
        }
        auto parse = [&](string token) -> int {
        if(isalpha(token[0])) {
            int col = token[0] - 'A';
            int row = stoi(token.substr(1)) - 1;
            return shit[row][col];
        }
        return stoi(token);
    };

    return parse(X) + parse(Y);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */