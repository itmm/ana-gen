
#line 6 "gen.md"

	
#line 21 "gen.md"

	
#line 108 "gen.md"

	
#line 63 "gen.md"

	
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

#line 64 "gen.md"


#line 71 "gen.md"

	#include <map>

#line 91 "gen.md"

	
#line 78 "gen.md"

	struct Entry {
		const char ch;
		const int count;
		Entry (char c, int v):
			ch { c }, count { v }
		{ }
	};

#line 145 "gen.md"

	#include <random>
	std::mt19937 _rng {
		std::random_device{ }()
	};

#line 92 "gen.md"
;
	#include <vector>
	class List {
		private:
			std::vector<Entry> _entries;
			int _sum { 0 };
		public:
			
#line 118 "gen.md"

	void add(char ch, int count) {
		_entries.emplace_back(
			ch, count
		);
		_sum += count;
	}

#line 131 "gen.md"

	class No_Entries { };
	char next() const {
		if (_sum > 0) {
			
#line 155 "gen.md"

	auto dist {
		std::uniform_int_distribution<
			std::mt19937::result_type
		>(
			0, _sum - 1
		) };
	int result = dist(_rng);

#line 168 "gen.md"

	for (const auto &i : _entries) {
		if (result < i.count) {
			return i.ch;
		}
		result -= i.count;
	}

#line 135 "gen.md"
;
		}
		throw No_Entries { };
	}

#line 99 "gen.md"
;
	};


#line 109 "gen.md"
;
	using Collection =
		std::map<Prefix, List>;
	Collection collection;

#line 180 "gen.md"

	Prefix state;

#line 22 "gen.md"
;
	struct No_Next { };
	inline char next() {
		
#line 194 "gen.md"

	try {
		char ch {
			collection[state].next()
		};
		push(state, ch);
		return ch;
	} catch (const List::No_Entries &) {
	}

#line 25 "gen.md"
;
		throw No_Next { };
	}

#line 34 "gen.md"

	#include <iostream>

#line 211 "gen.md"

	
#line 241 "gen.md"

	int hex_digit(char ch) {
		if (ch >= '0' && ch <= '9') {
			return ch - '0';
		} else if (
			ch >= 'a' && ch <= 'f'
		) {
			return ch - 'a' + 10;
		}
		std::cerr << "invalid digit\n";
		return 0;
	}

#line 212 "gen.md"
;
	std::string normalize(
		const std::string &key
	) {
		std::string result;
		unsigned i { 0 };
		for (; i < key.size(); ++i) {
			
#line 228 "gen.md"

	if (key[i] == '%') {
		
#line 258 "gen.md"

	result += static_cast<char>(
		(hex_digit(key[i + 1]) << 4) +
			hex_digit(key[i + 2])
	);

#line 230 "gen.md"
;
		i += 2;
	} else {
		result += key[i];
	}

#line 219 "gen.md"
;
		}
		return result;
	}

#line 7 "gen.md"
;
	int main() {
		
#line 268 "gen.md"

	bool first { true };
	Prefix k;
	for (;;) {
		
#line 286 "gen.md"

	std::string key;
	std::cin >> key;
	if (! std::cin) { break; }
	key = normalize(key);

#line 272 "gen.md"
;
		
#line 297 "gen.md"

	int count;
	std::cin >> count;
	if (! std::cin) { break; }

#line 273 "gen.md"
;
		if (first) {
			
#line 306 "gen.md"

	prefix_length = key.size() - 1;
	init(k);

#line 275 "gen.md"
;
			first = false;
		}
		
#line 314 "gen.md"

	for (unsigned i { 0 };
		i + 1 < key.size(); ++i
	) {
		push(k, key[i]);
	}
	collection[k].add(
		key.back(), count
	);

#line 278 "gen.md"
;
	}

#line 9 "gen.md"
;
		
#line 41 "gen.md"

	
#line 187 "gen.md"

	init(state);

#line 42 "gen.md"
;
	for (;;) {
		try {
			std::cout << next();
		} catch (const No_Next &) {
			
#line 187 "gen.md"

	init(state);

#line 47 "gen.md"
;
		}
	}

#line 10 "gen.md"
;
	}
