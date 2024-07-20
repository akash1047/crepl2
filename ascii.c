#define SHIFT(n) (1 << (n))

#define SPACE SHIFT(1)
#define ALPHA SHIFT(2)
#define UPPER SHIFT(3)
#define LOWER SHIFT(4)
#define DIGIT SHIFT(5)
#define HEX SHIFT(6)
#define BIN SHIFT(7)
#define OCT SHIFT(8)

static int ASCII_TABLE[128] = {
    0,                       // NUL - Null
    0,                       // SOH - Start of Heading
    0,                       // STX - Start of Text
    0,                       // ETX - End of Text
    0,                       // EOT - End of Transmission
    0,                       // ENQ - Enquiry
    0,                       // ACK - Acknowledgment
    0,                       // BEL - Bell
    0,                       // BS - Backspace
    SPACE,                   // TAB - Horizontal Tab
    SPACE,                   // LF - Line Feed
    0,                       // VT - Vertical Tab
    0,                       // FF - Form Feed
    SPACE,                   // CR - Carriage Return
    0,                       // SO - Shift Out
    0,                       // SI - Shift In
    0,                       // DLE - Data Link Escape
    0,                       // DC1 - Device Control 1 (XON)
    0,                       // DC2 - Device Control 2
    0,                       // DC3 - Device Control 3 (XOFF)
    0,                       // DC4 - Device Control 4
    0,                       // NAK - Negative Acknowledgment
    0,                       // SYN - Synchronous Idle
    0,                       // ETB - End of Transmission Block
    0,                       // CAN - Cancel
    0,                       // EM - End of Medium
    0,                       // SUB - Substitute
    0,                       // ESC - Escape
    0,                       // FS - File Separator
    0,                       // GS - Group Separator
    0,                       // RS - Record Separator
    0,                       // US - Unit Separator
    SPACE,                   // ' ' - Space
    0,                       // ! - Exclamation Mark
    0,                       // " - Quotation Mark
    0,                       // # - Number Sign
    0,                       // $ - Dollar Sign
    0,                       // % - Percent Sign
    0,                       // & - Ampersand
    0,                       // ' - Apostrophe
    0,                       // ( - Left Parenthesis
    0,                       // ) - Right Parenthesis
    0,                       // * - Asterisk
    0,                       // + - Plus Sign
    0,                       // , - Comma
    0,                       // - - Hyphen-Minus
    0,                       // . - Full Stop
    0,                       // / - Solidus
    DIGIT | HEX | OCT | BIN, // 0 - Digit Zero
    DIGIT | HEX | OCT | BIN, // 1 - Digit One
    DIGIT | HEX | OCT,       // 2 - Digit Two
    DIGIT | HEX | OCT,       // 3 - Digit Three
    DIGIT | HEX | OCT,       // 4 - Digit Four
    DIGIT | HEX | OCT,       // 5 - Digit Five
    DIGIT | HEX | OCT,       // 6 - Digit Six
    DIGIT | HEX | OCT,       // 7 - Digit Seven
    DIGIT | HEX,             // 8 - Digit Eight
    DIGIT | HEX,             // 9 - Digit Nine
    0,                       // : - Colon
    0,                       // ; - Semicolon
    0,                       // < - Less-Than Sign
    0,                       // = - Equals Sign
    0,                       // > - Greater-Than Sign
    0,                       // ? - Question Mark
    0,                       // @ - Commercial At
    ALPHA | UPPER | HEX,     // A - Latin Capital Letter A
    ALPHA | UPPER | HEX,     // B - Latin Capital Letter B
    ALPHA | UPPER | HEX,     // C - Latin Capital Letter C
    ALPHA | UPPER | HEX,     // D - Latin Capital Letter D
    ALPHA | UPPER | HEX,     // E - Latin Capital Letter E
    ALPHA | UPPER | HEX,     // F - Latin Capital Letter F
    ALPHA | UPPER,           // G - Latin Capital Letter G
    ALPHA | UPPER,           // H - Latin Capital Letter H
    ALPHA | UPPER,           // I - Latin Capital Letter I
    ALPHA | UPPER,           // J - Latin Capital Letter J
    ALPHA | UPPER,           // K - Latin Capital Letter K
    ALPHA | UPPER,           // L - Latin Capital Letter L
    ALPHA | UPPER,           // M - Latin Capital Letter M
    ALPHA | UPPER,           // N - Latin Capital Letter N
    ALPHA | UPPER,           // O - Latin Capital Letter O
    ALPHA | UPPER,           // P - Latin Capital Letter P
    ALPHA | UPPER,           // Q - Latin Capital Letter Q
    ALPHA | UPPER,           // R - Latin Capital Letter R
    ALPHA | UPPER,           // S - Latin Capital Letter S
    ALPHA | UPPER,           // T - Latin Capital Letter T
    ALPHA | UPPER,           // U - Latin Capital Letter U
    ALPHA | UPPER,           // V - Latin Capital Letter V
    ALPHA | UPPER,           // W - Latin Capital Letter W
    ALPHA | UPPER,           // X - Latin Capital Letter X
    ALPHA | UPPER,           // Y - Latin Capital Letter Y
    ALPHA | UPPER,           // Z - Latin Capital Letter Z
    0,                       // [ - Left Square Bracket
    0,                       // \ - Reverse Solidus
    0,                       // ] - Right Square Bracket
    0,                       // ^ - Circumflex Accent
    0,                       // _ - Low Line
    0,                       // ` - Grave Accent
    ALPHA | LOWER | HEX,     // a - Latin Small Letter A
    ALPHA | LOWER | HEX,     // b - Latin Small Letter B
    ALPHA | LOWER | HEX,     // c - Latin Small Letter C
    ALPHA | LOWER | HEX,     // d - Latin Small Letter D
    ALPHA | LOWER | HEX,     // e - Latin Small Letter E
    ALPHA | LOWER | HEX,     // f - Latin Small Letter F
    ALPHA | LOWER,           // g - Latin Small Letter G
    ALPHA | LOWER,           // h - Latin Small Letter H
    ALPHA | LOWER,           // i - Latin Small Letter I
    ALPHA | LOWER,           // j - Latin Small Letter J
    ALPHA | LOWER,           // k - Latin Small Letter K
    ALPHA | LOWER,           // l - Latin Small Letter L
    ALPHA | LOWER,           // m - Latin Small Letter M
    ALPHA | LOWER,           // n - Latin Small Letter N
    ALPHA | LOWER,           // o - Latin Small Letter O
    ALPHA | LOWER,           // p - Latin Small Letter P
    ALPHA | LOWER,           // q - Latin Small Letter Q
    ALPHA | LOWER,           // r - Latin Small Letter R
    ALPHA | LOWER,           // s - Latin Small Letter S
    ALPHA | LOWER,           // t - Latin Small Letter T
    ALPHA | LOWER,           // u - Latin Small Letter U
    ALPHA | LOWER,           // v - Latin Small Letter V
    ALPHA | LOWER,           // w - Latin Small Letter W
    ALPHA | LOWER,           // x - Latin Small Letter X
    ALPHA | LOWER,           // y - Latin Small Letter Y
    ALPHA | LOWER,           // z - Latin Small Letter Z
    0,                       // { - Left Curly Bracket
    0,                       // | - Vertical Line
    0,                       // } - Right Curly Bracket
    0,                       // ~ - Tilde
    0,                       // DEL - Delete
};
