// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "�ݼҴ�Ժ");
        set("long", @LONG
����һ��ũ��СԺ��Ժ��ɣ����Ժ���ֵú�������Ժ��һ��
���������Ÿ���ũ������ָ��һ������ϰ����
LONG
        );
        set("exits", ([
		"east" : __DIR__"cunkou",
		"west" : __DIR__"bkyard",
	]));

	set("objects", ([
		__DIR__"npc/changfa" : 1,
		__DIR__"npc/qifang" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
