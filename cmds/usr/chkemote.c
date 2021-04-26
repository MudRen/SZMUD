// function:    display emote
// update by:   ken@mud.szptt.net.cn
// update time: 1998-03-13

#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
inherit EMOTE_D;

int main(object me, string arg)
{
        mapping point;
        string *emotes, msg, str;
        int i;
        if( !arg || lower_case(arg) == "all") {
                emotes = sort_array(query_all_emote(), 1);
                if( !emotes ) {
                        msg = MUD_NAME+"��ǰû���κ� emote��\n";
                        return notify_fail(msg);
                }
        }
        else {
                point = EMOTE_D->query_emote(arg);
                if( !point["updated"] ) {
                        msg = sprintf("%s��ǰû�� %s ��� emote��\n",MUD_NAME,arg);
                        return notify_fail(msg);
                }
        }
	msg = "\n";
        if( ! arg || lower_case(arg) == "all") 
                        return notify_fail("��ָ��emote�����\n");		
                str = point["target"];
                str = replace_string(str, "$n", "��");
                str = replace_string(str, "$p", "��");
                str = replace_string(str, "$R", "(������)");
                str = replace_string(str, "$r", "(������)");
                msg += sprintf(WHT"\nemote ���ƣ�"CYN"%s\n"WHT
                	"������������������������������������������������������������������������\n"CYN
                        "�Լ�������\n��ʹ�ö���      %sʹ�ö������Լ���  %sʹ�ö��������ˣ�  %s\n\n"
                        CYN"�Է�������\n%s\n"
                        CYN"�����˿�����\n��ʹ�ö���      %sʹ�ö������Լ���  %sʹ�ö��������ˣ�  %s\n"
                        WHT"������������������������������������������������������������������������\n"NOR,
                        arg,
                        point["myself"], point["myself_self"],point["myself_target"],
                        str,
                        point["others_self"],
                        point["others"],
                        point["others_target"] );
                        msg = replace_string(msg, "$n", "(�Է�)");
                        msg = replace_string(msg, "$N", me->name(1));
                        msg = replace_string(msg, "$P", "��");
                        msg = replace_string(msg, "$p", "(��/��)");
                        msg = replace_string(msg, "$S", RANK_D->query_self(me));
                        msg = replace_string(msg, "$s", RANK_D->query_self_rude(me));
                        msg = replace_string(msg, "$R", "(�Է������)");
                        msg = replace_string(msg, "$r", "(�Է������)");
                        msg = replace_string(msg, "$C", "(�Լ����س�)");
                        msg = replace_string(msg, "$c", "(�Է����س�)");
        me->start_more(msg);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : chkemote [���鶯����]��

���ָ������г�Ŀǰ����ʹ�õ� emote ���ߵ����г�
ĳ�� emote �����ݡ�

HELP
);
return 1;
}



