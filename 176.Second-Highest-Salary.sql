# Write your MySQL query statement below

select IFNULL((select DISTINCT Salary from Employee order by Salary DESC limit 1 offset 1), NULL) as SecondHighestSalary