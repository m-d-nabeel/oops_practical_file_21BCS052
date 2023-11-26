#!/bin/bash

commit_message="$1"

# Add all changes
git add .

# Commit with the provided message
git commit -m "$commit_message"

# Push to the remote repository
git push
