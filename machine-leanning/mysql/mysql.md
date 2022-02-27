# _Setup enviroment_

## 1. [DBeaver community](#1)

## 2. [Setup Mysql in linux](#2)

## 3. [Commands mqsql](#3)
### 3.1 [Set or Change Password](#31)
### 3.2 [View Databases](#32)
### 3.3 [Create a Database](#33)
### 3.4 [Select a Database](#34)
### 3.5 [Create a Table](#35)
### 3.6 [View Tables](#36)
### 3.7 [View Table Structure](#37)
### 3.8 [Insert Data](#38)
### 3.9 [View Table Data](#39)
### 3.10 [Delete Data from Table](#310)
### 3.11 [Delete a Table](#311)
### 3.12 [Delete a Database](#312)

## 4. [Command sql](#4)
### 4.1 [SQL - Insert Query](#41)
### 4.2 [SQL - Select Query](#42)
### 4.3 [SQL - Where Clause](#43)
### 4.4 [SQL - AND & OR Clauses](#44)
### 4.5 [SQL - Update Query](#45)
### 4.6 [SQL - Delete Query](#46)
### 4.7 [SQL - Like Clause](#47)
### 4.8 [SQL - Top Clause](#48)
### 4.9 [SQL - Order By](#49)
### 4.10 [SQL - Group By](#410)
### 4.11 [SQL - Distinct Keyword](#411)
### 4.12 [SQL - Sorting Results](#412)
### 4.13 [SQL - Constraints](#413)
### 4.14 [SQL - Using Joins](#414)
### 4.15 [SQL - Unions Clause](#415)
### 4.16 [SQL - NULL Values](#416)
### 4.17 [SQL - Alias Syntax](#417)
### 4.18 [SQL - Indexes](#418)
### 4.19 [SQL - Alter Command](#419)
### 4.20 [SQL - Truncate Table](#421)
### 4.21 [SQL - Using Views](#421)
### 4.22 [SQL - Having Clause](#422)
### 4.23 [SQL - Transactions](#423)
### 4.24 [SQL - Wildcards](#424)
### 4.25 [SQL - Date Functions](#425)
### 4.26 [QL - Temporary Tables](#426)
### 4.27 [SQL - Clone Tables](#427)
### 4.28 [SQL - Sub Queries](#428)
### 4.29 [SQL - Using Sequences](#429)
### 4.30 [SQL - Handling Duplicates](#430)
### 4.31 [SQL - Injection](#431)
#

## 1. <a id="1"></a>DBeaver community

**On your command terminal run the below command:**

```sh
  > wget https://dbeaver.io/files/dbeaver-ce_latest_amd64.deb
```

**Run the installer:**

```sh
  > sudo dpkg -i dbeaver-ce_latest_amd64.deb
```

**If you get an error:**

```sh
  dpkg: error processing package dbeaver-ce (--install):
  dependency problems - leaving unconfigured
  Processing triggers for desktop-file-utils (0.24-1ubuntu3) ...
  Processing triggers for gnome-menus (3.36.0-1ubuntu1) ...
  Processing triggers for mime-support (3.64ubuntu1) ...
  Errors were encountered while processing:
  dbeaver-ce
```

**Then run this command:**

```sh
  > sudo apt install -f
```

## 2. <a id="2"></a> Setup Mysql in linux

**Reset mysql**

```sh
  > service mysql restart
```

**Open root user**

```sh
  > sudo mysql
```

**making a new user within the MySQL shell:**

```sh
  mysql> CREATE USER 'newuser'@'localhost' IDENTIFIED BY 'password';
```

**Access to the information**

```sh
  mysql> GRANT ALL PRIVILEGES ON * . * TO 'newuser'@'localhost';
```

**Always be sure to reload all the privileges**

```sh
  mysql> FLUSH PRIVILEGES;
```

**Ophen mysql**

```sh
  **mysql -u duonghd -h localhost --password=duongdh'
```

Grant Different User Permissions**

Here is a short list of other common possible permissions that users can enjoy.

- ALL PRIVILEGES- as we saw previously, this would allow a MySQL user full access to a designated database (or if no database is selected, global access across the system)

- CREATE- allows them to create new tables or databases

- DROP- allows them to them to delete tables or databases

- DELETE- allows them to delete rows from tables

- INSERT- allows them to insert rows into tables

- SELECT- allows them to use the SELECT command to read through databases

- UPDATE- allow them to update table rows

- GRANT OPTION- allows them to grant or remove other users’ privileges

To provide a specific user with a permission, you can use this framework:

```sh
  mysql> GRANT type_of_permission ON database_name.table_name TO 'username'@'localhost';
```

If you want to give them access to any database or to any table, make sure to put an asterisk (*) in the place of the database name or table name.

Each time you update or change a permission be sure to use the Flush Privileges command.

If you need to revoke a permission, the structure is almost identical to granting it:

```sh
  mysql> REVOKE type_of_permission ON database_name.table_name FROM 'username'@'localhost';
```

Note that when revoking permissions, the syntax requires that you use FROM, instead of TO as we used when granting permissions.

You can review a user’s current permissions by running the following:

```sh
  mysql> SHOW GRANTS FOR 'username'@'localhost';
```

Just as you can delete databases with DROP, you can use DROP to delete a user altogether:

```sh
  mysql> DROP USER 'username'@'localhost';
```

Connect to MySQL this command in terminal:

```sh
  mysql -u [username] -p
```

