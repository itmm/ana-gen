
#line 84 "index.md"

	
#line 98 "index.md"

	#include <iostream>

#line 111 "index.md"

	#include <map>
	
#line 261 "index.md"

	
#line 177 "index.md"

	
#line 189 "index.md"

	int key_length { 2 };

#line 195 "index.md"

	#include <cstring>

#line 178 "index.md"
;
	class Key {
		private:
			char *_key;
		public:
			
#line 201 "index.md"

	Key():
		_key { new char[key_length] }
	{
		memset(_key, 0, key_length);
	}
	~Key() {
		delete _key;
	}

#line 214 "index.md"

	Key(const Key &other):
		_key { new char[key_length] }
	{
		memcpy(
			_key, other._key, key_length
		);
	}

#line 226 "index.md"

	Key &operator=(const Key &other) {
		memcpy(
			_key, other._key, key_length
		);
		return *this;
	}

#line 237 "index.md"

	bool operator==(
		const Key &other
	) const {
		return memcmp(
			_key, other._key, key_length
		) == 0;
	}

#line 249 "index.md"

	bool operator<(
		const Key &other
	) const {
		return memcmp(
			_key, other._key, key_length
		) < 0;
	}

#line 270 "index.md"

	void push(char ch) {
		memmove(
			_key, _key + 1,
			key_length - 1
		);
		_key[key_length - 1] = ch;
	}

#line 289 "index.md"

	char operator[](int i) const {
		return _key[i];
	}

#line 183 "index.md"
;
	};

#line 262 "index.md"

	using Collection =
		std::map<Key, int>;
	Key key;

#line 113 "index.md"
;
	Collection collection;

#line 144 "index.md"

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
	int main(
		int argc, const char *argv[]
	) {
		
#line 307 "index.md"

	if (argc == 2) {
		const char *arg { argv[1] };
		if (
			arg[0] == '-' && arg[1] == 'n'
		) {
			key_length = std::stoi(arg + 2);
			key.~Key();
			new (&key) Key { };
		}
	}

#line 89 "index.md"
;
		char ch;
		
#line 119 "index.md"

	while (std::cin.get(ch)) {
		
#line 282 "index.md"

	key.push(ch);
	++collection[key];

#line 121 "index.md"
;
	}

#line 91 "index.md"
;
		
#line 134 "index.md"

	for (const auto &e : collection) {
		
#line 297 "index.md"

	for (
		int i = 0; i < key_length; ++i
	) {
		write_byte(e.first[i]);
	}

#line 136 "index.md"
;
		std::cout << "\t" <<
			e.second << "\n";
	}

#line 92 "index.md"
;
	}
