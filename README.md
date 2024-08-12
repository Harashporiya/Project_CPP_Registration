# Project_CPP_Registration

## Project Setup

This project allows users to create an account, log in, search for users, and delete accounts. User data is saved to a file using C++'s `<fstream>` header.

### 1. Features
- **User Registration:** Users can create an account by providing their name and password.
- **Login:** Users can log in using their credentials.
- **Show User List:** Displays a list of all registered users.
- **Search User:** Users can search for a specific user by name.
- **Delete User:** Users can delete their account.
- **Print User Credentials:** Displays the username and password of a logged-in user.
- **Exit:** Exits the application.

### 2. Data Storage
- **File:** User data is saved in a file named `userdata.txt`.
- **File Handling:** The file is managed using the `<fstream>` library in C++.

### 3. File Management
- **.gitignore:** The `userdata.txt` file is included in the `.gitignore` to prevent it from being tracked in the repository.

### 4. Running the Program
When running the program, you'll be presented with the following menu:

```plaintext
1. Register User 
2. Login 
3. Show User List 
4. Search User 
5. Delete User 
6. Print User Credentials 
7. Exit 
Enter your choice: 1
Enter Your Name: *******
Enter Your Password: ******
User Registered Successfully....
Do You Want to Continue [Yes/No]? :
```
### Cloning the Repository
- **To clone the repository, use the following command:**

git clone <https_url_paste_here>