## 3. <a id="3"></a> Commands mqsql

### 3.1 <a id="31"></a> Set or Change Password

To set or change the password for any MySQL database user, issue the following command:

```sh
  mysql> ALTER USER 'user_name'@'localhost' IDENTIFIED BY 'new_password';
```

Replace the user_name and new_password with your username and desired password. For example:

```sh
  mysql> ALTER USER 'root'@'localhost' IDENTIFIED BY '12345678';
```

### 3.2 <a id="32"></a> View Databases

In MySQL, you can view the list of databases under the user’s granted privileges by running the simple command stated below:

```sh
  mysql> SHOW DATABASES;
```

### 3.3 <a id="33"></a> Create a Database

You can create a database by issuing the following command in the MySQL shell:

```sh
  mysql> CREATE DATABASE IF NOT EXISTS database_name;
```

The above statement will not create a database if there already exists a database with the name that has been provided. For example:

```sh
  mysql> CREATE DATABASE IF NOT EXISTS db1;
```

### 3.4 <a id="34"></a> Select a Database

You can use any of the listed databases by running the following command in the MySQL shell:

```sh
  mysql> USE DATABASE db1;
```

### 3.5 <a id="35"></a> Create a Table

A table can be created by using the CRETE TABLE command and defining the column names and their types in the parentheses, as follows:

```sh
  mysql> CREATE TABLE IF NOT EXISTS tb1 (
  col1 INT,
  col2 VARCHAR(20),
  ...
  PRIMARY KEY (col1)
  );
```

In this creation query:

- tb1 is the name of the table
- col1, col2 are the names of the columns in the tb1 table
- INT and VARCHAR are the datatypes of the specified columns
- col1 is defined as the primary key

### 3.6 <a id="36"></a> View Tables

To list all the tables in the present database, run the simple SHOW TABLES command in the MySQL shell.

```sh
  mysql> SHOW TABLES;
```

### 3.7 <a id="37"></a> View Table Structure

The structure of the table, including column names, their types, and their default values, can be seen by running the DESC command.

```sh
  mysql> DESC tb1;
```

### 3.8 <a id="38"></a> Insert Data

Data can be inserted into the table by providing the column names into which you want to insert data, as well as the data or values, using the following syntax:

```sh
  mysql> INSERT INTO tb1(col1, col2)
  VALUES (1, "value1"),
  (2, "value2");
```

### 3.9 <a id="39"></a> View Table Data

The SELECT statement is used to view the data in a table. You can either provide the asterisk symbol (*) to select all the columns, or you can provide the specific columns that you want to view.

```sh
  mysql> SELECT * FROM tb1;
  mysql> SELECT col2 FROM tb1;
```

### 3.10 <a id="310"></a> Delete Data from Table

To delete a row from a table, provide the table name to the DELETE FROM command, along with the WHERE conditional clause.

```sh
  mysql> DELETE FROM tb1 WHERE col1 = 1;
```

### 3.11 <a id="311"></a> Delete a Table

Deleting a table is as easy as saying it. You can delete any table in the present database by running the statement given below.

```sh
  mysql> DROP TABLE tb1;
```

### 3.12 <a id="312"></a> Delete a Database

Deleting or dropping a database is the same as deleting a table in MySQL. Simply use the DROP DATABASE command with the database name.

```sh
  mysql> DROP DATABASE IF EXISTS db1;
```

## 4. <a id="4"></a> Command sql

### 4.1 <a id="41"></a>  SQL - Insert Query

The SQL **INSERT INTO** Statement is used to add new rows of data to a table in the database.

There are two basic syntaxes of the INSERT INTO statement which are shown below.

```sh
  INSERT INTO TABLE_NAME (column1, column2, column3,...columnN)  
  VALUES (value1, value2, value3,...valueN);
```

Here, column1, column2, column3,...columnN are the names of the columns in the table into which you want to insert the data.

You may not need to specify the column(s) name in the SQL query if you are adding values for all the columns of the table. But make sure the order of the values is in the same order as the columns in the table.

The SQL **INSERT INTO** syntax will be as follows −

```sh
  INSERT INTO TABLE_NAME VALUES (value1,value2,value3,...valueN);
```

You can create a record in the CUSTOMERS table by using the second syntax as shown below.

```sh
  INSERT INTO CUSTOMERS 
  VALUES (7, 'Muffy', 24, 'Indore', 10000.00 );
```

**Populate one table using another table**

You can populate the data into a table through the select statement over another table; provided the other table has a set of fields, which are required to populate the first table.

Here is the syntax −

```sh
  INSERT INTO first_table_name [(column1, column2, ... columnN)] 
  SELECT column1, column2, ...columnN 
  FROM second_table_name
  [WHERE condition];
```

### 4.2 <a id="42"></a>  SQL - Select Query

The SQL SELECT statement is used to fetch the data from a database table which returns this data in the form of a result table. These result tables are called result-sets.

**Syntax**

The basic syntax of the SELECT statement is as follows −

```sh
  SELECT column1, column2, columnN FROM table_name;
```

Here, column1, column2... are the fields of a table whose values you want to fetch. If you want to fetch all the fields available in the field, then you can use the following syntax.

```sh
  SELECT * FROM table_name;
```

The following code is an example, which would fetch the ID, Name and Salary fields of the customers available in CUSTOMERS table.

```sh
  SQL> SELECT ID, NAME, SALARY FROM CUSTOMERS;
```

