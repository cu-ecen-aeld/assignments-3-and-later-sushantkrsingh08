#!/bin/bash

# Check if both arguments are provided
if [ "$#" -ne 2 ]; then
  echo "Error: Missing parameters. Usage: $0 <writefile> <writestr>"
  exit 1
fi


writefile=$1
writestr=$2

# Extract directory path from the writefile
writefile_dir=$(dirname "$writefile")

# Create the directory path if it doesn't exist
mkdir -p "$writefile_dir"

# Attempt to write the content to the file
echo "$writestr" > "$writefile"

# Check if the file was created successfully
if [ $? -ne 0 ]; then
  echo "Error: Could not write to file $writefile"
  exit 1
fi