// Code of ShenZhou
// Room: /city/jujinge1.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "�۽��");
	set("long", @LONG
��һ��������ֻ���õ��������������������Ĵ������ϱ߰ڷ���һЩ����
չʾ���鱦���Ρ����ߵĹ�̨(guitai)�������Ҫ���Ľ����鱦���������￴��
���ر����壬�ǱߵĻ�ƿ�������Ҳ�޶����ԡ���ȥ�����ϴ���ˡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"nandajie2",
	]));

	set("item_desc", ([
                "guitai" : "�׽��ָ            ʮ���ƽ�\n"
			   "��ɽѩ����          ��������\n"
			   "��ͷ������          һ������\n"
                           "�����˿ͷ��        ��������\n"
                           "��ʯ��ָ          ��ʮ������\n"
			   "��ͨ��ָ          ʮ��������\n"
                           "������              ��������\n"
                           "�������        ��ʮ��������\n"
                           "��βԧ����      ��ʮ��������\n",  
	]));

	set("objects", ([
		__DIR__"npc/niu" : 1,
		__DIR__"npc/jjhuoji" : 1,
	]));

	set("cost", 0);
	set("day_shop", 1);
	setup();
	replace_program(ROOM);
}