This would produce the following result −

```sh
  +----+----------+----------+
  | ID | NAME     | SALARY   |
  +----+----------+----------+
  |  1 | Ramesh   |  2000.00 |
  |  2 | Khilan   |  1500.00 |
  |  3 | kaushik  |  2000.00 |
  |  4 | Chaitali |  6500.00 |
  |  5 | Hardik   |  8500.00 |
  |  6 | Komal    |  4500.00 |
  |  7 | Muffy    | 10000.00 |
  +----+----------+----------+
```

If you want to fetch all the fields of the CUSTOMERS table, then you should use the following query.

```sh
  SQL> SELECT * FROM CUSTOMERS;
```

This would produce the result as shown below.

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

### 4.3 <a id="43"></a>  SQL - Where Clause

The SQL WHERE clause is used to specify a condition while fetching the data from a single table or by joining with multiple tables. If the given condition is satisfied, then only it returns a specific value from the table. You should use the WHERE clause to filter the records and fetching only the necessary records.

The WHERE clause is not only used in the SELECT statement, but it is also used in the UPDATE, DELETE statement, etc., which we would examine in the subsequent chapters.

**Syntax**

The basic syntax of the SELECT statement with the WHERE clause is as shown below.

```sh
  SELECT column1, column2, columnN 
  FROM table_name
  WHERE [condition]
```

You can specify a condition using the comparison or logical operators like >, <, =, LIKE, NOT, etc. The following examples would make this concept clear.

**Example**

Consider the CUSTOMERS table having the following records −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

The following code is an example which would fetch the ID, Name and Salary fields from the CUSTOMERS table, where the salary is greater than 2000 −

```sh
  SQL> SELECT ID, NAME, SALARY 
  FROM CUSTOMERS
  WHERE SALARY > 2000;
```

This would produce the following result −

```sh
  +----+----------+----------+
  | ID | NAME     | SALARY   |
  +----+----------+----------+
  |  4 | Chaitali |  6500.00 |
  |  5 | Hardik   |  8500.00 |
  |  6 | Komal    |  4500.00 |
  |  7 | Muffy    | 10000.00 |
  +----+----------+----------+
```

The following query is an example, which would fetch the ID, Name and Salary fields from the CUSTOMERS table for a customer with the name Hardik.

Here, it is important to note that all the strings should be given inside single quotes (''). Whereas, numeric values should be given without any quote as in the above example.

```sh
  SQL> SELECT ID, NAME, SALARY 
  FROM CUSTOMERS
  WHERE NAME = 'Hardik';
```

This would produce the following result −

```sh
  +----+----------+----------+
  | ID | NAME     | SALARY   |
  +----+----------+----------+
  |  5 | Hardik   |  8500.00 |
  +----+----------+----------+
```

### 4.4 <a id="44"></a>  SQL - AND & OR Clauses

The SQL AND & OR operators are used to combine multiple conditions to narrow data in an SQL statement. These two operators are called as the conjunctive operators.

These operators provide a means to make multiple comparisons with different operators in the same SQL statement.

**The AND Operator**

The AND operator allows the existence of multiple conditions in an SQL statement's WHERE clause.

**Syntax**

The basic syntax of the AND operator with a WHERE clause is as follows −

```sh
  SELECT column1, column2, columnN 
  FROM table_name
  WHERE [condition1] AND [condition2]...AND [conditionN];
```

You can combine N number of conditions using the AND operator. For an action to be taken by the SQL statement, whether it be a transaction or a query, all conditions separated by the AND must be TRUE.

**Example**

Consider the CUSTOMERS table having the following records −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+----``-+-----------+----------+
```

Following is an example, which would fetch the ID, Name and Salary fields from the CUSTOMERS table, where the salary is greater than 2000 and the age is less than 25 years −

```sh
  SQL> SELECT ID, NAME, SALARY 
  FROM CUSTOMERS
  WHERE SALARY > 2000 AND age < 25;
```

This would produce the following result −

```sh
  +----+-------+----------+
  | ID | NAME  | SALARY   |
  +----+-------+----------+
  |  6 | Komal |  4500.00 |
  |  7 | Muffy | 10000.00 |
  +----+-------+----------+
```

**The OR Operator**

The OR operator is used to combine multiple conditions in an SQL statement's WHERE clause.

**Syntax**

The basic syntax of the OR operator with a WHERE clause is as follows −

```sh
  SELECT column1, column2, columnN 
  FROM table_name
  WHERE [condition1] OR [condition2]...OR [conditionN]
```

You can combine N number of conditions using the OR operator. For an action to be taken by the SQL statement, whether it be a transaction or query, the only any ONE of the conditions separated by the OR must be TRUE.

**Example**

Consider the CUSTOMERS table having the following records −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

The following code block hasa query, which would fetch the ID, Name and Salary fields from the CUSTOMERS table, where the salary is greater than 2000 OR the age is less than 25 years.

```sh
  SQL> SELECT ID, NAME, SALARY 
  FROM CUSTOMERS
  WHERE SALARY > 2000 OR age < 25;
```

This would produce the following result −

```sh
  +----+----------+----------+
  | ID | NAME     | SALARY   |
  +----+----------+----------+
  |  3 | kaushik  |  2000.00 |
  |  4 | Chaitali |  6500.00 |
  |  5 | Hardik   |  8500.00 |
  |  6 | Komal    |  4500.00 |
  |  7 | Muffy    | 10000.00 |
  +----+----------+----------+
