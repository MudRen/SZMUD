// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
����һ�鼫��ͨ�Ĳݵأ�����ֻ��һЩѰ���洦�ɼ���Сʯ�Ӻ�С��֦��������
һ��С����������ï�ܵ����֣���������һ���ɰ��֣��ɰ�����һ��С·�����򱱣�
��֪���ա�
LONG
	);
	 set("exits", ([
                "west" : __DIR__"shucong",
                "east" : __DIR__"xiaojing",
                "north" : __DIR__"songlin",
        ]));
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
