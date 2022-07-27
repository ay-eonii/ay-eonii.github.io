# 1. 데이터 살펴보기

## 1-1. 데이터 준비


```python
# pandas 라이브러리
import pandas as pd

train = pd.read_csv("C:/contest/dataset/train.csv")
test = pd.read_csv("C:/\contest/dataset/test.csv")
sample_submission = pd.read_csv("C:/contest/dataset/sample_submission.csv")
```


```python
train
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>id</th>
      <th>Store</th>
      <th>Date</th>
      <th>Temperature</th>
      <th>Fuel_Price</th>
      <th>Promotion1</th>
      <th>Promotion2</th>
      <th>Promotion3</th>
      <th>Promotion4</th>
      <th>Promotion5</th>
      <th>Unemployment</th>
      <th>IsHoliday</th>
      <th>Weekly_Sales</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>1</td>
      <td>05/02/2010</td>
      <td>42.31</td>
      <td>2.572</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>8.106</td>
      <td>False</td>
      <td>1643690.90</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>1</td>
      <td>12/02/2010</td>
      <td>38.51</td>
      <td>2.548</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>8.106</td>
      <td>True</td>
      <td>1641957.44</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>1</td>
      <td>19/02/2010</td>
      <td>39.93</td>
      <td>2.514</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>8.106</td>
      <td>False</td>
      <td>1611968.17</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>1</td>
      <td>26/02/2010</td>
      <td>46.63</td>
      <td>2.561</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>8.106</td>
      <td>False</td>
      <td>1409727.59</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>1</td>
      <td>05/03/2010</td>
      <td>46.50</td>
      <td>2.625</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>8.106</td>
      <td>False</td>
      <td>1554806.68</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>6250</th>
      <td>6251</td>
      <td>45</td>
      <td>31/08/2012</td>
      <td>75.09</td>
      <td>3.867</td>
      <td>23641.30</td>
      <td>6.00</td>
      <td>92.93</td>
      <td>6988.31</td>
      <td>3992.13</td>
      <td>8.684</td>
      <td>False</td>
      <td>734297.87</td>
    </tr>
    <tr>
      <th>6251</th>
      <td>6252</td>
      <td>45</td>
      <td>07/09/2012</td>
      <td>75.70</td>
      <td>3.911</td>
      <td>11024.45</td>
      <td>12.80</td>
      <td>52.63</td>
      <td>1854.77</td>
      <td>2055.70</td>
      <td>8.684</td>
      <td>True</td>
      <td>766512.66</td>
    </tr>
    <tr>
      <th>6252</th>
      <td>6253</td>
      <td>45</td>
      <td>14/09/2012</td>
      <td>67.87</td>
      <td>3.948</td>
      <td>11407.95</td>
      <td>NaN</td>
      <td>4.30</td>
      <td>3421.72</td>
      <td>5268.92</td>
      <td>8.684</td>
      <td>False</td>
      <td>702238.27</td>
    </tr>
    <tr>
      <th>6253</th>
      <td>6254</td>
      <td>45</td>
      <td>21/09/2012</td>
      <td>65.32</td>
      <td>4.038</td>
      <td>8452.20</td>
      <td>92.28</td>
      <td>63.24</td>
      <td>2376.38</td>
      <td>8670.40</td>
      <td>8.684</td>
      <td>False</td>
      <td>723086.20</td>
    </tr>
    <tr>
      <th>6254</th>
      <td>6255</td>
      <td>45</td>
      <td>28/09/2012</td>
      <td>64.88</td>
      <td>3.997</td>
      <td>4556.61</td>
      <td>20.64</td>
      <td>1.50</td>
      <td>1601.01</td>
      <td>3288.25</td>
      <td>8.684</td>
      <td>False</td>
      <td>713173.95</td>
    </tr>
  </tbody>
</table>
<p>6255 rows × 13 columns</p>
</div>



## 1-2. 데이터 확인


```python
train.head()
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>id</th>
      <th>Store</th>
      <th>Date</th>
      <th>Temperature</th>
      <th>Fuel_Price</th>
      <th>Promotion1</th>
      <th>Promotion2</th>
      <th>Promotion3</th>
      <th>Promotion4</th>
      <th>Promotion5</th>
      <th>Unemployment</th>
      <th>IsHoliday</th>
      <th>Weekly_Sales</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>1</td>
      <td>05/02/2010</td>
      <td>42.31</td>
      <td>2.572</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>8.106</td>
      <td>False</td>
      <td>1643690.90</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>1</td>
      <td>12/02/2010</td>
      <td>38.51</td>
      <td>2.548</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>8.106</td>
      <td>True</td>
      <td>1641957.44</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>1</td>
      <td>19/02/2010</td>
      <td>39.93</td>
      <td>2.514</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>8.106</td>
      <td>False</td>
      <td>1611968.17</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>1</td>
      <td>26/02/2010</td>
      <td>46.63</td>
      <td>2.561</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>8.106</td>
      <td>False</td>
      <td>1409727.59</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>1</td>
      <td>05/03/2010</td>
      <td>46.50</td>
      <td>2.625</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>8.106</td>
      <td>False</td>
      <td>1554806.68</td>
    </tr>
  </tbody>
