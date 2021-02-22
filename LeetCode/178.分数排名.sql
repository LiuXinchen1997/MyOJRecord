select a.Score,
(select count(distinct b.Id) from Scores b where b.Score > a.Score) as Rank
from Scores a
order by a.Score DESC;
