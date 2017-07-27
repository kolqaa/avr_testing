#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PARKING 1
#define GALLON 2

typedef struct		s_data
{
  int	miles;
  char	price;
  int 	car_age;
  float daily_cost;
  float	cost_per_gal;
  float	avg_mile_on_gal;
  float parking_fees;
  float	toils_per_day;
  char	toils;
}			t_data;

void take_cost(int cost_type, t_data *data)
{
  if (cost_type == GALLON)
    {
      printf("Enter cost per gallon of gasoline (Hint: 1 gallon = 3,78 liters): ");
      while ((scanf("%f",&data->cost_per_gal)) != 1)
	{
	  printf("Error on input try again or press 'Ctrl+Z' to quit (Notice: Enter only digits value)\nEnter new value: ");
	  while(getchar() != '\n' && getchar() != EOF)
	    ;
	}
    }
  else 
    {
      printf("Enter parking fees per day: ");
      while ((scanf("%f",&data->parking_fees)) != 1)
	{
	  printf("Error on input try again or press 'Ctrl+Z' to quit (Notice: Enter only digits value)\nEnter new value: ");
	  while(getchar() != '\n' && getchar() != EOF)
	    ;
	}
    }
}

void    take_miles(t_data *data)
{
  printf("Enter your total miles driven per day (hint 1 mile = 1,6 km): ");
  while ((scanf("%d", &data->miles)) != 1)
    {
      printf("Error on input try again or press 'Ctrl+Z' to quit (Notice: Enter only digits value)\nEnter new value: ");
      while(getchar() != '\n' && getchar() != EOF)
	;
    }
}

void	check_toils(t_data *data)
{
  printf("Your car more than 5 years? (Answer 'Y' or 'N' (Y-yes, N-no)): \n");
  while (data->toils != 'Y' && data->toils != 'N')
    {
      scanf(" %c", &data->toils);
      if (data->toils != 'Y' && data->toils != 'N')
	printf("Error on input try again or press 'Ctrl+Z'(Press only 'Y' or 'N' key (Y-yes, N-no)): ");
      if (data->toils == 'N')
	data->car_age = 1;
      else
	data->car_age = 0;
    }
  if (data->car_age)
    {
      printf("Total price of your car more than 45000 USD?(Answer 'Y' or 'N' (Y-yes, N-no)): ");
      while (data->price != 'Y' && data->price != 'N')
	{
	  scanf (" %c", &data->price);
	  if (data->price != 'Y' && data->price != 'N')
	    printf("Error on input try again or press 'Ctrl+Z' to quit (Press only 'Y' or 'N' key (Y-yes, N-no))\nEnter new value: ");
	  if (data->price == 'Y')
	    data->toils_per_day = 25000 / 365;
	  if (data->price == 'N')
	    break ;
	}
    }
}

void	take_ave_miles(t_data *data)
{
  printf("Enter average miles per gallon(Hint: 1 gallon = 3,78 liters): ");
  while ((scanf("%f", &data->avg_mile_on_gal)) != 1)
    {
      printf("Error on input try again or press 'Ctrl+Z' to quit (Notice: Enter only digits value)\nEnter new value: ");
      while (getchar() != '\n' && getchar() != EOF)
	;
    }
}
void	show_money_economy(t_data *data)
{
  float total = 0;
  total = data->miles / data->avg_mile_on_gal;
  total = (total * data->cost_per_gal) + data->parking_fees;
  total = total + data->toils_per_day;
  printf("If you choose public transport you can save %.2f per day\n", total);
}

int main(void)
{
  t_data *data;
 
  data = (t_data*)malloc(sizeof(*data));
  memset(data, 0, sizeof(*data));
  printf("Welcome to Saving Calculator it will help calculate your daily driving cost\n\n");
  take_miles(data);
  take_ave_miles(data);
  take_cost(GALLON, data);
  take_cost(PARKING, data);
  check_toils(data);
  show_money_economy(data);
  free(data);
  return (0);
}
