# My 42 Philosophers
## Description
Philosophers is a program that simulates the classic "Dining Philosophers Problem," a well-known thought experiment in computer science and concurrency. The problem involves a group of philosophers sitting at a table, alternating between eating, thinking, and sleeping, with a limited number of forks available for eating.

To eat, each philosopher needs two forks—one from their left and one from their right. Since the number of forks is limited and shared, the program must carefully manage access to these resources. The challenge lies in coordinating their actions to prevent two major issues:

  - Deadlock: A situation where every philosopher is waiting for a fork, and no one can proceed.
  - Starvation: A scenario where a philosopher is unable to eat because others are continuously taking priority.

The program models philosophers as concurrent threads or processes, with mechanisms in place to control access to the forks. This involves using synchronization techniques, like mutexes or semaphores, to ensure that forks are shared efficiently and fairly among the philosophers. Timing parameters for actions like eating, thinking, and sleeping add another layer of complexity, requiring careful handling of real-time events.

The result is a realistic simulation where philosophers can alternate between their activities seamlessly, with no interruptions or unfair treatment. It showcases the practical application of concurrency, resource sharing, and problem-solving in systems programming.
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
