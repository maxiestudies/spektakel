# this script creates a textfile with the right format to load the arrays in the patch

filename=loadarrs.txt

if test -f "$oldfile"; then
	rm $filename
fi

touch $filename
# pwd
fullpath=`pwd`
parent=${fullpath##*/}
counter=1
for i in *.wav;
	do name=`echo "$parent/${i%.*}.wav arr${counter}L arr${counter}R;"`;
	echo $name >> $filename;
	counter=$((counter+1))
done
