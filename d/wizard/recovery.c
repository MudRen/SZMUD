inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������Ϸ�ļ����ң�רΪ��������Ϸ��ë�����޹��ܺ������
����������������������������е��˸����������к��ô�������
�����һ�Ŵ�(bed)���������ڴ���ʵʩ�����һ��(lay)�ϴ�����
�����̿�ʼ��
LONG
        );

        set("no_fight", 1);

	set("exits", ([
		"out" : "/d/city/wumiao",
		"enter" : "/u/qfy/workroom",
	]));

	set("cost", 0);
        setup();
        //replace_program(ROOM);
}
/* disabled by ryu. For cyz have access to here.
void init()
{
        add_action("do_lay", "lay");
}
*/
int do_lay(string arg)
{
        object me = this_player();
	mapping skill_status;
	string *sname;
	int i, count, new_shen, new_exp, new_pot;

	seteuid( geteuid(me) );

	if ( !arg || arg != "bed" ) return notify_fail("���������Ƕ�ѽ��\n");
	
	if ( me->query_temp("rec") == 1 ) return notify_fail("����ô�ϳ�ë���������������ˣ�\n");

	message_vision("$N������һ�ɣ��������Ƶ������£�һ��������Ժ�����ʧȥ֪���ˡ�\n", me);

	me->disable_player("<������>");
	me->set_temp("block_msg/all",1);

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname = keys(skill_status);
		count = sizeof(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]+1);
		}
	}

	new_shen = (int)me->query("shen") / 0.9;
	new_exp = 50*(int)me->query("combat_exp") / 49;
	new_pot = (int)me->query("potential") - (int)me->query("learned_points");

	me->set("shen", new_shen);
	me->set("combat_exp", new_exp);
	me->add("potential", new_pot);
	if ( me->query("death_count") > 0 ) {
		me->add("death_count", -1);
		if ((int)me->query("death_times") > (int)me->query("death_count"))
			me->set("death_times", (int)me->query("death_count"));
	}
	me->set_temp("rec", 1);

	call_out("wakeup", 20, me); 

	return 1;
}

void wakeup(object me)
{
	me->enable_player();
	me->set_temp("block_msg/all", 0);
	message_vision("����$N���˹����������Լ�����ȫ�����ˣ�\n", me);
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && dir == "enter")
                return notify_fail("��δ�����룬���ܵ��Ƕ�ȥ��\n");
	return ::valid_leave(me, dir);
}
