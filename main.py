from kmp import kmp_search
from hash_table import HashTable
from document_loader import load_documents_from_folder
from utils import tokenize

def compute_similarity(doc1, doc2):
    tokens1 = tokenize(doc1)
    total = len(tokens1)
    if total == 0:
        return 0.0
    matches = 0
    for pattern in tokens1:
        if kmp_search(doc2, pattern) > 0:
            matches += 1
    return (matches / total) * 100

def main():
    folder = "./"
    documents = load_documents_from_folder(folder)
    table = HashTable()

    for filename, content in documents.items():
        table.put(filename, content)

    results = []
    files = list(table.keys())
    for i in range(len(files)):
        for j in range(i + 1, len(files)):
            file1, file2 = files[i], files[j]
            sim = compute_similarity(table.get(file1), table.get(file2))
            results.append((file1, file2, sim))

    for file1, file2, score in results:
        print(f"{file1} <-> {file2}: {score:.2f}% similarity")

if __name__ == "__main__":
    main()
