// Code of ShenZhou
// shuyuan.c ��ɽ��Ժ
// qfy July 7, 1996

inherit ROOM;

void create()
{
	set("short", "��ɽ��Ժ");
	set("long", @LONG
�����ǻ�ɽ��Ժ����ǽ��һ����ܣ��������鼮���Ҳ�������������
���ı��㱸����Ժ�������˴�ɨ��ʮ�ָɾ����롣
LONG
	);

	set("exits", ([
		"west" : __DIR__"donglang",
	]));

	set("objects", ([
		__DIR__"obj/zhengqi_book1" : 1,
		__DIR__"obj/zhengqi_book2" : 1,
                __DIR__"obj/sword_book" : 3,
		__DIR__"obj/ziyin_book1" : 1,
		__DIR__"obj/ziyin_book2" : 1,
	]));

	set("cost", 1);
	setup();
//	replace_program(ROOM);
}

void init()
{
	object *inv, me = this_player();
        int i, j=0;

	inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("id")=="ziyin book"
                || (string)inv[i]->query("id")=="zhengqi book"
                || (string)inv[i]->query("id")=="sword book" ) j++;
	}

	me->set_temp("possbooks", j);
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("id")=="ziyin book"
		|| (string)inv[i]->query("id")=="zhengqi book"
		|| (string)inv[i]->query("id")=="sword book" ) j++;
        }

        if ( j == (int)me->query_temp("possbooks")+1 ) 
		me->set_temp("huashan/��", 1);
        if ( j > (int)me->query_temp("possbooks")+1 ) 
		return notify_fail("�㿼״Ԫ����һ������ô���飡\n");

        return ::valid_leave(me, dir);
}
