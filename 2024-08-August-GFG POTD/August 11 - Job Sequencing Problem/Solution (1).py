class Job:
    def __init__(self, id, profit, dead):
        self.id = id
        self.profit = profit
        self.dead = dead

def job_comparator(job):
    return job.profit

def JobScheduling(jobs, n):
    # Sort the jobs array in descending order of profit
    jobs.sort(key=job_comparator, reverse=True)

    # Find the maximum deadline
    max_deadline = max(job.dead for job in jobs)

    # Initialize a slot array to store the job slots
    slot = [False] * (max_deadline + 1)

    count_jobs = 0
    job_profit = 0

    # Iterate through all jobs
    for job in jobs:
        # Check for a free slot before the deadline
        for j in range(job.dead, 0, -1):
            if not slot[j]:
                slot[j] = True
                count_jobs += 1
                job_profit += job.profit
                break

    return [count_jobs, job_profit]

# Example usage
jobs = [
    Job(1, 100, 2),
    Job(2, 19, 1),
    Job(3, 27, 2),
    Job(4, 25, 1),
    Job(5, 15, 3)
]

n = len(jobs)
result = JobScheduling(jobs, n)
print("Number of jobs done:", result[0])
print("Maximum profit:", result[1])
