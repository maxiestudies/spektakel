# this script creates a textfile with the right format to load the arrays in the patch

filename=loadarrs.txt
cd ../textfiles

if test -f $filename; then
	rm $filename
fi

touch $filename
# pwd
cd ../audio/finished
counter=1
for i in *.wav;
	do name=`echo ${i}`;
	cname=`echo "./audio/finished/$name ${name:0:7}-$counter;"`;
	echo $cname >> ../../textfiles/$filename;
	counter=$((counter+1))
	if [ $counter -gt 10 ]
	then
		counter=1
	fi
done

cd ../../textfiles
cat loadnumarrs.txt >> $filename 
