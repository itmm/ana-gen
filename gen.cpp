
#line 335 "index.md"

	
#line 344 "index.md"

	
#line 387 "index.md"

	int prev_length { 3 };
	char *previous { nullptr };

#line 345 "index.md"
;
	inline bool next(char &ch) {
		bool ok { false };
		
#line 406 "index.md"

	ch = previous[0];
	previous[0] = previous[1];
	previous[1] = previous[2];
	previous[2] = ch;
	ok = true;

#line 348 "index.md"
;
		return ok;
	}

#line 355 "index.md"

	#include <iostream>

#line 336 "index.md"
;
	int main() {
		
#line 361 "index.md"

	
#line 394 "index.md"

	if (! previous) {
		previous =
			new char[prev_length];
	}
	previous[0] = 'a';
	previous[1] = 'b';
	previous[2] = 'c';

#line 362 "index.md"
;
	for (;;) {
		char ch;
		if (next(ch)) {
			std::cout << ch;
		} else {
			
#line 394 "index.md"

	if (! previous) {
		previous =
			new char[prev_length];
	}
	previous[0] = 'a';
	previous[1] = 'b';
	previous[2] = 'c';

#line 368 "index.md"
;
		}
	}

#line 338 "index.md"

	}
