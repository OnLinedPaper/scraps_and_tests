#!/bin/bash
# get the name of process

read -p 'process name: ' p_name

if [ -z $p_name ]; then
  #default to hl2_linux, since i often use this to stop tf2
  p_name="hl2_linux"
fi

#find processes by this name
found_p=$(ps -e | fgrep "$p_name")
#how many did we find?
found_p_count=$(echo "$found_p" | wc -l)


if [ -z "$found_p" ]; then
  printf "no process by name $p_name found.\ndone\n"
  exit -1
elif [ $found_p_count -gt 1 ]; then
  read -p "$found_p_count processes matched name $p_name, halt the first? (y/N) " halt_p
  if [ -z $halt_p ] || [ $halt_p != "y" ]; then
    printf "user chose to abort.\ndone\n"
    exit -2
  fi
fi

#get pid
p_pid=$(echo "$found_p" | sed -n '1 p' | sed 's/[^0-9]*\([0-9]*\).*/\1/')

echo "halting $p_pid..."
kill -STOP $p_pid

read -p "(press enter to resume process)"
kill -CONT $p_pid

printf "done\n"
