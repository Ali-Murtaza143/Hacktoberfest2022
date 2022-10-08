#importing libraries
import streamlit as st
import pandas as pd
import matplotlib.pyplot as plt
import plotly.express as px
import seaborn as sns
import xgboost

st.set_option('deprecation.showPyplotGlobalUse', False)

st.markdown("<h1 style='text-align: center; color: black;'>House Price Prediction</h1>", unsafe_allow_html=True)
st.write("---")

# Loading the dataset
df = pd.read_csv('dataset.csv', index_col=[0])
X = df.drop(['SalePrice'], axis=1)
Y = df['SalePrice']
st.write("### Dataset")
st.write(X)

#Visualization
st.write('---')
st.markdown("<h3 style='text-align: left; color: black;'>Data Visualization</h3>", unsafe_allow_html=True)

chart_select = st.selectbox(
    label = "Select the type of chart",
    options = ['Scatterplot', 'Histogram', 'Boxplot']
)

num_cols = list(X.select_dtypes(['float','int']).columns)

if chart_select == "Scatterplot":
    st.write("###### Scatterplot Settings")
    try:
        x_values = st.selectbox('X axis', options=num_cols)
        y_values = st.selectbox('Y axis', options=num_cols)
        plot = px.scatter(data_frame=X, x=x_values, y=y_values)
        st.write(plot)
    except Exception as e:
        print(e)

if chart_select == "Histogram":
    st.write("###### Histogram Settings")
    try:
        x_values = st.selectbox('X axis', options=num_cols)
        plot = px.histogram(data_frame=X, x=x_values)
        st.write(plot)
    except Exception as e:
        print(e)

if chart_select == "Boxplot":
    st.write("###### Boxplot Settings")
    try:
        x_values = st.selectbox('X axis', options=num_cols)
        y_values = st.selectbox('Y axis', options=num_cols)
        plot = px.box(data_frame=X, x=x_values, y=y_values)
        st.write(plot)
    except Exception as e:
        print(e)

#User input for model parameters
st.markdown("<h2 style='text-align: left; color: black;'>Model Parameters</h2>", unsafe_allow_html=True)
st.write("###### Specify Input Parameters: ")

def user_input():
    OverallQual = st.slider('OverallQual',float(X.OverallQual.min()),float(X.OverallQual.max()), float(X.OverallQual.mean()))
    GrLivArea = st.slider('GrLivArea',float(X.GrLivArea.min()),float(X.GrLivArea.max()), float(X.GrLivArea.mean()))
    GarageCars = st.slider('GarageCars',float(X.GarageCars.min()),float(X.GarageCars.max()),float(X.GarageCars.mean()))
    GarageArea = st.slider('GarageArea',float(X.GarageArea.min()),float(X.GarageArea.max()),float(X.GarageArea.mean()))
    lstFlrSF = st.slider('lstFlrSF',float(X.lstFlrSF.min()),float(X.lstFlrSF.max()),float(X.lstFlrSF.mean()))
    data = { 'OverallQual': OverallQual,
             'GrLivArea': GrLivArea,
             'GarageCars': GarageCars,
             'GarageArea': GarageArea,
             '1stFlrSF': lstFlrSF}
    features = pd.DataFrame(data, index=[0])
    return features

df = user_input()

#Displaying given input parameters
st.write("###### Specified Input Parameters")
st.write(df)
st.write('---')

#model
model=xgboost.XGBRegressor()
model.fit(X, Y)
prediction = model.predict(df)

st.write("###### Predicted House Price Value based on the given parameters: ")
st.code(float(prediction))
st.write('---')

#SHAP
import shap
explainer = shap.TreeExplainer(model)
shap_values = explainer.shap_values(X)
st.markdown("<h2 style='text-align: left; color: black;'>Feature Importance</h2>", unsafe_allow_html=True)
st.write("###### Feature Importance based on SHAP values")
shap.summary_plot(shap_values,X)
st.pyplot(bbox_inches='tight')
shap.summary_plot(shap_values,X,plot_type='bar')
st.pyplot(bbox_inches='tight')
