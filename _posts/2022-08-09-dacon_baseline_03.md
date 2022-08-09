## I. 데이터 살펴보기

### 1. 데이터 준비


```python
import pandas as pd

train = pd.read_csv('C:/contest/dacon_summer_03/train.csv')
test = pd.read_csv('C:/contest/dacon_summer_03/test.csv')
sample_submission = pd.read_csv('C:/contest/dacon_summer_03/sample_submission.csv')
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
      <th>Age</th>
      <th>TypeofContact</th>
      <th>CityTier</th>
      <th>DurationOfPitch</th>
      <th>Occupation</th>
      <th>Gender</th>
      <th>NumberOfPersonVisiting</th>
      <th>NumberOfFollowups</th>
      <th>ProductPitched</th>
      <th>PreferredPropertyStar</th>
      <th>MaritalStatus</th>
      <th>NumberOfTrips</th>
      <th>Passport</th>
      <th>PitchSatisfactionScore</th>
      <th>OwnCar</th>
      <th>NumberOfChildrenVisiting</th>
      <th>Designation</th>
      <th>MonthlyIncome</th>
      <th>ProdTaken</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>28.0</td>
      <td>Company Invited</td>
      <td>1</td>
      <td>10.0</td>
      <td>Small Business</td>
      <td>Male</td>
      <td>3</td>
      <td>4.0</td>
      <td>Basic</td>
      <td>3.0</td>
      <td>Married</td>
      <td>3.0</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>1.0</td>
      <td>Executive</td>
      <td>20384.0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>34.0</td>
      <td>Self Enquiry</td>
      <td>3</td>
      <td>NaN</td>
      <td>Small Business</td>
      <td>Female</td>
      <td>2</td>
      <td>4.0</td>
      <td>Deluxe</td>
      <td>4.0</td>
      <td>Single</td>
      <td>1.0</td>
      <td>1</td>
      <td>5</td>
      <td>1</td>
      <td>0.0</td>
      <td>Manager</td>
      <td>19599.0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>45.0</td>
      <td>Company Invited</td>
      <td>1</td>
      <td>NaN</td>
      <td>Salaried</td>
      <td>Male</td>
      <td>2</td>
      <td>3.0</td>
      <td>Deluxe</td>
      <td>4.0</td>
      <td>Married</td>
      <td>2.0</td>
      <td>0</td>
      <td>4</td>
      <td>1</td>
      <td>0.0</td>
      <td>Manager</td>
      <td>NaN</td>
      <td>0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>29.0</td>
      <td>Company Invited</td>
      <td>1</td>
      <td>7.0</td>
      <td>Small Business</td>
      <td>Male</td>
      <td>3</td>
      <td>5.0</td>
      <td>Basic</td>
      <td>4.0</td>
      <td>Married</td>
      <td>3.0</td>
      <td>0</td>
      <td>4</td>
      <td>0</td>
      <td>1.0</td>
      <td>Executive</td>
      <td>21274.0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>42.0</td>
      <td>Self Enquiry</td>
      <td>3</td>
      <td>6.0</td>
      <td>Salaried</td>
      <td>Male</td>
      <td>2</td>
      <td>3.0</td>
      <td>Deluxe</td>
      <td>3.0</td>
      <td>Divorced</td>
      <td>2.0</td>
      <td>0</td>
      <td>3</td>
      <td>1</td>
      <td>0.0</td>
      <td>Manager</td>
      <td>19907.0</td>
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
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>1950</th>
      <td>1951</td>
      <td>28.0</td>
      <td>Self Enquiry</td>
      <td>1</td>
      <td>10.0</td>
      <td>Small Business</td>
      <td>Male</td>
      <td>3</td>
      <td>5.0</td>
      <td>Basic</td>
      <td>3.0</td>
      <td>Single</td>
      <td>2.0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>2.0</td>
      <td>Executive</td>
      <td>20723.0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1951</th>
      <td>1952</td>
      <td>41.0</td>
      <td>Self Enquiry</td>
      <td>3</td>
      <td>8.0</td>
      <td>Salaried</td>
      <td>Female</td>
      <td>3</td>
      <td>3.0</td>
      <td>Super Deluxe</td>
      <td>5.0</td>
      <td>Divorced</td>
      <td>1.0</td>
      <td>0</td>
      <td>5</td>
      <td>1</td>
      <td>1.0</td>
      <td>AVP</td>
      <td>31595.0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1952</th>
      <td>1953</td>
      <td>38.0</td>
      <td>Company Invited</td>
      <td>3</td>
      <td>28.0</td>
      <td>Small Business</td>
      <td>Female</td>
      <td>3</td>
      <td>4.0</td>
      <td>Basic</td>
      <td>3.0</td>
      <td>Divorced</td>
      <td>7.0</td>
      <td>0</td>
      <td>2</td>
      <td>1</td>
      <td>2.0</td>
      <td>Executive</td>
      <td>21651.0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1953</th>
      <td>1954</td>
      <td>28.0</td>
      <td>Self Enquiry</td>
      <td>3</td>
      <td>30.0</td>
      <td>Small Business</td>
      <td>Female</td>
      <td>3</td>
      <td>5.0</td>
      <td>Deluxe</td>
      <td>3.0</td>
      <td>Married</td>
      <td>3.0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>2.0</td>
      <td>Manager</td>
      <td>22218.0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1954</th>
      <td>1955</td>
      <td>22.0</td>
      <td>Company Invited</td>
      <td>1</td>
      <td>9.0</td>
      <td>Salaried</td>
      <td>Male</td>
      <td>2</td>
      <td>4.0</td>
      <td>Basic</td>
      <td>3.0</td>
      <td>Divorced</td>
      <td>1.0</td>
      <td>1</td>
      <td>3</td>
      <td>0</td>
      <td>0.0</td>
      <td>Executive</td>
      <td>17853.0</td>
      <td>1</td>
    </tr>
  </tbody>
</table>
<p>1955 rows × 20 columns</p>
</div>



### 2. 데이터 확인


```python
train.info() # Non_Null Count 확인결과, 결측치有
```

    <class 'pandas.core.frame.DataFrame'>
    RangeIndex: 1955 entries, 0 to 1954
    Data columns (total 20 columns):
     #   Column                    Non-Null Count  Dtype  
    ---  ------                    --------------  -----  
     0   id                        1955 non-null   int64  
     1   Age                       1861 non-null   float64
     2   TypeofContact             1945 non-null   object 
     3   CityTier                  1955 non-null   int64  
     4   DurationOfPitch           1853 non-null   float64
     5   Occupation                1955 non-null   object 
     6   Gender                    1955 non-null   object 
     7   NumberOfPersonVisiting    1955 non-null   int64  
     8   NumberOfFollowups         1942 non-null   float64
     9   ProductPitched            1955 non-null   object 
     10  PreferredPropertyStar     1945 non-null   float64
     11  MaritalStatus             1955 non-null   object 
     12  NumberOfTrips             1898 non-null   float64
     13  Passport                  1955 non-null   int64  
     14  PitchSatisfactionScore    1955 non-null   int64  
     15  OwnCar                    1955 non-null   int64  
     16  NumberOfChildrenVisiting  1928 non-null   float64
     17  Designation               1955 non-null   object 
     18  MonthlyIncome             1855 non-null   float64
     19  ProdTaken                 1955 non-null   int64  
    dtypes: float64(7), int64(7), object(6)
    memory usage: 305.6+ KB
    

### 3. 데이터 시각화


```python
import matplotlib.pyplot as plt

