/* Generated by re2c 0.13.5 */
/**
 * MojoShader; generate shader programs from bytecode of compiled
 *  Direct3D shaders.
 *
 * Please see the file LICENSE.txt in the source's root directory.
 *
 *  This file written by Ryan C. Gordon.
 */

// This was originally based on examples/pp-c.re from re2c: http://re2c.org/
//   re2c is public domain code.
//
// You build mojoshader_lexer_preprocessor.c from the .re file with re2c...
// re2c -is -o mojoshader_lexer_preprocessor.c mojoshader_lexer_preprocessor.re
//
// Changes to the lexer are done to the .re file, not the C code!
//
// Please note that this isn't a perfect C lexer, since it is used for both
//  HLSL and shader assembly language, and follows the quirks of Microsoft's
//  tools.

#define __MOJOSHADER_INTERNAL__ 1
#include "mojoshader_internal.h"

typedef unsigned char uchar;

#define YYMAXFILL 8
#define RET(t) return update_state(s, eoi, cursor, token, (Token) t)
#define YYCTYPE uchar
#define YYCURSOR cursor
#define YYLIMIT limit
#define YYMARKER s->lexer_marker
#define YYFILL(n) { if ((n) == 1) { cursor = sentinel; limit = cursor + YYMAXFILL; eoi = 1; } }

static uchar sentinel[YYMAXFILL];

static Token update_state(IncludeState *s, int eoi, const uchar *cur,
                          const uchar *tok, const Token val)
{
    if (eoi)
    {
        s->bytes_left = 0;
        s->source = (const char *) s->source_base + s->orig_length;
        if ( (tok >= sentinel) && (tok < (sentinel+YYMAXFILL)) )
            s->token = s->source;
        else
            s->token = (const char *) tok;
    } // if
    else
    {
        s->bytes_left -= (unsigned int) (cur - ((const uchar *) s->source));
        s->source = (const char *) cur;
        s->token = (const char *) tok;
    } // else
    s->tokenlen = (unsigned int) (s->source - s->token);
    s->tokenval = val;
    return val;
} // update_state

Token preprocessor_lexer(IncludeState *s)
{
    const uchar *cursor = (const uchar *) s->source;
    const uchar *token = cursor;
    const uchar *matchptr;
    const uchar *limit = cursor + s->bytes_left;
    int eoi = 0;
    int saw_newline = 0;



    // preprocessor directives are only valid at start of line.
    if (s->tokenval == ((Token) '\n'))
        goto ppdirective;  // may jump back to scanner_loop.

scanner_loop:
    if (YYLIMIT == YYCURSOR) YYFILL(1);
    token = cursor;


{
	YYCTYPE yych;
	unsigned int yyaccept = 0;

	if ((YYLIMIT - YYCURSOR) < 5) YYFILL(5);
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy61;
	case '\t':
	case '\v':
	case '\f':
	case ' ':	goto yy63;
	case '\n':	goto yy65;
	case '\r':	goto yy67;
	case '!':	goto yy35;
	case '"':	goto yy14;
	case '#':	goto yy37;
	case '%':	goto yy25;
	case '&':	goto yy29;
	case '\'':	goto yy11;
	case '(':	goto yy39;
	case ')':	goto yy41;
	case '*':	goto yy23;
	case '+':	goto yy19;
	case ',':	goto yy47;
	case '-':	goto yy21;
	case '.':	goto yy12;
	case '/':	goto yy4;
	case '0':	goto yy8;
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy10;
	case ':':	goto yy51;
	case ';':	goto yy59;
	case '<':	goto yy17;
	case '=':	goto yy33;
	case '>':	goto yy15;
	case '?':	goto yy57;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy6;
	case '[':	goto yy43;
	case '\\':	goto yy2;
	case ']':	goto yy45;
	case '^':	goto yy27;
	case '{':	goto yy53;
	case '|':	goto yy31;
	case '}':	goto yy55;
	case '~':	goto yy49;
	default:	goto yy68;
	}
yy2:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 0x08) goto yy3;
	if (yych <= '\r') goto yy177;
	if (yych == ' ') goto yy177;
yy3:
	{ goto bad_chars; }
yy4:
	++YYCURSOR;
	if ((yych = *YYCURSOR) <= '.') {
		if (yych == '*') goto yy174;
	} else {
		if (yych <= '/') goto yy172;
		if (yych == '=') goto yy170;
	}
	{ RET('/'); }
