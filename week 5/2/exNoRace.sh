if test ! -f Nums
then
	echo 0 > Nums
fi

if ln Nums Nums.lock
then
	for i in `seq 1 100`:
	do
		n=`tail -1 Nums`
		expr $n + 1 >>Nums
	done

	rm Nums.lock
fi