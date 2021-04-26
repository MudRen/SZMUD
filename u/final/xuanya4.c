// Code of ShenZhou
// road: /zhongnan/xuanya4.c
// by sdong 08/98

inherit ROOM;
#include <ansi.h>
#include "localtime.h"
#include "/kungfu/skill/force_list.h"
int exercising(object me);
int halt_exercise(object me);
int respirating(object me);
int halt_respirate(object me);

int do_climb(string arg);

void create()
{
		  set("short",HIW"�¶�"NOR);

		  set("long",@LONG
�¶��Ǹ��޴��ƽ̨�������˰�����ѩ����������һ��ʯ���������ƺ�����һ��
��(ci)��վ���¶���������ȥ������ƽ��ãã��һ���޾���ɳĮ��ʧ����ߣ�˵����
������֮�⣬��ֻ�޴�ĺڵ��ڿ�������������
LONG);

		  set("item_desc",(["ci" : "

        "HIM"������"NOR"

   "HIC"��ҹͬ�ƺ�������������죬���������¡�
sasdasdasdasd
   �����ߺ��ƻ����˼�ڰ�˭��˵��
"NOR"
   "HIG"��������������һ���⻪����ϧ����û��
   ¥�Ϻ��紵δЪ�������д���΢�ȡ�"NOR"

\n",]));

	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_dazuo", "dazuo");

	add_action("do_dazuo", "exercise");
	add_action("do_tuna", "tuna");
	add_action("do_tuna", "respirate");
}


int do_climb(string arg)
{
	object me = this_player();
	int gain,cost;

	if(me->is_busy())
		return notify_fail("�㻹��æ���ء�\n");

	if(arg != "down" )
		return notify_fail("�Ǹ�����û������\n");

	cost = ( 300-me->query_dex()*me->query_skill("dodge")/20 )/10;
	if ( cost<10 )cost = 10;
	cost *= 2;

	if( me->query("jingli") < 30)
		return notify_fail("���۵�ʵ���������ˡ�\n");

	me->add("jingli",-cost);
	gain = me->query("con",1)*2;
	gain *= 2;

	if ( me->query_skill("dodge") > 300 ) gain /= 2;

	me->improve_skill( "dodge",random( gain ) );
	if( me->query_skill( "jinyangong",1) > 0 )
		me->improve_skill( "jinyangong",random( gain ) );


	message_vision( HIY"\n$N�����������ٸ���С�Ľ���������ȥ��\n"NOR, me);
	me->move("/d/zhongnan/xuanya3");
	message_vision( HIY"\n$N����������\n"NOR, me);
	return 1;
}

string day_event(){ return NATURE_D->outdoor_room_event();}

int do_dazuo(string arg)
{
		  int exercise_cost;
		  object me = this_player();

		  seteuid(getuid());
		  if (me->is_busy() || me->query_temp("pending/exercising"))
					 return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("ս���в������ڹ������߻���ħ��\n");

        if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");

		  if( !arg || !sscanf(arg, "%d", exercise_cost))
					 return notify_fail("��Ҫ��������������\n");
		  if (exercise_cost < 10)
					 return notify_fail("����ڹ���û�дﵽ�Ǹ����磡\n");

		  if( (int)me->query("qi") < exercise_cost )
					 return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");

		  if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
					 return notify_fail("�����ھ��������޷�������Ϣ��������\n");

		 if (day_event() == "event_night" || day_event() == "event_midnight")
		 {
		  write(HIG"�������㾲֮�У��������������й���\n"NOR);

		  me->set_temp("pending/exercise", 1);
		  me->set_temp("exercise_cost", exercise_cost);
		  message_vision("$N��ϥ���£���ʼ����������\n", me);
		  me->start_busy((: exercising :), (:halt_exercise:));
		  return 1;
		  }
		  else {return 0;}
}

int exercising(object me)
{
		  int exercise_cost = (int)me->query_temp("exercise_cost");
                  int neili_gain = 1 + (int)me->query_skill("force") / 5;
		  int i, clan, extra;
		  string force;

		  if (exercise_cost < 1)
					 return 0;
		  force = (string)me->query_skill_mapped("force");

		  for (i = 0; i < sizeof(force_list); i++)
                if (force == force_list[i]["force"])
                        clan = i;       
        extra = 1;

		  if (force_list[clan]["zheng_xie"] == 0) extra = extra * 2;
					 else extra = extra * 1.5;

		  neili_gain = neili_gain*extra;
		  me->add("neili", neili_gain);
		  me->set_temp("exercise_cost", exercise_cost -= neili_gain);

		  //me->add("qi", -neili_gain);
		  me->receive_damage("qi", neili_gain, "�����߻���ħ����");

		  if (exercise_cost > 0)
					 return 1;

		  me->set_temp("pending/exercise", 0);
		  message_vision("$N�˹���ϣ��������˿�����վ��������\n", me);
		  if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
					 return 0;
		  else {
					 if ((int)me->query("max_neili") > (int)me->query_skill("force") * 10) {
								write("���������Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
								me->set("neili", (int)me->query("max_neili"));
								return 0;
					 }
                else {
                        me->add("max_neili", 1);
                        me->set("neili", (int)me->query("max_neili"));
                        write("������������ˣ���\n");
                        return 0;
                }
        }
}

int halt_exercise(object me)
{
        if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
					 me->set("neili", (int)me->query("max_neili") * 2);
        me->set_temp("pending/exercise", 0);
        return 1;
}



int do_tuna(string arg)
{
        int respirate_cost;
        object where;
		  object me = this_player();

		  seteuid(getuid());

		  if (me->is_busy() || me->query_temp("pending/exercising"))
					 return notify_fail("��������æ���ء�\n");

		  if( me->is_fighting() )
					 return notify_fail("ս���в������ɣ����߻���ħ��\n");

		  if (me->query_temp("cursed", 1))
					 return notify_fail("ʲô��\n");

		  if( me->query("rided"))
					 return notify_fail("�����������ɣ����߻���ħ��\n");

		  if( !arg || !sscanf(arg, "%d", respirate_cost))
					 return notify_fail("��Ҫ�����پ����У�\n");
		  if (respirate_cost < 10)
					 return notify_fail("�����Ϊ��û�дﵽ�Ǹ����磡\n");

		  if( (int)me->query("jing") < respirate_cost )
					 return notify_fail("�����ھ����㣬�޷����о�����\n");

		  if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
					 return notify_fail("����������״��̫���ˣ��޷����о���\n");


		 if (day_event() == "event_night" || day_event() == "event_midnight")
       {
		  write(HIG"�������㾲֮�У��������������й���\n"NOR);

		  me->set_temp("pending/respirate", 1);
		  me->set_temp("respirate_cost", respirate_cost);
		  message_vision("$N��ϥ���£���ʼ����������\n", me);
		  me->start_busy((: respirating :), (:halt_respirate:));
		  return 1;
		  }
		  else {return 0;}
}

int respirating(object me)
{
		  int respirate_cost = (int)me->query_temp("respirate_cost");
		  int jingli_gain = 1 + (int)me->query_skill("force",1) / 10;
		  int i, clan, extra;
		  string force;
        
		  if (respirate_cost < 1)
					 return 0;

		  force = (string)me->query_skill_mapped("force");

		  for (i = 0; i < sizeof(force_list); i++)
					 if (force == force_list[i]["force"])
								clan = i;
		  extra = 1;

		  if (force_list[clan]["zheng_xie"] == 0) extra = extra * 2;
					 else extra = extra * 1.5;

		  jingli_gain = jingli_gain*extra;
		  me->add("jingli", jingli_gain);
		  me->set_temp("respirate_cost", respirate_cost -= jingli_gain);

		  //me->add("jing", -jingli_gain);
		  me->receive_damage("jing", jingli_gain, "�����߻���ħ����");

		  if (respirate_cost > 0)
					 return 1;

		  me->set_temp("pending/respirate", 0);
		  message_vision("$N������ϣ�����˫�ۣ�վ��������\n", me);
		  if ((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
                return 0;
        else {
                if ((int)me->query("max_jingli") > (int)me->query_skill("force") * 8
                 || (int)me->query("eff_jingli") > (int)me->query_skill("force") * 8) {
                        write("��ľ�����Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
                        me->set("jingli", (int)me->query("max_jingli"));
                        return 0;
                }
                else {
                        me->add("eff_jingli", 1);
                        me->add("max_jingli", 1);
                        me->set("jingli", (int)me->query("max_jingli"));
                        write("��ľ��������ˣ���\n");
                        return 0;
                }
        }
}


int halt_respirate(object me)
{
		  if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
					 me->set("jingli", (int)me->query("max_jingli") * 2);
		  me->set_temp("pending/respirate", 0);
		  return 1;
}


