#!/usr/bin/env bash

set -e
set -o xtrace

BRANCHES=$(git branch -r | grep -v -- master | sed -e s-origin/--)
for b in ${BRANCHES}; do git branch --track ${b} origin/$b; done
git fetch --all