# 예측하고자 하는 ProdTaken 값 확인
plt.hist(train.ProdTaken)
plt.show() # 신청하지 않은 사람들(0)이 신청한 사람들(1)에 비해 약 3배 가량 많음
```


    
![output_7_0](https://user-images.githubusercontent.com/110026001/183614190-0896bed5-fc76-4837-bff5-665554dd3ae0.png)
    


## II. 데이터 전처리

### 1. 결측치(NA) 처리


```python
# 결측치 얼마나 있는지 확인
train.isna().sum()
```




    id                            0
    Age                          94
    TypeofContact                10
    CityTier                      0
    DurationOfPitch             102
    Occupation                    0
    Gender                        0
    NumberOfPersonVisiting        0
    NumberOfFollowups            13
    ProductPitched                0
    PreferredPropertyStar        10
    MaritalStatus                 0
    NumberOfTrips                57
    Passport                      0
    PitchSatisfactionScore        0
    OwnCar                        0
    NumberOfChildrenVisiting     27
    Designation                   0
    MonthlyIncome               100
    ProdTaken                     0
    dtype: int64




```python
# 결측치 처리 함수 (숫자형-0, 문자형-Unknown)
def handle_na(data):
    temp = data.copy()
    global value # 없으면 오류(UnboundLocalError)
    for col, dtype in temp.dtypes.items():
        if dtype == 'object': 
            value = 'Unknown'
        elif dtype == int or dtype == float:
            value = 0
        temp.loc[:,col] = temp[col].fillna(value)
    return temp

