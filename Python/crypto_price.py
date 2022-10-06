import requests
import streamlit as st

st.title("This page will help you to know  value of cryptocurrency in INR,USD and BTC")
crypto=st.selectbox("In which coin are you interested",["bitcoin","dogecoin","solana","aave","fantom","litecoin","cardeno","tether","ethereum","polkadot","tron"])
if st.button("Submit"):
    crypto_api='https://api.coingecko.com/api/v3/simple/price?ids=bitcoin%2Cdogecoin%2Csolana%2Caave%2Cfantom%2Clitecoin%2Ccardeno%2Ctether%2Cethereum%2Cpolkadot%2Ctron&vs_currencies=inr%2Cusd%2Cbtc'
    response=requests.get(crypto_api)
    crypto_json=response.json()
    st.text("INR:"+str(crypto_json[crypto]['inr']))
    st.text("USD:"+str(crypto_json[crypto]['usd']))
    st.text("BTC:"+str(crypto_json[crypto]['btc']))