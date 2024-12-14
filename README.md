# Quick Commerce System

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Class Overview](#class-overview)
- [Future Enhancements](#future-enhancements)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Quick Commerce System is a simple C++ console application that simulates a basic e-commerce platform. It allows users to register or log in using their phone numbers, place orders, track their orders, and view their order history. The system provides a straightforward interface for managing user interactions and orders.

## Features

- **User Registration and Login**: Users can log in with their phone number. If the user doesn't exist, they can create a new account.
- **Place Order**: Users can view a list of available products, add products to their cart, and place an order.
- **Track Order**: Users can track the delivery status of their most recent order with a countdown timer.
- **Order History**: Users can view their past orders, including the total amount, item count, and order date.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, clang++)
- A code editor or IDE (e.g., Visual Studio Code, CLion)

### Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/quick-commerce-system.git
    ```
2. Navigate to the project directory:
    ```bash
    cd quick-commerce-system
    ```

### Compilation

To compile the project, run the following command:
```bash
g++ -o quick_commerce_system main.cpp
```

### Running the Application

To run the compiled application, use the following command:
```bash
./quick_commerce_system
```

## Usage

1. **Start the application**: Enter your phone number.
2. **Login or Register**: If the phone number exists, you will be logged in. If not, you will be prompted to register by providing your name.
3. **Main Menu**:
    - Place Order
    - Track Previous Order
    - Order History
    - Logout
4. **Place Order**: Select products to add to your cart and confirm your order.
5. **Track Previous Order**: View the delivery status of your most recent order.
6. **Order History**: View details of your past orders.

## Class Overview

### Product

Represents a product with an ID, name, and price.

### Cart

Manages the products added by the user and calculates the total price.

### DeliveryPerson

Represents the delivery person assigned to deliver the order.

### Order

Contains details of the order, including the cart, total price, order time, and delivery person.

### User

Represents a user with a phone number, name, and order history.

## Future Enhancements

- **Persistent Storage**: Implement a database to store user and order information persistently.
- **Authentication**: Add more robust user authentication and password management.
- **Enhanced Tracking**: Implement real-time order tracking with more detailed status updates.
- **Product Management**: Add features for product management, such as adding, updating, and deleting products.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes. Ensure your code follows the project's coding standards and includes appropriate tests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

Enjoy using the Quick Commerce System! If you have any questions or suggestions, feel free to open an issue or contact us.

