import collections
import string
import heapq as heap


def count_letters(filename, case_sensitive=False):
    with open(filename, 'r') as f:
        original_text = f.read()
    if case_sensitive:
        alphabet = string.ascii_letters + string.digits
        text = original_text
    else:
        alphabet = string.ascii_lowercase + string.digits + ' ' + string.punctuation
        text = original_text.lower()
    alphabet_set = set(alphabet)
    counts = collections.Counter(c for c in text if c in alphabet_set)

    counts = dict(counts)
    return counts


def sort_freq(freq):
    node = []
    for letters in freq.keys():
        node.append([freq_count[letters], [letters, '']])
    node.sort()
    return node


def encode(node):
    while len(node) > 1:
        x = heap.heappop(node)
        y = heap.heappop(node)
        for step in x[1:]:
            step[1] = '0' + step[1]
        for step in y[1:]:
            step[1] = '1' + step[1]
        heap.heappush(node, [x[0] + y[0]] + x[1:] + y[1:])
    node = node[0]
    return node


if __name__ == '__main__':
    freq_count = count_letters('/Users/aniketwaliyan/PycharmProjects/Compression/file1.txt')
    tup = sort_freq(freq_count)
    huff = encode(tup)
    count = huff[0]
    print("Symbol".ljust(8) + "Frequency".ljust(15) + "Huffman Code")
    for i in huff[1:]:
        print(i[0].ljust(10) + str(freq_count[i[0]]).ljust(15) + i[1])
    print("\nNumber of Letters are : ", count)