</table>
</div>




```python
train.tail()
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>id</th>
      <th>Store</th>
      <th>Date</th>
      <th>Temperature</th>
      <th>Fuel_Price</th>
      <th>Promotion1</th>
      <th>Promotion2</th>
      <th>Promotion3</th>
      <th>Promotion4</th>
      <th>Promotion5</th>
      <th>Unemployment</th>
      <th>IsHoliday</th>
      <th>Weekly_Sales</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>6250</th>
      <td>6251</td>
      <td>45</td>
      <td>31/08/2012</td>
      <td>75.09</td>
      <td>3.867</td>
      <td>23641.30</td>
      <td>6.00</td>
      <td>92.93</td>
      <td>6988.31</td>
      <td>3992.13</td>
      <td>8.684</td>
      <td>False</td>
      <td>734297.87</td>
    </tr>
    <tr>
      <th>6251</th>
      <td>6252</td>
      <td>45</td>
      <td>07/09/2012</td>
      <td>75.70</td>
      <td>3.911</td>
      <td>11024.45</td>
      <td>12.80</td>
      <td>52.63</td>
      <td>1854.77</td>
      <td>2055.70</td>
      <td>8.684</td>
      <td>True</td>
      <td>766512.66</td>
    </tr>
    <tr>
      <th>6252</th>
      <td>6253</td>
      <td>45</td>
      <td>14/09/2012</td>
      <td>67.87</td>
      <td>3.948</td>
      <td>11407.95</td>
      <td>NaN</td>
      <td>4.30</td>
      <td>3421.72</td>
      <td>5268.92</td>
      <td>8.684</td>
      <td>False</td>
      <td>702238.27</td>
    </tr>
    <tr>
      <th>6253</th>
      <td>6254</td>
      <td>45</td>
      <td>21/09/2012</td>
      <td>65.32</td>
      <td>4.038</td>
      <td>8452.20</td>
      <td>92.28</td>
      <td>63.24</td>
      <td>2376.38</td>
      <td>8670.40</td>
      <td>8.684</td>
      <td>False</td>
      <td>723086.20</td>
    </tr>
    <tr>
      <th>6254</th>
      <td>6255</td>
      <td>45</td>
      <td>28/09/2012</td>
      <td>64.88</td>
      <td>3.997</td>
      <td>4556.61</td>
      <td>20.64</td>
      <td>1.50</td>
      <td>1601.01</td>
      <td>3288.25</td>
      <td>8.684</td>
      <td>False</td>
      <td>713173.95</td>
    </tr>
  </tbody>
</table>
</div>




```python
train.info()
```

    <class 'pandas.core.frame.DataFrame'>
    RangeIndex: 6255 entries, 0 to 6254
    Data columns (total 13 columns):
     #   Column        Non-Null Count  Dtype  
    ---  ------        --------------  -----  
     0   id            6255 non-null   int64  
     1   Store         6255 non-null   int64  
     2   Date          6255 non-null   object 
     3   Temperature   6255 non-null   float64
     4   Fuel_Price    6255 non-null   float64
     5   Promotion1    2102 non-null   float64
     6   Promotion2    1592 non-null   float64
     7   Promotion3    1885 non-null   float64
     8   Promotion4    1819 non-null   float64
     9   Promotion5    2115 non-null   float64
     10  Unemployment  6255 non-null   float64
     11  IsHoliday     6255 non-null   bool   
     12  Weekly_Sales  6255 non-null   float64
    dtypes: bool(1), float64(9), int64(2), object(1)
    memory usage: 592.6+ KB
    

## 1-3. 데이터 시각화


```python
import matplotlib.pyplot as plt