```

### 4.5 <a id="45"></a>  SQL - Update Query

The SQL UPDATE Query is used to modify the existing records in a table. You can use the WHERE clause with the UPDATE query to update the selected rows, otherwise all the rows would be affected.

**Syntax**

The basic syntax of the UPDATE query with a WHERE clause is as follows −

```sh
  UPDATE table_name
  SET column1 = value1, column2 = value2...., columnN = valueN
  WHERE [condition];
```

You can combine N number of conditions using the AND or the OR operators.

**Example**

Consider the CUSTOMERS table having the following records −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

The following query will update the ADDRESS for a customer whose ID number is 6 in the table.

```sh
  SQL> UPDATE CUSTOMERS
  SET ADDRESS = 'Pune'
  WHERE ID = 6;
```

Now, the CUSTOMERS table would have the following records −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | Pune      |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

If you want to modify all the ADDRESS and the SALARY column values in the CUSTOMERS table, you do not need to use the WHERE clause as the UPDATE query would be enough as shown in the following code block.

```SH
  SQL> UPDATE CUSTOMERS
  SET ADDRESS = 'Pune', SALARY = 1000.00;
```

Now, CUSTOMERS table would have the following records −

```sh
  +----+----------+-----+---------+---------+
  | ID | NAME     | AGE | ADDRESS | SALARY  |
  +----+----------+-----+---------+---------+
  |  1 | Ramesh   |  32 | Pune    | 1000.00 |
  |  2 | Khilan   |  25 | Pune    | 1000.00 |
  |  3 | kaushik  |  23 | Pune    | 1000.00 |
  |  4 | Chaitali |  25 | Pune    | 1000.00 |
  |  5 | Hardik   |  27 | Pune    | 1000.00 |
  |  6 | Komal    |  22 | Pune    | 1000.00 |
  |  7 | Muffy    |  24 | Pune    | 1000.00 |
  +----+----------+-----+---------+---------+
```

### 4.6 <a id="46"></a>  SQL - Delete Query

The SQL DELETE Query is used to delete the existing records from a table.

You can use the WHERE clause with a DELETE query to delete the selected rows, otherwise all the records would be deleted.

**Syntax**

The basic syntax of the DELETE query with the WHERE clause is as follows −

```sh
  DELETE FROM table_name
  WHERE [condition];
```

You can combine N number of conditions using AND or OR operators.

**Example**

Consider the CUSTOMERS table having the following records −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

The following code has a query, which will DELETE a customer, whose ID is 6.

```sh
  SQL> DELETE FROM CUSTOMERS
  WHERE ID = 6;
```

Now, the CUSTOMERS table would have the following records.

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

If you want to DELETE all the records from the CUSTOMERS table, you do not need to use the WHERE clause and the DELETE query would be as follows −

```sh
  SQL> DELETE FROM CUSTOMERS;
```

### 4.7 <a id="47"></a>  SQL - Like Clause

The SQL LIKE clause is used to compare a value to similar values using wildcard operators. There are two wildcards used in conjunction with the LIKE operator.

The percent sign (%)
The underscore (_)
The percent sign represents zero, one or multiple characters. The underscore represents a single number or character. These symbols can be used in combinations.

**Syntax**

The basic syntax of % and _ is as follows −

```sh
  SELECT FROM table_name
  WHERE column LIKE 'XXXX%'

  or 

  SELECT FROM table_name
  WHERE column LIKE '%XXXX%'

  or

  SELECT FROM table_name
  WHERE column LIKE 'XXXX_'

  or

  SELECT FROM table_name
  WHERE column LIKE '_XXXX'

  or

  SELECT FROM table_name
  WHERE column LIKE '_XXXX_'
```

You can combine N number of conditions using AND or OR operators. Here, XXXX could be any numeric or string value.

**Example**

The following table has a few examples showing the WHERE part having different LIKE clause with '%' and '_' operators −

| Sr.No.  | Statement & Description
| -       | -
| 1       |	WHERE SALARY LIKE '200%'
|         | Finds any values that start with 200.
| 2	      | WHERE SALARY LIKE '%200%'
|         | Finds any values that have 200 in any position.
| 3	      | WHERE SALARY LIKE '_00%'
|         | Finds any values that have 00 in the second and third positions.
| 4	      | WHERE SALARY LIKE '2_%_%'
|         | Finds any values that start with 2 and are at least 3 characters in length.
| 5	      | WHERE SALARY LIKE '%2'
|         | Finds any values that end with 2.
| 6	      | WHERE SALARY LIKE '_2%3'
|         | Finds any values that have a 2 in the second position and end with a 3.
| 7	      | WHERE SALARY LIKE '2___3'
|         | Finds any values in a five-digit number that start with 2 and end with 3.

Let us take a real example, consider the CUSTOMERS table having the records as shown below.

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

Following is an example, which would display all the records from the CUSTOMERS table, where the SALARY starts with 200.

```sh
  SQL> SELECT * FROM CUSTOMERS
  WHERE SALARY LIKE '200%';
```

This would produce the following result −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  +----+----------+-----+-----------+----------+
```

### 4.8 <a id="48"></a>  SQL - Top Clause

The SQL TOP clause is used to fetch a TOP N number or X percent records from a table.

Note − All the databases do not support the TOP clause. For example MySQL supports the LIMIT clause to fetch limited number of records while Oracle uses the ROWNUM command to fetch a limited number of records.