train_nona = handle_na(train)

train_nona.isna().sum()
```




    id                          0
    Age                         0
    TypeofContact               0
    CityTier                    0
    DurationOfPitch             0
    Occupation                  0
    Gender                      0
    NumberOfPersonVisiting      0
    NumberOfFollowups           0
    ProductPitched              0
    PreferredPropertyStar       0
    MaritalStatus               0
    NumberOfTrips               0
    Passport                    0
    PitchSatisfactionScore      0
    OwnCar                      0
    NumberOfChildrenVisiting    0
    Designation                 0
    MonthlyIncome               0
    ProdTaken                   0
    dtype: int64



### 2. 문자형 변수 전처리

분석을 위해 문자를 숫자로 변환하기


```python
object_columns = train_nona.columns[train_nona.dtypes == 'object']
print('object 칼럼은 다음과 같습니다 : ', list(object_columns))

# 문자형 칼럼 모음
train_nona[object_columns]
```

    object 칼럼은 다음과 같습니다 :  ['TypeofContact', 'Occupation', 'Gender', 'ProductPitched', 'MaritalStatus', 'Designation']
    




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
      <th>TypeofContact</th>
      <th>Occupation</th>
      <th>Gender</th>
      <th>ProductPitched</th>
      <th>MaritalStatus</th>
      <th>Designation</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>Company Invited</td>
      <td>Small Business</td>
      <td>Male</td>
      <td>Basic</td>
      <td>Married</td>
      <td>Executive</td>
    </tr>
    <tr>
      <th>1</th>
      <td>Self Enquiry</td>
      <td>Small Business</td>
      <td>Female</td>
      <td>Deluxe</td>
      <td>Single</td>
      <td>Manager</td>
    </tr>
    <tr>
      <th>2</th>
      <td>Company Invited</td>
      <td>Salaried</td>
      <td>Male</td>
      <td>Deluxe</td>
      <td>Married</td>
      <td>Manager</td>
    </tr>
    <tr>
      <th>3</th>
      <td>Company Invited</td>
      <td>Small Business</td>
      <td>Male</td>
      <td>Basic</td>
      <td>Married</td>
      <td>Executive</td>
    </tr>
    <tr>
      <th>4</th>
      <td>Self Enquiry</td>
      <td>Salaried</td>
      <td>Male</td>
      <td>Deluxe</td>
      <td>Divorced</td>
      <td>Manager</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>1950</th>
      <td>Self Enquiry</td>
      <td>Small Business</td>
      <td>Male</td>
      <td>Basic</td>
      <td>Single</td>
      <td>Executive</td>
    </tr>
    <tr>
      <th>1951</th>
      <td>Self Enquiry</td>
      <td>Salaried</td>
      <td>Female</td>
      <td>Super Deluxe</td>
      <td>Divorced</td>
      <td>AVP</td>
    </tr>
    <tr>
      <th>1952</th>
      <td>Company Invited</td>
      <td>Small Business</td>
      <td>Female</td>
      <td>Basic</td>
      <td>Divorced</td>
      <td>Executive</td>
    </tr>
    <tr>
      <th>1953</th>
      <td>Self Enquiry</td>
      <td>Small Business</td>
      <td>Female</td>
      <td>Deluxe</td>
      <td>Married</td>
      <td>Manager</td>
    </tr>
    <tr>
      <th>1954</th>
      <td>Company Invited</td>
      <td>Salaried</td>
      <td>Male</td>
      <td>Basic</td>
      <td>Divorced</td>
      <td>Executive</td>
    </tr>
  </tbody>
</table>
<p>1955 rows × 6 columns</p>
</div>




```python
from sklearn.preprocessing import LabelEncoder

encoder = LabelEncoder()

# LabelEncoder 학습
encoder.fit(train_nona['TypeofContact'])

