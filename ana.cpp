
#line 11 "ana-1.md"

	
#line 42 "ana-1.md"

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

#line 44 "ana-1.md"
;
	Collection collection;

#line 51 "ana-1.md"

	#include <iostream>

#line 93 "ana-1.md"

	#include <cctype>
	void write_byte(char b) {
		if (isprint(b) &&
			b != '%' && b > ' '
		) {
			std::cout << b;
		} else {
			
#line 111 "ana-1.md"

	static const char digits[] {
		"0123456789abcdef"
	};
	std::cout << '%' <<
		digits[(b >> 4) & 0xf] <<
		digits[b & 0xf];

#line 101 "ana-1.md"
;
		}
	}

#line 12 "ana-1.md"
;
	int main(
		int argc, const char *argv[]
	) {
		
#line 70 "ana-n.md"

	if (argc == 2) {
		const char *arg { argv[1] };
		if (
			arg[0] == '-' &&
				arg[1] == 'n'
		) {
			
#line 85 "ana-n.md"

	prefix_length = std::stoi(arg + 2);
	if (prefix_length < 1) {
		std::cerr << "invalid length\n";
		prefix_length = 2;
	}

#line 77 "ana-n.md"
;
		}
	}

#line 820 "index-combined.md"

	if (argc == 2) {
		const char *arg { argv[1] };
		if (
			arg[0] == '-' &&
				arg[1] == 'n'
		) {
			
#line 835 "index-combined.md"

	prefix_length = std::stoi(arg + 2);
	if (prefix_length < 1) {
		std::cerr << "invalid length\n";
		prefix_length = 2;
	}

#line 827 "index-combined.md"
;
		}
	}

#line 16 "ana-1.md"
;
		
#line 58 "ana-1.md"

	
#line 36 "ana-n.md"

	Prefix state;
	init(state);

#line 786 "index-combined.md"

	Prefix state;
	init(state);

#line 59 "ana-1.md"
;
	char ch;
	while (std::cin.get(ch)) {
		
#line 795 "index-combined.md"

	push(state, ch);
	++collection[state];

#line 62 "ana-1.md"
;
	}

#line 17 "ana-1.md"
;
		
#line 82 "ana-1.md"

	for (const auto &e : collection) {
		
#line 804 "index-combined.md"

	unsigned i { 0 };
	for (; i < prefix_length; ++i) {
		write_byte(e.first[i]);
	}

#line 84 "ana-1.md"
;
		std::cout << "\t" <<
			e.second << "\n";
	}

#line 18 "ana-1.md"
;
	}

#line 234 "index-combined.md"

	
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

#line 235 "index-combined.md"
;
	int main(
		int argc, const char *argv[]
	) {
		
#line 70 "ana-n.md"

	if (argc == 2) {
		const char *arg { argv[1] };
		if (
			arg[0] == '-' &&
				arg[1] == 'n'
		) {
			
#line 85 "ana-n.md"

	prefix_length = std::stoi(arg + 2);
	if (prefix_length < 1) {
		std::cerr << "invalid length\n";
		prefix_length = 2;
	}

#line 77 "ana-n.md"
;
		}
	}

#line 820 "index-combined.md"

	if (argc == 2) {
		const char *arg { argv[1] };
		if (
			arg[0] == '-' &&
				arg[1] == 'n'
		) {
			
#line 835 "index-combined.md"

	prefix_length = std::stoi(arg + 2);
	if (prefix_length < 1) {
		std::cerr << "invalid length\n";
		prefix_length = 2;
	}

#line 827 "index-combined.md"
;
		}
	}

#line 239 "index-combined.md"
;
		
#line 281 "index-combined.md"

	
#line 36 "ana-n.md"

	Prefix state;
	init(state);

#line 786 "index-combined.md"

	Prefix state;
	init(state);

#line 282 "index-combined.md"
;
	char ch;
	while (std::cin.get(ch)) {
		
#line 795 "index-combined.md"

	push(state, ch);
	++collection[state];

#line 285 "index-combined.md"
;
	}

#line 240 "index-combined.md"
;
		
#line 305 "index-combined.md"

	for (const auto &e : collection) {
		
#line 804 "index-combined.md"

	unsigned i { 0 };
	for (; i < prefix_length; ++i) {
		write_byte(e.first[i]);
	}

#line 307 "index-combined.md"
;
		std::cout << "\t" <<
			e.second << "\n";
	}

#line 241 "index-combined.md"
;
	}
