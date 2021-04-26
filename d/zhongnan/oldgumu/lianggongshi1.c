// By xuanyuan
// road: /zhongnan/lianggongshi1.c

inherit ROOM;
#include <ansi.h>
#include "/kungfu/skill/force_list.h"
int exercising(object me);
int halt_exercise(object me);
int respirating(object me);
int halt_respirate(object me);
int do_climb(object me);
int do_xia(object me);
int do_study(string);

void create()
{
        set("short","������");
        set("long",@LONG
    ��ʯ����״�������أ���խ�Ͽ���Ϊ���Σ����߰�Բ������ȴ��  
������״,�Ҷ�ʯ��(shibi)�Ͽ�������㻨�Ʒ��ţ������������̳ɣ�
�����ǳ�����޹���ʯ���������һ�Ű�ɫʯ��(chuang)��
LONG);

        set("item_desc",(["chuang" : "
��ʯ���������Լ����ຮ֮�ص��Ϲź����Ƴɣ�����ϰ�ϳ��ڹ�����
����\n",
                        "shibi" : "
��ʯ��ԭ��һ���ָ�������ĵط�����������˵������������ڴ��� 
����ѧ��ǰխ���ƣ����ʹȭ����Բ�н������Ƿ��ڣ���������̵ľ���
�����������ĵá�
\n"]));

        set("exits",([ "north" : __DIR__"zoudao3",
                        "east" : __DIR__"lianggongshi2",
                       ]));
        set("cost",1);

        setup();
}

int valid_leave(object me, string dir)
{
	me=this_player();
//	if (dir == "north" && me->query_temp("hanyuchuang"))
	if (me->query_temp("hanyuchuang"))
	 return notify_fail("�㻹û�µ�(xiachuang)�أ��������ܡ�\n");
	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_dazuo", "dazuo");
	add_action("do_dazuo", "exercise");
	add_action("do_tuna", "tuna");
	add_action("do_tuna", "respirate");
	add_action("do_climb", "climb");
	add_action("do_climb", "sit");
	add_action("do_xia", "xiachuang");
	add_action("do_study", "study");
	add_action("do_study", "du");
	add_action("do_study", "lingwu");
}

int do_climb(object me)
{      
        me=this_player();
	if(!me->query_skill("yunu-xinjing", 1)||(int)me->query_skill("yunu-xinjing", 1) < 60)
	   {
		write("�����Ů�ľ���Ϊ���������������溮��\n");                   
		message_vision("$N�����˺��񴲣���������òҲҵģ��Ͻ�����������\n",me);
		return 1; 
 	  }	
	message_vision("$N�����˺���,���ڴ������������ˡ�\n",me);
	me->set_temp("hanyuchuang",1);
	return 1;	
}

int do_xia(object me)
{
	me=this_player();
	if (!me->query_temp("hanyuchuang"))
	 return notify_fail("����û���Ϻ��񴲣��µ���ȥѽ����\n");
	me->delete_temp("hanyuchuang");
	message_vision("$N���깦��������������µ�����\n",me);
	return 1;
}

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

		 if ( me->query_temp("hanyuchuang"))
		 {
		  write(HIW"���������������񴲵��溮�����й���\n"NOR);

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
		  int neili_gain = 2 + (int)me->query_skill("force") / 10;
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


		 if ( me->query_temp("hanyuchuang"))
       {
		  write(HIW"���������������񴲵��溮�����й���\n"NOR);

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


int do_study(string arg)
{
	object me;
        mapping fam;

	me = this_player();

	if ( !arg || arg != "shibi" )
		return notify_fail("ʲô��\n");

        if (!mapp(fam = me->query("family")) || (string)me->query("family/family_name") != "��Ĺ��") 
		return notify_fail("�㲻�ǹ�Ĺ���ӵܣ����򲻵�ʯ���������书�İ��\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	if ( (int)me->query_skill("yunu-jue", 1) < 50)
		return notify_fail("�����Ů��ʮ�ľ���򲻹����޷���������ѧϰʯ���ϵ��书��\n");

	if (me->query("jing") < 60)
		return notify_fail("��ľ���������\n");

	me->receive_damage("jing", random(60), "�����ʴ�����");

	message_vision("$N��ר���ж�ʯ���ϵ��书�ĵá�\n", me);

	switch( random(3) ) 
	{
	    case 0:
		if ( (int)me->query_skill("yunu-xinjing", 1) < 20)
		{
			me->improve_skill("yunu-xinjing", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ�����Ů�ľ��е��ĵá�\n");
			me->set_temp("shibi1_learned",1);
		}
	    case 1:
		if ( (int)me->query_skill("tianluo-diwang", 1) < 100)
		{
			me->improve_skill("tianluo-diwang", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ������޵������е��ĵá�\n");
			me->set_temp("shibi1_learned",1);
		}
	    case 2:
		if ( (int)me->query_skill("strike", 1) < 100)
		{
			me->improve_skill("strike", me->query("int"));
			write("�����ʯ����ĥ��һ�ض����ƺ����Ʒ��е��ĵá�\n");
			me->set_temp("shibi1_learned",1);
		}
	    case 3:
		if ( (int)me->query_skill("cuff", 1) < 100)
		{
			me->improve_skill("cuff", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ���ȭ���е��ĵá�\n");
			me->set_temp("shibi1_learned",1);
		}
	    case 4:
		if ( (int)me->query_skill("parry", 1) < 100)
		{
			me->improve_skill("parry", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ����м��е��ĵá�\n");
			me->set_temp("shibi1_learned",1);
		}
	}

	if ( !me->query_temp("shibi1_learned") )
	{
		write("�����ʯ����ĥ��һ�ض�������������˵��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
	}
	return 1;
}
