# Trivialer Generator

```
@Def(file: gen.cpp)
	@put(gen main prereqs);
	int main() {
		@put(gen loop)
	}
@End(file: gen.cpp)
```

```
@def(gen main prereqs)
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
		previous = new char[prev_length];
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
@Def(file: ana.cpp)
	@put(ana main prereqs);
	int main(
		int argc, const char *argv[]
	) {
		@put(parse args);
		char ch;
		@put(read input);
		@put(write table);
	}
@End(file: ana.cpp)
```

```
@def(ana main prereqs)
	#include <iostream>
@end(ana main prereqs)
```

```
@def(def collection)
	using Collection =
		std::map<char, int>;
@end(def collection)
```

```
@add(ana main prereqs)
	#include <map>
	@put(def collection);
	Collection collection;
@end(ana main prereqs)
```

```
@def(read input)
	while (std::cin.get(ch)) {
		@put(add to collection);
	}
@end(read input)
```

```
@def(add to collection)
	++collection[ch];
@end(add to collection)
```


```
@def(write table)
	for (const auto &e : collection) {
		@put(write key);
		std::cout << "\t" <<
			e.second << "\n";
	}
@end(write table)
```

```
@add(ana main prereqs)
	#include <cctype>
	void write_byte(char b) {
		if (isprint(b) && b != '\\') {
			std::cout << b;
		} else {
			static const char digits[] =
				"0123456789abcdef";
			std::cout << "\\x" <<
				digits[(b >> 4) & 0xf] <<
				digits[b & 0xf];
		}
	}
@end(ana main prereqs)
```

```
@def(write key)
	write_byte(e.first);
@end(write key)
```

```
@rep(write key)
@end(write key)
```

```
@rep(add to collection)
@end(add to collection)
```

```
@def(def collection prereqs)
	@put(key prereqs);
	class Key {
		private:
			char *_key;
		public:
			@put(key publics);
	};
@end(def collection prereqs)
```

```
@def(key prereqs)
	int key_length { 2 };
@end(key prereqs)
```

```
@add(key prereqs)
	#include <cstring>
@end(key prereqs)
```

```
@def(key publics)
	Key():
		_key { new char[key_length] }
	{
		memset(_key, 0, key_length);
	}
	~Key() {
		delete _key;
	}
@end(key publics)
```

```
@add(key publics)
	Key(const Key &other):
		_key { new char[key_length] }
	{
		memcpy(
			_key, other._key, key_length
		);
	}
@end(key publics)
```

```
@add(key publics)
	Key &operator=(const Key &other) {
		memcpy(
			_key, other._key, key_length
		);
		return *this;
	}
@end(key publics)
```

```
@add(key publics)
	bool operator==(
		const Key &other
	) const {
		return memcmp(
			_key, other._key, key_length
		) == 0;
	}
@end(key publics)
```

```
@add(key publics)
	bool operator<(
		const Key &other
	) const {
		return memcmp(
			_key, other._key, key_length
		) < 0;
	}
@end(key publics)
```

```
@rep(def collection)
	@put(def collection prereqs)
	using Collection =
		std::map<Key, int>;
	Key key;
@end(def collection)
```

```
@add(key publics)
	void push(char ch) {
		memmove(
			_key, _key + 1,
			key_length - 1
		);
		_key[key_length - 1] = ch;
	}
@end(key publics)
```

```
@rep(add to collection)
	key.push(ch);
	++collection[key];
@end(add to collection)
```

```
@add(key publics)
	char operator[](int i) const {
		return _key[i];
	}
@end(key publics)
```

```
@rep(write key)
	for (
		int i = 0; i < key_length; ++i
	) {
		write_byte(e.first[i]);
	}
@end(write key)
```

```
@def(parse args)
	if (argc == 2) {
		const char *arg { argv[1] };
		if (
			arg[0] == '-' && arg[1] == 'n'
		) {
			key_length = std::stoi(arg + 2);
			key.~Key();
			new (&key) Key { };
		}
	}
@end(parse args)
```
