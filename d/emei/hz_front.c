// Code of ShenZhou
// hz_front.c ����������
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "����������");
	set("long", @LONG
�����Ƕ���ɽ�𶥻����ֵ���������ֹ�ģ��󣬵�����ש�̵أ��м�
�������������������������ǰ����һ��ľ���������������Թ�ߵ�ݡ�
�Դ����Ҹ���һ����ǽӴ���͵ĵط���������ͨ��һ����㳡��ֻ�ж�
�ҵ��Ӳ��ܹ�ȥ��
LONG
	);
	set("exits", ([
		"out" : __DIR__"huazang",
		"east" : __DIR__"hz_east",
		"west" : __DIR__"hz_west",
		"south" : __DIR__"hz_guangchang",
	]));

        set("item_desc",([
                "door"          :       (: look_door :),
        ]));

        set("objects",([
                __DIR__"npc/xiang-ke" : 1,
                CLASS_D("emei") + "/jingxin" : 1,
        ]));

        set("no_clean_up", 0);

	set("cost", 0);
	setup();
//	replace_program(ROOM);

}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "������") && dir == "south"  &&
                objectp(present("jingxin shitai", environment(me))))
           return notify_fail("����ʦ̫����ǰ˵������Ƕ��ҵ���������Ϣ�ĵط�����������\n");

        return ::valid_leave(me, dir);
}


