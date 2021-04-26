// Code of ShenZhou
// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
// 07/02/96 Marz 
// 3/16/97 Jay


#include <ansi.h>
string query_inquiry(object ob);
inherit F_CLEAN_UP;
//add ask job_system someting
#include "/clone/obj/job/job_ask_about.h"
////////////////////////////////////wzfeng 2000 7/////////////

string *msg_dunno = ({
	"$nҡҡͷ��˵����û��˵����\n",
	"$n�����۾�����$N����Ȼ��֪��$P��˵ʲô��\n",
	"$n�����ʼ磬�ܱ�Ǹ��˵���޿ɷ�档\n",
	"$n˵������....���ҿɲ��������������ʱ��˰ɡ�\n",
	"$n����һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n"
});

string *msg_foreign = ({
        "$n˵��������˵������ɣ��Ҳ��ᣬ����ô�����������\n",
        "$n����Ц������˵ʲô���\n",
        "$n˵�����Ű����ȹ����³���㿴����Ҳ�ܼ�װ��˵�������\n"
});


int main(object me, string arg)
{
	string dest, topic, msg, att;
	object ob;
	mapping inquiry;

	int iyes = 0;
	int k;	
	k = 33 - me->query_kar();
	if ( k < 4 ) k = 4;
	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("��Ҫ��˭ʲô�£�\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("����û������ˡ�\n");

	if( ob == me)
		return notify_fail("�α����Լ���\n");

	if( !ob->is_character() ) {
		message_vision("$N����$n��������....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") ) {
		message_vision("$N��$n�����йء�" + topic + "������Ϣ������$p��Ȼ�������˻���\n", me, ob);
		return 1;
	}
	if( iyes = !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�\n",
			me, ob);
		return 1;
	}
	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
			return 1;
		}
	}
	else if (topic[0] < 128  && iyes) {
                message_vision(msg_foreign[random(sizeof(msg_foreign))], me, ob);

	}
	else if ( ob->query("name") == topic || topic == "name" )

	{
		att = ob->query("attitude");
		
		switch (att)
		{
		case "aggressive":
		case "killer":
			message_vision(YEL"$N��$n����һ�ɣ�"+RANK_D->query_self_rude(ob)
				+"�������ǿ����������𣿣��ҿ�����"+RANK_D->query_rude(me)
				+"�ǻ����ˣ�\n"NOR, ob, me);
			break;	
		case "heroism":
			message_vision(CYN"$N��$n����һЦ��"+ob->query("name")+"����"
				+RANK_D->query_self_rude(ob)+"��\n"NOR, ob, me);
			break;
		case "peaceful":
		case "friendly":
			message_vision(CYN"$N��$n����һҾ����λ"+RANK_D->query_respect(me)
				+"����Ὺ��Ц����ô��ͻȻ����"+RANK_D->query_self(ob)
				+"�����֣�\n"NOR, ob, me);
			EMOTE_D->do_emote(ob, "sigh", ob->query("id"), 0);
			break;	
		default:
			message_vision(CYN"$N��$n����һҾ����λ"+RANK_D->query_respect(me)
				+"����Ὺ��Ц����ô��ͻȻ����"+RANK_D->query_self(ob)
				+"�����֣�\n"NOR, ob, me);
			EMOTE_D->do_emote(ob, "sigh", ob->query("id"), 0);
			break;	
		}		

		return 1;
		
	} else
		switch(topic)
	{
		case "here":
			message_vision(CYN "$n��$N˵����������" + environment(ob)->query("short") + "��������" + RANK_D->query_self(ob) + "�����˵��\n" NOR, me, ob);
			break;
//////////////////////////////////add job system ask about//////////////////////////////////
			case "���׶�":
			case "gongxiandu":
				tell_player_family_job_contribute(me,ob);
			break;
			//case "����ص�":
				//tell_player_family_job_opposepkerplace(me,ob);
				//break;
/////////////////////////////////////////////////////////////////////wzfeng 2000 7/////////

		case "all":
			if (!ob->query("inquiry") )
			{
			message_vision(CYN "$N��$n˵����" +query_inquiry(ob)+NOR "\n", ob ,me);
                         }else if ( random(k) == 2 )
				 {
			message_vision(CYN "$N��$n����˵������֪��" NOR, ob ,me);
			tell_object(me, CYN "���µ����飺\n"+query_inquiry(ob)+ NOR "\n");
	        message("vision",CYN "һЩ�����е����顣\n" NOR, environment(me), ({me}) );
			tell_object(me, CYN "������λ"+RANK_D->query_respect(me)+"����֪��ʲô�£�\n" NOR,me);
                            }else{
			EMOTE_D->do_emote(ob, "shake", me->query("id"), 0);
			message_vision(CYN "$N��$n˵������ΪʲôҪ�����㣡\n" NOR, ob ,me);
                            }                         
			break;

			default:
				message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
	}
		

	return 1;
}
string query_inquiry(object ob)
{
	int i=0;
	mapping inq;
	string str="", *indexs;
	string new_name;
	int	ppl_cnt;
	
	if(mapp(inq=ob->query("inquiry")))
		{
		indexs=keys(inq);
		ppl_cnt = 0;
		for(i=0;i<sizeof(indexs);i++)
			{
		 str = sprintf("%s%-0s%s", str, indexs[i], (ppl_cnt%7==6? " \n": "��"));
			ppl_cnt++;
				}
		str=HIB+str;
		return str;
		}
	return "ʵ���ǶԲ���,��ʲôҲ��֪��ѽ!";
	}

int help(object me)
{
   write( @HELP
ָ���ʽ: ask <someone> about <something>

���ָ���ڽ���ʱ����Ҫ, ͨ��������ɴ�һָ�����
��ý�һ������Ѷ��
HELP
   );
   return 1;
}
