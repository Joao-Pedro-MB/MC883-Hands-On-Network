#include "client-socket.h"

char * create_new_user() {
    char email[100], name[100], age[100], city[100], state[100], scholarity[100], graduationYear[10], skills[1000];

    // receive all client inputs
    printf( "Type new user's email:\n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf( "Type new user's name:\n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf( "Type new user's age:\n");
    fgets(age, sizeof(age), stdin);
    age[strcspn(age, "\n")] = '\0';

    printf( "Type new user's city:\n");
    fgets(city, sizeof(city), stdin);
    city[strcspn(city, "\n")] = '\0';

    printf( "Type new user's state initials (ex: SP):\n");
    fgets(state, sizeof(state), stdin);
    state[strcspn(state, "\n")] = '\0';

    printf( "Type new user's scholarity level (ex: Computer Science Bachelor):\n");
    fgets(scholarity, sizeof(scholarity), stdin);
    scholarity[strcspn(scholarity, "\n")] = '\0';

    printf( "Type new user's graduation year (it can be in the future):\n");
    fgets(graduationYear, sizeof(graduationYear), stdin);
    graduationYear[strcspn(graduationYear, "\n")] = '\0';

    printf( "Type de new user's skills separated by comma (ex: Java, Python, C, ...):\n");
    fgets(skills, sizeof(skills), stdin);
    skills[strcspn(skills, "\n")] = '\0';


    // create json object
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "name", name);
    cJSON_AddStringToObject(root, "age", age);
    cJSON_AddStringToObject(root, "email", email);
    cJSON_AddStringToObject(root, "city", city);
    cJSON_AddStringToObject(root, "state", state);
    cJSON_AddStringToObject(root, "scholarity", scholarity);
    cJSON_AddStringToObject(root, "graduationYear", graduationYear);
    cJSON_AddStringToObject(root, "skills", skills);

    // formt the json object to string
    char * message = cJSON_PrintUnformatted(root);
    cJSON_Delete(root);

    // return the payload and commands to be sent to the server
    return format_message(CREATE_PROFILE, NULL, NULL, message);
}

// todo: organize this function
char * show_all_profiles() {
    char field[100];
  
  strncpy(field, "All", 3);
  field[3] = '\0';
    return format_message(LIST_ALL, field, NULL, NULL);
}

// todo improve the comparision method for spaced values
char * search_group_of_profiles() {
    char field[100], operation[100], value[100], input[1000];

    // receive the query from the client
    printf( "Type the field, comparison method(>, <, ==, <=, >=, !=) and value devided by space (ex: Age > 29):\n");
    
    fgets(input, 1000, stdin);
    input[strcspn(input, "\n")] = '\0';
    parse_string(input, field, operation, value);

    // return the payload and commands to be sent to the server
    return format_message(SEARCH_BATCH, field, operation, value);
}

char * find_profile() {
    char client_input[100];

    // receive key for profile search
    printf( "Type the user's email:\n");
    scanf ("%s",client_input);

    // return the payload and commands to be sent to the server
    return format_message(FIND_PROFILE, NULL, NULL, client_input);
}

char * get_picture() {
    char client_input[100];

    // receive the image name
    printf( "Type the user's email to get image from:\n");
    scanf("%s",client_input);

    // return the payload and commands to be sent to the server
    return format_message(GET_PICTURE, NULL, NULL, client_input);
}







static const char base64_chars[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

int base64_index(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 26;
    }
    if (c >= '0' && c <= '9') {
        return c - '0' + 52;
    }
    if (c == '+') {
        return 62;
    }
    if (c == '/') {
        return 63;
    }
    return -1; // Invalid character
}

char *base64_encode(const unsigned char *data, size_t input_length, size_t *output_length) {
    *output_length = 4 * ((input_length + 2) / 3);
    char *encoded_data = malloc(*output_length);
    if (encoded_data == NULL) {
        return NULL;
    }

    size_t i, j;
    for (i = 0, j = 0; i < input_length;) {
        uint32_t octet_a = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_c = i < input_length ? (unsigned char)data[i++] : 0;

        uint32_t triple = (octet_a << 16) + (octet_b << 8) + octet_c;

        encoded_data[j++] = base64_chars[(triple >> 18) & 0x3F];
        encoded_data[j++] = base64_chars[(triple >> 12) & 0x3F];
        encoded_data[j++] = base64_chars[(triple >> 6) & 0x3F];
        encoded_data[j++] = base64_chars[triple & 0x3F];
    }

    // Pad the remaining bytes with '=' characters
    for (size_t padding = 0; padding < (3 - (input_length % 3)) % 3; padding++) {
        encoded_data[*output_length - 1 - padding] = '=';
    }

    return encoded_data;
}

