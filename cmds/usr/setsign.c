//Cracked by Kafei
// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if( !arg ) {
                me->delete("sign");
                return notify_fail("��Ҫ���Լ���һ��ʲô����ǩ����\n");
        }

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

        me->set("sign", arg + NOR);
        write("���ǩ������ˣ�\n");
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : setsign <ǩ��>
 
���ָ���������Ϊ�Լ�ȡһ�����õ�ǩ���������ϣ����ǩ����
ʹ�� ANSI �Ŀ�����Ԫ�ı���ɫ�����������µĿ����ִ���

$BLK$ - ��ɫ            $NOR$ - �ָ�������ɫ
$RED$ - ��ɫ            $HIR$ - ����ɫ
$GRN$ - ��ɫ            $HIG$ - ����ɫ
$YEL$ - ����ɫ          $HIY$ - ��ɫ
$BLU$ - ����ɫ          $HIB$ - ��ɫ
$MAG$ - ǳ��ɫ          $HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ          $HIC$ - ����ɫ
$WHT$ - ǳ��ɫ          $HIW$ - ��ɫ
 
����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��

HELP
        );
        return 1;
}
