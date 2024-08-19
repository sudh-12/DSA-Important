# Write your MySQL query statement below
SELECT Signups.user_id, round(avg(if(confirmations.action="confirmed",1,0)),2) AS confirmation_rate
FROM Signups
LEFT JOIN Confirmations on confirmations.user_id=Signups.user_id
GROUP BY user_id;