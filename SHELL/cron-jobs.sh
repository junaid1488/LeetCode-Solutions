#!/bin/bash

(crontab -l 2>/dev/null; echo "0 2 * * * /home/user/backup.sh") | crontab -
