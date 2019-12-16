
#line 11 "index.md"

	
#line 34 "index.md"

	#include <iostream>

#line 50 "index.md"

	#include <map>
	
#line 243 "index.md"

	
#line 136 "index.md"

	
#line 174 "index.md"

	#include <cstring>

#line 137 "index.md"
;
	#include <memory>
	class Key {
		private:
			std::unique_ptr<char> _key;
		public:
			
#line 155 "index.md"

	static int length;

#line 181 "index.md"

	Key():
		_key { new char[length] }
	{
		memset(&*_key, 0, length);
	}

#line 192 "index.md"

	Key(const Key &other):
		_key { new char[length] }
	{
		memcpy(
			&*_key, &*other._key, length
		);
	}

#line 205 "index.md"

	Key &operator=(const Key &other) {
		memcpy(
			&*_key, &*other._key, length
		);
		return *this;
	}

#line 217 "index.md"

	bool operator==(
		const Key &other
	) const {
		return memcmp(
			&*_key, &*other._key, length
		) == 0;
	}

#line 230 "index.md"

	bool operator<(
		const Key &other
	) const {
		return memcmp(
			&*_key, &*other._key, length
		) < 0;
	}

#line 253 "index.md"

	void push(char ch) {
		memmove(
			&*_key, &*_key + 1,
			length - 1
		);
		(&*_key)[length - 1] = ch;
	}

#line 276 "index.md"

	char operator[](int i) const {
		return (&*_key)[i];
	}

#line 143 "index.md"
;
	};
	
#line 167 "index.md"

	int Key::length { 2 };

#line 145 "index.md"
;

#line 244 "index.md"

	using Collection =
		std::map<Key, int>;
	Key key;

#line 52 "index.md"
;
	Collection collection;

#line 88 "index.md"

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

#line 12 "index.md"
;
	int main(
		int argc, const char *argv[]
	) {
		
#line 302 "index.md"

	if (argc == 2) {
		const char *arg { argv[1] };
		if (
			arg[0] == '-' &&
				arg[1] == 'n'
		) {
			
#line 317 "index.md"

	Key::length = std::stoi(arg + 2);
	if (Key::length < 1) {
		std::cerr << "wrong length\n";
		Key::length = 2;
	}
	key.~Key();
	new (&key) Key { };

#line 309 "index.md"
;
		}
	}

#line 16 "index.md"
;
		char ch;
		
#line 59 "index.md"

	while (std::cin.get(ch)) {
		
#line 267 "index.md"

	key.push(ch);
	++collection[key];

#line 61 "index.md"
;
	}

#line 18 "index.md"
;
		
#line 77 "index.md"

	for (const auto &e : collection) {
		
#line 285 "index.md"

	for (
		int i = 0; i < Key::length; ++i
	) {
		write_byte(e.first[i]);
	}

#line 79 "index.md"
;
		std::cout << "\t" <<
			e.second << "\n";
	}

#line 19 "index.md"
;
	}
