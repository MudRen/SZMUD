// Code of ShenZhou
// color.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
//int i;
	string cn;

        if( me->query("combat_exp") < 2000000)
		return notify_fail("дЦ╣дцШиЫ╩╧╡╩╧╩оЛааё╛ц╩спвй╦Яиои╚║ё\n");
	cn = me->query("colorname");
	if( cn &&  cn[7..strlen(cn)-8] == me->query("name"))
		return notify_fail("дЦ╣дцШвжря╬╜спяуи╚ак║ё\n");

	if( !arg ) return notify_fail("дЦр╙╦Ьвт╪╨╣дцШвжиой╡ц╢и╚ё©\n");

	if( arg == "RED") me->set_color("$RED$");
	if( arg == "GRN") me->set_color("$GRN$");
	if( arg == "YEL") me->set_color("$YEL$");
	if( arg == "BLU") me->set_color("$BLU$");
	if( arg == "MAG") me->set_color("$MAG$");
	if( arg == "CYN") me->set_color("$CYN$");
	if( arg == "WHT") me->set_color("$WHT$");
	if( arg == "HIR") me->set_color("$HIR$");
	if( arg == "HIG") me->set_color("$HIG$");
	if( arg == "HIY") me->set_color("$HIY$");
	if( arg == "HIB") me->set_color("$HIB$");
	if( arg == "HIM") me->set_color("$HIM$");
	if( arg == "HIC") me->set_color("$HIC$");
	if( arg == "HIW") me->set_color("$HIW$");

	else if(!me->query("colorname"))
	return notify_fail("дЦр╙╦Ьвт╪╨╣дцШвжиой╡ц╢и╚ё©\n");

	write("ожтздЦ╣дцШвжф╞аа╤Юак║ё\n");
	return 1;
}
int help(object me)
{
        write(@HELP
ж╦аН╦Яй╫ : color <яуи╚>
 
хГ╧ШдЦсп╤Ч╟ымР╬╜яИё╛дгц╢дЦ©ирт╦ЬдЦвт╪╨оЛаа╣дцШвж╪сиор╩╦Жяуи╚║ё
гКя║тЯртобяуи╚ё╨
ё╗в╒рБё║ё║ё║яуи╚р╩╣╘╪сио╬м╡╩дэ╦Э╦дё╛ЁЩ╥гдЦ╦Э╩╩акцШвжё║ё║ё║ё╘

RED - [31m╨Ли╚[37;0m		HIR - [1;31mаа╨Ли╚[37;0m
GRN - [32mбли╚[37;0m		HIG - [1;32mаабли╚[37;0m
YEL - [33mма╩фи╚[37;0m		HIY - [1;33m╩фи╚[37;0m
BLU - [34mиНю╤и╚[37;0m		HIB - [1;34mю╤и╚[37;0m
MAG - [35mгЁвои╚[37;0m		HIM - [1;35m╥ш╨Ли╚[37;0m
CYN - [36mю╤бли╚[37;0m		HIC - [1;36mлЛгЮи╚[37;0m
WHT - [37mгЁ╩ри╚[37;0m		HIW - [1;37m╟ви╚[37;0m

HELP
        );
        return 1;
}
