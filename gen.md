## Dokumente generieren

```
@Def(file: gen.cpp)
	@put(gen main prereqs);
	int main() {
		@put(read receipt);
		@put(gen loop);
	}
@End(file: gen.cpp)
```

```
@def(gen main prereqs)
	@put(static next prereqs);
	@put(next prereqs);
	inline bool next(char &ch) {
		bool ok { false };
		@put(next);
		return ok;
	}
@end(gen main prereqs)
```

```
@add(gen main prereqs)
	#include <iostream>
@end(gen main prereqs)
```

```
@def(gen loop)
	@mul(initialise);
	for (;;) {
		char ch;
		if (next(ch)) {
			std::cout << ch;
		} else {
			@mul(initialise);
		}
	}
@end(gen loop)
```

```
@def(next)
	ch = 'x';
	ok = true;
@end(next)
```

```
@def(initialise)
@end(initialise)
```

```
@def(next prereqs)
	int prev_length { 3 };
	char *previous { nullptr };
@end(next prereqs)
```

```
@rep(initialise)
	if (! previous) {
		previous =
			new char[prev_length];
	}
	previous[0] = 'a';
	previous[1] = 'b';
	previous[2] = 'c';
@end(initialise)
```

```
@rep(next)
	ch = previous[0];
	previous[0] = previous[1];
	previous[1] = previous[2];
	previous[2] = ch;
	ok = true;
@end(next)
```

```
@inc(key.md)
```

```
@add(gen main prereqs)
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
@end(gen main prereqs)
```

```
@def(static next prereqs)
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
	@Mul(key)
	using Collection = std::map<Key, List>;
	Collection collection;
@end(static next prereqs)
```

```
@def(read receipt)
	bool first { true };
	Key k;
	for (;;) {
		std::string key;
		std::cin >> key;
		if (! std::cin) { break; }
		int count;
		std::cin >> count;
		if (! std::cin) { break; }
		key = normalize(key);
		if (first) {
			key_length = key.size() - 1;
			first = false;
			init(k);
		}
		@put(add entry);
	}
@end(read receipt)
```

```
@def(add entry)
	for (unsigned i { 0 }; i + 1 < key.size(); ++i) {
		push(k, key[i]);
	}
	collection[k].add(key.back(), count);
@end(add entry)
```

```
@rep(next)
@end(next)
```

```
@rep(initialise)
@end(initialise)
```

```
@rep(next prereqs)
	Key prev;
	#include <iostream>
@end(next prereqs)
```

```
@rep(initialise)
	init(prev);
@end(initialise)
```

```
@rep(next)
	ch = collection[prev].next();
	ok = ch != '\0';
	push(prev, ch);
@end(next)
```
