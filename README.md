# Console Banking Application

## Overview
This is a comprehensive console-based banking application written in C++ that provides core banking functionalities with a detailed menu-driven interface. The application allows users to create accounts, log in, perform financial transactions, and manage account details.

## Features

### Account Management
- Sign Up for a new account
- Login with account number and password
- View account details
- Change account password

### Financial Transactions
- Withdraw money
- Deposit funds
- Check account balance
- Buy mobile phone charge

### Additional Functionalities
- Automatic account number and password generation
- Account creation timestamp
- Personal information storage
- Customizable console theme
- File-based account information storage

## Key Classes
- `Address`: Manages user location information
- `Date`: Handles date-related operations
- `Time`: Captures system time and date
- `account`: Core class managing user account details and transactions

## Technologies Used
- C++ Standard Library
- Windows-specific console manipulation (Windows.h)
- File I/O for account information storage
- Console-based user interface

## Console Interface Features
- Menu navigation using arrow keys
- Screen clearing and formatting
- Cursor positioning
- Color theme selection

## How to Use
1. Compile the code with a C++ compiler supporting Windows APIs
2. Run the executable
3. Choose from menu options:
   - Sign Up
   - Login
   - Add Comments
   - Change Theme
   - Logout

## Requirements
- Windows Operating System
- C++ Compiler (e.g., MinGW, Visual Studio)
- Windows.h header support

## Note
This is a console application with Windows-specific implementations and may require modifications to run on other platforms.

## Limitations
- Stores only one account per session
- Basic error handling
- Console-based interface

## Future Improvements
- Multi-account support
- Enhanced error handling
- Persistent data storage
- Cross-platform compatibility
