int faar, fmaaned, fdag;

main()
{
	printf("\n - Aldersberegner -\n");
	printf("Indtast dit f�dsels�r (1900-2004): ");
	scanf("%d", &faar);
	printf("\nIndtast din f�dselsm�ned (1-12): ");
	scanf("%d", &fmaaned);
	printf("\nOg s� f�dselsm�nedsdagen (1-31): ");
	scanf("%d", &fdag);
	printf("\n\nDu blev f�dt d.%d/%d �r %d\n", fdag, fmaaned, faar);
}
