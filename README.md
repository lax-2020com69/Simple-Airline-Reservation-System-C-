# 📝 Airline Reservation System in C++ with User Login, Flight Management, and Seat Booking

# 🧰 Requirements
A C++ compiler (e.g., g++)

A terminal or command prompt

Basic text files:

users.txt (for user login credentials)

flight.txt (for flight data)

seat.txt (for seat status data)

# ✅ Step-by-Step Instructions
# 🖥️ Option 1: Using a Local Machine
# 🔧 Step 1: Create the Files
Save the C++ code to a file named:
airline.cpp

Create the following plain text files in the same folder:

flight.txt (sample content):

AI101 10
AI202 8
seat.txt (sample content matching above flights):

AI101 0 0 0 0 0 0 0 0 0 0
AI202 0 0 0 0 0 0 0 0
(No need to create users.txt now—this file will be generated when a user registers.)

# ⚙️ Step 2: Compile the Program
Linux/macOS (Terminal):

g++ airline.cpp -o airline
./airline
Windows (Command Prompt or PowerShell):

g++ airline.cpp -o airline.exe
airline.exe
If you don’t have g++, install it via:

Linux: sudo apt install g++

macOS: brew install gcc

Windows: Install MinGW or use MSYS2

# 🎮 Step 3: Use the Program
On first run, choose:

1 to register

2 to login

After logging in:

View the list of flights

Select a flight to:

View seat availability

Book a seat

Cancel a seat

Return to the main flight list

# 🌐 Option 2: Using an Online Compiler
Use one of the following:

https://www.onlinegdb.com/

https://www.programiz.com/cpp-programming/online-compiler/

https://replit.com/

Instructions:

Paste the full code into the editor.

Create simulated text file behavior:

Online compilers may not support real file I/O, so you'd need to:

Replace file input/output with cin/cout simulation, or

Use a platform like Replit, which supports file editing.

Click Run.

# 💡 Notes
All file data is plain text, so you can edit flight.txt and seat.txt easily.

Data persists across runs as long as the .txt files are not deleted.

Seat numbers are 1-based (from 1 to number of seats).


Create a C++ console-based Airline Reservation System with the following features:

# 🔐 1. User Authentication
Login and Registration System:

Users can register with a username and password, stored in a users.txt file.

During login, credentials are verified against the file.

Displays appropriate messages for successful login or invalid credentials.

# ✈️ 2. Flight Management
Each flight is represented by a Flight object containing:

A flight number (e.g., AI101)

A list of seats (default: 10 seats)

Flight metadata is loaded from a flight.txt file with each line in the format:

AI101 10
AI202 12
Seat availability is maintained in a separate seat.txt file:

Each line corresponds to a flight and its seat status:

AI101 0 0 1 0 1 0 0 1 0 0

# 🪑 3. Seat Booking and Cancellation
Display seat status: Shows booked or available for each seat.

Book a seat:

Prompts user for a seat number.

Validates the seat is within range and not already booked.

Updates the seat.txt file.

Cancel a booking:

Prompts for the seat number to cancel.

Checks if it's currently booked before proceeding.

Saves updated seat data.

# 🗂️ 4. File I/O Operations
Reads and writes to users.txt, flight.txt, and seat.txt.

Uses file streams to persist data across sessions.

Uses stringstream for parsing lines.

# 🧾 5. Modular Design
Implements two main classes:

User: Handles authentication logic.

Flight: Handles flight seat operations, display, loading, and saving.

Uses vector containers for dynamic seat storage.

Handles multiple flights and allows selection via the menu.

# 🖥️ 6. User Interaction via Console
Displays a main menu to:

Register or login.

View available flights.

Interact with a selected flight.

Offers a flight-specific menu to:

View seats

Book seats

Cancel bookings

Go back to the main menu