yy6:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy169;
yy7:
	{ RET(TOKEN_IDENTIFIER); }
yy8:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 'X') {
		if (yych <= 'T') {
			if (yych == 'L') goto yy144;
			goto yy160;
		} else {
			if (yych <= 'U') goto yy144;
			if (yych <= 'W') goto yy160;
			goto yy161;
		}
	} else {
		if (yych <= 't') {
			if (yych == 'l') goto yy144;
			goto yy160;
		} else {
			if (yych <= 'u') goto yy144;
			if (yych == 'x') goto yy161;
			goto yy160;
		}
	}
yy9:
	{ RET(TOKEN_INT_LITERAL); }
yy10:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	goto yy142;
yy11:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '\n') goto yy3;
	if (yych == '\r') goto yy3;
	goto yy132;
yy12:
	++YYCURSOR;
	if ((yych = *YYCURSOR) <= '/') goto yy13;
	if (yych <= '9') goto yy123;
yy13:
	{ RET('.'); }
yy14:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '\n') goto yy3;
	if (yych == '\r') goto yy3;
	goto yy113;
yy15:
	++YYCURSOR;
	if ((yych = *YYCURSOR) <= '<') goto yy16;
	if (yych <= '=') goto yy106;
	if (yych <= '>') goto yy108;
yy16:
	{ RET('>'); }
yy17:
	++YYCURSOR;
	if ((yych = *YYCURSOR) <= ';') goto yy18;
	if (yych <= '<') goto yy102;
	if (yych <= '=') goto yy100;
yy18:
	{ RET('<'); }
yy19:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '+') goto yy96;
	if (yych == '=') goto yy98;
	{ RET('+'); }
yy21:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '-') goto yy92;
	if (yych == '=') goto yy94;
	{ RET('-'); }
yy23:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '=') goto yy90;
	{ RET('*'); }
yy25:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '=') goto yy88;
	{ RET('%'); }
yy27:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '=') goto yy86;
	{ RET('^'); }
yy29:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '&') goto yy82;
	if (yych == '=') goto yy84;
	{ RET('&'); }
yy31:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '=') goto yy80;
	if (yych == '|') goto yy78;
	{ RET('|'); }
yy33:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '=') goto yy76;
	{ RET('='); }
yy35:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '=') goto yy74;
	{ RET('!'); }
yy37:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '#') goto yy72;
	{ RET(TOKEN_HASH); }
yy39:
	++YYCURSOR;
	{ RET('('); }
yy41:
	++YYCURSOR;
	{ RET(')'); }
yy43:
	++YYCURSOR;
	{ RET('['); }
yy45:
	++YYCURSOR;
	{ RET(']'); }
yy47:
	++YYCURSOR;
	{ RET(','); }
yy49:
	++YYCURSOR;
	{ RET('~'); }
yy51:
	++YYCURSOR;
	{ RET(':'); }
yy53:
	++YYCURSOR;
	{ RET('{'); }
yy55:
	++YYCURSOR;
	{ RET('}'); }
yy57:
	++YYCURSOR;
	{ RET('?'); }
yy59:
	++YYCURSOR;
	{ if (s->asm_comments) goto singlelinecomment; RET(';'); }
yy61:
	++YYCURSOR;
	{ if (eoi) { RET(TOKEN_EOI); } goto bad_chars; }
yy63:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy71;
yy64:
	{ if (s->report_whitespace) RET(' '); goto scanner_loop; }
yy65:
	++YYCURSOR;
yy66:
	{ s->line++; RET('\n'); }
yy67:
	yych = *++YYCURSOR;
	if (yych == '\n') goto yy69;
	goto yy66;
yy68:
	yych = *++YYCURSOR;
	goto yy3;
yy69:
	yych = *++YYCURSOR;
	goto yy66;
yy70:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy71:
	if (yych <= '\n') {
		if (yych == '\t') goto yy70;
		goto yy64;
	} else {
		if (yych <= '\f') goto yy70;
		if (yych == ' ') goto yy70;
		goto yy64;
	}
yy72:
	++YYCURSOR;
	{ RET(TOKEN_HASHHASH); }
yy74:
	++YYCURSOR;
	{ RET(TOKEN_NEQ); }
yy76:
	++YYCURSOR;
	{ RET(TOKEN_EQL); }
yy78:
	++YYCURSOR;
	{ RET(TOKEN_OROR); }
