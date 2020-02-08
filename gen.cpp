
#line 6 "gen.md"

	
#line 21 "gen.md"

	
#line 107 "gen.md"

	
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
		for (unsigned i { 1 };
			i < p.size(); ++i
		) {
			p[i - 1] = p[i];
		}
		if (p.size() > 0) {
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

#line 144 "gen.md"

	#include <random>
	std::mt19937 rng_ {
		std::random_device{ }()
	};

#line 92 "gen.md"
;
	#include <vector>
	class List {
		private:
			std::vector<Entry> entries_;
			int sum_ { 0 };
		public:
			
#line 117 "gen.md"

	void add(char ch, int count) {
		entries_.emplace_back(
			ch, count
		);
		sum_ += count;
	}

#line 130 "gen.md"

	class No_Entries { };
	char next() const {
		if (sum_ > 0) {
			
#line 154 "gen.md"

	auto dist {
		std::uniform_int_distribution<
			std::mt19937::result_type
		>(
			0, sum_ - 1
		) };
	int result = dist(rng_);

#line 167 "gen.md"

	for (const auto &i : entries_) {
		if (result < i.count) {
			return i.ch;
		}
		result -= i.count;
	}

#line 134 "gen.md"
;
		}
		throw No_Entries { };
	}

#line 99 "gen.md"
;
	};

#line 108 "gen.md"
;
	using Collection =
		std::map<Prefix, List>;
	Collection collection;

#line 179 "gen.md"

	Prefix state;

#line 22 "gen.md"
;
	class No_Next { };
	inline char next() {
		
#line 193 "gen.md"

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

#line 210 "gen.md"

	
#line 240 "gen.md"

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

#line 211 "gen.md"
;
	std::string normalize(
		const std::string &key
	) {
		std::string result;
		unsigned i { 0 };
		for (; i < key.size(); ++i) {
			
#line 227 "gen.md"

	if (key[i] == '%') {
		
#line 257 "gen.md"

	result += static_cast<char>(
		(hex_digit(key[i + 1]) << 4) +
			hex_digit(key[i + 2])
	);

#line 229 "gen.md"
;
		i += 2;
	} else {
		result += key[i];
	}

#line 218 "gen.md"
;
		}
		return result;
	}

#line 7 "gen.md"
;
	int main() {
		
#line 267 "gen.md"

	bool first { true };
	Prefix k;
	for (;;) {
		
#line 285 "gen.md"

	std::string key;
	std::cin >> key;
	if (! std::cin) { break; }
	key = normalize(key);

#line 271 "gen.md"
;
		
#line 296 "gen.md"

	int count;
	std::cin >> count;
	if (! std::cin) { break; }

#line 272 "gen.md"
;
		if (first) {
			
#line 305 "gen.md"

	prefix_length = key.size() - 1;
	init(k);

#line 274 "gen.md"
;
			first = false;
		}
		
#line 313 "gen.md"

	for (unsigned i { 0 };
		i + 1 < key.size(); ++i
	) {
		push(k, key[i]);
	}
	collection[k].add(
		key.back(), count
	);

#line 277 "gen.md"
;
	}

#line 9 "gen.md"
;
		
#line 41 "gen.md"

	
#line 186 "gen.md"

	init(state);

#line 42 "gen.md"
;
	for (;;) {
		try {
			std::cout << next();
		} catch (const No_Next &) {
			
#line 186 "gen.md"

	init(state);

#line 47 "gen.md"
;
		}
	}

#line 10 "gen.md"
;
	}
