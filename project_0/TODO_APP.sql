CREATE Database TodoApp;
USE TodoApp;
Create table if not exists story(
Storyid integer AUTO_INCREMENT,
StoryText TEXT,
primary key (Storyid)
);
Create table if not exists todo(
TodoId Integer,
TodoText TEXT
);
Create table if not exists doing(
DoingId Integer,
DoingText TEXT
);
Create table if not exists review(
ReviewId Integer,
ReviewText TEXT

);
Create table if not exists done(
DoneId Integer,
DoneText TEXT
);

INSERT INTO story (StoryText)
values ("shopping"),("cleaning"), ("relax");

/*select * from story;*/

INSERT INTO todo (TodoId, TodoText)
select Storyid, StoryText FROM story;

INSERT INTO doing (DoingId, DoingText)
select * FROM todo
WHERE TodoText = "shopping";

DELETE FROM todo
WHERE TodoText = "shopping";

UPDATE todo
SET TodoText = "learning"
WHERE TodoText = "relax";

SELECT Storyid as nmb,TodoText as TODO, DoingText as DOING, ReviewText AS REVIEW, DoneText as DONE from story
LEFT JOIN todo
ON Storyid = TodoId
LEFT Join doing
ON Storyid = DoingId
LEFT JOIN review
ON Storyid = ReviewId
LEFT Join done
ON Storyid = DoneId;

DROP DATABASE ToDoApp;