yy80:
	++YYCURSOR;
	{ RET(TOKEN_ORASSIGN); }
yy82:
	++YYCURSOR;
	{ RET(TOKEN_ANDAND); }
yy84:
	++YYCURSOR;
	{ RET(TOKEN_ANDASSIGN); }
yy86:
	++YYCURSOR;
	{ RET(TOKEN_XORASSIGN); }
yy88:
	++YYCURSOR;
	{ RET(TOKEN_MODASSIGN); }
yy90:
	++YYCURSOR;
	{ RET(TOKEN_MULTASSIGN); }
yy92:
	++YYCURSOR;
	{ RET(TOKEN_DECREMENT); }
yy94:
	++YYCURSOR;
	{ RET(TOKEN_SUBASSIGN); }
yy96:
	++YYCURSOR;
	{ RET(TOKEN_INCREMENT); }
yy98:
	++YYCURSOR;
	{ RET(TOKEN_ADDASSIGN); }
yy100:
	++YYCURSOR;
	{ RET(TOKEN_LEQ); }
yy102:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '=') goto yy104;
	{ RET(TOKEN_LSHIFT); }
yy104:
	++YYCURSOR;
	{ RET(TOKEN_LSHIFTASSIGN); }
yy106:
	++YYCURSOR;
	{ RET(TOKEN_GEQ); }
yy108:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '=') goto yy110;
	{ RET(TOKEN_RSHIFT); }
yy110:
	++YYCURSOR;
	{ RET(TOKEN_RSHIFTASSIGN); }
yy112:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy113:
	if (yych <= '\r') {
		if (yych == '\n') goto yy114;
		if (yych <= '\f') goto yy112;
	} else {
		if (yych <= '"') {
			if (yych <= '!') goto yy112;
			goto yy116;
		} else {
			if (yych == '\\') goto yy115;
			goto yy112;
		}
	}
yy114:
	YYCURSOR = YYMARKER;
	if (yyaccept <= 1) {
		if (yyaccept <= 0) {
			goto yy3;
		} else {
			goto yy9;
		}
	} else {
		goto yy125;
	}
yy115:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'b') {
		if (yych <= '7') {
			if (yych <= '&') {
				if (yych == '"') goto yy112;
				goto yy114;
			} else {
				if (yych <= '\'') goto yy112;
				if (yych <= '/') goto yy114;
				goto yy119;
			}
		} else {
			if (yych <= '[') {
				if (yych == '?') goto yy112;
				goto yy114;
			} else {
				if (yych <= '\\') goto yy112;
				if (yych <= '`') goto yy114;
				goto yy112;
			}
		}
	} else {
		if (yych <= 'r') {
			if (yych <= 'm') {
				if (yych == 'f') goto yy112;
				goto yy114;
			} else {
				if (yych <= 'n') goto yy112;
				if (yych <= 'q') goto yy114;
				goto yy112;
			}
		} else {
			if (yych <= 'u') {
				if (yych == 't') goto yy112;
				goto yy114;
			} else {
				if (yych <= 'v') goto yy112;
				if (yych == 'x') goto yy118;
				goto yy114;
			}
		}
	}
yy116:
	++YYCURSOR;
	{ RET(TOKEN_STRING_LITERAL); }
yy118:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '@') {
		if (yych <= '/') goto yy114;
		if (yych <= '9') goto yy121;
		goto yy114;
	} else {
		if (yych <= 'F') goto yy121;
		if (yych <= '`') goto yy114;
		if (yych <= 'f') goto yy121;
		goto yy114;
	}
yy119:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '!') {
		if (yych <= '\n') {
			if (yych <= '\t') goto yy112;
			goto yy114;
		} else {
			if (yych == '\r') goto yy114;
			goto yy112;
		}
	} else {
		if (yych <= '7') {
			if (yych <= '"') goto yy116;
			if (yych <= '/') goto yy112;
			goto yy119;
		} else {
			if (yych == '\\') goto yy115;
			goto yy112;
		}
	}
yy121:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '/') {
		if (yych <= '\f') {
			if (yych == '\n') goto yy114;
			goto yy112;
		} else {
			if (yych <= '\r') goto yy114;
			if (yych == '"') goto yy116;
			goto yy112;
		}
	} else {
		if (yych <= '[') {
			if (yych <= '9') goto yy121;
			if (yych <= '@') goto yy112;
			if (yych <= 'F') goto yy121;
			goto yy112;
		} else {
			if (yych <= '\\') goto yy115;
			if (yych <= '`') goto yy112;
			if (yych <= 'f') goto yy121;
			goto yy112;
		}
	}
