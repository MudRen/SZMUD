// Code of ShenZhou
// Room: /guandao1.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
������ͨ������Ĺٵ������׿�Ĵ����ȫ���ɻ����̳ɣ��ɲ�������
����������ӵ���������ǽ����ؿڵıؾ�֮·��·��������Ⱥ�����˶���
��������Ƥ����ҩ�ĵ������ˡ�ż�������Źٱ�����ɳ۶�����
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"shguan1",
		"northeast" : __DIR__"guandao2",
	]));

        set("objects",([
                __DIR__"npc/xiao" : 1,
        ]));

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}

