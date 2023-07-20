// https://www.hackerrank.com/challenges/attribute-parser/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;

vector<string> customSplit(string str, char separator) {
    vector<string> strings;
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= str.size(); i++) {
        
        // If we reached the end of the word or the end of the input.
        if (str[i] == separator || i == str.size()) {
            endIndex = i;
            string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return strings;
}

class Tag {
    public:
        string m_name;
        vector<pair<string, string>> m_attributes;
        vector<shared_ptr<Tag>> m_sub_tags;
    
        bool get_tag(string name, shared_ptr<Tag> &found){
            for(int i = 0; i < m_sub_tags.size(); i++){
                if(m_sub_tags[i]->m_name == name){
                    found = m_sub_tags[i];
                    return true;
                }  
            }
            return false;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,Q;
    cin >> N >> Q;
    vector<shared_ptr<Tag>> tags;
    vector<shared_ptr<Tag>> open_tags;
    string nona; 
    getline(std::cin, nona);
    for(int i = 0; i < N; i++){
        string line; 
        getline(std::cin, line);
        //cout << "line: " << line << endl;
        if(line.rfind("</", 0) == 0){
            //tag close
            line = line.substr(2, line.size() - 3);
            if(line == open_tags.back()->m_name)
                open_tags.pop_back();
            else 
                cout << "problemo" << endl;
        } else{
            line = line.substr(1, line.size() - 2);
            vector<string> strings = customSplit(line, ' ');
            
            shared_ptr<Tag> new_tag = make_unique<Tag>();
            
            new_tag->m_name = strings[0];
            //cout << "size: " << strings.size() << endl;
            for(int j = 1; j < strings.size(); j+=3){
                //cout << "add: " << strings[j] << "," << strings[j+2] << endl;
                new_tag->m_attributes.push_back(pair(strings[j], strings[j+2].substr(1, strings[j+2].size() - 2)));
            }
            
            if(open_tags.size() > 0) {
                //cout << "hinten rauf : " << new_tag.m_name << endl;
                open_tags.back()->m_sub_tags.push_back(new_tag);
            } else{
                tags.push_back(new_tag);
            }                           
                
            open_tags.push_back(new_tag);
        }
        
    }
    
    //cout << "tagsize " << tags.size() << endl;
    
    for(int i = 0; i < Q; i++){ 
        string line; 
        getline(std::cin, line);
        //line = line.substr(0, line.size() - 2);
        vector<string> strings = customSplit(line, '~');
        string value_name = strings[1];
        strings = customSplit(strings[0], '.');
        
        shared_ptr<Tag> current_tag;
        bool found = false;
        for (int j = 0; j < tags.size(); j++) {
            //cout << strings[0] << "==" << tags[j].m_name << endl;
            if(strings[0] == tags[j]->m_name){
                current_tag = tags[j];
                found = true;
                break;
            }
        }
        
        if (!found){
            cout << "Not Found!\n";
            continue;
        }
        //cout << "found " << current_tag.m_name << " size: " << current_tag.m_sub_tags.size() << endl;
        
        for (int j = 1; j < strings.size(); j++) {
            found = current_tag->get_tag(strings[j], current_tag);
            if(!found)
                break;

        }
        
        if(found) {
            found = false;
            for (int j = 0; j < current_tag->m_attributes.size(); j++)
            {
                if(current_tag->m_attributes[j].first == value_name){
                    cout << current_tag->m_attributes[j].second << endl;
                    found = true;
                    break;
                }
            }
            
        }
        
        if(!found) 
            cout << "Not Found!\n";
        
    }
    
    return 0;
}
