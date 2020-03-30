#!/bin/bash

# This script installs the apache web server on the given host.
# This script assumes the user running it has sudo privs on the remote host.

# A list of servers, one per line.
SERVER_LIST='/vagrant/servers'

# Options for the ssh command.
SSH_OPTIONS='-o ConnectTimeout=2'

sudo remote host 

usage() {
  # Display the usage and exit.
  echo "Usage: ${0} HOST [HOSTN...]" >&2
  exit 1
}

# Make sure the script is not being executed with superuser privileges.
if [[ "${UID}" -eq 0 ]]
then
  echo 'Do not execute this script as root.' >&2
  usage
fi

# If the user doesn't supply at least one argument, give them help.
if [[ "${#}" -lt 1 ]]
then
  usage
fi

# Expect the best, prepare for the worst.
# Prepare for the worst : exit status 
EXIT_STATUS='0'

# Loop through the SERVER_LIST
for SERVER in $(cat ${SERVER_LIST})
do
  if [[ "${VERBOSE}" = 'true' ]]
  then
    echo "${SERVER}"
  fi

  SSH_COMMAND="ssh ${SSH_OPTIONS} ${SERVER} ${SUDO} ${COMMAND}"
 
  # If it's a dry run, don't execute anything, just echo it.
  if [[ "${DRY_RUN}" = 'true' ]]
  then
    echo "DRY RUN: ${SSH_COMMAND}"
  else
    ${SSH_COMMAND}
    SSH_EXIT_STATUS="${?}"

    # Capture any non-zero exit status from the SSH_COMMAND and report to the user.
    if [[ "${SSH_EXIT_STATUS}" -ne 0 ]]
    then
      EXIT_STATUS=${SSH_EXIT_STATUS}
      echo "Execution on ${SERVER} failed." >&2
    fi 
  fi
done


# Loop through the provided servers.
for SERVER in "${@}"
do
  echo "Starting installation process on: ${SERVER}"

  # Ping the server to make sure it's up.
  # Ping server to make sure it is up 
  ping -c 1 ${SERVER} &> /dev/null

  if [[ "${?}" -ne 0 ]]
  then
    echo "${SERVER} down."
    EXIT_STATUS='1'
    continue
  fi

  # Install the httpd package
  ssh ${SERVER} sudo yum install -y httpd

  # Create an index.html file.
  ssh ${SERVER} 'echo "${HOSTNAME}" | sudo tee /var/www/html/index.html >/dev/null'

  # Start httpd
  ssh ${SERVER} sudo systemctl start httpd

  # Enable httpd
  ssh ${SERVER} sudo systemctl enable httpd

  # Test that the web server is accessible.
  curl http://${SERVER}

  if [[ "${?}" -ne 0 ]]
  then
    echo "Could not access the web server on ${SERVER}." >&2
    EXIT_STATUS='1'
    continue
  fi

  echo "Finished installation process on: ${SERVER}"
done

exit ${EXIT_STATUS}
