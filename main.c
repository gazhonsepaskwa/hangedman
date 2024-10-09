#include <stdio.h>

char *ascii_tab[] = {
    " +--+\n"
    " |  |\n"
    "    |\n"
    "    |\n"
    "    |\n"
    "    |\n"
    "=====\n",

    " +--+\n"
    " |  |\n"
    " 0  |\n"
    "    |\n"
    "    |\n"
    "    |\n"
    "=====\n",

    " +--+\n"
    " |  |\n"
    " 0  |\n"
    " |  |\n"
    "    |\n"
    "    |\n"
    "=====\n",

    " +--+\n"
    " |  |\n"
    " 0  |\n"
    "/|  |\n"
    "    |\n"
    "    |\n"
    "=====\n",

    " +--+\n"
    " |  |\n"
    " 0  |\n"
    "/|\\ |\n"
    "    |\n"
    "    |\n"
    "=====\n",

    " +--+\n"
    " |  |\n"
    " 0  |\n"
    "/|\\ |\n"
    "/   |\n"
    "    |\n"
    "=====\n",

    " +--+\n"
    " |  |\n"
    " 0  |\n"
    "/|\\ |\n"
    "/ \\ |\n"
    "    |\n"
    "=====\n"
};

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int	is_ph_complete(char *ph)
{
	int i;

	i = 0;
	while (ph[i])
	{
		if (ph[i] == '_')
			return (0);
		i++;
	}
	return (1);
}

int	check_ph(char c, char *src, char *ph, char *alpha_used)
{
	int i;
	int	len;
	int true;
	int	j;

	i = 0;
	j = 0;
	len = strlen(src);
	while (alpha_used[j])
	{
		if (alpha_used[j] < 97 || alpha_used[j > 122])
		{
			alpha_used[j] = c;
			break;
		}
		else if (alpha_used[j] == c)
			return (0);
	}
	while (i < len)
	{
		if (src[i] == c)
		{
			ph[i] = c;
			true = 1;
			i++;
		}
		else
			i++;
	}
	if (true == 1)
		return (1);
	else
		return (0);
}

char	*get_ph(char *word)
{
	//strcpy(ph, word);
	int	len = strlen(word);
	char *ph;
	int	i = 0;

	ph = (char *)malloc(sizeof(char) * len + 1);
	if (!ph)
		return (NULL);
	while (i < len)
		ph[i++] = '_';
	ph[i] = '\0';
	return (ph); // last error
}

void	getdrawing(int i)
{
	putstr(&ascii_tab[i][0]);
}

void	to_lower(char *c)
{
	if (c[0] >= 65 && c[0] <= 90)
		c[0] += 32;
		return;
}
int is_alpha(char c){
	if ((c >= 65 && c <= 90) || (c >= 97 && c<= 122))
		return 1;
	else
		return 0;
}

int scanValid(char *scan)
{
	if (!(strlen(scan) == 1 ) && is_alpha(scan[0]))
		return 0;
	else
		return 1;
}


int	main(int ac, char **av)
{
	(void)ac;
	int	hangCount = 0;
	char lettre[50000];
	char *ph = get_ph(av[1]);
	char alpha_used[26] = "00000000000000000000000000";

	if (ac == 2)
	{
		while (is_ph_complete(ph) == 0 && hangCount < 6)
		{
			getdrawing(hangCount);
			putstr("\n");
			putstr(ph);
			putstr("\n");
			putstr("\n");
			putstr("Enter a letter : ");
			scanf("%s", lettre);
			if (scanValid(lettre))
			{
				to_lower(lettre);
				if (check_ph(lettre[0], av[1], ph, alpha_used) == 0)
					hangCount++;
			}else {
				putstr("Invalid answer! \n");
			}
		}
		getdrawing(hangCount);
		if (hangCount < 6)
		{	
			putstr(av[1]);
			putstr("\n");
			putstr("Well done!\n");
		} else {
			putstr("Hanged\n");
		}
	}

	
}

