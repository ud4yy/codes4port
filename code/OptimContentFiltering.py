import numpy as np

# Example: Precompute similarity scores and store in Hashmap
similarity_scores = {}

# Assume V_u and V_m are stored in arrays or fetched from a model
# Dummy data for illustration
users = ['user1', 'user2']
movies = ['movie1', 'movie2', 'movie3']
V_u = {user: np.random.randn(10) for user in users}
V_m = {movie: np.random.randn(10) for movie in movies}

# Precompute similarity scores ||V_u - V_m||^2
for user in users:
    for movie in movies:
        similarity_scores[(user, movie)] = np.linalg.norm(V_u[user] - V_m[movie])**2

# Example usage: Retrieve similarity score for a user and a movie
user = 'user1'
movie = 'movie2'
print(f"Similarity score between {user} and {movie}: {similarity_scores[(user, movie)]}")

