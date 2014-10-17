QtSQLiteCipher
===============

QSQLite database driver with password support based on wxSQLite3 in wxWidget.

wxSQLite3 is a C wrapper around the public domain SQLite 3.x database and is specifically designed for use in programs based on the wxWidgets library. wxSQLite3 includes an optional extension for SQLite supporting key based database file encryption using 128 bit AES encryption. You could find more details at http://wxcode.sourceforge.net/components/wxsqlite3/. wxSQLite3 is released under wxWindows Library Licence.

## Dependencies

| Name         | Version                          |
|--------------|----------------------------------|
| Qt           | >= 5.0.0                         |

## Usage

1) Build QtSQLiteCipher plugin. 

2a) Copy QtSQLiteCipher plugin into sqldrivers folder. 

OR

2b) Instantiate QSqlDriverPlugin as in example QtSQLiteCipherExample project.

See `examples/` for examples on using this class.

## Contact

Questions and suggestions can be sent to email: lysenkoalexmail@gmail.com

## Contributing

Please report any suggestions, feature requests, bug reports, or annoyances to
the Github [issue tracker][issue_tracker]. 

## License

QtSQLiteCipherExample is licensed under [MIT](LICENSE).


[issue_tracker]: https://github.com/alexeylysenko/QtSQLiteCipher/issues