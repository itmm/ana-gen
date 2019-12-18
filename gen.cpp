
#line 345 "index.md"

	
#line 355 "index.md"

	
#line 457 "index.md"

	#include <memory>
	#include <cassert>
	#include <random>
	class Entry {
		private:
			std::unique_ptr<Entry> _next;
			char _ch;
			int _count;
		public:
			Entry(char ch, int count): _ch { ch }, _count { count} { }
			char ch() const { return _ch; }
			int count() const { return _count; }
			bool last() const { return ! _next; }
			Entry &next() const { return *_next; }
			void add(std::unique_ptr<Entry> &&entry) {
				if (last()) {
					_next = std::move(entry);
				} else {
					_next->add(std::move(entry));
				}
			}
	};

	std::random_device _dev;
	std::mt19937 _rng { _dev() };

	class List {
		private:
			std::unique_ptr<Entry> _entries;
			int _sum { 0 };
		public:
			void add(char ch, int count) {
				auto entry { std::make_unique<Entry>(ch, count) };
				if (_entries) {
					_entries->add(std::move(entry));
				} else {
					_entries = std::move(entry);
				}
				_sum += count;
			}
			char next() {
				assert(_sum > 0);
				auto dist { std::uniform_int_distribution<std::mt19937::result_type>(0, _sum - 1) };
				int result = dist(_rng);
				for (Entry *e { &*_entries };; e = &e->next()) {
					if (result < e->count()) {
						return e->ch();
					}
					result -= e->count();
					if (e->last()) { break; }
				}
				return '\0';
			}
	};

	
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
		if (length > 0) {
			memmove(
				&*_key, &*_key + 1,
				length - 1
			);
			(&*_key)[length - 1] = ch;
		}
	}

#line 286 "index.md"

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

#line 513 "index.md"
;

	#include <map>
	using Collection = std::map<Key, List>;
	Collection collection;

#line 356 "index.md"
;
	
#line 565 "index.md"

	Key prev;

#line 357 "index.md"
;
	inline bool next(char &ch) {
		bool ok { false };
		
#line 577 "index.md"

	ch = collection[prev].next();
	ok = ch != '\0';
	prev.push(ch);

#line 360 "index.md"
;
		return ok;
	}

#line 367 "index.md"

	#include <iostream>

#line 428 "index.md"

	int hex_digit(char ch) {
		if (ch >= '0' && ch <= '9') {
			return ch - '0';
		} else if (ch >= 'a' && ch <= 'f') {
			return ch - 'a' + 10;
		} else {
			std::cerr << "invalid digit\n";
			return 0;
		}
	}
	std::string normalize(const std::string &key) {
		std::string result;
		for (unsigned i { 0 }; i < key.size(); ++i) {
			if (key[i] == '%') {
				result += static_cast<char>(
					(hex_digit(key[i + 1]) << 4) + hex_digit(key[i + 2])
				);
				i += 2;
			} else {
				result += key[i];
			}
		}
		return result;
	}

#line 346 "index.md"
;
	int main() {
		
#line 522 "index.md"

	bool first { true };
	Key k;
	for (;;) {
		std::string key;
		std::cin >> key;
		if (! std::cin) { break; }
		int count;
		std::cin >> count;
		if (! std::cin) { break; }
		key = normalize(key);
		if (first) {
			Key::length = key.size() - 1;
			first = false;
			k.~Key();
			new (&k) Key { };
		}
		
#line 545 "index.md"

	assert((int) key.size() == Key::length + 1);
	for (unsigned i { 0 }; i + 1 < key.size(); ++i) {
		k.push(key[i]);
	}
	collection[k].add(key.back(), count);

#line 539 "index.md"
;
	}

#line 348 "index.md"
;
		
#line 373 "index.md"

	
#line 571 "index.md"

	prev = Key { };

#line 374 "index.md"
;
	for (;;) {
		char ch;
		if (next(ch)) {
			std::cout << ch;
		} else {
			
#line 571 "index.md"

	prev = Key { };

#line 380 "index.md"
;
		}
	}

#line 349 "index.md"
;
	}
