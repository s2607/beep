#!/bin/bash
#example script to sync mail and beep on new mail
mbsync -q liberty 
messages=$(ls /home/swiley/mail/liberty/Inbox/cur | wc -l )
if [ $messages -ne $(cat /home/swiley/.mnums) ]
then
	beep
fi
echo $messages >/home/swiley/.mnums
