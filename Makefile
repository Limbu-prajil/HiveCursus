commit:
	git add .
	git commit -m "Automated commit"

pull:
	git pull origin master

push:
	git push -u origin master

all: pull commit push
