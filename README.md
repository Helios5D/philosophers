# My 42 Philosophers
## Description

Philosophers is a project from 42 School that simulates the classic "Dining Philosophers Problem." The challenge is to manage the behavior of philosophers who alternate between eating and thinking while sharing a limited number of forks, all while avoiding deadlock and starvation.
## Installation

Clone the repository:
```
git clone https://github.com/your-account/philosophers.git
```
Compile the project:
```
make
```
This will create the executable philo.
## Usage

Run the program with the following arguments:
```
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

  - <number_of_philosophers>: The number of philosophers.
  - <time_to_die>: Time (in milliseconds) a philosopher can live without eating.
  - <time_to_eat>: Time (in milliseconds) a philosopher spends eating.
  - <time_to_sleep>: Time (in milliseconds) a philosopher spends sleeping.
  - [number_of_times_each_philosopher_must_eat] (optional): The number of times each philosopher must eat before the simulation ends.

## Example

Run the program with 5 philosophers, 800ms to die, 200ms to eat, 200ms to sleep, and no eating limit:
```
./philo 5 800 200 200
```
Run the program with 5 philosophers, 800ms to die, 200ms to eat, 200ms to sleep, and an eating limit of 7 times per philosopher:
```
./philo 5 800 200 200 7
```
In both cases, the program will simulate the behavior of the philosophers while adhering to the specified constraints.
