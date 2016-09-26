echo "Removing old TAGS"
rm -f TAGS
echo "Creating new TAGS for working & subdirectories"
find . -name "*.[ch]pp" -print | xargs etags -a
