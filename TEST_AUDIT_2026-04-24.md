# Test-audit (2026-04-24)

Dette dokument opsummerer en bred teknisk smoke-test af repository'et.

## Kørte checks

- `python3 -m py_compile` på alle `python/**/*.py`
- `perl -c` på alle `perl/**/*.pl`
- `bash -n` på alle `**/*.sh`
- `gcc -fsyntax-only` på alle `c/**/*.c` og `misc/**/*.c`
- `javac -encoding ISO-8859-1` på alle `java/**/*.java`
- `make` i mapper med `Makefile`

## Resultat (overblik)

- Python (python3): **3 pass / 15 fail**
- Perl: **43 pass / 6 fail**
- Shell: **79 pass / 4 fail**
- C (syntaks): **115 pass / 22 fail**
- Java: **12 pass / 17 fail**
- Makefiles: **0/3 byggede succesfuldt**

## Hvad virker

- En stor del af C-eksemplerne kan stadig syntaks-kompileres i moderne GCC.
- Størstedelen af Perl-scripts er syntaktisk valide.
- De fleste shellscripts er parsebare i `bash`.

## Hvad virker ikke (udvalgte konkrete fejl)

1. **Python er primært Python 2-kode**
   - Eksempler fejler i Python 3 pga. `print`-syntaks uden parenteser.
   - Nogle filer har tabs/spaces-indenteringsfejl.

2. **Perl har både kodefejl og manglende moduler**
   - `perl/examples/0b_getopt.pl`: `%args` bruges uden deklaration.
   - `perl/slowloris.pl`, `perl/slowloris_apache_dos.pl`, `perl/dgs.pl`, `perl/degulesider.pl`: mangler CPAN-moduler i miljøet.
   - `perl/ubuntu-pw-extract.pl`: filindhold ligner HTML og er ikke gyldigt Perl.

3. **Shell scripts med syntaksproblemer eller ikke-bash konstruktioner**
   - `shellscripts/local_mailbomb.sh`
   - `exploits/simple_grep_dos_unix.sh`
   - `exploits/beautiful_forkbomb.sh`
   - `sms_gateway/smsgate/smsgate.sh`

4. **C-filer der kræver gamle/OS-specifikke headers eller har rå syntaksfejl**
   - Manglende headers: `gcrypt.h`, `machine/sysarch.h`, `asm/io.h`, `machine/param.h`, `gtk/gtk.h`, m.fl.
   - Rå syntaks/datafejl i enkelte filer, fx `c/80char_linebreak.c`, `c/rccar/rccar_own.c`, `c/readconffile/readconffile.c`.

5. **Java indeholder mindst én reel kodefejl**
   - `java/mm4/threads/DynamicSystem.java` har ufuldstændig array-initialisering.
   - Flere filer kræver legacy tegnsætning/encoding.

6. **Makefiles fejler**
   - `misc/Designing_BSD_Rootkits_own/Makefile`: `missing separator` (typisk spaces i stedet for TAB).
   - `c/sorting_algorithms`: afhænger af `libc.h`, som ikke findes i moderne miljø.
   - `misc/rsaplay`: linker med `-lm` i forkert rækkefølge (symboler `pow`/`sqrt` ikke resolved).

## Foreslåede rettelser (prioriteret)

1. **Skab reproducerbart test-setup pr. sprog**
   - Tilføj en lille `scripts/test_smoke.sh`, der kører alle checks deterministisk og returnerer samlet exit-kode.

2. **Fastlæg legacy-scope**
   - Marker mapper der er historiske/OS-specifikke (fx FreeBSD kernel/parallelport), så de ikke fejler i standard CI.
   - Løsning: mappe-specifik allowlist/skiplist i smoke-test.

3. **Python-modernisering (hurtige gevinster)**
   - Kør `2to3` på `python/examples/*.py`.
   - Ret tabs/spaces i S60-filer.

4. **Perl-stabilisering**
   - Deklarér `%args` i `perl/examples/0b_getopt.pl`.
   - Flyt afhængighedstunge scripts bag feature-flag eller dokumentér CPAN-krav i en `perl/README.md`.

5. **C-portabilitet**
   - Pak hardware-/OS-tunge filer ind i `#ifdef` guards.
   - Ret rene syntaksfejl i de nævnte filer først (lav risiko, høj signalværdi).

6. **Java-fix**
   - Ret `DynamicSystem.java` (array-initialisering).
   - Kompilér med eksplicit encoding i build-script.

7. **Makefiles**
   - `misc/rsaplay`: flyt `-lm` til sidst i link-linjen.
   - `misc/Designing_BSD_Rootkits_own`: ret TAB-indryk.
   - `c/sorting_algorithms`: erstat `libc.h` med standard headers.

