cf-wargame
==========

Ethical hacking, vulnerability research and exploit understanding environment.

Jeopardy 'Capture The Flag' format:
  When a challange is solved, the user is given a key (tied to their username)
  which they can submit to a score-bot for points!

The aim of this project is to teach vulnerability research skills and enable
understanding exploitation in a fun, safe environment.

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

  Have a relatively up-to-date GCC, and libssl-dev (apt-get, etc).

  Run the run_me_as_root.sh shellscript in the root directory!

  What it does:
  <pre>
  Creates the usernames required
  Runs a makefile which:
    Compiles the files
    chown and chmods them
  Moves the levels and the keygen to the root dir
  </pre>

TO DO
-----

Make the code more consistent (retab, similar macros, etc)
Write comments
