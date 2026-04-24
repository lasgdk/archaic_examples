# Forslag: opdeling af `archaic_examples`

Dette repository er en blanding af mange teknologier, tidsperioder og risikoprofiler.

## Hvorfor opdele?

- Top-level indeholder et meget bredt miks af sprog/domæner (`c`, `java`, `python`, `perl`, `asm`, `shellscripts`, `exploits`, `misc`).
- Root README beskriver, at meget kode er gammel (ca. 1995-2005) og kan være skadelig ved forkert brug.
- Der ligger direkte exploit-/offensiv kode samt bevidst sårbar demo-kode i samme repo som almindelige læringseksempler.

## Anbefalet målarkitektur

1. `archaic-examples-safe`  
   Klassiske læringseksempler uden aktivt skadelig adfærd.
2. `archaic-examples-security-lab`  
   Sårbarheds- og exploit-demokode (isoleres tydeligt med advarsler).
3. `archaic-examples-archive`  
   Historisk, uændret reference (read-only/arkiv).

Alternativt: behold ét mono-repo, men opdel i tydelige domæner med stærke guardrails:

- `safe/`
- `security-lab/`
- `archive/`

## Praktisk migrationsplan

1. Frys nuværende repo (tag fx `legacy-snapshot-YYYYMMDD`).
2. Definér flytteregler pr. mappe (safe vs. security-lab vs. archive).
3. Flyt i batches og bevar historik (`git filter-repo` eller `git subtree split`).
4. Tilføj tydelige README-advarsler og kørselspolitikker i hvert nyt repo.
5. Aktivér branch protection + CODEOWNERS pr. repo.
6. Brug CI med minimum: lint + statisk scan + hemmeligheds-scan.

## Minimum hvis I ikke splitter nu

- Kræv kørsel i container/VM for alt under `exploits/` og risikable `misc/`-dele.
- Tilføj pre-commit/CI, der blokerer nye hardcoded credentials og farlige shell-kald.
- Indfør navngivningskonventioner (`demo-vuln-*`, `exploit-*`, `safe-*`) for tydelighed.

## Kort anbefaling

Ja: opdeling er fornuftig. Den bedste balance er typisk 2-3 repos efter risikoprofil og formål, så læringskode, offensiv lab-kode og historisk arkiv ikke blandes i samme samarbejdsflow.
