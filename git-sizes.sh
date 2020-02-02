#!/bin/bash
git log "--format=format:%H;%at" > ../git.log
while read -r line; do
	items=(${line//;/ })
	commit=${items[0]}
	date=${items[1]}
	git checkout $commit >/dev/null 2>/dev/null
	count=`find * -type f -exec cat \{\} \; | wc -l`
	echo "$commit;$date;$count"
done < ../git.log