yy123:
	yyaccept = 2;
	YYMARKER = ++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	if (yych <= 'G') {
		if (yych <= 'D') {
			if (yych <= '/') goto yy125;
			if (yych <= '9') goto yy123;
		} else {
			if (yych <= 'E') goto yy126;
			if (yych <= 'F') goto yy127;
		}
	} else {
		if (yych <= 'e') {
			if (yych <= 'H') goto yy127;
			if (yych >= 'e') goto yy126;
		} else {
			if (yych == 'g') goto yy125;
			if (yych <= 'h') goto yy127;
		}
	}
yy125:
	{ RET(TOKEN_FLOAT_LITERAL); }
yy126:
	yych = *++YYCURSOR;
	if (yych <= ',') {
		if (yych == '+') goto yy128;
		goto yy114;
	} else {
		if (yych <= '-') goto yy128;
		if (yych <= '/') goto yy114;
		if (yych <= '9') goto yy129;
		goto yy114;
	}
yy127:
	yych = *++YYCURSOR;
	goto yy125;
yy128:
	yych = *++YYCURSOR;
	if (yych <= '/') goto yy114;
	if (yych >= ':') goto yy114;
yy129:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'G') {
		if (yych <= '9') {
			if (yych <= '/') goto yy125;
			goto yy129;
		} else {
			if (yych == 'F') goto yy127;
			goto yy125;
		}
	} else {
		if (yych <= 'f') {
			if (yych <= 'H') goto yy127;
			if (yych <= 'e') goto yy125;
			goto yy127;
		} else {
			if (yych == 'h') goto yy127;
			goto yy125;
		}
	}
yy131:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy132:
	if (yych <= '\r') {
		if (yych == '\n') goto yy114;
		if (yych <= '\f') goto yy131;
		goto yy114;
	} else {
		if (yych <= '\'') {
			if (yych <= '&') goto yy131;
			goto yy134;
		} else {
			if (yych != '\\') goto yy131;
		}
	}
yy133:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'b') {
		if (yych <= '7') {
			if (yych <= '&') {
				if (yych == '"') goto yy131;
				goto yy114;
			} else {
				if (yych <= '\'') goto yy131;
				if (yych <= '/') goto yy114;
				goto yy136;
			}
		} else {
			if (yych <= '[') {
				if (yych == '?') goto yy131;
				goto yy114;
			} else {
				if (yych <= '\\') goto yy131;
				if (yych <= '`') goto yy114;
				goto yy131;
			}
		}
	} else {
		if (yych <= 'r') {
			if (yych <= 'm') {
				if (yych == 'f') goto yy131;
				goto yy114;
			} else {
				if (yych <= 'n') goto yy131;
				if (yych <= 'q') goto yy114;
				goto yy131;
			}
		} else {
			if (yych <= 'u') {
				if (yych == 't') goto yy131;
				goto yy114;
			} else {
				if (yych <= 'v') goto yy131;
				if (yych == 'x') goto yy135;
				goto yy114;
			}
		}
	}
yy134:
	yych = *++YYCURSOR;
	goto yy9;
yy135:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '@') {
		if (yych <= '/') goto yy114;
		if (yych <= '9') goto yy138;
		goto yy114;
	} else {
		if (yych <= 'F') goto yy138;
		if (yych <= '`') goto yy114;
		if (yych <= 'f') goto yy138;
		goto yy114;
	}
yy136:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '&') {
		if (yych <= '\n') {
			if (yych <= '\t') goto yy131;
			goto yy114;
		} else {
			if (yych == '\r') goto yy114;
			goto yy131;
		}
	} else {
		if (yych <= '7') {
			if (yych <= '\'') goto yy134;
			if (yych <= '/') goto yy131;
			goto yy136;
		} else {
			if (yych == '\\') goto yy133;
			goto yy131;
		}
	}
yy138:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '/') {
		if (yych <= '\f') {
			if (yych == '\n') goto yy114;
			goto yy131;
		} else {
			if (yych <= '\r') goto yy114;
			if (yych == '\'') goto yy134;
			goto yy131;
		}
	} else {
		if (yych <= '[') {
			if (yych <= '9') goto yy138;
			if (yych <= '@') goto yy131;
			if (yych <= 'F') goto yy138;
			goto yy131;
		} else {
			if (yych <= '\\') goto yy133;
			if (yych <= '`') goto yy131;
			if (yych <= 'f') goto yy138;
			goto yy131;
		}
	}