plt.hist(train.Weekly_Sales, bins=50)
plt.show()
```


    
![png](output_9_0.png)
    


# 데이터 전처리

## 2-1. 결측치(NA) 처리


```python
train = train.fillna(0)

train
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>id</th>
      <th>Store</th>
      <th>Date</th>
      <th>Temperature</th>
      <th>Fuel_Price</th>
      <th>Promotion1</th>
      <th>Promotion2</th>
      <th>Promotion3</th>
      <th>Promotion4</th>
      <th>Promotion5</th>
      <th>Unemployment</th>
      <th>IsHoliday</th>
      <th>Weekly_Sales</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>1</td>
      <td>05/02/2010</td>
      <td>42.31</td>
      <td>2.572</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>False</td>
      <td>1643690.90</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>1</td>
      <td>12/02/2010</td>
      <td>38.51</td>
      <td>2.548</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>True</td>
      <td>1641957.44</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>1</td>
      <td>19/02/2010</td>
      <td>39.93</td>
      <td>2.514</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>False</td>
      <td>1611968.17</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>1</td>
      <td>26/02/2010</td>
      <td>46.63</td>
      <td>2.561</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>False</td>
      <td>1409727.59</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>1</td>
      <td>05/03/2010</td>
      <td>46.50</td>
      <td>2.625</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>False</td>
      <td>1554806.68</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>6250</th>
      <td>6251</td>
      <td>45</td>
      <td>31/08/2012</td>
      <td>75.09</td>
      <td>3.867</td>
      <td>23641.30</td>
      <td>6.00</td>
      <td>92.93</td>
      <td>6988.31</td>
      <td>3992.13</td>
      <td>8.684</td>
      <td>False</td>
      <td>734297.87</td>
    </tr>
    <tr>
      <th>6251</th>
      <td>6252</td>
      <td>45</td>
      <td>07/09/2012</td>
      <td>75.70</td>
      <td>3.911</td>
      <td>11024.45</td>
      <td>12.80</td>
      <td>52.63</td>
      <td>1854.77</td>
      <td>2055.70</td>
      <td>8.684</td>
      <td>True</td>
      <td>766512.66</td>
    </tr>
    <tr>
      <th>6252</th>
      <td>6253</td>
      <td>45</td>
      <td>14/09/2012</td>
      <td>67.87</td>
      <td>3.948</td>
      <td>11407.95</td>
      <td>0.00</td>
      <td>4.30</td>
      <td>3421.72</td>
      <td>5268.92</td>
      <td>8.684</td>
      <td>False</td>
      <td>702238.27</td>
    </tr>
    <tr>
      <th>6253</th>
      <td>6254</td>
      <td>45</td>
      <td>21/09/2012</td>
      <td>65.32</td>
      <td>4.038</td>
      <td>8452.20</td>
      <td>92.28</td>
      <td>63.24</td>
      <td>2376.38</td>
      <td>8670.40</td>
      <td>8.684</td>
      <td>False</td>
      <td>723086.20</td>
    </tr>
    <tr>
      <th>6254</th>
      <td>6255</td>
      <td>45</td>
      <td>28/09/2012</td>
      <td>64.88</td>
      <td>3.997</td>
      <td>4556.61</td>
      <td>20.64</td>
      <td>1.50</td>
      <td>1601.01</td>
      <td>3288.25</td>
      <td>8.684</td>
      <td>False</td>
      <td>713173.95</td>
    </tr>
  </tbody>
</table>
<p>6255 rows × 13 columns</p>
</div>



## 2-2. Date 전처리


