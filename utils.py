def tokenize(text, n=10):
    words = text.split()
    return [' '.join(words[i:i+n]) for i in range(len(words) - n + 1)]
