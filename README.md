
---

# Social Network Simulation

This project is a simulation of a basic social network built in C, featuring user registration, login, following functionality, and a simple post system. The network data (users and posts) is stored in a file so that the information persists across sessions.

## Features

- **User Registration and Login**
  - Users can create an account with a username and password.
  - Login to access additional features of the social network.

- **Create Posts**
  - Logged-in users can create posts with a timestamp.
  - Posts are stored and can be viewed in different feeds.

- **Follow Users**
  - Users can follow other registered users.
  - Once a user follows someone, they can view that user's posts in their following feed.

- **View Feeds**
  - View all users that the logged-in user is following.
  - View posts from users you are following.
  - View posts from users who are following you.
  - View your own posts.

- **Persistent Storage**
  - User data, including posts and followers, is saved to a file (`users.txt`) and loaded when the program starts.

## How to Run

### Prerequisites

- A C compiler (such as GCC) installed on your system.

### Compilation

To compile the program, use the following command in the terminal:

```bash
gcc -o social_network social_network.c
```

### Running the Program

Once compiled, run the program with the following command:

```bash
./social_network
```

### Example Usage

- **Register a new user**: 
  - Enter your username and password.
  
- **Login**: 
  - Enter your username and password to login to the social network.

- **Create a post**: 
  - Once logged in, you can create posts that will be saved to your feed.

- **Follow other users**: 
  - Follow other users by their username to see their posts.

- **View Feeds**:
  - Check your feed, the feed of users you follow, and the feed of your followers.

### Program Menu

```plaintext
1. Register
2. Login
3. View All Users
4. Exit
```

After logging in:

```plaintext
1. Create Post
2. Follow User
3. View Following
4. View Your Feed
5. View Following Feed
6. View Followers Feed
7. Go Back
```

### File Structure

- **users.txt**: Stores the users and their posts.
  - Format:
    ```
    <username> <password>
    POST <timestamp> <post content>
    END
    ```

## Project Structure

- **social_network.c**: Main source file containing the social network code.
- **users.txt**: File used to store the registered users and their posts persistently.


