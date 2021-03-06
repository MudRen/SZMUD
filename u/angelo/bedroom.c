//            #include <room.h>

inherit ROOM; 
 void wakeup(object me, object where);

void create()
{
          set("short", "睡房");
       set("long", @LONG
  这里是观荷小筑的睡房. 窗上挂着层层薄纱. 一阵阵带着荷花香的清
风吹来, 让人觉得像在云里。这里有一张很柔软舒适的大床(bed)。
LONG
	);
	set("sleep_room", 1);
	set("no_fight", 1);
	set("exits", ([ 
              "west" :"/u/angelo/livingroom",
	]));
 set("item_desc", ([  "bed" : "        青纱红褥,温柔梦乡。\n", 
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

          write("你往床上一躺,在淡淡的荷花香中甜甜的睡着了。\n");
              me->set_temp("block_msg/all",1); 
              message_vision("$N躺在床上，在淡淡的荷花香中，$N就进入了梦乡。\n",me);

	where->add_temp("sleeping_person", 1);
	
	me->set_temp("sleeped",1);

	me->set("disable_type", "<睡梦中>");
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
                  message_vision("$N一觉醒来,伸了个懒腰，精力充沛地活动了一下筋骨。\n",me);
		me->set_temp("block_msg/all", 0);
                  write("你一觉醒来,伸了个懒腰，精力充沛地活动了一下筋骨。\n",);

	}
	else {
		message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
		me->set_temp("block_msg/all", 0);
		write("你一觉醒来，只觉精力充沛。该活动一下了。\n");
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
                        return notify_fail("你不能带着其他玩家离开休息室。\n");
                }
        }
        return ::valid_leave(me, dir);
}