# 학습된 encoder 사용하여 문자형 변수(ex.TypeofContact) 숫자로 변환
encoder.transform(train_nona['TypeofContact'])
```




    array([0, 1, 0, ..., 0, 1, 0])




```python
train_enc = train_nona.copy()

# 모든 문자형 변수에 대해 encoder 적용
for o_col in object_columns:
    encoder = LabelEncoder()
    encoder.fit(train_enc[o_col])
    train_enc[o_col] = encoder.transform(train_enc[o_col])
    
train_enc
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
      <th>Age</th>
      <th>TypeofContact</th>
      <th>CityTier</th>
      <th>DurationOfPitch</th>
      <th>Occupation</th>
      <th>Gender</th>
      <th>NumberOfPersonVisiting</th>
      <th>NumberOfFollowups</th>
      <th>ProductPitched</th>
      <th>PreferredPropertyStar</th>
      <th>MaritalStatus</th>
      <th>NumberOfTrips</th>
      <th>Passport</th>
      <th>PitchSatisfactionScore</th>
      <th>OwnCar</th>
      <th>NumberOfChildrenVisiting</th>
      <th>Designation</th>
      <th>MonthlyIncome</th>
      <th>ProdTaken</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>28.0</td>
      <td>0</td>
      <td>1</td>
      <td>10.0</td>
      <td>3</td>
      <td>2</td>
      <td>3</td>
      <td>4.0</td>
      <td>0</td>
      <td>3.0</td>
      <td>1</td>
      <td>3.0</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>1.0</td>
      <td>1</td>
      <td>20384.0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>34.0</td>
      <td>1</td>
      <td>3</td>
      <td>0.0</td>
      <td>3</td>
      <td>1</td>
      <td>2</td>
      <td>4.0</td>
      <td>1</td>
      <td>4.0</td>
      <td>2</td>
      <td>1.0</td>
      <td>1</td>
      <td>5</td>
      <td>1</td>
      <td>0.0</td>
      <td>2</td>
      <td>19599.0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>45.0</td>
      <td>0</td>
      <td>1</td>
      <td>0.0</td>
      <td>2</td>
      <td>2</td>
      <td>2</td>
      <td>3.0</td>
      <td>1</td>
      <td>4.0</td>
      <td>1</td>
      <td>2.0</td>
      <td>0</td>
      <td>4</td>
      <td>1</td>
      <td>0.0</td>
      <td>2</td>
      <td>0.0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>29.0</td>
      <td>0</td>
      <td>1</td>
      <td>7.0</td>
      <td>3</td>
      <td>2</td>
      <td>3</td>
      <td>5.0</td>
      <td>0</td>
      <td>4.0</td>
      <td>1</td>
      <td>3.0</td>
      <td>0</td>
      <td>4</td>
      <td>0</td>
      <td>1.0</td>
      <td>1</td>
      <td>21274.0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>42.0</td>
      <td>1</td>
      <td>3</td>
      <td>6.0</td>
      <td>2</td>
      <td>2</td>
      <td>2</td>
      <td>3.0</td>
      <td>1</td>
      <td>3.0</td>
      <td>0</td>
      <td>2.0</td>
      <td>0</td>
      <td>3</td>
      <td>1</td>
      <td>0.0</td>
      <td>2</td>
      <td>19907.0</td>
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
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>1950</th>
      <td>1951</td>
      <td>28.0</td>
      <td>1</td>
      <td>1</td>
      <td>10.0</td>
      <td>3</td>
      <td>2</td>
      <td>3</td>
      <td>5.0</td>
      <td>0</td>
      <td>3.0</td>
      <td>2</td>
      <td>2.0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>2.0</td>
      <td>1</td>
      <td>20723.0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1951</th>
      <td>1952</td>
      <td>41.0</td>
      <td>1</td>
      <td>3</td>
      <td>8.0</td>
      <td>2</td>
      <td>1</td>
      <td>3</td>
      <td>3.0</td>
      <td>4</td>
      <td>5.0</td>
      <td>0</td>
      <td>1.0</td>
      <td>0</td>
      <td>5</td>
      <td>1</td>
      <td>1.0</td>
      <td>0</td>
      <td>31595.0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1952</th>
      <td>1953</td>
      <td>38.0</td>
      <td>0</td>
      <td>3</td>
      <td>28.0</td>
      <td>3</td>
      <td>1</td>
      <td>3</td>
      <td>4.0</td>
      <td>0</td>
      <td>3.0</td>
      <td>0</td>
      <td>7.0</td>
      <td>0</td>
      <td>2</td>
      <td>1</td>
      <td>2.0</td>
      <td>1</td>
      <td>21651.0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1953</th>
      <td>1954</td>
      <td>28.0</td>
      <td>1</td>
      <td>3</td>
      <td>30.0</td>
      <td>3</td>
      <td>1</td>
      <td>3</td>
      <td>5.0</td>
      <td>1</td>
      <td>3.0</td>
      <td>1</td>
      <td>3.0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>2.0</td>
      <td>2</td>
      <td>22218.0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1954</th>
      <td>1955</td>
      <td>22.0</td>
      <td>0</td>
      <td>1</td>
      <td>9.0</td>
      <td>2</td>
      <td>2</td>
      <td>2</td>
      <td>4.0</td>
      <td>0</td>
      <td>3.0</td>
      <td>0</td>
      <td>1.0</td>
      <td>1</td>
      <td>3</td>
      <td>0</td>
      <td>0.0</td>
      <td>1</td>
      <td>17853.0</td>
      <td>1</td>
    </tr>
  </tbody>