yy140:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == 'E') goto yy151;
	if (yych == 'e') goto yy151;
	goto yy150;
yy141:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
yy142:
	if (yych <= 'L') {
		if (yych <= '9') {
			if (yych == '.') goto yy140;
			if (yych <= '/') goto yy9;
			goto yy141;
		} else {
			if (yych == 'E') goto yy143;
			if (yych <= 'K') goto yy9;
			goto yy144;
		}
	} else {
		if (yych <= 'e') {
			if (yych == 'U') goto yy144;
			if (yych <= 'd') goto yy9;
		} else {
			if (yych <= 'l') {
				if (yych <= 'k') goto yy9;
				goto yy144;
			} else {
				if (yych == 'u') goto yy144;
				goto yy9;
			}
		}
	}
yy143:
	yych = *++YYCURSOR;
	if (yych <= ',') {
		if (yych == '+') goto yy146;
		goto yy114;
	} else {
		if (yych <= '-') goto yy146;
		if (yych <= '/') goto yy114;
		if (yych <= '9') goto yy147;
		goto yy114;
	}
yy144:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'U') {
		if (yych == 'L') goto yy144;
		if (yych <= 'T') goto yy9;
		goto yy144;
	} else {
		if (yych <= 'l') {
			if (yych <= 'k') goto yy9;
			goto yy144;
		} else {
			if (yych == 'u') goto yy144;
			goto yy9;
		}
	}
yy146:
	yych = *++YYCURSOR;
	if (yych <= '/') goto yy114;
	if (yych >= ':') goto yy114;
yy147:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'G') {
		if (yych <= '9') {
			if (yych <= '/') goto yy125;
			goto yy147;
		} else {
			if (yych == 'F') goto yy127;
			goto yy125;
		}
	} else {
		if (yych <= 'f') {
			if (yych <= 'H') goto yy127;
			if (yych <= 'e') goto yy125;
			goto yy127;
		} else {
			if (yych == 'h') goto yy127;
			goto yy125;
		}
	}
yy149:
	yyaccept = 2;
	YYMARKER = ++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
yy150:
	if (yych <= 'G') {
		if (yych <= 'D') {
			if (yych <= '/') goto yy125;
			if (yych <= '9') goto yy149;
			goto yy125;
		} else {
			if (yych <= 'E') goto yy155;
			if (yych <= 'F') goto yy127;
			goto yy125;
		}
	} else {
		if (yych <= 'e') {
			if (yych <= 'H') goto yy127;
			if (yych <= 'd') goto yy125;
			goto yy155;
		} else {
			if (yych == 'g') goto yy125;
			if (yych <= 'h') goto yy127;
			goto yy125;
		}
	}
yy151:
	yych = *++YYCURSOR;
	if (yych <= ',') {
		if (yych != '+') goto yy114;
	} else {
		if (yych <= '-') goto yy152;
		if (yych <= '/') goto yy114;
		if (yych <= '9') goto yy153;
		goto yy114;
	}
yy152:
	yych = *++YYCURSOR;
	if (yych <= '/') goto yy114;
	if (yych >= ':') goto yy114;
yy153:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'G') {
		if (yych <= '9') {
			if (yych <= '/') goto yy125;
			goto yy153;
		} else {
			if (yych == 'F') goto yy127;
			goto yy125;
		}
	} else {
		if (yych <= 'f') {
			if (yych <= 'H') goto yy127;
			if (yych <= 'e') goto yy125;
			goto yy127;
		} else {
			if (yych == 'h') goto yy127;
			goto yy125;
		}
	}
yy155:
	yych = *++YYCURSOR;
	if (yych <= ',') {
		if (yych != '+') goto yy114;
	} else {
		if (yych <= '-') goto yy156;
		if (yych <= '/') goto yy114;
		if (yych <= '9') goto yy157;
		goto yy114;
	}
yy156:
	yych = *++YYCURSOR;
	if (yych <= '/') goto yy114;
	if (yych >= ':') goto yy114;
yy157:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'G') {
		if (yych <= '9') {
			if (yych <= '/') goto yy125;
			goto yy157;
		} else {
			if (yych == 'F') goto yy127;
			goto yy125;
		}
	} else {
		if (yych <= 'f') {
			if (yych <= 'H') goto yy127;
			if (yych <= 'e') goto yy125;
			goto yy127;
		} else {
			if (yych == 'h') goto yy127;
			goto yy125;
		}
	}
