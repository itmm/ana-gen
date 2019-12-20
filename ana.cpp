
#line 6 "ana-1.md"

	
#line 29 "ana-1.md"

	#include <iostream>

#line 45 "ana-1.md"

	#include <map>
	
#line 26 "ana-n.md"

	
#line 4 "key.md"

	using Key = std::string;
	unsigned key_length { 2 };
	Key key;

#line 12 "key.md"

	void init(Key &k) {
		k = std::string { };
		for (unsigned i { 0 }; i < key_length; ++i) {
			k += '\0';
		}
	}

#line 23 "key.md"

	void push(Key &key, char ch) {
		if (key.size() > 0) {
			for (unsigned i = 1; i < key.size(); ++i) {
				key[i - 1] = key[i];
			}
			key[key.size() - 1] = ch;
		}
	}

#line 27 "ana-n.md"
;
	using Collection =
		std::map<Key, int>;

#line 47 "ana-1.md"
;
	Collection collection;

#line 84 "ana-1.md"

	#include <cctype>
	void write_byte(char b) {
		if (isprint(b) &&
			b != '%' && b > ' '
		) {
			std::cout << b;
		} else {
			static const char digits[] =
				"0123456789abcdef";
			std::cout << '%' <<
				digits[(b >> 4) & 0xf] <<
				digits[b & 0xf];
		}
	}

#line 7 "ana-1.md"
;
	int main(
		int argc, const char *argv[]
	) {
		
#line 67 "ana-n.md"

	if (argc == 2) {
		const char *arg { argv[1] };
		if (
			arg[0] == '-' &&
				arg[1] == 'n'
		) {
			
#line 82 "ana-n.md"

	key_length = std::stoi(arg + 2);
	if (key_length < 1) {
		std::cerr << "wrong length\n";
		key_length = 2;
	}

#line 74 "ana-n.md"
;
		}
	}

#line 11 "ana-1.md"
;
		char ch;
		
#line 54 "ana-1.md"

	
#line 35 "ana-n.md"

	init(key);

#line 55 "ana-1.md"
;
	while (std::cin.get(ch)) {
		
#line 41 "ana-n.md"

	push(key, ch);
	++collection[key];

#line 57 "ana-1.md"
;
	}

#line 13 "ana-1.md"
;
		
#line 73 "ana-1.md"

	for (const auto &e : collection) {
		
#line 50 "ana-n.md"

	for (
		unsigned i = 0; i < key_length; ++i
	) {
		write_byte(e.first[i]);
	}

#line 75 "ana-1.md"
;
		std::cout << "\t" <<
			e.second << "\n";
	}

#line 14 "ana-1.md"
;
	}