**Syntax**

The basic syntax of the TOP clause with a SELECT statement would be as follows.

```sh
SELECT TOP number|percent column_name(s)
FROM table_name
WHERE [condition]
```

**Example**

Consider the CUSTOMERS table having the following records −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

The following query is an example on the SQL server, which would fetch the top 3 records from the CUSTOMERS table.

```sh
SQL> SELECT TOP 3 * FROM CUSTOMERS;
```

This would produce the following result −

```sh
  +----+---------+-----+-----------+---------+
  | ID | NAME    | AGE | ADDRESS   | SALARY  |
  +----+---------+-----+-----------+---------+
  |  1 | Ramesh  |  32 | Ahmedabad | 2000.00 |
  |  2 | Khilan  |  25 | Delhi     | 1500.00 |
  |  3 | kaushik |  23 | Kota      | 2000.00 |
  +----+---------+-----+-----------+---------+
```

If you are using MySQL server, then here is an equivalent example −

```sh
  SQL> SELECT * FROM CUSTOMERS
  LIMIT 3;
```

This would produce the following result −

```sh
  +----+---------+-----+-----------+---------+
  | ID | NAME    | AGE | ADDRESS   | SALARY  |
  +----+---------+-----+-----------+---------+
  |  1 | Ramesh  |  32 | Ahmedabad | 2000.00 |
  |  2 | Khilan  |  25 | Delhi     | 1500.00 |
  |  3 | kaushik |  23 | Kota      | 2000.00 |
  +----+---------+-----+-----------+---------+
```

If you are using an Oracle server, then the following code block has an equivalent example.

```sh
  SQL> SELECT * FROM CUSTOMERS
  WHERE ROWNUM <= 3;
```

This would produce the following result −

```sh
  +----+---------+-----+-----------+---------+
  | ID | NAME    | AGE | ADDRESS   | SALARY  |
  +----+---------+-----+-----------+---------+
  |  1 | Ramesh  |  32 | Ahmedabad | 2000.00 |
  |  2 | Khilan  |  25 | Delhi     | 1500.00 |
  |  3 | kaushik |  23 | Kota      | 2000.00 |
  +----+---------+-----+-----------+---------+
```

### 4.9 <a id="49"></a>  SQL - Order By

The SQL ORDER BY clause is used to sort the data in ascending or descending order, based on one or more columns. Some databases sort the query results in an ascending order by default.

**Syntax**

The basic syntax of the ORDER BY clause is as follows −

```sh
  SELECT column-list 
  FROM table_name 
  [WHERE condition] 
  [ORDER BY column1, column2, .. columnN] [ASC | DESC];
```

You can use more than one column in the ORDER BY clause. Make sure whatever column you are using to sort that column should be in the column-list.

**Example**

Consider the CUSTOMERS table having the following records −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

The following code block has an example, which would sort the result in an ascending order by the NAME and the SALARY −

```sh
  SQL> SELECT * FROM CUSTOMERS
  ORDER BY NAME, SALARY;
```

This would produce the following result −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  +----+----------+-----+-----------+----------+
```

The following code block has an example, which would sort the result in the descending order by NAME.

```sh
  SQL> SELECT * FROM CUSTOMERS
  ORDER BY NAME DESC;
```

This would produce the following result −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  +----+----------+-----+-----------+----------+
```

### 4.10 <a id="410"></a>  SQL - Group By

The SQL GROUP BY clause is used in collaboration with the SELECT statement to arrange identical data into groups. This GROUP BY clause follows the WHERE clause in a SELECT statement and precedes the ORDER BY clause.

**Syntax**

The basic syntax of a GROUP BY clause is shown in the following code block. The GROUP BY clause must follow the conditions in the WHERE clause and must precede the ORDER BY clause if one is used.

```sh
  SELECT column1, column2
  FROM table_name
  WHERE [ conditions ]
  GROUP BY column1, column2
  ORDER BY column1, column2
```

**Example**

Consider the CUSTOMERS table is having the following records −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

If you want to know the total amount of the salary on each customer, then the GROUP BY query would be as follows.

```sh
  SQL> SELECT NAME, SUM(SALARY) FROM CUSTOMERS
  GROUP BY NAME;
```

This would produce the following result −

```sh
  +----------+-------------+
  | NAME     | SUM(SALARY) |
  +----------+-------------+
  | Chaitali |     6500.00 |
  | Hardik   |     8500.00 |
  | kaushik  |     2000.00 |
  | Khilan   |     1500.00 |
  | Komal    |     4500.00 |
  | Muffy    |    10000.00 |
  | Ramesh   |     2000.00 |
  +----------+-------------+
```

Now, let us look at a table where the CUSTOMERS table has the following records with duplicate names −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Ramesh   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | kaushik  |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

Now again, if you want to know the total amount of salary on each customer, then the GROUP BY query would be as follows −

```sh
  SQL> SELECT NAME, SUM(SALARY) FROM CUSTOMERS
  GROUP BY NAME;
```

This would produce the following result −

```sh
  +---------+-------------+
  | NAME    | SUM(SALARY) |
  +---------+-------------+
  | Hardik  |     8500.00 |
  | kaushik |     8500.00 |
  | Komal   |     4500.00 |
  | Muffy   |    10000.00 |
  | Ramesh  |     3500.00 |
  +---------+-------------+
```

### 4.11 <a id="411"></a>  SQL - Distinct Keyword