```python
# Date에서 "월"에 해당하는 정보만 추출하여 숫자 형태로 반환하는 함수
def get_month(date):
    month = date[3:5]
    month = int(month)
    return month

# get_month 함수 적용해 Month 칼럼 만들기
train['Month'] = train['Date'].apply(get_month)

train
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>id</th>
      <th>Store</th>
      <th>Date</th>
      <th>Temperature</th>
      <th>Fuel_Price</th>
      <th>Promotion1</th>
      <th>Promotion2</th>
      <th>Promotion3</th>
      <th>Promotion4</th>
      <th>Promotion5</th>
      <th>Unemployment</th>
      <th>IsHoliday</th>
      <th>Weekly_Sales</th>
      <th>Month</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>1</td>
      <td>05/02/2010</td>
      <td>42.31</td>
      <td>2.572</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>False</td>
      <td>1643690.90</td>
      <td>2</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>1</td>
      <td>12/02/2010</td>
      <td>38.51</td>
      <td>2.548</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>True</td>
      <td>1641957.44</td>
      <td>2</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>1</td>
      <td>19/02/2010</td>
      <td>39.93</td>
      <td>2.514</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>False</td>
      <td>1611968.17</td>
      <td>2</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>1</td>
      <td>26/02/2010</td>
      <td>46.63</td>
      <td>2.561</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>False</td>
      <td>1409727.59</td>
      <td>2</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>1</td>
      <td>05/03/2010</td>
      <td>46.50</td>
      <td>2.625</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>False</td>
      <td>1554806.68</td>
      <td>3</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>6250</th>
      <td>6251</td>
      <td>45</td>
      <td>31/08/2012</td>
      <td>75.09</td>
      <td>3.867</td>
      <td>23641.30</td>
      <td>6.00</td>
      <td>92.93</td>
      <td>6988.31</td>
      <td>3992.13</td>
      <td>8.684</td>
      <td>False</td>
      <td>734297.87</td>
      <td>8</td>
    </tr>
    <tr>
      <th>6251</th>
      <td>6252</td>
      <td>45</td>
      <td>07/09/2012</td>
      <td>75.70</td>
      <td>3.911</td>
      <td>11024.45</td>
      <td>12.80</td>
      <td>52.63</td>
      <td>1854.77</td>
      <td>2055.70</td>
      <td>8.684</td>
      <td>True</td>
      <td>766512.66</td>
      <td>9</td>
    </tr>
    <tr>
      <th>6252</th>
      <td>6253</td>
      <td>45</td>
      <td>14/09/2012</td>
      <td>67.87</td>
      <td>3.948</td>
      <td>11407.95</td>
      <td>0.00</td>
      <td>4.30</td>
      <td>3421.72</td>
      <td>5268.92</td>
      <td>8.684</td>
      <td>False</td>
      <td>702238.27</td>
      <td>9</td>
    </tr>
    <tr>
      <th>6253</th>
      <td>6254</td>
      <td>45</td>
      <td>21/09/2012</td>
      <td>65.32</td>
      <td>4.038</td>
      <td>8452.20</td>
      <td>92.28</td>
      <td>63.24</td>
      <td>2376.38</td>
      <td>8670.40</td>
      <td>8.684</td>
      <td>False</td>
      <td>723086.20</td>
      <td>9</td>
    </tr>
    <tr>
      <th>6254</th>
      <td>6255</td>
      <td>45</td>
      <td>28/09/2012</td>
      <td>64.88</td>
      <td>3.997</td>
      <td>4556.61</td>
      <td>20.64</td>
      <td>1.50</td>
      <td>1601.01</td>
      <td>3288.25</td>
      <td>8.684</td>
      <td>False</td>
      <td>713173.95</td>
      <td>9</td>
    </tr>
  </tbody>
</table>
<p>6255 rows × 14 columns</p>
</div>



## 2-3. IsHoliday 전처리


```python
# IsHoliday 칼럼의 값을 숫자 형태로 반환하는 함숴
def holiday_to_number(isholiday):
    if isholiday == True:
        number = 1
    else:
        number = 0
    return number

# holiday_to_number 함수 적용해 NumberHoliday 칼럼 만들기
train['NumberHoliday'] = train['IsHoliday'].apply(holiday_to_number)

