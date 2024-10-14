struct Document {
    int id;
    int relevance;
};

bool HasDocumentGreaterRelevance(const Document& l, const Document& r) {
    return l.relevance > r.relevance;
}

int main() {
}