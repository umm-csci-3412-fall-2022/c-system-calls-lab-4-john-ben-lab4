#!/bin/bash

inputDirectory="$1"

directoryCount=$(find "$inputDirectory" -type d | wc -l | xargs)
fileCount=$(find "$inputDirectory" -type f | wc -l | xargs)

echo "There were $directoryCount directories."
echo "There were $fileCount regular files."
