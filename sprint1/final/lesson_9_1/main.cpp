#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <map>

using namespace std;

const int MAX_RESULT_DOCUMENT_COUNT = 5;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result = 0;
    cin >> result;
    ReadLine();
    return result;
}

vector<string> SplitIntoWords(const string& text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

struct Document {
    int id;
    int relevance;
};

struct Query {
    vector<string> query_words;
    set<string> minus_words;
};


class SearchServer {
public:
    void SetStopWords(const string& text) {
        for (const string& word : SplitIntoWords(text)) {
            stop_words_.insert(word);
        }
    }

    void AddDocument(int document_id, const string& document) {
        const vector<string> words = SplitIntoWordsNoStop(document);
        for (const string& word: words) {
            documents_[word].insert(document_id);
        }
    }

    vector<Document> FindTopDocuments(const string& raw_query) const {
        const Query query_words = ParseQuery(raw_query);
        //из списка слов нужно отсеять минус слова в отдельный сет.
        auto matched_documents = FindAllDocuments(query_words);

        //по минус словам отсеять matched_documents


        sort(matched_documents.begin(), matched_documents.end(),
            [](const Document& lhs, const Document& rhs) {
                return lhs.relevance > rhs.relevance;
            });
        if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
            matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
        }
        return matched_documents;
    }

private:
    map<string, set<int>> documents_;

    set<string> stop_words_;

    bool IsStopWord(const string& word) const {
        return stop_words_.count(word) > 0;
    }

    vector<string> SplitIntoWordsNoStop(const string& text) const {
        vector<string> words;
        for (const string& word : SplitIntoWords(text)) {
            if (!IsStopWord(word)) {
                words.push_back(word);
            }
        }
        return words;
    }

    Query ParseQuery(const string& text) const {
        Query query;
        for (const string& word : SplitIntoWordsNoStop(text)) {
            if (word[0] == '-') {
                query.minus_words.insert(word.substr(1, word.size()));
            }
            else {
                query.query_words.push_back(word);
            }
        }
        return query;
    }

    vector<Document> FindAllDocuments(const Query& query) const {
        //В методе FindAllDocuments сначала вычислите релевантность документов, в которые входят плюс - слова запроса.
        //Для этого используйте map<int, int>, где ключ — id документа, а значение — количество плюс - слов, которые в этом документе встречаются
        map<int, int> rel;

        for (const string& word: query.query_words) {
            int docs_count = documents_.count(word);
            
            if (docs_count > 0 && (query.minus_words.count(word) == 0)) {
                for (auto& id : documents_.at(word)) {
                    rel[id]++;
                }
            }
           
        }

        vector<Document> matched_documents;
        for (const auto& [id, words_count] : rel) {
            matched_documents.push_back({id, words_count});
        }
        return matched_documents;
    }
};

SearchServer CreateSearchServer() {
    SearchServer search_server;
    search_server.SetStopWords(ReadLine());

    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        search_server.AddDocument(document_id, ReadLine());
    }

    return search_server;
}

int main() {
    const SearchServer search_server = CreateSearchServer();

    const string query = ReadLine();
    for (const auto& [document_id, relevance] : search_server.FindTopDocuments(query)) {
        cout << "{ document_id = "s << document_id << ", "
            << "relevance = "s << relevance << " }"s << endl;
    }
}