train
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>id</th>
      <th>Store</th>
      <th>Date</th>
      <th>Temperature</th>
      <th>Fuel_Price</th>
      <th>Promotion1</th>
      <th>Promotion2</th>
      <th>Promotion3</th>
      <th>Promotion4</th>
      <th>Promotion5</th>
      <th>Unemployment</th>
      <th>IsHoliday</th>
      <th>Weekly_Sales</th>
      <th>Month</th>
      <th>NumberHoliday</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>1</td>
      <td>05/02/2010</td>
      <td>42.31</td>
      <td>2.572</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>False</td>
      <td>1643690.90</td>
      <td>2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>1</td>
      <td>12/02/2010</td>
      <td>38.51</td>
      <td>2.548</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>True</td>
      <td>1641957.44</td>
      <td>2</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>1</td>
      <td>19/02/2010</td>
      <td>39.93</td>
      <td>2.514</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>False</td>
      <td>1611968.17</td>
      <td>2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>1</td>
      <td>26/02/2010</td>
      <td>46.63</td>
      <td>2.561</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>False</td>
      <td>1409727.59</td>
      <td>2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>1</td>
      <td>05/03/2010</td>
      <td>46.50</td>
      <td>2.625</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>0.00</td>
      <td>8.106</td>
      <td>False</td>
      <td>1554806.68</td>
      <td>3</td>
      <td>0</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>6250</th>
      <td>6251</td>
      <td>45</td>
      <td>31/08/2012</td>
      <td>75.09</td>
      <td>3.867</td>
      <td>23641.30</td>
      <td>6.00</td>
      <td>92.93</td>
      <td>6988.31</td>
      <td>3992.13</td>
      <td>8.684</td>
      <td>False</td>
      <td>734297.87</td>
      <td>8</td>
      <td>0</td>
    </tr>
    <tr>
      <th>6251</th>
      <td>6252</td>
      <td>45</td>
      <td>07/09/2012</td>
      <td>75.70</td>
      <td>3.911</td>
      <td>11024.45</td>
      <td>12.80</td>
      <td>52.63</td>
      <td>1854.77</td>
      <td>2055.70</td>
      <td>8.684</td>
      <td>True</td>
      <td>766512.66</td>
      <td>9</td>
      <td>1</td>
    </tr>
    <tr>
      <th>6252</th>
      <td>6253</td>
      <td>45</td>
      <td>14/09/2012</td>
      <td>67.87</td>
      <td>3.948</td>
      <td>11407.95</td>
      <td>0.00</td>
      <td>4.30</td>
      <td>3421.72</td>
      <td>5268.92</td>
      <td>8.684</td>
      <td>False</td>
      <td>702238.27</td>
      <td>9</td>
      <td>0</td>
    </tr>
    <tr>
      <th>6253</th>
      <td>6254</td>
      <td>45</td>
      <td>21/09/2012</td>
      <td>65.32</td>
      <td>4.038</td>
      <td>8452.20</td>
      <td>92.28</td>
      <td>63.24</td>
      <td>2376.38</td>
      <td>8670.40</td>
      <td>8.684</td>
      <td>False</td>
      <td>723086.20</td>
      <td>9</td>
      <td>0</td>
    </tr>
    <tr>
      <th>6254</th>
      <td>6255</td>
      <td>45</td>
      <td>28/09/2012</td>
      <td>64.88</td>
      <td>3.997</td>
      <td>4556.61</td>
      <td>20.64</td>
      <td>1.50</td>
      <td>1601.01</td>
      <td>3288.25</td>
      <td>8.684</td>
      <td>False</td>
      <td>713173.95</td>
      <td>9</td>
      <td>0</td>
    </tr>
  </tbody>
</table>
<p>6255 rows × 15 columns</p>
</div>




```python
# test set 적용
test = test.fillna(0)

test['Month'] = test['Date'].apply(get_month)

test['NumberHoliday'] = test['IsHoliday'].apply(holiday_to_number)
```


