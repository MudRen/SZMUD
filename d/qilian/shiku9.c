// Code of ShenZhou
inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG
������һ���γ�����Ķ��ߣ����бڻ����õ����й�д���ֱ������
���̷����������ɫ�嵭���űʴ����������η��������������һ��
��ɫ��͹�ױʵĵ��̷�������Ů��
LONG);
	set("exits", ([
                "east" : __DIR__"dtongdao4",
]));
	set("objects", ([
                "/d/wudang/obj/daodejing-i" : 1,
                "/d/wudang/obj/daodejing-ii" : 1,
]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

