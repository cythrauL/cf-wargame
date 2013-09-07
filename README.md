cf-wargame
==========

Ethical hacking, vulnerability research and exploit understanding environment.

Jeopardy 'Capture The Flag' format:
  When a challange solved, the user is given a key (tied to their username) they
  can submit to a score-bot for points!

The aim of this project is to teach vulnerability research and exploit
understanding in a fun, safe environment.

_“To know your Enemy, you must become your Enemy.”_
― Sun Tzu, The Art of War

The best security mitigations, patches and secure code come from security
professionals with a deep understanding of security flaws and the way exploits
work; this environment is designed to give students that understanding.

Created by
<pre>
  _   _                                              
 | \ | |                                             
 |  \| | _____   _____ _ __ _ __ ___   ___  _ __ ___ 
 | . ` |/ _ \ \ / / _ \ '__| '_ ` _ \ / _ \| '__/ _ \
 | |\  |  __/\ V /  __/ |  | | | | | | (_) | | |  __/
 \_| \_/\___| \_/ \___|_|  |_| |_| |_|\___/|_|  \___|
</pre>                                                     
With a special thanks to
<pre>
__   ____   _______ 
\ \ / /\ \ / /  _  \
 \ V /  \ V /| | | |
 /   \  /   \| | | |
/ /^\ \/ /^\ \ |/ / 
\/   \/\/   \/___/  
                      
</pre>                      
And the rest of the team, who taught me much of what I know.

Installation Instructions
-------------------------

Currently a work in progress...

Done -> Make bad shell script to call all the makefiles...
        (Should almost certainly just be one makefile...
        but this is easier for me at the moment)

WIP ->  At the moment, a user has to manually change the secret key material in
        the keygenerator, which will be visible to users, so they can cheat if
        they are lame... Should be more automatic, should be more secure.

WIP ->  Make the makefiles(?) set up the user-accounts and chown and chmod u+s
        the binaries.

WIP ->  This one is easy... make the shell script set up the binaries at the top
        level directory (/levels/) and drop the keygen binary at /level_up.

NEED TO START ->  A jeopardy style website that understands the keygen algorithm
                  and has a leaderboard :)
