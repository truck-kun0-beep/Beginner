import requests

def convert_currency(from_currency, to_currency, amount):
    url = f"https://api.exchangerate-api.com/v4/latest/{from_currency.upper()}"


    try:
        response = requests.get(url)
        data = response.json()

        if to_currency.upper() not in data['rates']:
            print("Currency not supported.")
            return
        rate = data["rates"][to_currency.upper()]
        converted_amount = amount * rate

        print(f"\n{amount} {from_currency.upper()} = {converted_amount} {to_currency.upper()}")
    except Exception as e:
        print("Error fetching exchange rates. Check your internet or currency codes.")
        print("Details:", e)


print("Currency Converter")
from_curr = input("Enter source currency (e.g., USD): ")
to_curr = input("Enter target currency (e.g., EUR): ")
amt = float(input("Enter amount to convert: "))

convert_currency(from_curr, to_curr, amt)