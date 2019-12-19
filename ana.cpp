
#line 6 "ana.md"

	
#line 29 "ana.md"

	#include <iostream>

#line 45 "ana.md"

	#include <map>
	
#line 138 "ana.md"

	
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

#line 139 "ana.md"
;
	using Collection =
		std::map<Key, int>;

#line 47 "ana.md"
;
	Collection collection;

#line 84 "ana.md"

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

#line 7 "ana.md"
;
	int main(
		int argc, const char *argv[]
	) {
		
#line 179 "ana.md"

	if (argc == 2) {
		const char *arg { argv[1] };
		if (
			arg[0] == '-' &&
				arg[1] == 'n'
		) {
			
#line 194 "ana.md"

	key_length = std::stoi(arg + 2);
	if (key_length < 1) {
		std::cerr << "wrong length\n";
		key_length = 2;
	}

#line 186 "ana.md"
;
		}
	}

#line 11 "ana.md"
;
		char ch;
		
#line 54 "ana.md"

	
#line 147 "ana.md"

	init(key);

#line 55 "ana.md"
;
	while (std::cin.get(ch)) {
		
#line 153 "ana.md"

	push(key, ch);
	++collection[key];

#line 57 "ana.md"
;
	}

#line 13 "ana.md"
;
		
#line 73 "ana.md"

	for (const auto &e : collection) {
		
#line 162 "ana.md"

	for (
		unsigned i = 0; i < key_length; ++i
	) {
		write_byte(e.first[i]);
	}

#line 75 "ana.md"
;
		std::cout << "\t" <<
			e.second << "\n";
	}

#line 14 "ana.md"
;
	}
