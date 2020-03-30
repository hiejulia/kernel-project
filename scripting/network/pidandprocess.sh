#!/bin/bash

# This script displays the PIDs and count of matching processes.

PROC_NAME="${1}"
# pid
PIDS=$(pidof ${PROC_NAME})

COUNT=$(echo $PIDS | wc -w)

if [[ "${COUNT}" -gt 0 ]]
then
  echo "PROCESS NAME: ${PROC_NAME}"
  echo "COUNT: ${COUNT}"
  echo "PID(S): ${PIDS}"
else
  echo "No processes named ${PROC_NAME} found." >&2
  exit 1
fi



# Shows the open network ports on a system.
# Use -4 as an argument to limit to tcpv4 ports.

netstat -nutl ${1} | grep : | awk '{print $4}' | awk -F':' '{print $NF}'
