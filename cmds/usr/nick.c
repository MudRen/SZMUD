//Cracked by Kafei
// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg ) {
		me->delete("nickname");
		return notify_fail("дЦр╙лФвт╪╨х║й╡ц╢╢б╨её©\n");
	}

	if( strlen(arg) > 40 )
		return notify_fail("дЦ╣д╢б╨ел╚Ё╓акё╛оКр╩╦Ж╤лр╩╣Ц╣д║╒оЛаар╩╣Ц╣д║ё\n");

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("nickname", arg + NOR);
	write("дЦ╣д╢б╨еспакё║\n");
	return 1;
}
int help(object me)
{
        write(@HELP
ж╦аН╦Яй╫ : nick <мБ╨е, ╢б╨е>
 
уБ╦Жж╦аН©иртхцдЦн╙вт╪╨х║р╩╦ЖоЛаа╣дцШ╨е╩Рм╥он║ёдЦхГ╧ШоёмШтз╢б╨ежп
й╧сц ANSI ╣д©ьжфвжт╙╦д╠Дяуи╚ё╛©иртсцртоб╣д©ьжфвж╢╝ё╨

$BLK$ - ╨зи╚		$NOR$ - ╩ж╦╢уЩЁёяуи╚
$RED$ - [31m╨Ли╚[37;0m		$HIR$ - [1;31mаа╨Ли╚[37;0m
$GRN$ - [32mбли╚[37;0m		$HIG$ - [1;32mаабли╚[37;0m
$YEL$ - [33mма╩фи╚[37;0m		$HIY$ - [1;33m╩фи╚[37;0m
$BLU$ - [34mиНю╤и╚[37;0m		$HIB$ - [1;34mю╤и╚[37;0m
$MAG$ - [35mгЁвои╚[37;0m		$HIM$ - [1;35m╥ш╨Ли╚[37;0m
$CYN$ - [36mю╤бли╚[37;0m		$HIC$ - [1;36mлЛгЮи╚[37;0m
$WHT$ - [37mгЁ╩ри╚[37;0m		$HIW$ - [1;37m╟ви╚[37;0m
 
фДжпо╣мЁвт╤╞╩Атзвж╢╝н╡╤к╪ср╩╦Ж $NOR$║ё

HELP
        );
        return 1;
}