yy159:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
yy160:
	if (yych <= 'L') {
		if (yych <= '9') {
			if (yych == '.') goto yy140;
			if (yych <= '/') goto yy9;
			goto yy159;
		} else {
			if (yych == 'E') goto yy143;
			if (yych <= 'K') goto yy9;
			goto yy166;
		}
	} else {
		if (yych <= 'e') {
			if (yych == 'U') goto yy166;
			if (yych <= 'd') goto yy9;
			goto yy143;
		} else {
			if (yych <= 'l') {
				if (yych <= 'k') goto yy9;
				goto yy166;
			} else {
				if (yych == 'u') goto yy166;
				goto yy9;
			}
		}
	}
yy161:
	yych = *++YYCURSOR;
	if (yych <= '@') {
		if (yych <= '/') goto yy114;
		if (yych >= ':') goto yy114;
	} else {
		if (yych <= 'F') goto yy162;
		if (yych <= '`') goto yy114;
		if (yych >= 'g') goto yy114;
	}
yy162:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'T') {
		if (yych <= '@') {
			if (yych <= '/') goto yy9;
			if (yych <= '9') goto yy162;
			goto yy9;
		} else {
			if (yych <= 'F') goto yy162;
			if (yych != 'L') goto yy9;
		}
	} else {
		if (yych <= 'k') {
			if (yych <= 'U') goto yy164;
			if (yych <= '`') goto yy9;
			if (yych <= 'f') goto yy162;
			goto yy9;
		} else {
			if (yych <= 'l') goto yy164;
			if (yych != 'u') goto yy9;
		}
	}
yy164:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'U') {
		if (yych == 'L') goto yy164;
		if (yych <= 'T') goto yy9;
		goto yy164;
	} else {
		if (yych <= 'l') {
			if (yych <= 'k') goto yy9;
			goto yy164;
		} else {
			if (yych == 'u') goto yy164;
			goto yy9;
		}
	}
yy166:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'U') {
		if (yych == 'L') goto yy166;
		if (yych <= 'T') goto yy9;
		goto yy166;
	} else {
		if (yych <= 'l') {
			if (yych <= 'k') goto yy9;
			goto yy166;
		} else {
			if (yych == 'u') goto yy166;
			goto yy9;
		}
	}
yy168:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy169:
	if (yych <= 'Z') {
		if (yych <= '/') goto yy7;
		if (yych <= '9') goto yy168;
		if (yych <= '@') goto yy7;
		goto yy168;
	} else {
		if (yych <= '_') {
			if (yych <= '^') goto yy7;
			goto yy168;
		} else {
			if (yych <= '`') goto yy7;
			if (yych <= 'z') goto yy168;
			goto yy7;
		}
	}
yy170:
	++YYCURSOR;
	{ RET(TOKEN_DIVASSIGN); }
yy172:
	++YYCURSOR;
	{ goto singlelinecomment; }
yy174:
	++YYCURSOR;
	{ goto multilinecomment; }
yy176:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
yy177:
	if (yych <= '\f') {
		if (yych <= 0x08) goto yy114;
		if (yych != '\n') goto yy176;
	} else {
		if (yych <= '\r') goto yy180;
		if (yych == ' ') goto yy176;
		goto yy114;
	}
yy178:
	++YYCURSOR;
yy179:
	{ s->line++; goto scanner_loop; }
yy180:
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '\n') goto yy178;
	goto yy179;
}


multilinecomment:
    if (YYLIMIT == YYCURSOR) YYFILL(1);
    matchptr = cursor;
// The "*\/" is just to avoid screwing up text editor syntax highlighting.

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych <= '\f') {
		if (yych <= 0x00) goto yy188;
		if (yych == '\n') goto yy185;
		goto yy190;
	} else {
		if (yych <= '\r') goto yy187;
		if (yych != '*') goto yy190;
	}
	++YYCURSOR;
	if ((yych = *YYCURSOR) == '/') goto yy192;
yy184:
	{ goto multilinecomment; }
yy185:
	++YYCURSOR;
yy186:
	{
                        s->line++;
                        token = matchptr;
                        saw_newline = 1;
                        goto multilinecomment;
                    }
