// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������������ľ�Ծ����ϣ����Ǹ�������������������̡�
�乹���������¥�����濪�ţ����ݿ����£��ϸ��糵��״���в�ס
�ˣ��������²㣬һ��Ϊţ��Ȧ��
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov13",
		"up" : __DIR__"minov15",
		]));

	set("objects", ([
		"/d/dali/npc/goat.c" : 2,
		]));

	set("outdoors","dali");
       set("fjing", 1);
	set("cost", 2);
	setup();
}
