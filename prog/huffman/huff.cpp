#include <iostream>
#include <stddef.h>
#include <string>
#include <queue>
#include <fstream>
#include <unordered_map>

using namespace std;

/**
 * @brief Коды ошибок
 * 
 */
enum {
    FILE_OPENING_ERROR = -3,
    ALLOCATION_ERROR,
    PARAMETRS_ERROR
};

/**
 * @brief A Tree node
 * 
 */
struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

/**
 * @brief Get the Node objectFunction to allocate a new tree node
 * 
 * @param ch 
 * @param freq 
 * @param left 
 * @param right 
 * @return Node* 
 */
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

/**
 * @brief Comparison object to be used to order the heap
 * 
 */
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};

/**
 * @brief traverse the Huffman Tree and store Huffman Codes in a map.
 * 
 * @param root 
 * @param str 
 * @param huffmanCode 
 */
void encode(Node* root, string str,
			unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

/**
 * @brief traverse the Huffman Tree and decode the encoded string
 * 
 * @param root 
 * @param index 
 * @param str 
 */
void decode(Node* root, int &index, string str)
{
	if (root == nullptr) {
		return;
	}

	// found a leaf node
	if (!root->left && !root->right)
	{
		cout << root->ch;
		return;
	}

	index++;

	if (str[index] =='0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}

/**
 * @brief Builds Huffman Tree and decode given input text
 * 
 * @param text 
 * @param compressed_file
 */
string buildHuffmanTree(string text)
{
	// count frequency of appearance of each character
	// and store it in a map
	unordered_map<char, int> freq;
	for (char ch: text) {
		freq[ch]++;
	}

	// Create a priority queue to store live nodes of
	// Huffman tree;
	priority_queue<Node*, vector<Node*>, comp> pq;

	// Create a leaf node for each character and add it
	// to the priority queue.
	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
		// Remove the two nodes of highest priority
		// (lowest frequency) from the queue
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();

		// Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	// root stores pointer to root of Huffman Tree
	Node* root = pq.top();

	// traverse the Huffman Tree and store Huffman Codes
	// in a map. Also prints them
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	// cout << "Huffman Codes are :\n" << '\n';
	// for (auto pair: huffmanCode) {
		// cout << pair.first << " " << pair.second << '\n';
	// }

	// cout << "\nOriginal string was :\n" << text << '\n';

	// print encoded string
	string str = "";
	for (char ch: text) {
		str += huffmanCode[ch];
	}

	// cout << "\nEncoded string is :\n" << str << '\n';

    return str;

	// traverse the Huffman Tree again and this time
	// decode the encoded string
	// int index = -1;
	// cout << "\nDecoded string is: \n";
	// while (index < (int)str.size() - 2) {
		// decode(root, index, str);
	// }
}

size_t ft_strlen(char *str)
{
    size_t len = 0;

    while (*str++)
        ++len;

    return len;
}

/**
 * @brief Create a compressed name object
 * 
 * @param original_name 
 * @return char* 
 */
char* create_comp_name(char* original_name)
{
    char* res = new char[ft_strlen(original_name) + 25];
    char* res_copy = res;
    char added[17] = "_.cmp";
    
    while (*original_name != '.')
    {
        *res = *original_name;
        ++res;
        ++original_name;
    }

    for (int i = 0; i < 17; i++)
    {
        *res = added[i];
        ++res;
    }

    return res_copy;
}

int p2_to_10(string str)
{
    int pow = 1;
    int res = 0;
    const char* strc = str.c_str();
    for (int i = 7; i >= 0; i--)
    {
        res += atoi(&strc[i]) * pow;
        pow *= 2;
    }
    return res;
}

string code_string(string line)
{
    int size = line.size();
    if (size == 0) return "";
    if (size % 8 != 0)
    {
        line.insert(0, size % 8, '0');
        size += size % 8;
    }

    string res;
    int ind = 0;
    while (size > 0)
    {
        string substr = line.substr(ind, 8);
        char symb = p2_to_10(substr);
        res.append(1, symb);
        size -= 8;
    }
    return res;
}

char* create_compressed_name(char* original_name)
{
    char* res = new char[ft_strlen(original_name) + 25];
    char* res_copy = res;
    char added[17] = "_compressed.comp";
    
    while (*original_name != '.')
    {
        *res = *original_name;
        ++res;
        ++original_name;
    }

    for (int i = 0; i < 17; i++)
    {
        *res = added[i];
        ++res;
    }

    return res_copy;
}

// Huffman coding algorithm
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Недостаточно параметров\n");
        return PARAMETRS_ERROR;
    }

	char* compressed_name = create_comp_name(argv[1]);

    string line;
    
    ofstream out;
    out.open(compressed_name);
    ifstream in(argv[1]);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            if (line.size() == 0)
                out << endl;
            else
            {
                line = buildHuffmanTree(line);
                out << line << endl;
            }
        }
    }
    in.close();
    out.close();

    char* final_name = create_compressed_name(argv[1]);
    ifstream inp(compressed_name);
    ofstream outp;
    outp.open(final_name);
    if (inp.is_open())
    {
        while (getline(inp, line))
        {
            if (line.size() == 0)
                outp << endl;
            else
                outp << code_string(line) << endl;
        }
    }

	return 0;
}