// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ��������ķ��ݡ�������ӵĽ��غ����򽲾���������ɽ
�ƣ�һ����ʯΪǽ�ͻ�����ľΪ�����ṹ���ºͺ��˷�����£�����
ƽ����ʯ��Χǽ�����Ժ����һ��ľ�ܣ�����Щɽ����ҰѼ�������
���һ���������ڸ������Ƥ���š�
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov84",
		]));

	set("objects", ([
		"/d/dali/npc/wylieren.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
