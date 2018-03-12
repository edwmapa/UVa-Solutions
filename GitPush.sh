#Simple script. Adds all, commits, and push it.
echo "---Simple Commit---"
sleep .2
echo "Commit message: "
read -p '> ' MESSAGE

git add --all && git commit -m "$MESSAGE"
git push origin master || echo "Can't push to master, check manually"
