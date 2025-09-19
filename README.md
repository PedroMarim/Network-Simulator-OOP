# OOP Network Simulator

This project was developed as part of the **Object-Oriented Programming Laboratory** course at **Escola Politécnica da Universidade de São Paulo (USP)**.  
It implements a **simplified computer network simulator** in C++, applying object-oriented programming principles.

## 🚀 Overview

The simulator models a small-scale computer network composed of:
- **Routers** and **QoS-enabled routers** (with priority queues)
- **Hosts** (end devices capable of running chat processes)
- **Chats** (processes that exchange messages through the network)
- **Datagrams and Segments** (representing packets and transport-layer messages)
- **Scheduler** (to simulate the passage of time and event processing)
- **Persistence** (loading network configurations from a file)

This project builds upon a first version (EP1) by introducing **end-to-end communication between processes**, support for **hosts**, and **priority-based message forwarding**.

## 🛠️ Features

- Object-oriented C++ design with:
  - Classes: `Rede`, `No`, `Roteador`, `RoteadorComQoS`, `Hospedeiro`, `Chat`, `Datagrama`, `Segmento`, `Fila`, `FilaComPrioridade`, `Agendador`, `TabelaDeRepasse`, `Evento`, `PersistenciaDeRede`, etc.
- Simulates message transmission between processes (chats) in different hosts.
- Routing and forwarding of packets with configurable delays.
- Priority queue support to simulate **Quality of Service (QoS)**.
- Console-based interface for:
  - Loading a network from a configuration file
  - Sending messages between chats
  - Advancing simulation time

## 📂 Project Structure

## Project Structure

The code is organized with one header (`.h`) and one implementation (`.cpp`) file for each class.  
Key files include:

- `main.cpp` — console interface to run the simulator  
- `Rede.*` — network management  
- `No.*`, `Roteador.*`, `RoteadorComQoS.*`, `Hospedeiro.*` — network nodes  
- `Chat.*` — process for message exchange  
- `Datagrama.*`, `Segmento.*` — packet and transport-layer segment  
- `Fila.*`, `FilaComPrioridade.*` — queues for packets  
- `TabelaDeRepasse.*` — routing table  
- `Evento.*`, `Agendador.*` — event scheduling and time simulation  
- `PersistenciaDeRede.*` — loading network configuration from files

## 🎓 Academic Context

This project was part of PCS3111 - Object-Oriented Programming Laboratory for Electrical Engineering at USP.  
It was designed to practice:

- Object-oriented concepts (encapsulation, inheritance, polymorphism, abstract classes)
- Exception handling in C++
- Modular program design
- Simulation of distributed systems

