// Room: /d/chengdu/dongdajie1.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�񶼴��");
        set("long", @LONG
�������񶼴���������Ϳ��Ե��ᶽ���ˡ������ĳ����������
��������ȥ�Ĺٲ�����ɣ���һЩ�ٱ���·��Ѳ�ڡ���е�һ���
���£����ڹս���������
LONG );
        set("outdoors", "chengdu");

	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"west" : __DIR__"center",
	]));
        set("objects", ([
            "/d/city/npc/bing" : 2,
        ]));

	setup();
	replace_program(ROOM);
}

