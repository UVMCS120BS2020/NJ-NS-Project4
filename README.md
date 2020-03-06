# NJ-NS-Project4
Project 4 Nolan Jimmo Noah Stracqualursi

# Analysis

### Nolan's function
Nolan's function uses srand and generates two random numbers seeded by the current time. These numbers then are
used to swap indexes of the vector.

### Noah's function
Noah's function uses the chrono library to calculate the timestamp to the nanosecond and generates 'random'
numbers through multiple time stamps and constant multiplication of the current time through each iteration using
multiple metrics: milliseconds, microseconds, and nanoseconds. These numbers are then used to swap two indexes
in the vector.

### Randomness Evaluation
Both functions that we created do a good job randomizing the vector as they have a high probability of
returning a vector that is completely different from the previous sorted version. At first glance you would
think Noah's function was better at randomizing because it consistently shows a randomness metric ratio of 0
meaning that 0% of the trials were identical out of 100. After many runs of my randomizer I noticed that I never
saw a trial with a randomness metric ratio higher than 0, where as Nolan's randomizer did occasionally. As a group,
we weren't sure how often we should see a randomness metric ratio higher than 0 so that the random function was
'truly' random. My function truly did randomize the vector each iteration, but it could be almost too random.
Nolan's function also randomized consistently, but might provide a less randomized vector more often than it
should.