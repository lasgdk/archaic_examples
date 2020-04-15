#!/bin/sh

#sk0rping af LaSG, spam@lasg.dk
#version 1.0 (virker, men kan meget lidt) 01-01-2005
#udgivet under GPL
#
#Dette simple script pinger mod en raekke servere
#Hvis serveren er oppe, sker der intet
#Hvis serveren er nede (ikke svarer paa ping), bliver admin kontaktet
#Scriptet boer koeres automatisk via crontabben, f.eks. hver halve time 


#Hvordan skal det forbedres/udvides:
#Hvis der ikke er forbindelse, skal scriptet laegge et nyt script i crontab, 
# der tjekker oftere. Naar dette script faar forbindelse, skal det laegge det gamle tilbage.


#Listen her er de maskiner der skal testes. Formatet er <maskinens adresse>:<admins kontaktadresse>
#F.eks.:
#lasg.dk:larssommer@hotmail.com
PINGLISTE="
217.157.189.181:28625027@gsm1800.telia.dk
217.157.189.181:jollymonk@gmail.com
"

#Listen her er en raekke adresser der foerst testes mod, 
# for at kontrollere at maskinen der testes fra har netforbindelse og kan pinge ud. 
#Det er ligemeget hvor mange adresser du har her, men jo flere, 
# jo bedre sikkerhed for at der doemmes korrekt.
#Formatet er <adresse>
EGENKONTROLLISTE="
212.242.40.3
google.dk
204.152.189.116
199.232.76.164
80.209.192.6
"

#Foest kontrollerer vi at vi kan pinge
if [ -x ping ]; then
	echo "Fejl, scriptet kan ikke finde og bruge programmet ping!"
	exit 1
fi

#Og om vi kan bruge mail
if [ -x mail ]; then
	echo "Fejl, scriptet kan ikke finde og bruge programmet mail!"
	exit 1
fi

#Her kontrollerer vi at vi har netforbindelse.
#Hvis vi bare kan pinge mindst en af adresserne i EGENKONTROLLISTE, 
# regner vi med vi har netforbindelse
OPPETOTAL=0
for EGENAKTUEL in $EGENKONTROLLISTE; do
	OPPE=`ping -c 1 $EGENAKTUEL | grep -c "1 packets received"`
	OPPETOTAL=$((OPPETOTAL + OPPE))
done
if [ "$OPPE" = "0" ]; then
	echo "Det ser ud som om du ikke selv har netforbindelse"
	exit 1
fi

#Her laver vi selve de ping der er vigtige, 
# og hvis vi ikke faar svar, sender vi en mail til admin
for AKTUEL in $PINGLISTE; do
	VAERT=`echo $AKTUEL | sed s/:[a-zA-Z0-9@.]*//`
	KONTAKT=`echo $AKTUEL | sed s/:[a-zA-Z0-9@.]*://`
	OPPE=`ping -c 1 $VAERT | grep -c "1 packets received"`

if [ "$OPPE" = "0" ]; then
	TIDSPUNKT=`date +%Y%m%d-%H%M`
	mail -s "Fra sk0rping, jeg kan ikke pinge $VAERT ! tid: $TIDSPUNKT" $KONTAKT < .	
fi

done

