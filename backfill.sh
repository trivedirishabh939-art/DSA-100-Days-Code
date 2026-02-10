#!/bin/bash

DATES=(
  "2026-02-10" "2026-02-11" "2026-02-12" "2026-02-13"
  "2026-02-14" "2026-02-15"
)

for DATE in "${DATES[@]}"; do
  echo "update $DATE" >> log.txt
  git add .
  GIT_AUTHOR_DATE="${DATE}T12:00:00" GIT_COMMITTER_DATE="${DATE}T12:00:00" git commit -m "daily update: $DATE"
done

git push origin main --force
