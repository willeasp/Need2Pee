


/* Declare bitmap array containing font */
extern const uint8_t const font[128*8];
/* Declare bitmap array containing icon */
extern const uint8_t const icon[128];

/* Declare text buffer for display output */
extern char textbuffer[4][16];


void setup_chipkit ( void );
void delay(int cyc);
uint8_t spi_send_recv(uint8_t data);
void display_init();
void display_string(int line, char *s);
void display_image(int x, const uint8_t *data);
void display_update();

void timerinit (void);
void interruptinit (void);


