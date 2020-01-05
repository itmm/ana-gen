
#line 11 "ana-1.md"

	
#line 42 "ana-1.md"

	#include <map>
	
#line 27 "ana-n.md"

	
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

#line 28 "ana-n.md"
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

	static const char digits[] =
		"0123456789abcdef";
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

#line 16 "ana-1.md"
;
		
#line 58 "ana-1.md"

	
#line 36 "ana-n.md"

	Prefix state;
	init(state);

#line 59 "ana-1.md"
;
	char ch;
	while (std::cin.get(ch)) {
		
#line 45 "ana-n.md"

	push(state, ch);
	++collection[state];

#line 62 "ana-1.md"
;
	}

#line 17 "ana-1.md"
;
		
#line 82 "ana-1.md"

	for (const auto &e : collection) {
		
#line 54 "ana-n.md"

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
