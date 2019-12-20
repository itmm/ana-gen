
#line 4 "gen.md"

	
#line 14 "gen.md"

	
#line 120 "gen.md"

	#include <memory>
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
				if (_sum > 0) {
					auto dist { std::uniform_int_distribution<std::mt19937::result_type>(0, _sum - 1) };
					int result = dist(_rng);
					for (Entry *e { &*_entries };; e = &e->next()) {
						if (result < e->count()) {
							return e->ch();
						}
						result -= e->count();
						if (e->last()) { break; }
					}
				}
				return '\0';
			}
	};

	#include <map>
	
#line 8 "prefix.md"

	#include <string>
	using Prefix = std::string;
	unsigned prefix_length { 2 };

#line 18 "prefix.md"

	void init(Prefix &p) {
		p = std::string { };
		for (unsigned i { 0 };
			i < prefix_length; ++i
		) {
			p += '\0';
		}
	}

#line 32 "prefix.md"

	void push(Prefix &p, char ch) {
		if (p.size() > 0) {
			for (unsigned i = 1;
				i < p.size(); ++i
			) {
				p[i - 1] = p[i];
			}
			p[p.size() - 1] = ch;
		}
	}

#line 177 "gen.md"

	using Collection = std::map<Prefix, List>;
	Collection collection;

#line 15 "gen.md"
;
	
#line 225 "gen.md"

	Prefix prev;
	#include <iostream>

#line 16 "gen.md"
;
	inline bool next(char &ch) {
		bool ok { false };
		
#line 238 "gen.md"

	ch = collection[prev].next();
	ok = ch != '\0';
	push(prev, ch);

#line 19 "gen.md"
;
		return ok;
	}

#line 26 "gen.md"

	#include <iostream>

#line 91 "gen.md"

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

#line 5 "gen.md"
;
	int main() {
		
#line 184 "gen.md"

	bool first { true };
	Prefix k;
	for (;;) {
		std::string key;
		std::cin >> key;
		if (! std::cin) { break; }
		int count;
		std::cin >> count;
		if (! std::cin) { break; }
		key = normalize(key);
		if (first) {
			prefix_length = key.size() - 1;
			first = false;
			init(k);
		}
		
#line 206 "gen.md"

	for (unsigned i { 0 }; i + 1 < key.size(); ++i) {
		push(k, key[i]);
	}
	collection[k].add(key.back(), count);

#line 200 "gen.md"
;
	}

#line 7 "gen.md"
;
		
#line 32 "gen.md"

	
#line 232 "gen.md"

	init(prev);

#line 33 "gen.md"
;
	for (;;) {
		char ch;
		if (next(ch)) {
			std::cout << ch;
		} else {
			
#line 232 "gen.md"

	init(prev);

#line 39 "gen.md"
;
		}
	}

#line 8 "gen.md"
;
	}
