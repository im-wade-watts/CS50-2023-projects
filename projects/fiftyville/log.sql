-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find the crime scene description

select description from crime_scene_reports where month = 7 and day = 28 and street = "Humphrey Street";

-- information gathered:
--  duck cs50 was robbed at 10:15am

-- Loking at the interviews of the three witnesses:

select transcript from interviews where month = 7 and day = 28 and year = 2021;

-- information gathered:
--  10 min later possible footage from bakery parking lot
--  purchase the earliest flight the next morning out of fifthyville
--  early in the morning the thief was withdrawing some money from the atm on leggett street


-- Loking at the activity, minutes and license_plate from the bakery_security_logs to know exactly the time and the license_plate of the cars.

select license_plate from bakery_security_logs where year = 2021 and month = 7 and day = 28 and hour = 10 and activity = 'exit' and minute between 15 and 25;

-- information gathered:
--  possible license_plates:
-- +---------------+
-- | license_plate |
-- +---------------+
-- | 5P2BI95       |
-- | 94KL13X       |
-- | 6P58WS2       |
-- | 4328GD8       |
-- | G412CB7       |
-- | L93JTIZ       |
-- | 322W7JE       |
-- | 0NTHK55       |
-- +---------------+

-- Loking at the owners of that cars.

select * from people where license_plate in (select license_plate from bakery_security_logs where year = 2021 and month = 7 and day = 28 and hour = 10 and activity = 'exit' and minute between 15 and 25);

-- information gathered:
--      possible suspects:
-- +--------+---------+----------------+-----------------+---------------+
-- |   id   |  name   |  phone_number  | passport_number | license_plate |
-- +--------+---------+----------------+-----------------+---------------+
-- | 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       |
-- | 243696 | Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       |
-- | 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
-- | 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
-- | 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
-- | 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
-- | 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
-- | 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
-- +--------+---------+----------------+-----------------+---------------+

-- Loking for possible suspects that made a call of less that day:

select * from people
where license_plate in (
select license_plate from bakery_security_logs
where year = 2021 and month = 7 and day = 28 and hour = 10
and activity = 'exit' and minute between 15 and 25)
and phone_number in (select caller from phone_calls
where year = 2021 and month = 7 and day =  28 and duration <= 60);

-- +--------+--------+----------------+-----------------+---------------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate |
-- +--------+--------+----------------+-----------------+---------------+
-- | 398010 | Sofia  | (130) 555-0289 | 1695452385      | G412CB7       |
-- | 514354 | Diana  | (770) 555-1861 | 3592750733      | 322W7JE       |
-- | 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
-- | 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
-- +--------+--------+----------------+-----------------+---------------+

-- Knowing how these people called:

select * from people where phone_number in (
select receiver from phone_calls where year = 2021
and month = 7 and day = 28 and duration <= 60 and
caller in (select phone_number from people
where license_plate in (
select license_plate from bakery_security_logs
where year = 2021 and month = 7 and day = 28 and hour = 10
and activity = 'exit' and minute between 15 and 25)
and phone_number in (select caller from phone_calls
where year = 2021 and month = 7 and day =  28 and duration <= 60)));

-- +--------+---------+----------------+-----------------+---------------+
-- |   id   |  name   |  phone_number  | passport_number | license_plate |
-- +--------+---------+----------------+-----------------+---------------+
-- | 251693 | Larry   | (892) 555-8872 | 2312901747      | O268ZZ0       |
-- | 567218 | Jack    | (996) 555-8899 | 9029462229      | 52R0Y8U       |
-- | 626361 | Melissa | (717) 555-1342 | 7834357192      | NULL          |
-- | 847116 | Philip  | (725) 555-3243 | 3391710505      | GW362R6       |
-- | 864400 | Robin   | (375) 555-8161 | NULL            | 4V16VO0       |
-- +--------+---------+----------------+-----------------+---------------+

-- Looking for the id of the earliest flight the next day

select id from flights where month = 7 and day = 29 and origin_airport_id = 8 order by hour asc limit 1;

-- id = 36

-- checking if the suspects where in the earliest flight

select name from people
join passengers on passengers.passport_number = people.passport_number
join flights on flights.id = passengers.flight_id
where flights.id = 36 and passengers.passport_number in (
select passport_number from people
where id = 398010  or id = 514354
or id = 560886 or id = 686048);

-- +--------+
-- |  name  |
-- +--------+
-- | Sofia  |
-- | Bruce  |
-- | Kelsey |
-- +--------+

select name from people
join passengers on passengers.passport_number = people.passport_number
join flights on flights.id = passengers.flight_id
where flights.id = 36 and passengers.passport_number in (
select passport_number from people
where id = 251693  or id = 567218
or id = 626361 or id = 847116 or id = 864400);

select * from people where phone_number in (
select caller from phone_calls where year = 2021
and month = 7 and day = 28 and duration <= 60 and
receiver = "(375) 555-8161");

-- this doesn't result in nothing meaning that, Robin that is the only one that doesn't have passport, is our accomplice and the person that called Robin is Bruce our thief


-- knowing the destination of the flight (New York City)

select city from airports
where id = (
select destination_airport_id from flights
join airports on airports.id = flights.origin_airport_id
where flights.id = 36);
