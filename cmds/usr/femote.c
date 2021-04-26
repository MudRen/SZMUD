/* grep.c
 * 98-10-26
 * modify name to femote.c
 * make code less
 * by ken@XAJH
 */

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
int help(object me);
int check(string msg, string arg);
int main(object me, string arg)
{
        mapping emote;
        string *e, *loop;
        string result="", msg2, msg;
        int i,count=0;

        loop = ({ "others_target", "others_self", "others" });
        if( !arg )
                return help(me);

	if(me->query_temp("femote_time") + 120 > time() && !wizardp(me))
                return notify_fail("��ϵͳЪ���������\n");	

        if( strlen(arg) < 4 || sizeof(explode( arg, "\*" )) > strlen(arg) / 4)
                return notify_fail("��ָ���Ĺؼ��ֶ�һЩ�ź��ң������¶���ؼ��֡�\n");	

        e = sort_array( EMOTE_D->query_all_emote(), 1);
        for(i=0; i<sizeof(e); i++) {
                emote = EMOTE_D->query_emote(e[i]);
                for( int j=0; j<sizeof(loop); j++ ) {
                        msg = emote[ loop[j] ];
                        if( msg && check(msg,arg)) {
                                result += sprintf(CYN + "emote ��: %s\n" + CYN + "����: %s\n" + NOR, e[i], msg);
                                count ++;
                        }
                }
        }
        if(  result == "" )
                return notify_fail(MUD_NAME" ���޷��ϲ�ѯ������ emote.\n");
        else
		if (strlen(arg) > 20)
                        msg2 = arg[0..24-(sizeof(explode( arg[0..23], "\*" ))%2)] + "...";
              if (!msg2) msg2 = arg;
              msg2 = replace_string(msg2, "*", " "); 
                result = WHT"\n��ѯ���"NOR
                                "\n������������������������������������������������������������������������\n"
                                +result;
        result = replace_string(result, "$n", "(�Է�)");
        result = replace_string(result, "$N", me->name(1));
        result = replace_string(result, "$P", "��");
        result = replace_string(result, "$p", "(��/��)");
        result = replace_string(result, "$S", RANK_D->query_self(me));
        result = replace_string(result, "$s", RANK_D->query_self_rude(me));
        result = replace_string(result, "$R", "(�Է������)");
        result = replace_string(result, "$r", "(�Է������)");
        result = replace_string(result, "$C", "(�Լ����س�)");
        result = replace_string(result, "$c", "(�Է����س�)");
        result += NOR"������������������������������������������������������������������������\n";
        result += sprintf("��%s�У�������%s���� emote ���� %s ����\n�����֪��ʹ�ú��Ч����ʹ��"HIG"chkemote <emote��>"NOR"�����ѯ��",
                                        MUD_NAME, msg2, chinese_number(count) );
        me->start_more(result);
	me->add("jingli",-10);
	me->set_temp("femote_time",time());
        return 1;
}

int check(string msg, string arg)
{
	int j = 0, x = 0;
        msg = replace_string(msg, "$n", "");
        msg = replace_string(msg, "$N", "");
        msg = replace_string(msg, "$P", "");
        msg = replace_string(msg, "$p", "");
        msg = replace_string(msg, "$S", "");
        msg = replace_string(msg, "$s", "");
        msg = replace_string(msg, "$R", "");
        msg = replace_string(msg, "$r", "");
        msg = replace_string(msg, "$C", "");
        msg = replace_string(msg, "$c", "");
	if (!sizeof(explode( arg, "\*" ))
	 && strsrch(msg, arg) >= 0 )
	 	return 1;
	for(int i=0;i<sizeof(explode( arg, "\*" ));i++)
	{
		if(stringp(explode(arg,"\*")[i])
		 && strsrch(msg, explode(arg,"\*")[i]) >=0 )
			j++;
		if(explode(arg,"\*")[i] == "") x++;
		}
	if (j + x == sizeof(explode( arg, "\*" )) ) return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : femote �ؼ���
���ܣ��г�Ŀǰ���к�ָ���ؼ��ֵ� emote.

ע���ؼ����п��Լ���*��Ϊ������������ν�Ȳ��������֡�
����femote *����ľ������׼*�ĺ���һ���ƹ���*��Ҳû��һ���������ˤ���ڵء�
�ͻ���ҵ� club ���emote��

HELP
    );
    return 1;
}