The SQL DISTINCT keyword is used in conjunction with the SELECT statement to eliminate all the duplicate records and fetching only unique records.

There may be a situation when you have multiple duplicate records in a table. While fetching such records, it makes more sense to fetch only those unique records instead of fetching duplicate records.

**Syntax**

The basic syntax of DISTINCT keyword to eliminate the duplicate records is as follows −

```sh
  SELECT DISTINCT column1, column2,.....columnN 
  FROM table_name
  WHERE [condition]
```

**Example**

Consider the CUSTOMERS table having the following records −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

First, let us see how the following SELECT query returns the duplicate salary records.

```sh
  SQL> SELECT SALARY FROM CUSTOMERS
  ORDER BY SALARY;
```

This would produce the following result, where the salary (2000) is coming twice which is a duplicate record from the original table.

```sh
  +----------+
  | SALARY   |
  +----------+
  |  1500.00 |
  |  2000.00 |
  |  2000.00 |
  |  4500.00 |
  |  6500.00 |
  |  8500.00 |
  | 10000.00 |
  +----------+
```

Now, let us use the DISTINCT keyword with the above SELECT query and then see the result.

```sh
  SQL> SELECT DISTINCT SALARY FROM CUSTOMERS
  ORDER BY SALARY;
```

This would produce the following result where we do not have any duplicate entry.

```sh
  +----------+
  | SALARY   |
  +----------+
  |  1500.00 |
  |  2000.00 |
  |  4500.00 |
  |  6500.00 |
  |  8500.00 |
  | 10000.00 |
  +----------+
```

### 4.12 <a id="412"></a>  SQL - Sorting Results

The SQL ORDER BY clause is used to sort the data in ascending or descending order, based on one or more columns. Some databases sort the query results in an ascending order by default.

**Syntax**

The basic syntax of the ORDER BY clause which would be used to sort the result in an ascending or descending order is as follows −

```sh
  SELECT column-list 
  FROM table_name 
  [WHERE condition] 
  [ORDER BY column1, column2, .. columnN] [ASC | DESC];
```

You can use more than one column in the ORDER BY clause. Make sure that whatever column you are using to sort, that column should be in the column-list.

**Example**

Consider the CUSTOMERS table having the following records −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

Following is an example, which would sort the result in an ascending order by NAME and SALARY.

```sh
  SQL> SELECT * FROM CUSTOMERS
  ORDER BY NAME, SALARY;
```

This would produce the following result −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  +----+----------+-----+-----------+----------+
```

The following code block has an example, which would sort the result in a descending order by NAME.

```sh
  SQL> SELECT * FROM CUSTOMERS
  ORDER BY NAME DESC;
```

This would produce the following result −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  +----+----------+-----+-----------+----------+
```

To fetch the rows with their own preferred order, the SELECT query used would be as follows −

```sh
  SQL> SELECT * FROM CUSTOMERS
  ORDER BY (CASE ADDRESS
  WHEN 'DELHI' 	 THEN 1
  WHEN 'BHOPAL' 	 THEN 2
  WHEN 'KOTA' 	 THEN 3
  WHEN 'AHMEDABAD' THEN 4
  WHEN 'MP' 	THEN 5
  ELSE 100 END) ASC, ADDRESS DESC;
```

This would produce the following result −

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  +----+----------+-----+-----------+----------+
```

This will sort the customers by ADDRESS in your ownoOrder of preference first and in a natural order for the remaining addresses. Also, the remaining Addresses will be sorted in the reverse alphabetical order.

### 4.13 <a id="413"></a>SQL - Constraints

Constraints are the rules enforced on the data columns of a table. These are used to limit the type of data that can go into a table. This ensures the accuracy and reliability of the data in the database.

Constraints could be either on a column level or a table level. The column level constraints are applied only to one column, whereas the table level constraints are applied to the whole table.

Following are some of the most commonly used constraints available in SQL. These constraints have already been discussed in SQL - RDBMS Concepts chapter, but it’s worth to revise them at this point.

- NOT NULL Constraint − Ensures that a column cannot have NULL value.

- DEFAULT Constraint − Provides a default value for a column when none is specified.

- UNIQUE Constraint − Ensures that all values in a column are different.

- PRIMARY Key − Uniquely identifies each row/record in a database table.

- FOREIGN Key − Uniquely identifies a row/record in any of the given database table.

- CHECK Constraint − The CHECK constraint ensures that all the values in a column satisfies certain conditions.

- INDEX − Used to create and retrieve data from the database very quickly.

Constraints can be specified when a table is created with the CREATE TABLE statement or you can use the ALTER TABLE statement to create constraints even after the table is created.

Dropping Constraints
Any constraint that you have defined can be dropped using the ALTER TABLE command with the DROP CONSTRAINT option.

For example, to drop the primary key constraint in the EMPLOYEES table, you can use the following command.

ALTER TABLE EMPLOYEES DROP CONSTRAINT EMPLOYEES_PK;

Some implementations may provide shortcuts for dropping certain constraints. For example, to drop the primary key constraint for a table in Oracle, you can use the following command.

ALTER TABLE EMPLOYEES DROP PRIMARY KEY;

Some implementations allow you to disable constraints. Instead of permanently dropping a constraint from the database, you may want to temporarily disable the constraint and then enable it later.

**Integrity Constraints**

Integrity constraints are used to ensure accuracy and consistency of the data in a relational database. Data integrity is handled in a relational database through the concept of referential integrity.

There are many types of integrity constraints that play a role in Referential Integrity (RI). These constraints include Primary Key, Foreign Key, Unique Constraints and other constraints which are mentioned above.

### 4.14 <a id="414"></a>SQL - Using Joins

The SQL Joins clause is used to combine records from two or more tables in a database. A JOIN is a means for combining fields from two tables by using values common to each.

Consider the following two tables −

Table 1 − CUSTOMERS Table

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

Table 2 − ORDERS Table

```sh
  +-----+---------------------+-------------+--------+
  |OID  | DATE                | CUSTOMER_ID | AMOUNT |
  +-----+---------------------+-------------+--------+
  | 102 | 2009-10-08 00:00:00 |           3 |   3000 |
  | 100 | 2009-10-08 00:00:00 |           3 |   1500 |
  | 101 | 2009-11-20 00:00:00 |           2 |   1560 |
  | 103 | 2008-05-20 00:00:00 |           4 |   2060 |
  +-----+---------------------+-------------+--------+
