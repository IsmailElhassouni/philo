int data_in(t_data *data, int ac , char **av)
{
    data->nb_full_p = 0;
   data->keep_iterating = 1;
   data->nb_philos = ft_atoi(argv[1]);
}

int philosophers(int ac, char **av)
{
    t_data data;

    if(data_in(&data, ac, argv) != 0)
        return 0;
}