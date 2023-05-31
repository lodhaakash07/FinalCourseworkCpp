import pandas as pd
import matplotlib.pyplot as plt

# Load the data from the CSV file
data = pd.read_csv('portfolio_data.csv')

# Hypothesis 1: Performance of the Markowitz model for different Target_Returns
# Plotting the mean returns for different Target_Returns
data.head()
plt.figure(figsize=(10, 6))
plt.plot(data['Target_Return'], data['In-sample Mean'], marker='o', label='In-sample Mean')
plt.plot(data['Target_Return'], data['Out-sample Mean'], marker='o', label='Out-sample Mean')
plt.xlabel('Target_Return')
plt.ylabel('Mean Return')
plt.title('Performance of the Markowitz Model')
plt.legend()
plt.grid(True)
plt.show()

# Hypothesis 2: Relationship between Target_Return and portfolio covariance
# Plotting the covariance for different Target_Returns
plt.figure(figsize=(10, 6))
plt.plot(data['Target_Return'], data['In-sample Covariance'], marker='o', label='In-sample Covariance')
plt.plot(data['Target_Return'], data['Out-sample Covariance'], marker='o', label='Out-sample Covariance')
plt.xlabel('Target_Return')
plt.ylabel('Covariance')
plt.title('Relationship between Target_Return and Covariance')
plt.legend()
plt.grid(True)
plt.show()

# Hypothesis 3: Comparison of in-sample and out-sample performance
# Plotting the mean returns for different windows
plt.figure(figsize=(10, 6))
plt.plot(data['Window'], data['In-sample Mean'], marker='o', label='In-sample Mean')
plt.plot(data['Window'], data['Out-sample Mean'], marker='o', label='Out-sample Mean')
plt.xlabel('Window')
plt.ylabel('Mean Return')
plt.title('Comparison of In-sample and Out-sample Performance')
plt.legend()
plt.grid(True)
plt.show()

# Hypothesis 4: Variability of portfolio performance across windows
# Plotting the covariance for different windows
plt.figure(figsize=(10, 6))
plt.plot(data['Window'], data['In-sample Covariance'], marker='o', label='In-sample Covariance')
plt.plot(data['Window'], data['Out-sample Covariance'], marker='o', label='Out-sample Covariance')
plt.xlabel('Window')
plt.ylabel('Covariance')
plt.title('Variability of Portfolio Performance across Windows')
plt.legend()
plt.grid(True)
plt.show()

# Add more hypotheses and corresponding visual plots as needed


# Hypothesis 5: Impact of rolling window size on portfolio performance
# Plotting the mean returns for different rolling window sizes
plt.figure(figsize=(10, 6))
plt.plot(data['Window'], data['In-sample Mean'], marker='o', label='In-sample Mean')
plt.plot(data['Window'], data['Out-sample Mean'], marker='o', label='Out-sample Mean')
plt.xlabel('Window Size')
plt.ylabel('Mean Return')
plt.title('Impact of Rolling Window Size on Portfolio Performance')
plt.legend()
plt.grid(True)
plt.show()

# Hypothesis 6: Diversification benefits of the Markowitz model
# Plotting the covariance for different rolling window sizes
plt.figure(figsize=(10, 6))
plt.plot(data['Window'], data['In-sample Covariance'], marker='o', label='In-sample Covariance')
plt.plot(data['Window'], data['Out-sample Covariance'], marker='o', label='Out-sample Covariance')
plt.xlabel('Window Size')
plt.ylabel('Covariance')
plt.title('Diversification Benefits of the Markowitz Model')
plt.legend()
plt.grid(True)
plt.show()

# Hypothesis 7: Comparing portfolio performance across different Target_Return levels
# Plotting the mean returns for different Target_Return levels
plt.figure(figsize=(10, 6))
plt.plot(data['Target_Return'], data['In-sample Mean'], marker='o', label='In-sample Mean')
plt.plot(data['Target_Return'], data['Out-sample Mean'], marker='o', label='Out-sample Mean')
plt.xlabel('Target_Return')
plt.ylabel('Mean Return')
plt.title('Comparing Portfolio Performance across Target_Return Levels')
plt.legend()
plt.grid(True)
plt.show()

# Hypothesis 8: Tracking error analysis of portfolio returns
# Plotting the difference between in-sample and out-sample mean returns
plt.figure(figsize=(10, 6))
plt.plot(data['Window'], data['In-sample Mean'] - data['Out-sample Mean'], marker='o')
plt.xlabel('Window')
plt.ylabel('Tracking Error')
plt.title('Tracking Error Analysis of Portfolio Returns')
plt.grid(True)
plt.show()

# You can add more hypotheses and corresponding plots as needed



# Hypothesis 9: Relationship between portfolio mean and covariance
# Plotting the covariance against the mean return for different Target_Returns
plt.figure(figsize=(10, 6))
plt.scatter(data['In-sample Covariance'], data['In-sample Mean'], marker='o', label='In-sample')
plt.scatter(data['Out-sample Covariance'], data['Out-sample Mean'], marker='o', label='Out-sample')
plt.xlabel('Covariance')
plt.ylabel('Mean Return')
plt.title('Relationship between Portfolio Mean and Covariance')
plt.legend()
plt.grid(True)
plt.show()

# Hypothesis 10: Risk-return tradeoff analysis
# Plotting the mean return against the covariance for different rolling window sizes
plt.figure(figsize=(10, 6))
plt.scatter(data['In-sample Covariance'], data['In-sample Mean'], c=data['Window'], cmap='viridis', label='In-sample')
plt.scatter(data['Out-sample Covariance'], data['Out-sample Mean'], c=data['Window'], cmap='viridis', marker='x', label='Out-sample')
plt.colorbar(label='Window Size')
plt.xlabel('Covariance')
plt.ylabel('Mean Return')
plt.title('Risk-Return Tradeoff Analysis')
plt.legend()
plt.grid(True)
plt.show()

# Hypothesis 11: Evaluation of optimal portfolios
# Plotting the weights of optimal portfolios for different Target_Returns
optimal_weights = pd.DataFrame(data['Window']).apply(lambda x: data.loc[data['Window'] == x.values[0], ['In-sample Mean', 'In-sample Covariance']].idxmax(axis=0), axis=1)
optimal_weights.columns = ['In-sample Mean', 'In-sample Covariance']
plt.figure(figsize=(10, 6))
plt.plot(data['Target_Return'], optimal_weights['In-sample Mean'], marker='o', label='Mean-Optimal Portfolio')
plt.plot(data['Target_Return'], optimal_weights['In-sample Covariance'], marker='o', label='Covariance-Optimal Portfolio')
plt.xlabel('Target_Return')
plt.ylabel('Optimal Portfolio')
plt.title('Evaluation of Optimal Portfolios')
plt.legend()
plt.grid(True)
plt.show()

# You can add more hypotheses and corresponding plots as needed