yy187:
	yych = *++YYCURSOR;
	if (yych == '\n') goto yy191;
	goto yy186;
yy188:
	++YYCURSOR;
	{
                        if (eoi)
                            RET(TOKEN_INCOMPLETE_COMMENT);
                        goto multilinecomment;
                    }
yy190:
	yych = *++YYCURSOR;
	goto yy184;
yy191:
	yych = *++YYCURSOR;
	goto yy186;
yy192:
	++YYCURSOR;
	{
                        if (s->report_comments)
                            RET(TOKEN_MULTI_COMMENT);
                        else if (saw_newline)
                            RET('\n');
                        else if (s->report_whitespace)
                            RET(' ');
                        goto scanner_loop;
                    }
}


singlelinecomment:
    if (YYLIMIT == YYCURSOR) YYFILL(1);
    matchptr = cursor;

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych <= '\n') {
		if (yych <= 0x00) goto yy199;
		if (yych <= '\t') goto yy201;
	} else {
		if (yych == '\r') goto yy198;
		goto yy201;
	}
	++YYCURSOR;
yy197:
	{
                        s->line++;
                        if (s->report_comments)
                            RET(TOKEN_SINGLE_COMMENT);
                        token = matchptr;
                        RET('\n');
                    }
yy198:
	yych = *++YYCURSOR;
	if (yych == '\n') goto yy203;
	goto yy197;
yy199:
	++YYCURSOR;
	{
                        if (eoi)
                        {
                            if (s->report_comments)
                                RET(TOKEN_SINGLE_COMMENT);
                            else
                                RET(TOKEN_EOI);
                        }
                        goto singlelinecomment;
                    }
yy201:
	++YYCURSOR;
	{ goto singlelinecomment; }
yy203:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy197;
}


ppdirective:
    if (YYLIMIT == YYCURSOR) YYFILL(1);

{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	if ((YYLIMIT - YYCURSOR) < 8) YYFILL(8);
	yych = *YYCURSOR;
	if (yych <= '\f') {
		if (yych == '\t') goto yy208;
		if (yych <= '\n') goto yy210;
		goto yy208;
	} else {
		if (yych <= ' ') {
			if (yych <= 0x1F) goto yy210;
			goto yy208;
		} else {
			if (yych != '#') goto yy210;
		}
	}
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 'h') {
		if (yych <= 0x1F) {
			if (yych == '\t') goto yy214;
		} else {
			if (yych <= ' ') goto yy214;
			if (yych <= 'c') goto yy207;
			if (yych <= 'e') goto yy214;
		}
	} else {
		if (yych <= 'o') {
			if (yych <= 'i') goto yy214;
			if (yych == 'l') goto yy214;
		} else {
			if (yych <= 'p') goto yy214;
			if (yych == 'u') goto yy214;
		}
	}
yy207:
	{
                            token = cursor = (const uchar *) s->source;
                            limit = cursor + s->bytes_left;
                            goto scanner_loop;
                        }
yy208:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy212;
yy209:
	{ goto ppdirective; }
yy210:
	yych = *++YYCURSOR;
	goto yy207;
yy211:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy212:
	if (yych <= '\n') {
		if (yych == '\t') goto yy211;
		goto yy209;
	} else {
		if (yych <= '\f') goto yy211;
		if (yych == ' ') goto yy211;
		goto yy209;
	}
yy213:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 7) YYFILL(7);
	yych = *YYCURSOR;
yy214:
	if (yych <= 'h') {
		if (yych <= ' ') {
			if (yych == '\t') goto yy213;
			if (yych >= ' ') goto yy213;
		} else {
			if (yych <= 'c') goto yy215;
			if (yych <= 'd') goto yy220;
			if (yych <= 'e') goto yy217;
		}
	} else {
		if (yych <= 'o') {
			if (yych <= 'i') goto yy218;
			if (yych == 'l') goto yy221;
		} else {
			if (yych <= 'p') goto yy216;
			if (yych == 'u') goto yy219;
		}
	}
yy215:
	YYCURSOR = YYMARKER;
	if (yyaccept <= 0) {
		goto yy207;
	} else {
		goto yy239;
	}
yy216:
	yych = *++YYCURSOR;
	if (yych == 'r') goto yy272;
	goto yy215;
yy217:
	yych = *++YYCURSOR;
	if (yych <= 'm') {
		if (yych == 'l') goto yy255;
		goto yy215;
	} else {
		if (yych <= 'n') goto yy256;
		if (yych == 'r') goto yy257;
		goto yy215;
	}
