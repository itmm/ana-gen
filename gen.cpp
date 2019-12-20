
#line 4 "gen.md"

	
#line 14 "gen.md"

	
#line 88 "gen.md"

	
#line 45 "gen.md"

	#include <map>

#line 55 "gen.md"

	
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

#line 56 "gen.md"


#line 73 "gen.md"

	
#line 61 "gen.md"

	struct Entry {
		const char ch;
		const int count;
		Entry (char c, int v):
			ch { c }, count { v }
		{ }
	};

#line 119 "gen.md"

	#include <random>
	std::mt19937 _rng {
		std::random_device{ }()
	};


#line 74 "gen.md"
;
	#include <vector>
	class List {
		private:
			std::vector<Entry> _entries;
			int _sum { 0 };
		public:
			
#line 97 "gen.md"

	void add(char ch, int count) {
		_entries.emplace_back(
			ch, count
		);
		_sum += count;
	}

#line 108 "gen.md"

	char next() const {
		if (_sum > 0) {
			
#line 129 "gen.md"

	auto dist {
		std::uniform_int_distribution<
			std::mt19937::result_type
		>(0, _sum - 1) };
	int result = dist(_rng);

#line 139 "gen.md"

	for (const auto &i : _entries) {
		if (result < i.count) {
			return i.ch;
		}
		result -= i.count;
	}

#line 111 "gen.md"
;
		}
		return '\0';
	}

#line 81 "gen.md"
;
	};


#line 89 "gen.md"
;
	using Collection =
		std::map<Prefix, List>;
	Collection collection;

#line 150 "gen.md"

	Prefix state;

#line 15 "gen.md"
;
	inline bool next(char &ch) {
		bool ok { false };
		
#line 162 "gen.md"

	ch = collection[state].next();
	push(state, ch);
	ok = ch != '\0';

#line 18 "gen.md"
;
		return ok;
	}

#line 25 "gen.md"

	#include <iostream>

#line 170 "gen.md"

	
#line 192 "gen.md"

	int hex_digit(char ch) {
		if (ch >= '0' && ch <= '9') {
			return ch - '0';
		} else if (
			ch >= 'a' && ch <= 'f'
		) {
			return ch - 'a' + 10;
		} else {
			std::cerr <<
				"invalid digit\n";
			return 0;
		}
	}

#line 171 "gen.md"
;
	std::string normalize(
		const std::string &key
	) {
		std::string result;
		for (unsigned i { 0 };
			i < key.size(); ++i
		) {
			if (key[i] == '%') {
				
#line 210 "gen.md"

	result += static_cast<char>(
		(hex_digit(key[i + 1]) << 4) +
			hex_digit(key[i + 2])
	);

#line 180 "gen.md"
;
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
		
#line 219 "gen.md"

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
		
#line 237 "gen.md"

	if (first) {
		prefix_length = key.size() - 1;
		first = false;
		init(k);
	}

#line 230 "gen.md"
;
		
#line 247 "gen.md"

	for (unsigned i { 0 };
		i + 1 < key.size(); ++i
	) {
		push(k, key[i]);
	}
	collection[k].add(
		key.back(), count
	);

#line 231 "gen.md"
;
	}

#line 7 "gen.md"
;
		
#line 31 "gen.md"

	
#line 156 "gen.md"

	init(state);

#line 32 "gen.md"
;
	for (;;) {
		char ch;
		if (next(ch)) {
			std::cout << ch;
		} else {
			
#line 156 "gen.md"

	init(state);

#line 38 "gen.md"
;
		}
	}

#line 8 "gen.md"
;
	}
