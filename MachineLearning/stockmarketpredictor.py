import yfinance as yf
import matplotlib.pyplot as plt
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, LSTM
from sklearn.preprocessing import MinMaxScaler
import numpy as np

def plot_stock_predictions(ticker):
    stock = yf.Ticker(ticker)
    data = stock.history(period="max")
    data = data[["Close"]]
    
    scaler = MinMaxScaler()
    data = scaler.fit_transform(data)
    
    X_train, y_train = [], []
    for i in range(60, len(data)):
        X_train.append(data[i-60:i, 0])
        y_train.append(data[i, 0])
    X_train, y_train = np.array(X_train), np.array(y_train)
    X_train = np.reshape(X_train, (X_train.shape[0], X_train.shape[1], 1))
    
    model = Sequential()
    model.add(LSTM(units=50, return_sequences=True, input_shape=(X_train.shape[1], 1)))
    model.add(LSTM(units=50))
    model.add(Dense(units=1))
    model.compile(optimizer="adam", loss="mean_squared_error")
    model.fit(X_train, y_train, epochs=25, batch_size=32)
    
    predictions = []
    for i in range(1, 91):
        X_test = data[-60:]
        X_test = np.reshape(X_test, (1, X_test.shape[0], 1))
        predicted_price = model.predict(X_test)
        predictions.append(predicted_price[0][0])
        data = np.append(data, predicted_price, axis=0)
    
    predictions = scaler.inverse_transform([predictions])
    predictions = predictions[0]
    
    # Plot stock data and predictions
    plt.plot(stock.history().index, stock.history()["Close"], label="Actual")
    #plt.plot(data.date_range(start=stock.history().index[-1], periods=90, freq="D"), predictions, label="Predicted")
    #print(predictions)
    #still need to plot the predictions on the graph, i'll do that later lol
    plt.legend()
    plt.show()
