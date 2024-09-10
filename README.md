# My 42 Philosophers

## Description

Philosophers is a project from 42 School that simulates the classic "Dining Philosophers Problem." The goal is to manage the behavior of philosophers trying to eat, think, and avoid deadlock while sharing a limited number of forks.

## Installation

Clone the repository:
```
git clone https://github.com/your-account/philosophers.git
```
Compile the project:
```
make
```
## Usage

Run the program with the following arguments:
```
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```
<number_of_philosophers>: The number of philosophers. </br>
<time_to_die>: Time (in milliseconds) a philosopher can live without eating. </br>
<time_to_eat>: Time (in milliseconds) a philosopher spends eating. </br>
<time_to_sleep>: Time (in milliseconds) a philosopher spends sleeping. </br>
[number_of_times_each_philosopher_must_eat]: (Optional) Number of times each philosopher must eat before the simulation ends. </br>
