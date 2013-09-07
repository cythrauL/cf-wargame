#include <unistd.h>
#include <stdio.h>
#include <openssl/sha.h>
#include <sys/types.h>
#include <pwd.h>
#include <errno.h>
#include <stdlib.h>

#define MAX_DATA_LEN 256

#define SECRET_KEY_MATERIAL "SOMESECRETKEYsomesecretkey"

int main()
{
  unsigned char sha_digest[SHA_DIGEST_LENGTH];
  unsigned char printable_sha[(SHA_DIGEST_LENGTH * 2) + 1];
  char key_material[MAX_DATA_LEN];
  struct passwd *uid_data;
  struct passwd *euid_data;

  if ((uid_data = getpwuid(getuid())) == NULL)
  {
    perror("getpwname");
    exit(-1);
  }

  

  if ((euid_data = getpwuid(geteuid())) == NULL)
  {
    perror("getpwname");
    exit(-1);
  }

  int data_len = snprintf(key_material, MAX_DATA_LEN, "%s%s%s",
                          SECRET_KEY_MATERIAL,
                          euid_data->pw_name,
                          uid_data->pw_name);
  if (data_len > MAX_DATA_LEN)
  {
    data_len = MAX_DATA_LEN;
  }

  int i;

  SHA1(key_material, data_len, sha_digest);

  for(i = 0; i < SHA_DIGEST_LENGTH; i++)
  {
    sprintf(&printable_sha[(2 * i)], "%02x", sha_digest[i]);
  }
  printable_sha[SHA_DIGEST_LENGTH] = '\x00';
  
  printf("\nCongratulations, you completed %s.\n\nFLAG: %s\n\n", euid_data->pw_name, printable_sha);

  return 0;
}
