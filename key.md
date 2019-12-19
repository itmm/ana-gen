# Keys

```
@Def(key)
	using Key = std::string;
	unsigned key_length { 2 };
	Key key;
@End(key)
```

```
@Add(key)
	void init(Key &k) {
		k = std::string { };
		for (unsigned i { 0 }; i < key_length; ++i) {
			k += '\0';
		}
	}
@End(key)
```

```
@Add(key)
	void push(Key &key, char ch) {
		if (key.size() > 0) {
			for (unsigned i = 1; i < key.size(); ++i) {
				key[i - 1] = key[i];
			}
			key[key.size() - 1] = ch;
		}
	}
@End(key)
```

