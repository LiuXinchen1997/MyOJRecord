# Write your MySQL query statement below
select 
distinct b1.Num as ConsecutiveNums
from Logs b1, Logs b2, Logs b3
where b1.Id = b2.Id - 1
and b2.Id = b3.Id - 1
and b1.Num = b2.Num
and b2.Num = b3.Num