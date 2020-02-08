
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

#line 432 "index-combined.md"

	#include <string>
	using Prefix = std::string;
	unsigned prefix_length { 2 };

#line 442 "index-combined.md"

	void init(Prefix &p) {
		p = std::string { };
		for (unsigned i { 0 };
			i < prefix_length; ++i
		) {
			p += '\0';
		}
	}

#line 456 "index-combined.md"

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

#line 369 "index-combined.md"

	
#line 265 "index-combined.md"

	#include <map>
	
#line 777 "index-combined.md"

	
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

#line 432 "index-combined.md"

	#include <string>
	using Prefix = std::string;
	unsigned prefix_length { 2 };

#line 442 "index-combined.md"

	void init(Prefix &p) {
		p = std::string { };
		for (unsigned i { 0 };
			i < prefix_length; ++i
		) {
			p += '\0';
		}
	}

#line 456 "index-combined.md"

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

#line 778 "index-combined.md"
;
	using Collection =
		std::map<Prefix, int>;

#line 267 "index-combined.md"
;
	Collection collection;

#line 274 "index-combined.md"

	#include <iostream>

#line 316 "index-combined.md"

	#include <cctype>
	void write_byte(char b) {
		if (isprint(b) &&
			b != '%' && b > ' '
		) {
			std::cout << b;
		} else {
			
#line 334 "index-combined.md"

	static const char digits[] {
		"0123456789abcdef"
	};
	std::cout << '%' <<
		digits[(b >> 4) & 0xf] <<
		digits[b & 0xf];

#line 324 "index-combined.md"
;
		}
	}

#line 384 "index-combined.md"

	
#line 522 "index-combined.md"

	
#line 478 "index-combined.md"

	
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

#line 432 "index-combined.md"

	#include <string>
	using Prefix = std::string;
	unsigned prefix_length { 2 };

#line 442 "index-combined.md"

	void init(Prefix &p) {
		p = std::string { };
		for (unsigned i { 0 };
			i < prefix_length; ++i
		) {
			p += '\0';
		}
	}

#line 456 "index-combined.md"

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

#line 479 "index-combined.md"


#line 486 "index-combined.md"

	#include <map>

#line 506 "index-combined.md"

	
#line 493 "index-combined.md"

	struct Entry {
		const char ch;
		const int count;
		Entry (char c, int v):
			ch { c }, count { v }
		{ }
	};

#line 559 "index-combined.md"

	#include <random>
	std::mt19937 rng_ {
		std::random_device{ }()
	};

#line 507 "index-combined.md"
;
	#include <vector>
	class List {
		private:
			std::vector<Entry> entries_;
			int sum_ { 0 };
		public:
			
#line 532 "index-combined.md"

	void add(char ch, int count) {
		entries_.emplace_back(
			ch, count
		);
		sum_ += count;
	}

#line 545 "index-combined.md"

	class No_Entries { };
	char next() const {
		if (sum_ > 0) {
			
#line 569 "index-combined.md"

	auto dist {
		std::uniform_int_distribution<
			std::mt19937::result_type
		>(
			0, sum_ - 1
		) };
	int result = dist(rng_);

#line 582 "index-combined.md"

	for (const auto &i : entries_) {
		if (result < i.count) {
			return i.ch;
		}
		result -= i.count;
	}

#line 549 "index-combined.md"
;
		}
		throw No_Entries { };
	}

#line 514 "index-combined.md"
;
	};

#line 523 "index-combined.md"
;
	using Collection =
		std::map<Prefix, List>;
	Collection collection;

#line 594 "index-combined.md"

	Prefix state;

#line 385 "index-combined.md"
;
	class No_Next { };
	inline char next() {
		
#line 608 "index-combined.md"

	try {
		char ch {
			collection[state].next()
		};
		push(state, ch);
		return ch;
	} catch (const List::No_Entries &) {
	}

#line 388 "index-combined.md"
;
		throw No_Next { };
	}

#line 397 "index-combined.md"

	#include <iostream>

#line 625 "index-combined.md"

	
#line 655 "index-combined.md"

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

#line 626 "index-combined.md"
;
	std::string normalize(
		const std::string &key
	) {
		std::string result;
		unsigned i { 0 };
		for (; i < key.size(); ++i) {
			
#line 642 "index-combined.md"

	if (key[i] == '%') {
		
#line 672 "index-combined.md"

	result += static_cast<char>(
		(hex_digit(key[i + 1]) << 4) +
			hex_digit(key[i + 2])
	);

#line 644 "index-combined.md"
;
		i += 2;
	} else {
		result += key[i];
	}

#line 633 "index-combined.md"
;
		}
		return result;
	}

#line 370 "index-combined.md"
;
	int main() {
		
#line 682 "index-combined.md"

	bool first { true };
	Prefix k;
	for (;;) {
		
#line 700 "index-combined.md"

	std::string key;
	std::cin >> key;
	if (! std::cin) { break; }
	key = normalize(key);

#line 686 "index-combined.md"
;
		
#line 711 "index-combined.md"

	int count;
	std::cin >> count;
	if (! std::cin) { break; }

#line 687 "index-combined.md"
;
		if (first) {
			
#line 720 "index-combined.md"

	prefix_length = key.size() - 1;
	init(k);

#line 689 "index-combined.md"
;
			first = false;
		}
		
#line 728 "index-combined.md"

	for (unsigned i { 0 };
		i + 1 < key.size(); ++i
	) {
		push(k, key[i]);
	}
	collection[k].add(
		key.back(), count
	);

#line 692 "index-combined.md"
;
	}

#line 372 "index-combined.md"
;
		
#line 404 "index-combined.md"

	
#line 601 "index-combined.md"

	init(state);

#line 405 "index-combined.md"
;
	for (;;) {
		try {
			std::cout << next();
		} catch (const No_Next &) {
			
#line 601 "index-combined.md"

	init(state);

#line 410 "index-combined.md"
;
		}
	}

#line 373 "index-combined.md"
;
	}
