// Code of ShenZhou
// Room: /d/dali/dinganfu1.c
#include <login.h>
#include <ansi.h>

inherit ROOM;
string Point1="";
string Point2="";

void create()
{
	set("short", "����");
	set("long", @LONG
�������ķ������������£��õ����װڵ���һ������������������������
��ͬ����Ĺ�Ա����������������ͨ�룬�д��������⣬�������߻���վ������
���ۡ�
LONG);
	set("objects", ([
		"kungfu/class/dali/wujiang1" : 1,
		__DIR__"npc/duanjin" : 1,
		__DIR__"npc/bypanguan" : 1,
       ]));
	set("exits", ([
		"south" : __DIR__"dinganfu",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
}
void init()
{
	add_action("do_cant", "kill");
	add_action("do_cant", "perform");
	add_action("do_cant", "forcekill");
	add_action("do_cant", "yun");
	add_action("do_cant", "exert");
	add_action("do_cant", "throw");
}
int do_cant(string arg)
{
	object ob, item, me=this_player();
	string what, who;

	if (me->query_temp("dali/investigation"))
	{
		write("\n�Ѿ������˻�������һ�㣿\n");
		return 1;
	}
	if (query_verb()=="exert" || query_verb()=="yun")
	{
		if (arg == "roar")
		{
			write("\n����֮�Ͻ�ֹ������\n");
			return 1;
		}
		if (arg == "sing")
		{
			write("\n����֮�Ͻ�ֹ������\n");
			return 1;
		}
		return 0;
	}
	if (query_verb()=="perform")
	{
		if( sscanf(arg, "%s %s", what, arg))
		{
			if( what !="tuxi") return 0;
			if( (int)me->query_skill("qianzhu-wandu", 1) < 120 ) return 0;
			if (arg == "duan jin" || arg == "duan")
			{
				if (!ob=present(arg, environment(me))) return 0;
				message_vision("$N��$n����, ��Ȼ��ת��, �ӱ����ָͻϮ��\n\n\n", me, ob);
				message_vision(CYN "$Nŭ�������󵨿ɶ񣡹���֮�Ͼ���͵Ϯ���٣����˰�����\n\n\n"NOR, ob, me);
				me->start_busy(30);    
				Point1="��ͼ�ڹ�����͵Ϯ";
				Point2="����͵Ϯ����";
				me->set_temp("dali/investigation",1);
				remove_call_out("processing");
				call_out("processing", 5, ob);
				return 1;
			}
		}
	}
	if (query_verb()=="forcekill")
	{
		if( sscanf(arg, "%s with %s", arg, who))
		{
			if (who == arg) return 0;
			if (who == me->query("id")) return 0;
			if (arg == me->query("id")) return 0;
			if (me->query_skill("necromancy", 1) < 90) return 0;
	        item = present(who, environment(me));
			if (me->query("id") != item->query("xueshan/necromancy_singer")) return 0;
			if (arg == "duan jin" || arg == "duan")
			{
				if (!ob=present(arg, environment(me))) return 0;
                message_vision(HIR "$N��Ц�ж���$n���˼������䣬������ָ��ָ"+ob->name()+"��\n\n\n", me, item);
				message_vision(CYN "$Nһ�����һ���������󵨣������ڹ���֮�Ͻ���ɱ�ˣ����˰�����\n\n\n"NOR, ob, me);
				me->start_busy(30);    
				Point1="��������";
				Point2="����������ı������";
				me->set_temp("dali/investigation",1);
				remove_call_out("processing");
				call_out("processing", 5, ob);
				return 1;
			}
		}
	}
	if (query_verb()=="throw")
	{
		if(sscanf(arg,"%s at %s", what, arg))
		{
			if (arg == "duan jin" || arg == "duan")
			{
				if (!ob=present(arg, environment(me))) return 0;
				item = present(what, me);
				if (!item) return 0;
				message_vision("$N��һ���"+item->name()+"��׼$n��ȥ��\n\n\n", me, ob);
				message_vision(CYN "$Nŭ�������󵨿ɶ񣡹���֮�Ͼ���͵Ϯ���٣����˰�����\n\n\n"NOR, ob, me);
				me->start_busy(30);    
				Point1="��ͼ�ڹ�����͵Ϯ";
				Point2="��������Ϯ������";
				me->set_temp("dali/investigation",1);
				remove_call_out("processing");
				call_out("processing", 5, ob);
				return 1;
			}
		}
	}
	if (query_verb()=="kill")
	{
		if (arg == "duan jin" || arg == "duan")
		{
			if (!ob=present(arg, environment(me))) return 0;
			message_vision("$N����$n�ȵ��������������ղ������������һ��\n\n\n", me, ob);
			message_vision(CYN "$Nһ�����һ���������󵨣�����֮�Ͼ������ף����˰�����\n\n\n"NOR, ob, me);
			me->start_busy(30);    
			Point1="��ͼ�ڹ���������";
			Point2="������ͼ����";
			me->set_temp("dali/investigation",1);
			remove_call_out("processing");
			call_out("processing", 5, ob);
			return 1;
		}
	}
	return 0;
}
void processing(object ob)
{
	message_vision(HIR "�������������������������䡫��������\n" NOR, ob);
	write(HIW "\n��˫��һ�������˵��ϣ�̧ͷϸ����ֻ����ʮλ��ʿ�ֳֵ�ǹ��������Χ��\n����һ�˸��Ӷ������������㾱��������\n\n\n" NOR);
	message_vision(HIY "\n\n����ȵ��������Ҵ�����֮��"+Point2+"���õ������\n\n\n" NOR, ob);
	call_out("jailing", 5, ob, 5);
}
void jailing(object ob)
{
	object me=this_player();
	message_vision(HIY "\n\n$N�ֵ���������$n�ռ������£��Գͺ�Ч�������ٷ����һ�ȣ���\n\n\n" NOR, ob, me);
	message_vision(HIR "����ִ����֮������һק��$Nֻ��������˳�����˹�ȥ......\n\n" NOR, me);
	me->delete_temp("dali/investigation");
	me->set("startroom", "/d/dali/laoyu");
	me->move(__DIR__"laoyu");
	me->unconcious();
	CHANNEL_D->do_channel(ob, "chat", sprintf("����" + me->name()+"("+me->query("id")+")"+Point1+"��Ŀǰ���ɴ��������ռ࣡"));
}