</table>
<p>1955 rows × 20 columns</p>
</div>




```python
# test set에 같은 내용 적용

test = handle_na(test)

for o_col in object_columns:
    encoder = LabelEncoder()
    
    encoder.fit(train_nona[o_col])
    test[o_col] = encoder.transform(test[o_col])
    
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
      <th>Age</th>
      <th>TypeofContact</th>
      <th>CityTier</th>
      <th>DurationOfPitch</th>
      <th>Occupation</th>
      <th>Gender</th>
      <th>NumberOfPersonVisiting</th>
      <th>NumberOfFollowups</th>
      <th>ProductPitched</th>
      <th>PreferredPropertyStar</th>
      <th>MaritalStatus</th>
      <th>NumberOfTrips</th>
      <th>Passport</th>
      <th>PitchSatisfactionScore</th>
      <th>OwnCar</th>
      <th>NumberOfChildrenVisiting</th>
      <th>Designation</th>
      <th>MonthlyIncome</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>32.0</td>
      <td>0</td>
      <td>3</td>
      <td>0.0</td>
      <td>3</td>
      <td>2</td>
      <td>2</td>
      <td>5.0</td>
      <td>1</td>
      <td>3.0</td>
      <td>1</td>
      <td>1.0</td>
      <td>0</td>
      <td>2</td>
      <td>0</td>
      <td>1.0</td>
      <td>2</td>
      <td>19668.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>46.0</td>
      <td>1</td>
      <td>2</td>
      <td>11.0</td>
      <td>3</td>
      <td>2</td>
      <td>3</td>
      <td>0.0</td>
      <td>1</td>
      <td>4.0</td>
      <td>1</td>
      <td>1.0</td>
      <td>1</td>
      <td>5</td>
      <td>0</td>
      <td>1.0</td>
      <td>2</td>
      <td>20021.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>37.0</td>
      <td>1</td>
      <td>3</td>
      <td>22.0</td>
      <td>3</td>
      <td>2</td>
      <td>3</td>
      <td>4.0</td>
      <td>1</td>
      <td>3.0</td>
      <td>1</td>
      <td>5.0</td>
      <td>0</td>
      <td>5</td>
      <td>1</td>
      <td>0.0</td>
      <td>2</td>
      <td>21334.0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>43.0</td>
      <td>1</td>
      <td>1</td>
      <td>36.0</td>
      <td>3</td>
      <td>2</td>
      <td>3</td>
      <td>6.0</td>
      <td>1</td>
      <td>3.0</td>
      <td>3</td>
      <td>6.0</td>
      <td>0</td>
      <td>3</td>
      <td>1</td>
      <td>2.0</td>
      <td>2</td>
      <td>22950.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>25.0</td>
      <td>1</td>
      <td>3</td>
      <td>7.0</td>
      <td>1</td>
      <td>1</td>
      <td>4</td>
      <td>4.0</td>
      <td>0</td>
      <td>4.0</td>
      <td>3</td>
      <td>3.0</td>
      <td>1</td>
      <td>4</td>
      <td>1</td>
      <td>3.0</td>
      <td>1</td>
      <td>21880.0</td>
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
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>2928</th>
      <td>2929</td>
      <td>54.0</td>
      <td>1</td>
      <td>1</td>
      <td>6.0</td>
      <td>3</td>
      <td>1</td>
      <td>2</td>
      <td>3.0</td>
      <td>4</td>
      <td>3.0</td>
      <td>2</td>
      <td>7.0</td>
      <td>0</td>
      <td>4</td>
      <td>1</td>
      <td>1.0</td>
      <td>0</td>
      <td>32328.0</td>
    </tr>
    <tr>
      <th>2929</th>
      <td>2930</td>
      <td>33.0</td>
      <td>1</td>
      <td>1</td>
      <td>9.0</td>
      <td>3</td>
      <td>0</td>
      <td>4</td>
      <td>2.0</td>
      <td>1</td>
      <td>3.0</td>
      <td>3</td>
      <td>2.0</td>
      <td>0</td>
      <td>3</td>
      <td>0</td>
      <td>1.0</td>
      <td>2</td>
      <td>23733.0</td>
    </tr>
    <tr>
      <th>2930</th>
      <td>2931</td>
      <td>33.0</td>
      <td>0</td>
      <td>1</td>
      <td>31.0</td>
      <td>2</td>
      <td>2</td>
      <td>4</td>
      <td>4.0</td>
      <td>1</td>
      <td>3.0</td>
      <td>0</td>
      <td>3.0</td>
      <td>0</td>
      <td>4</td>
      <td>1</td>
      <td>1.0</td>
      <td>2</td>
      <td>23987.0</td>
    </tr>
    <tr>
      <th>2931</th>
      <td>2932</td>
      <td>26.0</td>
      <td>1</td>
      <td>1</td>
      <td>9.0</td>
      <td>3</td>
      <td>2</td>
      <td>4</td>
      <td>2.0</td>
      <td>0</td>
      <td>5.0</td>
      <td>3</td>
      <td>2.0</td>
      <td>0</td>
      <td>2</td>
      <td>1</td>
      <td>3.0</td>
      <td>1</td>
      <td>22102.0</td>
    </tr>
    <tr>
      <th>2932</th>
      <td>2933</td>
      <td>31.0</td>
      <td>1</td>
      <td>1</td>
      <td>9.0</td>
      <td>2</td>
      <td>2</td>
      <td>3</td>
      <td>5.0</td>
      <td>1</td>
      <td>3.0</td>
      <td>0</td>
      <td>3.0</td>
      <td>0</td>
      <td>4</td>
      <td>1</td>
      <td>1.0</td>
      <td>2</td>
      <td>22830.0</td>
    </tr>
  </tbody>
</table>
<p>2933 rows × 19 columns</p>
</div>



## III. Modeling

### 1. 모델 선택


```python
from sklearn.linear_model import LogisticRegression

