#ifndef DBSCHEMA_H
#define DBSCHEMA_H

// List of scripts to create database
static const char * kCreationScriptsList[] =
{
       "CREATE TABLE [profile] ("
       " [id] integer NOT NULL PRIMARY KEY AUTOINCREMENT, "
       " [profile_name] [VARCHAR(100)] NOT NULL, "
       " [first_name] [VARCHAR(50)], "
       " [last_name] [VARCHAR(50)], "
       " [email] [VARCHAR(100)] NOT NULL, "
       " [is_active_profile] BOOLEAN NOT NULL DEFAULT 1, "
       " CONSTRAINT [u_email] UNIQUE ([email]));",

       "CREATE TABLE [email] ("
       " [id] integer NOT NULL PRIMARY KEY AUTOINCREMENT, "
       " [profile_id] integer NOT NULL CONSTRAINT [fk_profile_email] "
       "  REFERENCES [profile]([id]) ON DELETE CASCADE, "
       " [from_address] [varchar(100)] NOT NULL, "
       " [subject] [varchar(100)], "
       " [email_text] TEXT);",

       "CREATE TABLE [address] ("
       " [id] integer NOT NULL PRIMARY KEY AUTOINCREMENT, "
       " [email_id] integer NOT NULL CONSTRAINT [fk_email_address] "
       "  REFERENCES [email]([id]) ON DELETE CASCADE, "
       " [address] [varchar(100)] NOT NULL, "
       " [alias] [varchar(100)], "
       " [type] integer NOT NULL);"
};

template<size_t SIZE, class T>
inline size_t arraySize(T (&arr)[SIZE])
{
    Q_UNUSED(arr);
    return SIZE;
}

#endif // DBSCHEMA_H
