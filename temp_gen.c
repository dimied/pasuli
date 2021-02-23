
#include <dirent.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void clearBuffer(char *buffer, int size)
{
    for (int i = 0; i < size; i++)
    {
        buffer[i] = '\0';
    }
}

char *readMode = "r";
char *writeMode = "w";
char *commonInclude = "surfaces_c_includes.h";
char *include = "#include";

int createCFile(char *path, char *headerName)
{
    FILE *f = fopen(path, writeMode);

    if (f == 0)
    {
        printf("Failed to open for write");
        return 1;
    }

    char *tmpl = "\n%s \"%s\"\n%s \"%s\"\n\n";
    int err = fprintf(f, tmpl,
                      include,
                      headerName,
                      include,
                      commonInclude);

    fclose(f);

    return err < 0 ? 1 : 0;
}

char *voidWord = "void";

int doesHaveImplementation(char *path)
{
    FILE *f = fopen(path, readMode);
    char readBuffer[2048];
    for (int i = 0; i < 2048; i++)
    {
        readBuffer[i] = '\0';
    }

    if (f == 0)
    {
        printf("Failed to open for read");
        return -1;
    }
    int read = fread(readBuffer, 1, 2048, f);

    if (ferror(f) != 0)
    {
        printf("Failed to read file %s\n", path);
        fclose(f);
        return -1;
    }

    char *ptr = strstr(readBuffer, voidWord);

    if (ptr != 0)
    {
        return 1;
    }

    fclose(f);
    return 0;
}

char *appendMode = "a";

int copyIfBlock(char *from, char *to)
{
    char readBuffer[2048];
    memset(readBuffer, 0, 2048);

    char *szIf1 = "#if(USE";
    char *szIf2 = "#if (USE";
    char *szEndif = "#endif";

    FILE *toFile = fopen(to, readMode);

    if (toFile == 0)
    {
        printf("Failed to open for write %s\n", to);
        return -1;
    }

    int read = fread(readBuffer, 1, 2048, toFile);

    if (ferror(toFile) != 0)
    {
        printf("Failed to read file %s\n", to);
        fclose(toFile);
        return -1;
    }
    fclose(toFile);

    char *found1 = strstr(readBuffer, szIf1);
    char *found2 = strstr(readBuffer, szIf2);

    if ((found1 != 0) || (found2 != 0))
    {
        printf("#if(USE already in %s\n", to);
        return 1;
    }
    printf("Not found in %s\n", to);

    // Read and try to copy
    FILE *fromFile = fopen(from, readMode);

    if (fromFile == 0)
    {
        printf("Failed to open for read %s\n", from);
        return -1;
    }

    memset(readBuffer, 0, 2048);

    read = fread(readBuffer, 1, 2048, fromFile);

    if (ferror(fromFile) != 0)
    {
        printf("Failed to read file %s\n", from);
        fclose(fromFile);
        return -1;
    }
    fclose(fromFile);

    found1 = strstr(readBuffer, szIf1);
    found2 = strstr(readBuffer, szIf2);
    char *foundEnd = strstr(readBuffer, szEndif);

    char *foundStart = 0;
    if (found1 != 0)
    {
        foundStart = found1;
    }
    if (found2 != 0)
    {
        foundStart = found2;
    }

    int l = 0;
    if (foundStart != 0 && foundEnd != 0)
    {
        ptrdiff_t length = foundEnd - foundStart;
        l = (int)length;
        printf("Found text of length %d\n", l);
    }

    if (l > 0)
    {
        toFile = fopen(to, appendMode);

        if (toFile == 0)
        {
            printf("Failed to open for append %s\n", to);
            return -1;
        }

        int written = fwrite(foundStart, 1, l + 7, toFile);

        if (written != l + 7)
        {
            printf("Not written enough into %s\n", to);
            fclose(toFile);
            return -1;
        }
        printf("Written into %s\n", to);

        fclose(toFile);
    }

    return 0;
}

int main(int argc, char *argv[])
{

    int num = 20;
    char pathBuffer[2048];
    char pathBuffer2[2048];

    DIR *d;
    struct dirent *dir;
    char *basepath = argv[1];

    if (argc < 2)
    {
        printf("Arg %s\n\n", basepath);
        return 0;
    }

    d = opendir(basepath);

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            struct stat attribut;
            struct stat attribut_c;

            clearBuffer(pathBuffer, 2048);

            printf("%s\n", dir->d_name);

            int n = sprintf(pathBuffer,
                            "%s/%s",
                            basepath,
                            dir->d_name);

            if (n <= 1)
            {
                printf("Fehler bei sprintf ...\n");
                closedir(d);
                return 1;
            }

            if (stat(pathBuffer, &attribut) == -1)
            {
                fprintf(stderr, "Fehler bei stat ...\n");
                closedir(d);
                return 1;
            }
            if (attribut.st_mode & S_IFREG)
            {
                printf("Reguläre Datei\n");

                if (pathBuffer[n - 1] == 'h')
                {
                    printf("  Header\n");

                    pathBuffer[n - 1] = 'c';
                    void *dst = memcpy(pathBuffer2,
                                       pathBuffer,
                                       2048);

                    if (dst != pathBuffer2)
                    {
                        closedir(d);
                        printf("Failed to copy");
                        return 1;
                    }

                    pathBuffer2[n - 1] = 'h';

                    if (stat(pathBuffer, &attribut_c) != -1)
                    {
                        printf("Maybe to extend %s\n", pathBuffer);
                        int res = doesHaveImplementation(pathBuffer);

                        if (res < 0)
                        {
                            closedir(d);
                            return 1;
                        }

                        if (res > 0)
                        {
                            printf("Has implementation %s\n", pathBuffer);
                        }
                        else
                        {
                            printf("No implementation in %s\n", pathBuffer);
                            int res = copyIfBlock(pathBuffer2, pathBuffer);
                            if (res != 0)
                            {
                                printf("Failed to copy \n%s -> %s\n",
                                       pathBuffer2,
                                       pathBuffer);
                            }
                        }
                    }

                    if (
                        stat(pathBuffer, &attribut_c) == -1 &&
                        access(pathBuffer, R_OK) == -1)
                    {
                        fprintf(stderr, "Fehler bei stat ...\n");
                        //return 1;
                        int created = createCFile(
                            pathBuffer,
                            dir->d_name);

                        if (created != 0)
                        {
                            printf("Failed to created %s", pathBuffer);
                            closedir(d);
                            return 1;
                        }
                        printf("Created %s\n", pathBuffer);

                        num--;
                        if (num == 0)
                        {
                            printf("Done ...");
                            closedir(d);
                            return 0;
                        }
                    }
                    else
                    {
                        printf("C-File exists ...\n");
                    }
                }
            }
            printf("\n");
        }
        closedir(d);
    }

    return 0;
}