yy218:
	yych = *++YYCURSOR;
	if (yych == 'f') goto yy238;
	if (yych == 'n') goto yy237;
	goto yy215;
yy219:
	yych = *++YYCURSOR;
	if (yych == 'n') goto yy232;
	goto yy215;
yy220:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy226;
	goto yy215;
yy221:
	yych = *++YYCURSOR;
	if (yych != 'i') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'n') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy215;
	++YYCURSOR;
	{ RET(TOKEN_PP_LINE); }
yy226:
	yych = *++YYCURSOR;
	if (yych != 'f') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'i') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'n') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy215;
	++YYCURSOR;
	{ RET(TOKEN_PP_DEFINE); }
yy232:
	yych = *++YYCURSOR;
	if (yych != 'd') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'f') goto yy215;
	++YYCURSOR;
	{ RET(TOKEN_PP_UNDEF); }
yy237:
	yych = *++YYCURSOR;
	if (yych == 'c') goto yy249;
	goto yy215;
yy238:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == 'd') goto yy241;
	if (yych == 'n') goto yy240;
yy239:
	{ RET(TOKEN_PP_IF); }
yy240:
	yych = *++YYCURSOR;
	if (yych == 'd') goto yy245;
	goto yy215;
yy241:
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'f') goto yy215;
	++YYCURSOR;
	{ RET(TOKEN_PP_IFDEF); }
yy245:
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'f') goto yy215;
	++YYCURSOR;
	{ RET(TOKEN_PP_IFNDEF); }
yy249:
	yych = *++YYCURSOR;
	if (yych != 'l') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'u') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'd') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy215;
	++YYCURSOR;
	{ RET(TOKEN_PP_INCLUDE); }
yy255:
	yych = *++YYCURSOR;
	if (yych == 'i') goto yy266;
	if (yych == 's') goto yy267;
	goto yy215;
yy256:
	yych = *++YYCURSOR;
	if (yych == 'd') goto yy262;
	goto yy215;
yy257:
	yych = *++YYCURSOR;
	if (yych != 'r') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'o') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'r') goto yy215;
	++YYCURSOR;
	{ RET(TOKEN_PP_ERROR); }
yy262:
	yych = *++YYCURSOR;
	if (yych != 'i') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'f') goto yy215;
	++YYCURSOR;
	{ RET(TOKEN_PP_ENDIF); }
yy266:
	yych = *++YYCURSOR;
	if (yych == 'f') goto yy270;
	goto yy215;
yy267:
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy215;
	++YYCURSOR;
	{ RET(TOKEN_PP_ELSE); }
yy270:
	++YYCURSOR;
	{ RET(TOKEN_PP_ELIF); }
yy272:
	yych = *++YYCURSOR;
	if (yych != 'a') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'g') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'm') goto yy215;
	yych = *++YYCURSOR;
	if (yych != 'a') goto yy215;
	++YYCURSOR;
	{ RET(TOKEN_PP_PRAGMA); }
}


bad_chars:
    if (YYLIMIT == YYCURSOR) YYFILL(1);

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '#') {
		if (yych <= '\r') {
			if (yych <= 0x00) goto yy282;
			if (yych <= 0x08) goto yy284;
		} else {
			if (yych <= 0x1F) goto yy284;
			if (yych == '"') goto yy284;
		}
	} else {
		if (yych <= '@') {
			if (yych <= '$') goto yy284;
			if (yych >= '@') goto yy284;
		} else {
			if (yych == '`') goto yy284;
			if (yych >= 0x7F) goto yy284;
		}
	}
	++YYCURSOR;
	{ cursor--; RET(TOKEN_BAD_CHARS); }
yy282:
	++YYCURSOR;
	{
                        if (eoi)
                        {
                            assert( !((token >= sentinel) &&
                                     (token < sentinel+YYMAXFILL)) );
                            eoi = 0;
                            cursor = (uchar *) s->source_base + s->orig_length;
                            RET(TOKEN_BAD_CHARS);  // next call will be EOI.
                        }
                        goto bad_chars;
                    }
yy284:
	++YYCURSOR;
	{ goto bad_chars; }
}


    assert(0 && "Shouldn't hit this code");
    RET(TOKEN_UNKNOWN);
} // preprocessor_lexer

// end of mojoshader_lexer_preprocessor.re (or .c) ...