```

Now, let us join these two tables in our SELECT statement as shown below.

```sh
  SQL> SELECT ID, NAME, AGE, AMOUNT
  FROM CUSTOMERS, ORDERS
  WHERE  CUSTOMERS.ID = ORDERS.CUSTOMER_ID;
```

This would produce the following result.

```sh
  +----+----------+-----+--------+
  | ID | NAME     | AGE | AMOUNT |
  +----+----------+-----+--------+
  |  3 | kaushik  |  23 |   3000 |
  |  3 | kaushik  |  23 |   1500 |
  |  2 | Khilan   |  25 |   1560 |
  |  4 | Chaitali |  25 |   2060 |
  +----+----------+-----+--------+
```

Here, it is noticeable that the join is performed in the WHERE clause. Several operators can be used to join tables, such as =, <, >, <>, <=, >=, !=, BETWEEN, LIKE, and NOT; they can all be used to join tables. However, the most common operator is the equal to symbol.

There are different types of joins available in SQL −

[INNER JOIN](https://www.tutorialspoint.com/sql/sql-inner-joins.htm) − returns rows when there is a match in both tables.

[LEFT JOIN](https://www.tutorialspoint.com/sql/sql-left-joins.htm) − returns all rows from the left table, even if there are no matches in the right table.

[RIGHT JOIN](https://www.tutorialspoint.com/sql/sql-right-joins.htm) − returns all rows from the right table, even if there are no matches in the left table.

[FULL JOIN](https://www.tutorialspoint.com/sql/sql-full-joins.htm) − returns rows when there is a match in one of the tables.

[SELF JOIN](https://www.tutorialspoint.com/sql/sql-self-joins.htm) − is used to join a table to itself as if the table were two tables, temporarily renaming at least one table in the SQL statement.

[CARTESIAN JOIN](https://www.tutorialspoint.com/sql/sql-cartesian-joins.htm) − returns the Cartesian product of the sets of records from the two or more joined tables.


### 4.15 <a id="415"></a>SQL - Unions Clause

The SQL UNION clause/operator is used to combine the results of two or more SELECT statements without returning any duplicate rows.

To use this UNION clause, each SELECT statement must have

- The same number of columns selected
- The same number of column expressions
- The same data type and
- Have them in the same order

But they need not have to be in the same length.

**Syntax**

The basic syntax of a UNION clause is as follows −

```sh
  SELECT column1 [, column2 ]
  FROM table1 [, table2 ]
  [WHERE condition]

  UNION

  SELECT column1 [, column2 ]
  FROM table1 [, table2 ]
  [WHERE condition]
```

Here, the given condition could be any given expression based on your requirement.

**Example**

Consider the following two tables.

Table 1 − CUSTOMERS Table is as follows.

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

Table 2 − ORDERS Table is as follows.

```sh
  +-----+---------------------+-------------+--------+
  |OID  | DATE                | CUSTOMER_ID | AMOUNT |
  +-----+---------------------+-------------+--------+
  | 102 | 2009-10-08 00:00:00 |           3 |   3000 |
  | 100 | 2009-10-08 00:00:00 |           3 |   1500 |
  | 101 | 2009-11-20 00:00:00 |           2 |   1560 |
  | 103 | 2008-05-20 00:00:00 |           4 |   2060 |
  +-----+---------------------+-------------+--------+
```

Now, let us join these two tables in our SELECT statement as follows −

```sh
  SQL> SELECT  ID, NAME, AMOUNT, DATE
    FROM CUSTOMERS
    LEFT JOIN ORDERS
    ON CUSTOMERS.ID = ORDERS.CUSTOMER_ID
  UNION
    SELECT  ID, NAME, AMOUNT, DATE
    FROM CUSTOMERS
    RIGHT JOIN ORDERS
    ON CUSTOMERS.ID = ORDERS.CUSTOMER_ID;
```

This would produce the following result −

```sh
  +------+----------+--------+---------------------+
  | ID   | NAME     | AMOUNT | DATE                |
  +------+----------+--------+---------------------+
  |    1 | Ramesh   |   NULL | NULL                |
  |    2 | Khilan   |   1560 | 2009-11-20 00:00:00 |
  |    3 | kaushik  |   3000 | 2009-10-08 00:00:00 |
  |    3 | kaushik  |   1500 | 2009-10-08 00:00:00 |
  |    4 | Chaitali |   2060 | 2008-05-20 00:00:00 |
  |    5 | Hardik   |   NULL | NULL                |
  |    6 | Komal    |   NULL | NULL                |
  |    7 | Muffy    |   NULL | NULL                |
  +------+----------+--------+---------------------+
