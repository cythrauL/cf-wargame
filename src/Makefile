all: keygen mario bolt juxtaposition ropasaurusrandom compound-problem matrix poor-argument smash-me old-school

.PHONY: keygen

clean: remove_keygen
	rm ./levels/*/*.out

keygen:
	gcc ./keygen/keygen.c -lcrypto -lssl -o ./keygen/level_up

remove_keygen:
	rm ./keygen/level_up

mario:
	gcc ./levels/mario/mario.c -o ./levels/mario/mario.out

bolt:
	gcc ./levels/bolt/bolt.c -o ./levels/bolt/bolt.out

juxtaposition:
	gcc ./levels/juxtaposition/juxtaposition.c -w -o ./levels/juxtaposition/juxtaposition.out

ropasaurusrandom:
	gcc ./levels/ropasaurusrandom/ropasaurusrandom.c -PIE -o ./levels/ropasaursrandom/ropasaurusrandom.out

compound-problem:
	gcc ./levels/compound-problem/compound-problem.c -w -PIE -o ./levels/compound-problem/compound-problem.out

matrix:
	gcc ./levels/matrix/matrix.c -o ./levels/matrix/matrix.out

poor-argument:
	gcc ./levels/poor-argument/poor-argument.c -fno-stack-protector -o ./levels/poor-argument/poor-argument.out

smash-me:
	gcc ./levels/smash-me/smash-me.c -fno-stack-protector -o ./levels/smash-me/smash-me.out

old-school:
	gcc ./levels/old-school/old-school.c -o ./levels/old-school/old-school.out
