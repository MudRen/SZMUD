// Code of ShenZhou
// d/emei/tombhouse.c ����Ĺ��Сé��
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "Сé��");
	set("long", @LONG
����һ��Сé�ݣ����ڰ���򵥣�һ��ľ����һ��ʯ����һֻľ��ܣ���
�ϰ��ż������顣ǽ�Ϲ���һ����üɽ��ɽˮ����ǽ�Ƿ���һ��С����������
���˶����ң�����ѷ���Щ��ͷ��ɨ��ȹ��ߡ�һ������Сʦ̫�����ڼ�ǰ
ר�Ķ��顣
LONG
	);

        set("exits", ([
                "west" : __DIR__"grassland",
        ]));

        set("objects",([
                __DIR__"npc/guard" : 1,
		__DIR__"obj/yugajing0" :1,
        ]));

	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	object ob, *inv;
	object guard = present("guard", environment(me));
//	object guard = objectp(present("guard", environment(me)));
	int i;

	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) 
		if (inv[i]->query_max_encumbrance() && ob = present("jiuyin-zhenjing", inv[i]) ) break;

	if ( !ob ) ob = present("jiuyin-zhenjing", me);

	if ( (dir == "west") && objectp(ob) ) {
        	message_vision("$N���黹���ķƣ��߳���ȥ��\n", me);
        	ob->move(environment(me));
        	destruct(ob);
		guard->add("jing_count", 1);
		me->delete_temp("visited");
        }

        return ::valid_leave(me, dir);
}