```

**The UNION ALL Clause**

The UNION ALL operator is used to combine the results of two SELECT statements including duplicate rows.

The same rules that apply to the UNION clause will apply to the UNION ALL operator.

**Syntax**

The basic syntax of the UNION ALL is as follows.

```sh
  SELECT column1 [, column2 ]
  FROM table1 [, table2 ]
  [WHERE condition]

  UNION ALL

  SELECT column1 [, column2 ]
  FROM table1 [, table2 ]
  [WHERE condition]
```

Here, the given condition could be any given expression based on your requirement.

**Example**

Consider the following two tables,

Table 1 − CUSTOMERS Table is as follows.

```sh
  +----+----------+-----+-----------+----------+
  | ID | NAME     | AGE | ADDRESS   | SALARY   |
  +----+----------+-----+-----------+----------+
  |  1 | Ramesh   |  32 | Ahmedabad |  2000.00 |
  |  2 | Khilan   |  25 | Delhi     |  1500.00 |
  |  3 | kaushik  |  23 | Kota      |  2000.00 |
  |  4 | Chaitali |  25 | Mumbai    |  6500.00 |
  |  5 | Hardik   |  27 | Bhopal    |  8500.00 |
  |  6 | Komal    |  22 | MP        |  4500.00 |
  |  7 | Muffy    |  24 | Indore    | 10000.00 |
  +----+----------+-----+-----------+----------+
```

Table 2 − ORDERS table is as follows.

```sh
  +-----+---------------------+-------------+--------+
  |OID  | DATE                | CUSTOMER_ID | AMOUNT |
  +-----+---------------------+-------------+--------+
  | 102 | 2009-10-08 00:00:00 |           3 |   3000 |
  | 100 | 2009-10-08 00:00:00 |           3 |   1500 |
  | 101 | 2009-11-20 00:00:00 |           2 |   1560 |
  | 103 | 2008-05-20 00:00:00 |           4 |   2060 |
  +-----+---------------------+-------------+--------+
```

Now, let us join these two tables in our SELECT statement as follows −

```sh
  SQL> SELECT  ID, NAME, AMOUNT, DATE
    FROM CUSTOMERS
    LEFT JOIN ORDERS
    ON CUSTOMERS.ID = ORDERS.CUSTOMER_ID
  UNION ALL
    SELECT  ID, NAME, AMOUNT, DATE
    FROM CUSTOMERS
    RIGHT JOIN ORDERS
    ON CUSTOMERS.ID = ORDERS.CUSTOMER_ID;
```

This would produce the following result −

```sh
  +------+----------+--------+---------------------+
  | ID   | NAME     | AMOUNT | DATE                |
  +------+----------+--------+---------------------+
  |    1 | Ramesh   |   NULL | NULL                |
  |    2 | Khilan   |   1560 | 2009-11-20 00:00:00 |
  |    3 | kaushik  |   3000 | 2009-10-08 00:00:00 |
  |    3 | kaushik  |   1500 | 2009-10-08 00:00:00 |
  |    4 | Chaitali |   2060 | 2008-05-20 00:00:00 |
  |    5 | Hardik   |   NULL | NULL                |
  |    6 | Komal    |   NULL | NULL                |
  |    7 | Muffy    |   NULL | NULL                |
  |    3 | kaushik  |   3000 | 2009-10-08 00:00:00 |
  |    3 | kaushik  |   1500 | 2009-10-08 00:00:00 |
  |    2 | Khilan   |   1560 | 2009-11-20 00:00:00 |
  |    4 | Chaitali |   2060 | 2008-05-20 00:00:00 |
  +------+----------+--------+---------------------+
```

There are two other clauses (i.e., operators), which are like the UNION clause.

[SQL INTERSECT Clause](https://www.tutorialspoint.com/sql/sql-intersect-clause.htm) − This is used to combine two SELECT statements, but returns rows only from the first SELECT statement that are identical to a row in the second SELECT statement.

[SQL EXCEPT Clause](https://www.tutorialspoint.com/sql/sql-except-clause.htm) − This combines two SELECT statements and returns rows from the first SELECT statement that are not returned by the second SELECT statement.

Useful Video Courses
### 4.16 <a id="416"></a>SQL - NULL Values
### 4.17 <a id="417"></a>SQL - Alias Syntax
### 4.18 <a id="418"></a>SQL - Indexes
### 4.19 <a id="419"></a>SQL - Alter Command
### 4.20 <a id="420"></a>SQL - Truncate Table
### 4.21 <a id="421"></a>SQL - Using Views
### 4.22 <a id="422"></a>SQL - Having Clause
### 4.23 <a id="423"></a>SQL - Transactions
### 4.24 <a id="424"></a>SQL - Wildcards
### 4.25 <a id="425"></a>SQL - Date Functions
### 4.26 <a id="426"></a>SQL - Temporary Tables
### 4.27 <a id="427"></a>SQL - Clone Tables
### 4.28 <a id="428"></a>SQL - Sub Queries
### 4.29 <a id="429"></a>SQL - Using Sequences
### 4.30 <a id="430"></a>SQL - Handling Duplicates
### 4.31 <a id="431"></a>SQL - Injection