#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

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
    double relevance;
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
        ++document_count_;
        double word_ratio = CalculateWordRatio(words);
        for (const string& word : words) {
            documents_[word].insert(document_id);
            tf_map_[word][document_id] += word_ratio;
        }
    }

    vector<Document> FindTopDocuments(const string& raw_query) const {
        const Query query_words = ParseQuery(raw_query);
        auto matched_documents = FindAllDocuments(query_words);
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
    map<string, map<int, double>> tf_map_; // мапа: слово на id документа и tf этого слова в документе
    int document_count_ = 0;

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
                string minus_word = word.substr(1, word.size());
                query.minus_words.insert(minus_word);
                query.query_words.push_back(minus_word);
            }
            else {
                query.query_words.push_back(word);
            }
        }
        return query;
    }

    //Доля возникновения слова в документе
    double CalculateWordRatio(const vector<string>& words) const {
        return 1.0 / words.size();
    }

    //IDF (Inverse Document Frequency) 
    double CalculateIDF(int docs_count) const {
        return log(document_count_ / static_cast<double>(docs_count));
    }

    vector<Document> FindAllDocuments(const Query& query) const {
        //В методе FindAllDocuments сначала вычислите релевантность документов, в которые входят плюс - слова запроса.
        //Для этого используйте map<int, int>, где ключ — id документа, а значение — количество плюс - слов, которые в этом документе встречаются
        map<int, double> rel;

        map<int, int> rel2;

        for (const string& word : query.query_words) {
            int docs_exists = documents_.count(word);
            int docs_count = 0;
            if (docs_exists > 0) {
                docs_count = documents_.at(word).size();
            }

            if (docs_count > 0) {
                double idf = CalculateIDF(docs_count);
                int d = query.minus_words.count(word);

                for (auto& [id, tf] : tf_map_.at(word)) {
                    //расчитываем правильную релевантность через TF + IDF
                    //перемножаем TF и IDF
                    //прибавляем результат к rel[id]
                    rel[id] += tf * idf;

                    rel2[id] = d;
                }
            }
        }

        vector<Document> matched_documents;
        for (const auto& [id, words_count] : rel) {
            matched_documents.push_back({ id, words_count });
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