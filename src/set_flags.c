void set_bools(char *av, fs flags)
{
	if (ft_strcmp(R, av) == 0)
		flags.r = 1;
	if (ft_strcmp(L, av) == 0)
		flags.l = 1;
	if (ft_strcmp(A, av) == 0)
		flags.a = 1;
	if (ft_strcmp(LR, av) == 0)
		flags.lr = 1;
	if (ft_strcmp(T, av) == 0)
		flags.t = 1;
}
