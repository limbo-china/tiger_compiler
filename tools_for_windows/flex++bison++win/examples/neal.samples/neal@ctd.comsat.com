From root Wed Sep 29 14:14:52 1993
>From neal@ctd.comsat.com Wed Sep 29 14:14:51 1993
Date: 29 Sep 93 09:17:00-0400
From: Neal Becker <neal@ctd.comsat.com>
To: coetmeur@icdc.fr
Subject: Re: flex++ -> ftp
Content-Length: 7184
X-Lines: 271
Status: RO

Thanks!  I installed the latest bison++ and flex++.  Now I got it
working fine.  I did have some trouble to get the order of #includes
and definitions correct.  It was not obvious to me that the order of
%defines and %union in the source controls the order they are written
into the '.h' file.  So, to make sure that yystype is declared before
%defines I just had to put %union first.  I suggest that you point
this out in the documentation.

I got my application working fine.  I am sending you a small example.
Here parse.c opens the file.  The FILE* is passed to the parse( FILE*
), which passes it to lex( FILE* ).  (Originally I thought to pass
char* filename, but then lex would have to somehow communicate back to
the main program if the file didn't exist, so I think this is better
for my application).  lex is a member of parse, which I
think makes sense.

parse communicates with lex by calling yylex( yylval& ).  This is
almost the same as %pure, but not quite.  Instead this is done with
inline LEX_BODY.

Perhaps this will serve as a useful example.

