#!/usr/bin/env bash

set -e
set -o xtrace

# Merging several projects into one, keeping history but losing ability to track original projects (because of git filter-branch)

BRANCHES="master ${BRANCHES}"
git filter-branch --tree-filter 'mkdir -p sub-project-dir && git ls-files | egrep --invert-match sub-project-dir\|another-ignored-subdir | xargs -I{} rsync -R --remove-source-files {} sub-project-dir' -- ${BRANCHES}

