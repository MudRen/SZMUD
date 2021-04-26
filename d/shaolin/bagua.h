// Code of ShenZhou
// Room: /d/shaolin/bagua.h
// Date: YZC 96/01/19

#include <ansi.h>

string* dirs = ({
	"��", "��", "��", "Ǭ",
	"��", "��", "��", "��"
	});

int check_dirs(object me, string dir)
{
	int i, bc, count;
	if (member_array(dir, dirs) != -1)
	{
		bc = me->query_temp("bagua/count");

		switch (dir)
		{
		case "��":
			if (bc == 0 || bc == 13 || bc == 17)
				me->set_temp("bagua/count",  bc + 1);
			else    me->delete_temp("bagua/count");
			
			tell_object(me, HIR "\n��������һƬ���ƺ���ض���ת�˹�������ֻ����ͷ����Ҳ��һ����ѣ....\n\n" NOR);
			me->receive_damage("jing",50);
			break;
		case "��":
			me->delete_temp("bagua/count");
			break;
		case "��":
			if (bc == 1 || bc == 12 )
				me->set_temp("bagua/count",  bc + 1);
			else    me->delete_temp("bagua/count");

			tell_object(me, HIR "\n�����ʯ�������𣬽����ذ��������������ֻ��ȫ�����������ɢ��\n\n" NOR);
			if ((int)me->query("neili") >= 50)
				me->add("neili", -50);
			else 	me->set("neili", 0);	
			break;
		case "Ǭ":
			if (bc == 8 )
				me->set_temp("bagua/count",  bc + 1);
			else    me->delete_temp("bagua/count");

			tell_object(me, HIR "\n��ͨһ������һ����������������������·�������С���ӳ����������������\n\n" NOR);
			me->receive_damage("qi", 50);
			break;
		case "��":
			if (bc == 3 || bc == 4 || bc == 15)
				me->set_temp("bagua/count",  bc + 1);
			else    me->delete_temp("bagua/count");

			tell_object(me, HIR "\n��ֻ��ͷ�Կյ����ģ��ƺ���ʲô���������ȥ��ȴ��˵������ʲô����....\n\n" NOR);
			if ((int)me->query("combat_exp") >= 50)
				me->add("combat_exp", -50);
			else	me->set("combat_exp", 6);	
			break;
		case "��":
			if (bc == 2 || bc == 7 || bc == 9 )
				me->set_temp("bagua/count",  bc + 1);
			else    me->delete_temp("bagua/count");

			tell_object(me, HIR "\n�ұڼ䴫��һ�������ף�ͻȻ����дܳ�һ�����磬�������ͷ����\n\n" NOR);
			me->unconcious();
			break;
		case "��":
			if (bc == 6 || bc == 11 )
				me->set_temp("bagua/count",  bc + 1);
			else	me->delete_temp("bagua/count");

			tell_object(me, HIR "\n��Ȼ����ǰ��Ӱ��������ʮ�ѷɵ�бб������������������˳�����Ѫ�ۣ�\n\n" NOR);
			me->receive_wound("qi", 50);
			break;
		case "��":
			if (bc == 5 || bc == 10 || bc == 14 || bc == 16)
				me->set_temp("bagua/count",  bc + 1);
			else	me->delete_temp("bagua/count");

			tell_object(me, HIR "\nֻ��ƹ��һ����һֻ�޴��ľ������������������ǰ��ʱ������ð��\n\n" NOR);
			me->receive_wound("jing", 50);
			break;
		default:
			me->delete_temp("bagua/count");
			break;
		}

		if (dir == "��")
		{
			me->delete_temp("bagua");
		}
		else
		{
			count =  me->query_temp("bagua/"+dir);
			count++;
			me->set_temp("bagua/"+dir, count);
			if (count > 13)
			{
				me->delete_temp("bagua");
				me->move(__DIR__"jianyu");
				return (1);
			}
		}
	}

/*
	write("* " + me->query_temp("bagua/northwest"));
	write(" " + me->query_temp("bagua/north"));
	write(" " + me->query_temp("bagua/northeast") +"\n");
	
	write("* " + me->query_temp("bagua/west"));
	write(" " + me->query_temp("bagua/count"));
	write(" " + me->query_temp("bagua/east") +"\n");
	
	write("* " + me->query_temp("bagua/southwest"));
	write(" " + me->query_temp("bagua/south"));
	write(" " + me->query_temp("bagua/southeast") +"\n");
*/
	return (0);
}
