# TermTicker
- A terminal application for viewing market data using https://www.alphavantage.co/ for queries

## Quick Start
- Clone this repo
- Navigate to termticker/c++ and run make then ./main to run
- Follow instructions in command line
- Note: for date in daily queries you can write today instead of YYYY-MM-DD format

## Commit History
- Initial commit: Allows user to input a date and symbol and get back current market data including open, daily high and low, last close and volume.
- 4/10: rewrote most of this, split functions out of main.cpp into funcs.cpp so main only handles initial input.
