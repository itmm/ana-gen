## Dokumente generieren

```
@Def(file: gen.cpp)
	@put(main prereqs);
	int main() {
		@put(read receipt);
		@put(loop);
	}
@End(file: gen.cpp)
```

```
@def(main prereqs)
	@put(next prereqs);
	inline bool next(char &ch) {
		bool ok { false };
		@put(next);
		return ok;
	}
@end(main prereqs)
```

```
@add(main prereqs)
	#include <iostream>
@end(main prereqs)
```

```
@def(loop)
	@mul(initialise);
	for (;;) {
		char ch;
		if (next(ch)) {
			std::cout << ch;
		} else {
			@mul(initialise);
		}
	}
@end(loop)
```

```
@def(collection prereqs)
	#include <map>
@end(collection prereqs)
```

```
@inc(prefix.md)
```

```
@add(collection prereqs)
	@Mul(prefix)
@end(collection prereqs)
```

```
@def(list prereqs)
	struct Entry {
		const char ch;
		const int count;
		Entry (char c, int v):
			ch { c }, count { v }
		{ }
	};
@end(list prereqs)
```

```
@add(collection prereqs)
	@put(list prereqs);
	#include <vector>
	class List {
		private:
			std::vector<Entry> _entries;
			int _sum { 0 };
		public:
			@put(list publics);
	};

@end(collection prereqs)
```

```
@def(next prereqs)
	@put(collection prereqs);
	using Collection =
		std::map<Prefix, List>;
	Collection collection;
@end(next prereqs)
```

```
@def(list publics)
	void add(char ch, int count) {
		_entries.emplace_back(
			ch, count
		);
		_sum += count;
	}
@end(list publics)
```

```
@add(list publics)
	char next() const {
		if (_sum > 0) {
			@put(next ch);
		}
		return '\0';
	}
@end(list publics)
```

```
@add(list prereqs)
	#include <random>
	std::mt19937 _rng {
		std::random_device{ }()
	};

@end(list prereqs)
```

```
@def(next ch)
	auto dist {
		std::uniform_int_distribution<
			std::mt19937::result_type
		>(0, _sum - 1) };
	int result = dist(_rng);
@end(next ch)
```

```
@add(next ch)
	for (const auto &i : _entries) {
		if (result < i.count) {
			return i.ch;
		}
		result -= i.count;
	}
@end(next ch)
```

```
@add(next prereqs)
	Prefix state;
@end(next prereqs)
```

```
@def(initialise)
	init(state);
@end(initialise)
```

```
@def(next)
	ch = collection[state].next();
	push(state, ch);
	ok = ch != '\0';
@end(next)
```

```
@add(main prereqs)
	@put(normalize prereqs);
	std::string normalize(
		const std::string &key
	) {
		std::string result;
		for (unsigned i { 0 };
			i < key.size(); ++i
		) {
			if (key[i] == '%') {
				@put(unescape);
				i += 2;
			} else {
				result += key[i];
			}
		}
		return result;
	}
@end(main prereqs)
```

```
@def(normalize prereqs)
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
@end(normalize prereqs)
```

```
@def(unescape)
	result += static_cast<char>(
		(hex_digit(key[i + 1]) << 4) +
			hex_digit(key[i + 2])
	);
@end(unescape)
```

```
@def(read receipt)
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
		@put(setup length);
		@put(add entry);
	}
@end(read receipt)
```

```
@def(setup length)
	if (first) {
		prefix_length = key.size() - 1;
		first = false;
		init(k);
	}
@end(setup length)
```

```
@def(add entry)
	for (unsigned i { 0 };
		i + 1 < key.size(); ++i
	) {
		push(k, key[i]);
	}
	collection[k].add(
		key.back(), count
	);
@end(add entry)
```