model = LogisticRegression()
```

### 2. 학습/예측


```python
# 분석 의미 없는 칼럼 제거
train = train_enc.drop(columns=['id'])
test = test.drop(columns=['id'])

# 학습에 사용할 정보와 예측하고자 하는 정보 분리
x_train = train.drop(columns=['ProdTaken'])
y_train = train[['ProdTaken']]
```


```python
model.fit(x_train,y_train)
```

    C:\Users\naaye\anaconda3\lib\site-packages\sklearn\utils\validation.py:993: DataConversionWarning: A column-vector y was passed when a 1d array was expected. Please change the shape of y to (n_samples, ), for example using ravel().
      y = column_or_1d(y, warn=True)
    




    LogisticRegression()




```python
# 학습된 모델 이용해 결과값 예측
prediction = model.predict(test)
print('----------------예측된 데이터의 상위 10개의 값 확인----------------\n')
print(prediction[:10])
```

    ----------------예측된 데이터의 상위 10개의 값 확인----------------
    
    [0 0 0 0 1 0 0 0 0 0]
    

## IV. 데이콘 제출하기

### 1. submission 파일 생성


```python
sample_submission['ProdTaken'] = prediction

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
      <th>ProdTaken</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>1</td>
    </tr>
  </tbody>
</table>
</div>




```python
sample_submission.to_csv('submission.csv',index = False)
```
