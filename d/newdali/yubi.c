// Code of ShenZhou
// Room: /dali/yubi.c
// AceP

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
������ɽ·�ľ�ͷ��ǰ��ɽ���¾��ǽ����������ɽ��а����壬�嶥�п��
��ľ���ʯ(stone)��վ����߶��ܿ��ú����������������һ�����ٲ���ɽ����
����������ע����С�
LONG );

	set("item_desc", ([
		"stone" : "���ʯͷƽ���羵�����ռ�ë��������˵�ǿ�������ʵ�أ�ֻ��һ���ְ��ֹ��ʯͷ���ˡ�\n",
	]));

	set("exits", ([
		"southdown" : __DIR__"houshan",
	]));

	set("cost", 1);
        set("outdoors", "dali");
	setup();
}
