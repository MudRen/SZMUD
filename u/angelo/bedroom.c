//            #include <room.h>

inherit ROOM; 
 void wakeup(object me, object where);

void create()
{
          set("short", "˯��");
       set("long", @LONG
  �����ǹۺ�С����˯��. ���Ϲ��Ų�㱡ɴ. һ������źɻ������
�紵��, ���˾����������������һ�ź��������ʵĴ�(bed)��
LONG
	);
	set("sleep_room", 1);
	set("no_fight", 1);
	set("exits", ([ 
              "west" :"/u/angelo/livingroom",
	]));
 set("item_desc", ([  "bed" : "        ��ɴ����,�������硣\n", 
 ])); 
	set("cost", 1);
	setup();
}
void init()
{
	add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
	object shiji, me, where;
	
	me = this_player();
	where = environment(me);

	seteuid(getuid());

          write("��������һ��,�ڵ����ĺɻ����������˯���ˡ�\n");
              me->set_temp("block_msg/all",1); 
              message_vision("$N���ڴ��ϣ��ڵ����ĺɻ����У�$N�ͽ��������硣\n",me);

	where->add_temp("sleeping_person", 1);
	
	me->set_temp("sleeped",1);

	me->set("disable_type", "<˯����>");
	me->set_temp("disabled", 1);
	me->disable_commands();
	me->enable_commands();

         call_out("wakeup",3, me, where);
	return 1;
}

void wakeup(object me, object where)
{
	int sp, new_hp;
	object shiji;
	sp = 10 - (int)me->query_condition("sleep");

	new_hp = (int)me->query("qi");
	new_hp += ((int)me->query("eff_qi") - new_hp)*sp/10;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("eff_qi") ) new_hp = me->query("eff_qi");
	me->set("qi", new_hp);
	
	new_hp = (int)me->query("jing");
	new_hp += ((int)me->query("eff_jing") - new_hp)*sp/10;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("eff_jing") ) new_hp = me->query("eff_jing");
	me->set("jing", new_hp);

	new_hp = (int)me->query("jingli");
	new_hp += ((int)me->query("max_jingli") - new_hp)*sp/5;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("max_jingli") ) new_hp = me->query("max_jingli");
	me->set("jingli", new_hp);

	new_hp = (int)me->query("neili");
	new_hp += ((int)me->query("max_neili") - new_hp)*sp/12;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("max_neili") ) new_hp = me->query("max_neili");
	me->set("neili", new_hp);
	
	if (living(me)) return;

	me->enable_player();
	while( environment(me)->is_character() )
              me->move(environment(environment(me)));
        me->apply_condition("sleep", 6 + random(3));

        me->delete("disable_type");
	if(environment(me) == where)
	{
                  message_vision("$Nһ������,���˸���������������ػ��һ�½�ǡ�\n",me);
		me->set_temp("block_msg/all", 0);
                  write("��һ������,���˸���������������ػ��һ�½�ǡ�\n",);

	}
	else {
		message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
		me->set_temp("block_msg/all", 0);
		write("��һ��������ֻ���������档�ûһ���ˡ�\n");
	}
	where->add_temp("sleeping_person", -1);
	setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
        int i;
        inv = all_inventory(me);
        if ( dir == "southeast" || dir == "north" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character() && userp(inv[i]))
                        return notify_fail("�㲻�ܴ�����������뿪��Ϣ�ҡ�\n");
                }
        }
        return ::valid_leave(me, dir);
}
