#!/usr/bin/env bash

set -e
set -o xtrace

git merge subproject-history-branch --allow-unrelated-histories --no-edit
git remote rm subtree_remote
git branch -d subproject-history-branch