unsigned char *base64_decode(const char *data, size_t input_length, size_t *output_length) {
    if (input_length % 4 != 0) {
        return NULL;
    }

    *output_length = input_length / 4 * 3;
    if (data[input_length - 1] == '=') {
        (*output_length)--;
    }
    if (data[input_length - 2] == '=') {
        (*output_length)--;
    }

    unsigned char *decoded_data = malloc(*output_length);
    if (decoded_data == NULL) {
        return NULL;
    }

    size_t i, j;
    for (i = 0, j = 0; i < input_length;) {
        uint32_t sextet_a = data[i] == '=' ? 0 & i++ : base64_index(data[i++]);
        uint32_t sextet_b = data[i] == '=' ? 0 & i++ : base64_index(data[i++]);
        uint32_t sextet_c = data[i] == '=' ? 0 & i++ : base64_index(data[i++]);
        uint32_t sextet_d = data[i] == '=' ? 0 & i++ : base64_index(data[i++]);

        uint32_t triple = (sextet_a << 18) + (sextet_b << 12) + (sextet_c << 6) + sextet_d;

        if (j < *output_length) {
            decoded_data[j++] = (triple >> 16) & 0xFF;
        }
        if (j < *output_length) {
            decoded_data[j++] = (triple >> 8) & 0xFF;
        }
        if (j < *output_length) {
            decoded_data[j++] = triple & 0xFF;
        }
    }

    return decoded_data;
}

char * add_picture() {
    char image[BUFFER_SIZE], client_input[100], image_path[400];

    // receive the image name
    printf( "Add a .jpg image in the ./socket-udp/client/image directory\n and name it with the email of a user then fill the next line\n\n");
    printf( "Type the user's email for this profile picture:\n");
    scanf("%s",client_input);

    FILE *image_file;
    size_t numbytes, file_size;

    // Create a string variable
    sprintf(image_path, "./client/image/%s.jpg", client_input);

    image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        printf("Failed to open the image file: %s\n", image_path);
        exit(1);
    }


    // Determine the size of the image file
    fseek(image_file, 0, SEEK_END);
    file_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    // Check if the image file size is greater than the buffer size
    if (file_size > BUFFER_SIZE) {
        printf("Image file size exceeds buffer size\n");
        fclose(image_file);
        exit(1);
    }

    // Read the image file into the buffer
    numbytes = fread(image, 1, file_size, image_file);

    if (numbytes != file_size) {
        printf("Failed to read the image file\n");
        exit(1);
    }

    fclose(image_file);



    // Base64 encoding
    size_t encoded_length = 0;
    char *encoded_data = base64_encode(image, file_size, &encoded_length);

    printf("Base64 Encoded Data: %s\n", encoded_data);

    // Base64 decoding
    size_t decoded_length = 0;
    unsigned char *decoded_data = base64_decode(encoded_data, encoded_length, &decoded_length);

    printf("Base64 Decoded Data: %s\n", decoded_data);

    FILE* output_file;

    output_file = fopen("./client/image/output.jpg", "wb");
    if (output_file == NULL) {
        printf("Failed to open output file.\n");
        exit(1);
    }

    // Write the buffer to the output file
    fwrite(decoded_data, sizeof(char), decoded_length, output_file);
    fclose(output_file);
    free(decoded_data);












    // return the payload and commands to be sent to the server
    return format_message(ADD_PICTURE, client_input, NULL, encoded_data);
}

char * delete_profile() {
    char client_input[100];
    
    // receive key for profile deletion
    printf( "Type the user's email:\n");
    scanf("%s",client_input);

    // return the payload and commands to be sent to the server
    return format_message(DELETE_PROFILE, NULL, NULL, client_input);
}

int main() {
    int client_input_int;
    char trash[2];
    

    printf( "Escolha a ação que deseja realizar digitando o número correspondente:\n\
     1 - cadastrar um novo perfil utilizando o email como identificador;\n\
     2 - listar perfis com base em um critério (>, <, ==, >=, <=, !=);\n\
     3 - listar todas as informações de todos os perfis;\n\
     4 - dado o email de um perfil, retornar suas informações;\n\
     5 - receber foto de usuário;\n\
     6 - remover um perfil;\n\
     7 - cadastrar foto de usuário;\n");
    scanf("%d",&client_input_int);
    trash[0] = getchar();

    char * request;

    switch (client_input_int) {
        case 1:
            request = create_new_user();
            break;

        case 2:
            request = search_group_of_profiles();
            break;

        case 3:
            request = show_all_profiles();
            break;

        case 4:
            request = find_profile();
            break;

        case 5:
            request = get_picture();
            break;

        case 6:
            request = delete_profile();
            break;

        case 7:
            request = add_picture();
            break;

        default:
            printf("You entered an invalid command. Please try again.");
            exit(1);
    };

    int err = use_socket(request, client_input_int == 5);
    free(request);

    if (err != 0) {
        printf("Error: %d\n", err);
        exit(1);
    }

}
