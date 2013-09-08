all: keygen mario bolt juxtaposition ropasaurusrandom compound-problem matrix poor-argument smash-me old-school

.PHONY: keygen

clean: remove_keygen
	rm -f ./levels/*/*.out

keygen:
	gcc ./keygen/keygen.c -w -lcrypto -lssl -o ./keygen/level_up
	chown root ./keygen/level_up

remove_keygen:
	rm -f ./keygen/level_up

mario:
	gcc ./levels/mario/mario.c -o ./levels/mario/mario.out
	chown mario:mario ./levels/mario/mario.out
	chmod u+s ./levels/mario/mario.out
bolt:
	gcc ./levels/bolt/bolt.c -o ./levels/bolt/bolt.out
	chown bolt:bolt ./levels/bolt/bolt.out
	chmod u+s ./levels/bolt/bolt.out

juxtaposition:
	gcc ./levels/juxtaposition/juxtaposition.c -w -o ./levels/juxtaposition/juxtaposition.out
	chown juxtaposition:juxtaposition ./levels/juxtaposition/juxtaposition.out
	chmod u+s ./levels/juxtaposition/juxtaposition.out

ropasaurusrandom:
	gcc ./levels/ropasaurusrandom/ropasaurusrandom.c -w -m32 -fno-stack-protector -pie -o ./levels/ropasaurusrandom/ropasaurusrandom.out
	chown ropasaurusrandom:ropasaurusrandom ./levels/ropasaurusrandom/ropasaurusrandom.out
	chmod u+s ./levels/ropasaurusrandom/ropasaurusrandom.out

compound-problem:
	gcc ./levels/compound-problem/compound-problem.c -w -pie -o ./levels/compound-problem/compound-problem.out
	chown compound-problem:compound-problem ./levels/compound-problem/compound-problem.out
	chmod u+s ./levels/compound-problem/compound-problem.out

matrix:
	gcc ./levels/matrix/matrix.c -o ./levels/matrix/matrix.out
	chown matrix:matrix ./levels/matrix/matrix.out
	chmod u+s ./levels/matrix/matrix.out

poor-argument:
	gcc ./levels/poor-argument/poor-argument.c -fno-stack-protector -o ./levels/poor-argument/poor-argument.out
	chown poor-argument:poor-argument ./levels/poor-argument/poor-argument.out
	chmod u+s ./levels/poor-argument/poor-argument.out

smash-me:
	gcc ./levels/smash-me/smash-me.c -fno-stack-protector -o ./levels/smash-me/smash-me.out
	chown smash-me:smash-me ./levels/smash-me/smash-me.out
	chmod u+s ./levels/smash-me/smash-me.out

old-school:
	gcc ./levels/old-school/old-school.c -w -o ./levels/old-school/old-school.out
	chown old-school:old-school ./levels/old-school/old-school.out
	chmod u+s ./levels/old-school/old-school.out
