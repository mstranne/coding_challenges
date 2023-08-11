//https://www.hackerrank.com/challenges/determining-dna-health/problem?isFullScreen=true

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <valarray> 
#include <map>
#include <memory>

using namespace std;

string& ltrim(string &);
string& rtrim(string &);
vector<string> split(const string &);


string &ltrim(string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !isspace(c);}));
    return s;
}

string &rtrim(string &s) {
    s.erase((++s.rbegin()).base(), std::find_if((++s.rbegin()).base(), s.rbegin().base(), [](int c) {return !isspace(c);}));
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

class Node {
    public:
        map<char,unique_ptr<Node>> m_childs;
        vector<pair<int,int>> m_health;

        int getHealth(string sub, int first, int last){
            int h = 0;
            for(auto hi : m_health){
                if(hi.first > last)
                    break;
                    
                if(first <= hi.first){
                    h+=hi.second;
                }
            }
            if(sub.size() > 0){                
                char c = sub[0];
                sub.erase(0, 1);
                if (m_childs.find(c) == m_childs.end()) {
                    return h;
                } else { 
                    return h + m_childs[c]->getHealth(sub, first, last);
                }
            } 
            return h;
        }

        void addChild(string sub, pair<int,int> health){
            if(sub.size() > 0){
                char c = sub[0];
                sub.erase(0, 1);
                if (m_childs.find(c) == m_childs.end()) {
                    unique_ptr<Node> new_node(new Node());
                    new_node->addChild(sub, health);
                    m_childs.insert_or_assign(c,std::move(new_node));
                } else { 
                    m_childs[c]->addChild(sub, health);
                }
            } else{
                m_health.push_back(health);
            }
        }
};

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string genes_temp_temp;
    getline(cin, genes_temp_temp);

    vector<string> genes_temp = split(rtrim(genes_temp_temp));

    vector<string> genes(n);

    for (int i = 0; i < n; i++) {
        string genes_item = genes_temp[i];

        genes[i] = genes_item;
    }

    string health_temp_temp;
    getline(cin, health_temp_temp);

    vector<string> health_temp = split(rtrim(health_temp_temp));

    vector<int> health(n);

    for (int i = 0; i < n; i++) {
        int health_item = stoi(health_temp[i]);

        health[i] = health_item;
    }

    string s_temp;
    getline(cin, s_temp);

    int s = stoi(ltrim(rtrim(s_temp)));

    int min_health = 2147483647;
    int max_health = 0;

    //TODO
    //5 aus 35 noch Timeouts 
    //4 noch wrong answer, aber wo?

    //construct "tree"
    map<char,unique_ptr<Node>> nodes;
    for(int g_i = 0; g_i < genes.size(); g_i++){
        string sub = genes[g_i];
        char c = sub[0];
        sub.erase(0, 1);
        if (nodes.find(c) == nodes.end()) {
            unique_ptr<Node> new_node(new Node());
            new_node->addChild(sub, pair<int,int>(g_i, health[g_i]));
            nodes.insert_or_assign(c,move(new_node));
        } else { 
            nodes[c]->addChild(sub, pair<int,int>(g_i, health[g_i]));
        }
    }

    for (int s_itr = 0; s_itr < s; s_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int first = stoi(first_multiple_input[0]);

        int last = stoi(first_multiple_input[1]);

        string d = first_multiple_input[2];


        //gene = [g0,g1,..gn]   genes
        //health = [h0,h1,..hn] health of gi    health
        //sets of dna with start,end and d with healthy dna from gstart to gend
        //print the one with min and max health

        // Solve with aho-corasick algo
        //https://cp-algorithms.com/string/aho_corasick.html // maybe also simpler

        
        int curr_h = 0;
        for (int i = 0; i < d.size(); i++)
        {
            string sub = d.substr(i, d.size()-i);
            char c = sub[0];
            sub.erase(0, 1);
            if (nodes.find(c) == nodes.end()) {
                
            } else{
                curr_h += nodes[c]->getHealth(sub, first, last);
            }
        }
        
        if(curr_h > max_health) 
            max_health = curr_h;
        if(curr_h < min_health)
            min_health = curr_h;
    }

    cout << min_health << " " << max_health << endl;

    return 0;
}