//Cracked by Kafei
// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg ) {
		me->delete("nickname");
		return notify_fail("你要替自己取什么绰号？\n");
	}

	if( strlen(arg) > 40 )
		return notify_fail("你的绰号太长了，想一个短一点的、响亮一点的。\n");

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
	write("你的绰号有了！\n");
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : nick <外号, 绰号>
 
这个指令可以让你为自己取一个响亮的名号或头衔。你如果希望在绰号中
使用 ANSI 的控制字元改变颜色，可以用以下的控制字串：

$BLK$ - 黑色		$NOR$ - 恢复正常颜色
$RED$ - [31m红色[37;0m		$HIR$ - [1;31m亮红色[37;0m
$GRN$ - [32m绿色[37;0m		$HIG$ - [1;32m亮绿色[37;0m
$YEL$ - [33m土黄色[37;0m		$HIY$ - [1;33m黄色[37;0m
$BLU$ - [34m深蓝色[37;0m		$HIB$ - [1;34m蓝色[37;0m
$MAG$ - [35m浅紫色[37;0m		$HIM$ - [1;35m粉红色[37;0m
$CYN$ - [36m蓝绿色[37;0m		$HIC$ - [1;36m天青色[37;0m
$WHT$ - [37m浅灰色[37;0m		$HIW$ - [1;37m白色[37;0m
 
其中系统自动会在字串尾端加一个 $NOR$。

HELP
        );
        return 1;
}
