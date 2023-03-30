import requests
from bs4 import BeautifulSoup
import pandas as pd
import matplotlib.pyplot as plt

# Function to web scrape stock data for a given symbol
def get_stock_data(symbol):
    # Construct the URL for the stock history page on Yahoo Finance
    url = f"https://finance.yahoo.com/quote/{symbol}/history?p={symbol}"
    
    # Send an HTTP request to the webpage and store the response
    response = requests.get(url)
    
    # Parse the HTML content of the webpage
    soup = BeautifulSoup(response.text, "html.parser")
    
    # Find the element on the webpage that contains the stock data table
    table_element = soup.find(id="C-%s" % symbol)
    
    # Extract the data from the table and store it in a list of dictionaries
    data = []
    for row in table_element.find_all("tr"):
        cells = row.find_all("td")
        if len(cells) == 7:
            data.append({
                "Date": cells[0].text,
                "Open": float(cells[1].text),
                "High": float(cells[2].text),
                "Low": float(cells[3].text),
                "Close": float(cells[4].text),
                "Adj Close": float(cells[5].text),
                "Volume": int(cells[6].text.replace(",", ""))
            })
    
    # Create a pandas DataFrame from the data
    df = pd.DataFrame(data)
    
    # Set the Date column as the index
    df.set_index("Date", inplace=True)
    
    return df

# Function to analyze a stock and make a recommendation
def analyze_stock(symbol):
    # Get the stock data for the symbol
    df = get_stock_data(symbol)

    # Calculate the 50-day and 200-day moving averages
    df["50-day"] = df["Close"].rolling(50).mean()
    df["200-day"] = df["Close"].rolling(200).mean()

    # Plot the stock data and moving averages
    plt.plot(df["Close"], label="Close")
    plt.plot(df["50-day"], label="50-day")
    plt.plot(df["200-day"], label="200-day")
    plt.legend()
    plt.show()

    # Check if the 50-day moving average is above the 200-day moving average
    if df["50-day"].iloc[-1] > df["200-day"].iloc[-1]:
        print("Recommendation: Buy")
    else:
        print("Recommendation: Sell")

# Test the function
analyze_stock("AAPL")
