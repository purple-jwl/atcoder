{
    s = $1
	len = length(s)

    for (i = 0; i < len; i++) {
        s = substr(s, 2) substr(s, 0, 1)
        ss[i] = s
    }

    asort(ss)

	print ss[1]
    print ss[len]
}
