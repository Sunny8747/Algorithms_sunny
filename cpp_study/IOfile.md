# Input/Output with file

<http://www.cplusplus.com/doc/tutorial/files/>

## Open a file

|   option    |                                                           description                                                            |
| :---------: | :------------------------------------------------------------------------------------------------------------------------------: |
|   ios::in   |                                                    Open for input operations.                                                    |
|  ios::out   |                                                   Open for output operations.                                                    |
| ios::binary |                                                       Open in binary mode.                                                       |
|  ios::ate   |                                         Set the initial position at the end of the file.                                         |
|  ios::app   |      All output operations are performed at the end of the file, appending the content to the current content of the file.       |
| ios::trunc  | If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one. |
|             |                                                                                                                                  |

| class    | decault mode parameter  |
| -------- | ----------------------- |
| ofstream | ios::out                |
| ifstream | ios::in                 |
| fstream  | ios::in &#124; ios::out |
