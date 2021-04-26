// Code of ShenZhou
// ��ʯ��
// qfy July 8, 1996.

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��ʯ��");
	set("long", @LONG
��վ��ɽ���еľ�ʯ�ϣ�����ˮ���ɽ��������ľ�ʪ�����������У�
˫������վ����ˮλ���������ܿ��ɽ������ͷ����¡��¡�ĳ����
�������ȴ��������������ˮ������������Ϫ���д�����֦ɽʯ(stone)
���������Լ�������������(bank)Ҳ��ʼ�����ˡ�
LONG
        );
        
	set("item_desc",([
	    "stone" : "һ����ɽʯ����Ѹ���ر�ɽ��������������\n",
	    "bank" : "ˮλ�����ߣ���ʼ�����ˡ�\n",
	]));
	
        set("no_clean_up", 0);
        set("outdoors", "huashan" );

	set("cost", 3);
        setup();
}

void init()
{
	add_action("do_da", "da");
	add_action("do_da", "ji");
	add_action("do_da", "hit");
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me = this_player();

	if ( !arg || arg != "bank" )
	     return notify_fail( "ʲô��\n");

	message_vision("$N�������ذ��ϡ�\n\n", me);
	me->move(__DIR__"shanhong");
	message("vision", me->name() + "�����ɾ��������˹�����\n",environment(me), ({me}) );

	return 1;
}

int do_da(string arg)
{
	object weapon, me = this_player();

	if ( !arg || arg != "stone" )
	     return notify_fail( "ʲô��\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
   	|| (string)weapon->query("skill_type") != "sword"){ 
	  if ( me->query("neili") >=50 ) {
	     me->add("neili", -50);
	  }
	  else {
	     me->set("neili", 0);
          }
	  me->receive_wound("qi", 50, "��ɽʯ������");   	
	  me->receive_damage("qi", 70, "��ɽʯ������");
	  message_vision(
	  "$N����������˫��ͬʱ����ɽʯ��������������Լ��������ˡ�\n", me);
	  return 1;
	}

	if ( (int)me->query("neili") < 50 )
		return notify_fail( "���������㣬���ܻ�ʯ������\n"); 
	if ( (int)me->query("jingli") < 50 )
                return notify_fail( "�㾫�����㣬���ܻ�ʯ������\n");


	if ( weapon->name() == "С��֦" && weapon->query_temp("marks/��") >= 1 ) {
	  message_vision(HIW "ֻ������ž����һ����$N���е�" + weapon->name() + "�Ѿ���Ϊ���أ�\n" NOR, me);
	  weapon->unequip();
          weapon->move(environment(me));
          weapon->set("name", "�ϵ���" + weapon->name());
          weapon->set("value", 0);
          weapon->set("weapon_prop", 0);
        }
	else if ( weapon->name() == "�廨��" && weapon->query_temp("marks/��") >=3 ) {
	  message_vision(HIW "ֻ������ž����һ����$N���е�" + weapon->name() + "�Ѿ���Ϊ���أ�\n" NOR, me);
	  weapon->unequip();
          weapon->move(environment(me));
          weapon->set("name", "�ϵ���" + weapon->name());
          weapon->set("value", 0);
          weapon->set("weapon_prop", 0);
        }
	else if ( weapon->name() == "��" && weapon->query_temp("marks/��") >= 3 ) {
	  message_vision(HIW "ֻ������ž����һ����$N���е�" + weapon->name() + "�Ѿ���Ϊ���أ�\n" NOR, me);
	  weapon->unequip();
	  weapon->move(environment(me));
	  weapon->set("name", "�ϵ���" + weapon->name());
	  weapon->set("value", 0);
	  weapon->set("weapon_prop", 0);
	}
	else if ( weapon->name() == "�̽�" && weapon->query_temp("marks/��") >= 5 ) {
	  message_vision(HIW "ֻ������ž����һ����$N���е�" + weapon->name() + "�Ѿ���Ϊ���أ�\n" NOR, me);
          weapon->unequip();
          weapon->move(environment(me));
          weapon->set("name", "�ϵ���" + weapon->name());
          weapon->set("value", 0);
          weapon->set("weapon_prop", 0);
        }
	else if ( weapon->name() == "��ü��" && weapon->query_temp("marks/��") >= 6 ) {
  	  message_vision(HIW "ֻ������ž����һ����$N���е�" + weapon->name() + "�Ѿ���Ϊ���أ�\n" NOR, me);
  	  weapon->unequip();
  	  weapon->move(environment(me));
  	  weapon->set("name", "�ϵ���" + weapon->name());
  	  weapon->set("value", 0);
  	  weapon->set("weapon_prop", 0);
	}
	else if ( weapon->name() == "����" && weapon->query_temp("marks/��") >= 8 ) {
	  message_vision(HIW "ֻ������ž����һ����$N���е�" + weapon->name() + "�Ѿ���Ϊ���أ�\n" NOR, me);
          weapon->unequip();
          weapon->move(environment(me));
          weapon->set("name", "�ϵ���" + weapon->name());
          weapon->set("value", 0);
          weapon->set("weapon_prop", 0);
        }
	else if ( weapon->name() == "�ֽ�" && weapon->query_temp("marks/��") >= 15 ) {
  	  message_vision(HIW "ֻ������ž����һ����$N���е�" + weapon->name() + "�Ѿ���Ϊ���أ�\n" NOR, me);
  	  weapon->unequip();
  	  weapon->move(environment(me));
  	  weapon->set("name", "�ϵ���" + weapon->name());
  	  weapon->set("value", 0);
  	  weapon->set("weapon_prop", 0);
	}
	else if ( weapon->name() == "������" && weapon->query_temp("marks/��") >= 20 ) {
          message_vision(HIW "ֻ������ž����һ����$N���е�" + weapon->name() + "�Ѿ���Ϊ���أ�\n" NOR, me);
          weapon->unequip();
          weapon->move(environment(me));
          weapon->set("name", "�ϵ���" + weapon->name());
          weapon->set("value", 0);
          weapon->set("weapon_prop", 0);
	}
	else {
	  if ( weapon->name() != "�����ؽ�" && weapon->name() != "���콣" ) { 
	     weapon->add_temp("marks/��",1);
	  }
	  message_vision("$N�ٽ���ʯ����ȥ����ɽʯ���˻�ȥ��ʹɽʯ��������ߡ�\n", me);
	  
	  if ( (int)me->query_skill("strike",1) >= 30 
	  && (int)me->query_skill("strike",1) <= 100 ) {
	     me->improve_skill("strike", me->query("int"));
	     write( "��Ļ����Ʒ������ˡ�\n");
	  }

	  if ( (int)me->query_skill("sword",1)  >= 30
	  && (int)me->query_skill("sword",1) <= 100 ) {
             me->improve_skill("sword", me->query("int"));
	     write( "��Ļ������������ˡ�\n");
	  }

	  if ( (int)me->query_skill("force",1) >= 30
	  && (int)me->query_skill("force",1) <= 100 ) {
  	     me->improve_skill("force", me->query("int"));
	     write( "��Ļ����ڹ������ˡ�\n");
	  }	

	  if ( me->query_skill("dugu-jiujian",1) >= 1 ) {
	     me->improve_skill("dugu-jiujian", me->query("int")+20);
	     write( "��Ķ��¾Ž������ˡ�\n");
	  }

	  me->receive_damage("jingli", 30, "����͸֧��������");
	  me->receive_damage("qi", 10, "����͸֧��������");
          me->add("neili",-50);
	  return 1;
	}	  
} 
