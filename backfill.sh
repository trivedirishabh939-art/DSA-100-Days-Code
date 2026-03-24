#!/bin/bash

# Jitne din ka gap fill karna hai, dates daal
# Format: YYYY-MM-DD

DATES=(
  "2026-03-24"
  "2026-03-28" "2026-03-29" "2026-03-30" "2026-03-31"
  "2026-04-01" "2026-04-02" "2026-04-03" "2026-04-04" "2026-04-05"
  "2026-04-06" "2026-04-07" "2026-04-08"
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