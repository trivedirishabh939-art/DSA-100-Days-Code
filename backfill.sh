#!/bin/bash

# Jitne din ka gap fill karna hai, dates daal
# Format: YYYY-MM-DD

DATES=(
  "2026-02-10" "2026-02-11" "2026-02-12" "2026-02-14"
  "2026-02-15" 
)

for DATE in "${DATES[@]}"; do
  # Ek choti si change karo file mein
  echo "update $DATE" >> log.txt
  
  git add .
  
  # Yahan magic hai — date manually set karo
  GIT_AUTHOR_DATE="$DATE 12:00:00" \
  GIT_COMMITTER_DATE="$DATE 12:00:00" \
  git commit -m "daily update: $DATE"
  
done