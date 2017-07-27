/*BMI CALC*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_data
{
  int kg_weight;
  float meters_height;
  float bmi;
}		t_data;

void	clear_input_buff(void)
{
  while (getchar() != '\n')
    ;
}

void	take_height_weight(t_data *data)
{
  printf("Enter your weight (in kg): ");
  while ((scanf("%d", &data->kg_weight)) != 1)
    {
      printf("Enter weight only in digit:");
      clear_input_buff();
    }
  printf("Enter your height in format x.xx (ex: 1.75):");
  while ((scanf("%f", &data->meters_height)) != 1)
    {
      printf("Enter height in x.xx format(ex: 1.75) which consist only digit: ");
      clear_input_buff();
    }
}

void show_your_bmi(t_data *data)
{
  data->bmi =  data->kg_weight / (data->meters_height * data->meters_height);
  if (data->bmi < 18.5)
    printf("Yours: %1.f - Underweight\n", data->bmi);
  else if (data->bmi > 18.5 && data->bmi < 24.9)
    printf("Yours: %1.f - Normal\n", data->bmi);
  else if (data->bmi > 25 && data->bmi < 29.9)
    printf("Yours: %1.f - Overweight\n", data->bmi);
  else if (data->bmi > 30)
    printf("Yours: %1.f - Obese\n", data->bmi);
}
void	show_result(t_data *data)
{
  printf("BMI VALUES\n");
  printf("Underweight: less than 18.5\n");
  printf("Normal: between 18.5 and 24.9\n");
  printf("Overweight: between 25 and 29.9\n");
  printf("Obese: 30 or greater\n");
  printf("-------------------------------\n");
  show_your_bmi(data);
}

int main(void)
{
  t_data *data;

  data = (t_data *)malloc(sizeof(*data));
  memset(data, 0, sizeof(*data));
  take_height_weight(data);
  show_result(data);
  free(data);
  return (0);
}
