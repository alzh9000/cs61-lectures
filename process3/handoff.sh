#! /bin/sh

/bin/echo "HANDOFF FAIL" > handoff.txt

/bin/echo Handoff > handoff.txt & cat handoff.txt
