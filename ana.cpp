
#line 11 "index.md"

	
#line 34 "index.md"

	#include <iostream>

#line 50 "index.md"

	#include <map>
	
#line 251 "index.md"

	
#line 138 "index.md"

	
#line 144 "index.md"

	
#line 182 "index.md"

	#include <cstring>

#line 145 "index.md"
;
	#include <memory>
	class Key {
		private:
			std::unique_ptr<char> _key;
		public:
			
#line 163 "index.md"

	static int length;

#line 189 "index.md"

	Key():
		_key { new char[length] }
	{
		memset(&*_key, 0, length);
	}

#line 200 "index.md"

	Key(const Key &other):
		_key { new char[length] }
	{
		memcpy(
			&*_key, &*other._key, length
		);
	}

#line 213 "index.md"

	Key &operator=(const Key &other) {
		memcpy(
			&*_key, &*other._key, length
		);
		return *this;
	}

#line 225 "index.md"

	bool operator==(
		const Key &other
	) const {
		return memcmp(
			&*_key, &*other._key, length
		) == 0;
	}

#line 238 "index.md"

	bool operator<(
		const Key &other
	) const {
		return memcmp(
			&*_key, &*other._key, length
		) < 0;
	}

#line 261 "index.md"

	void push(char ch) {
		memmove(
			&*_key, &*_key + 1,
			length - 1
		);
		(&*_key)[length - 1] = ch;
	}

#line 284 "index.md"

	char operator[](int i) const {
		return (&*_key)[i];
	}

#line 151 "index.md"
;
	};
	
#line 175 "index.md"

	int Key::length { 2 };

#line 153 "index.md"
;

#line 139 "index.md"
;

#line 252 "index.md"

	using Collection =
		std::map<Key, int>;
	Key key;

#line 52 "index.md"
;
	Collection collection;

#line 88 "index.md"

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

#line 12 "index.md"
;
	int main(
		int argc, const char *argv[]
	) {
		
#line 310 "index.md"

	if (argc == 2) {
		const char *arg { argv[1] };
		if (
			arg[0] == '-' &&
				arg[1] == 'n'
		) {
			
#line 325 "index.md"

	Key::length = std::stoi(arg + 2);
	if (Key::length < 1) {
		std::cerr << "wrong length\n";
		Key::length = 2;
	}
	key.~Key();
	new (&key) Key { };

#line 317 "index.md"
;
		}
	}

#line 16 "index.md"
;
		char ch;
		
#line 59 "index.md"

	while (std::cin.get(ch)) {
		
#line 275 "index.md"

	key.push(ch);
	++collection[key];

#line 61 "index.md"
;
	}

#line 18 "index.md"
;
		
#line 77 "index.md"

	for (const auto &e : collection) {
		
#line 293 "index.md"

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
