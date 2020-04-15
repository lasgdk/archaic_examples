int faar, fmaaned, fdag;

main()
{
	printf("\n - Aldersberegner -\n");
	printf("Indtast dit fødselsår (1900-2004): ");
	scanf("%d", &faar);
	printf("\nIndtast din fødselsmåned (1-12): ");
	scanf("%d", &fmaaned);
	printf("\nOg så fødselsmånedsdagen (1-31): ");
	scanf("%d", &fdag);
	printf("\n\nDu blev født d.%d/%d år %d\n", fdag, fmaaned, faar);
}
