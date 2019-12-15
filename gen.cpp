
#line 4 "index.md"

	
#line 13 "index.md"

	
#line 56 "index.md"

	int prev_length { 3 };
	char *previous { nullptr };

#line 14 "index.md"
;
	inline bool next(char &ch) {
		bool ok { false };
		
#line 74 "index.md"

	ch = previous[0];
	previous[0] = previous[1];
	previous[1] = previous[2];
	previous[2] = ch;
	ok = true;

#line 17 "index.md"
;
		return ok;
	}

#line 24 "index.md"

	#include <iostream>

#line 5 "index.md"
;
	int main() {
		
#line 30 "index.md"

	
#line 63 "index.md"

	if (! previous) {
		previous = new char[prev_length];
	}
	previous[0] = 'a';
	previous[1] = 'b';
	previous[2] = 'c';

#line 31 "index.md"
;
	for (;;) {
		char ch;
		if (next(ch)) {
			std::cout << ch;
		} else {
			
#line 63 "index.md"

	if (! previous) {
		previous = new char[prev_length];
	}
	previous[0] = 'a';
	previous[1] = 'b';
	previous[2] = 'c';

#line 37 "index.md"
;
		}
	}

#line 7 "index.md"

	}