```python
test
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>id</th>
      <th>Store</th>
      <th>Date</th>
      <th>Temperature</th>
      <th>Fuel_Price</th>
      <th>Promotion1</th>
      <th>Promotion2</th>
      <th>Promotion3</th>
      <th>Promotion4</th>
      <th>Promotion5</th>
      <th>Unemployment</th>
      <th>IsHoliday</th>
      <th>Month</th>
      <th>NumberHoliday</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>1</td>
      <td>05/10/2012</td>
      <td>68.55</td>
      <td>3.617</td>
      <td>8077.89</td>
      <td>0.00</td>
      <td>18.22</td>
      <td>3617.43</td>
      <td>3626.14</td>
      <td>6.573</td>
      <td>False</td>
      <td>10</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>1</td>
      <td>12/10/2012</td>
      <td>62.99</td>
      <td>3.601</td>
      <td>2086.18</td>
      <td>0.00</td>
      <td>8.11</td>
      <td>602.36</td>
      <td>5926.45</td>
      <td>6.573</td>
      <td>False</td>
      <td>10</td>
      <td>0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>1</td>
      <td>19/10/2012</td>
      <td>67.97</td>
      <td>3.594</td>
      <td>950.33</td>
      <td>0.00</td>
      <td>4.93</td>
      <td>80.25</td>
      <td>2312.85</td>
      <td>6.573</td>
      <td>False</td>
      <td>10</td>
      <td>0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>1</td>
      <td>26/10/2012</td>
      <td>69.16</td>
      <td>3.506</td>
      <td>2585.85</td>
      <td>31.75</td>
      <td>6.00</td>
      <td>1057.16</td>
      <td>1305.01</td>
      <td>6.573</td>
      <td>False</td>
      <td>10</td>
      <td>0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>2</td>
      <td>05/10/2012</td>
      <td>70.27</td>
      <td>3.617</td>
      <td>6037.76</td>
      <td>0.00</td>
      <td>10.04</td>
      <td>3027.37</td>
      <td>3853.40</td>
      <td>6.170</td>
      <td>False</td>
      <td>10</td>
      <td>0</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>175</th>
      <td>176</td>
      <td>44</td>
      <td>26/10/2012</td>
      <td>46.97</td>
      <td>3.755</td>
      <td>38.65</td>
      <td>2.61</td>
      <td>0.98</td>
      <td>0.00</td>
      <td>457.74</td>
      <td>5.217</td>
      <td>False</td>
      <td>10</td>
      <td>0</td>
    </tr>
    <tr>
      <th>176</th>
      <td>177</td>
      <td>45</td>
      <td>05/10/2012</td>
      <td>64.89</td>
      <td>3.985</td>
      <td>5046.74</td>
      <td>0.00</td>
      <td>18.82</td>
      <td>2253.43</td>
      <td>2340.01</td>
      <td>8.667</td>
      <td>False</td>
      <td>10</td>
      <td>0</td>
    </tr>
    <tr>
      <th>177</th>
      <td>178</td>
      <td>45</td>
      <td>12/10/2012</td>
      <td>54.47</td>
      <td>4.000</td>
      <td>1956.28</td>
      <td>0.00</td>
      <td>7.89</td>
      <td>599.32</td>
      <td>3990.54</td>
      <td>8.667</td>
      <td>False</td>
      <td>10</td>
      <td>0</td>
    </tr>
    <tr>
      <th>178</th>
      <td>179</td>
      <td>45</td>
      <td>19/10/2012</td>
      <td>56.47</td>
      <td>3.969</td>
      <td>2004.02</td>
      <td>0.00</td>
      <td>3.18</td>
      <td>437.73</td>
      <td>1537.49</td>
      <td>8.667</td>
      <td>False</td>
      <td>10</td>
      <td>0</td>
    </tr>
    <tr>
      <th>179</th>
      <td>180</td>
      <td>45</td>
      <td>26/10/2012</td>
      <td>58.85</td>
      <td>3.882</td>
      <td>4018.91</td>
      <td>58.08</td>
      <td>100.00</td>
      <td>211.94</td>
      <td>858.33</td>
      <td>8.667</td>
      <td>False</td>
      <td>10</td>
      <td>0</td>
    </tr>
  </tbody>
</table>
<p>180 rows × 14 columns</p>
</div>



# 3. Modeling

## 3-1. 모델 선택


```python
from sklearn.linear_model import LinearRegression

# 모델 선언
model = LinearRegression()
```

## 3-2. 학습/예측


```python
# train = train.drop(columns=['id'])
# test = test.drop(columns=['id'])

# train = train.drop(columns=['Date','IsHoliday'])
# test = test.drop(columns=['Date','IsHoliday'])

# x_train = train.drop(columns=['Weekly_Sales'])
y_train = train[['Weekly_Sales']]
```


```python
model.fit(x_train, y_train)
```




    LinearRegression()




```python
prediction = model.predict(test)
print('-------------------예측된 데이터의 상위 10개의 값 확인-------------------\n')
print(prediction[:10])
```

    -------------------예측된 데이터의 상위 10개의 값 확인-------------------
    
    [[1481332.55782774]
     [1461330.0803101 ]
     [1387783.09207984]
     [1389854.53005949]
     [1443978.94274371]
     [1514601.15440918]
     [1416193.17838576]
     [1439121.74595411]
     [1334090.21769006]
     [1324831.19678272]]
    

# 4. 데이콘 제출하기

## 4-1. submission 파일 생성


```python
sample_submission['Weekly_Sales'] = prediction

sample_submission.head()
```




<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>id</th>
      <th>Weekly_Sales</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>1.481333e+06</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>1.461330e+06</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>1.387783e+06</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>1.389855e+06</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>1.443979e+06</td>
    </tr>
  </tbody>
</table>
</div>




```python
sample_submission.to_csv('submission.csv',index = False)
```


```python

```
