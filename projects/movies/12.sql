select title from movies join stars on stars.movie_id = movies.id join people on people.id = stars.person_id where people.name = 'Bradley Cooper' and movies.title in( select title from movies join stars on stars.movie_id = movies.id join people on people.id = stars.person_id where people.name = 'Jennifer Lawrence');
