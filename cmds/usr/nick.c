//Cracked by Kafei
// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg ) {
		me->delete("nickname");
		return notify_fail("��Ҫ���Լ�ȡʲô�ºţ�\n");
	}

	if( strlen(arg) > 40 )
		return notify_fail("��Ĵº�̫���ˣ���һ����һ��ġ�����һ��ġ�\n");

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
	write("��Ĵº����ˣ�\n");
	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : nick <���, �º�>
 
���ָ���������Ϊ�Լ�ȡһ�����������Ż�ͷ�Ρ������ϣ���ڴº���
ʹ�� ANSI �Ŀ�����Ԫ�ı���ɫ�����������µĿ����ִ���

$BLK$ - ��ɫ		$NOR$ - �ָ�������ɫ
$RED$ - [31m��ɫ[37;0m		$HIR$ - [1;31m����ɫ[37;0m
$GRN$ - [32m��ɫ[37;0m		$HIG$ - [1;32m����ɫ[37;0m
$YEL$ - [33m����ɫ[37;0m		$HIY$ - [1;33m��ɫ[37;0m
$BLU$ - [34m����ɫ[37;0m		$HIB$ - [1;34m��ɫ[37;0m
$MAG$ - [35mǳ��ɫ[37;0m		$HIM$ - [1;35m�ۺ�ɫ[37;0m
$CYN$ - [36m����ɫ[37;0m		$HIC$ - [1;36m����ɫ[37;0m
$WHT$ - [37mǳ��ɫ[37;0m		$HIW$ - [1;37m��ɫ[37;0m
 
����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��

HELP
        );
        return 1;
}
