pull:
	git pull origin master

commit:
	git add -A
	git commit -m "Automated commit"

push:
	git push -u origin master

all: pull commit push
