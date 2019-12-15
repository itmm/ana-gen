
#line 84 "index.md"

	
#line 95 "index.md"

	#include <iostream>

#line 107 "index.md"

	#include <map>
	
#line 211 "index.md"

	
#line 163 "index.md"

	int key_length { 2 };
	#include <cstring>
	class Key {
		private:
			char *_key;
		public:
			Key(): _key { new char[key_length] } {
				memset(_key, 0, key_length);
			}
			Key(const Key &other): _key { new char[key_length] } {
				memcpy(_key, other._key, key_length);
			}
			Key &operator=(const Key &other) {
				memcpy(_key, other._key, key_length);
				return *this;
			}
			~Key() {
				delete _key;
			}
			bool operator==(const Key &other) const {
				return memcmp(_key, other._key, key_length) == 0;
			}
			bool operator<(const Key &other) const {
				return memcmp(_key, other._key, key_length) < 0;
			}
			char operator[](int i) const {
				return _key[i];
			}
			void push(char ch) {
				memmove(_key, _key + 1, key_length - 1);
				_key[key_length - 1] = ch;
			}
	};

#line 212 "index.md"

	using Collection = std::map<Key, int>;
	Key key;

#line 109 "index.md"
;
	Collection collection;

#line 140 "index.md"

	#include <cctype>
	void write_byte(char b) {
		if (isprint(b) && b != '\\') {
			std::cout << b;
		} else {
			static const char digits[] =
				"0123456789abcdef";
			std::cout << "\\x" <<
				digits[(b >> 4) & 0xf] <<
				digits[b & 0xf];
		}
	}

#line 85 "index.md"
;
	int main() {
		char ch;
		
#line 115 "index.md"

	while (std::cin.get(ch)) {
		
#line 219 "index.md"

	key.push(ch);
	++collection[key];

#line 117 "index.md"
;
	}

#line 88 "index.md"
;
		
#line 130 "index.md"

	for (const auto &e : collection) {
		
#line 226 "index.md"

	for (int i = 0; i < key_length; ++i) {
		write_byte(e.first[i]);
	}

#line 132 "index.md"
;
		std::cout << "\t" <<
			e.second << "\n";
	}

#line 89 "index.md"
;
	}
